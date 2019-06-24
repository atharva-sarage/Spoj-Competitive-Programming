/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 100005
struct node
{
	int val;
	node *left,*right;
	node() {}
	node(node*l,node*r,int v)
	{
		left=l;
		right=r;
		val=v;
	}	
};

int a[mx],b[mx];
map <int,int> map1;
node* version[mx];

void build(node*n , int low,int high)
{
	if(low==high)
	{
		n->val=0;
		return;
	}
	int mid=(low+high)/2;
	n->left=new node(NULL,NULL,0);
	n->right=new node(NULL,NULL,0);
	build(n->left,low,mid);
	build(n->right,mid+1,high);
	n->val=n->left->val+n->right->val;
}
void upgrade(node*prev,node*curr,int low,int high,int idx,int value)
{
	if(idx>high || idx<low || low>high)
		return;
	if(low==high)
		{curr->val=value;return;}
	int mid=(low+high)/2;
	if(idx<=mid)
	{
		curr->right=prev->right;
		curr->left=new node(NULL,NULL,0);
		upgrade(prev->left,curr->left,low,mid,idx,value);
	}
	else
	{
		curr->left=prev->left;
		curr->right=new node(NULL,NULL,0);
		upgrade(prev->right,curr->right,mid+1,high,idx,value);
	}
	curr->val=curr->right->val+curr->left->val;
}
int solve(node* l1,node*r1,int low,int high,int k)
{
	if(low==high)
		return low;
	int mid=(low+high)/2;
	int left_size=r1->left->val-l1->left->val;
	if(k<=left_size)
		{return solve(l1->left,r1->left,low,mid,k);}
	else
		return solve(l1->right,r1->right,mid+1,high,k-left_size);
}
int main()
{
	IOS;
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
	sort(b+1,b+n+1);
	int id=0;
	int rmap[mx];
	for(int i=1;i<=n;i++)
	{
		int x=b[i];
		if(map1.count(x)==0)
		{
			id++;
			map1[x]=id;
			rmap[id]=x;			
		}
	}
		for(int i=1;i<=n;i++)
			a[i]=map1[a[i]];
		int N=id;
		version[0]=new node(NULL,NULL,0);
		build(version[0],1,N);
		for(int i=1;i<=N;i++)
		{
			version[i]=new node(NULL,NULL,0);
			upgrade(version[i-1],version[i],1,N,a[i],1);			
		}
		while(q--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			int ans=solve(version[l-1],version[r],1,N,k);
			cout<<rmap[ans]<<endl;
		}	
	
}
