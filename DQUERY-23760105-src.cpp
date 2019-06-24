/******************************************
*    AUTHOR:         Atharva Sarage       *
*    InSTITUITIOn:   IIT HYDERABAD        *
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
# define mx 1000005
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

int a[mx],prev1[mx];
node* version[30005];

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
		{
			curr->val=value+prev->val;
			return;
		}
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
int query(node*n ,int low,int high,int l,int r)
{
	if(l>high || r<low || low>high)
		return 0;
	if(l<=low && high<=r)
		return n->val;
	int mid=(low+high)/2;
	int p1=query(n->left,low,mid,l,r);
	int p2=query(n->right,mid+1,high,l,r);
	return p1+p2;
}
int main()
{
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{scanf("%d",&a[i]);;prev1[a[i]]=0;}
	scanf("%d",&q);
	version[0]=new node(NULL,NULL,0);
	build(version[0],0,n);
	for(int i=1;i<=n;i++)
	{
		version[i]=new node(NULL,NULL,0);
		upgrade(version[i-1],version[i],0,n,prev1[a[i]],1);			
		prev1[a[i]]=i;
	}
	while(q--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int ans1=query(version[r],0,n,0,l-1);
		int ans2=query(version[l-1],0,n,0,l-1);
		printf("%d\n",ans1-ans2);		
	}	
	
}
