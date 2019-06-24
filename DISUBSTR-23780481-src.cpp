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
# define mx 100005
# define mx2 20

string a;
struct entry{
	int nr[2],x;
} l[mx];
int p[mx2][mx],n,i,stp,cnt;

bool compare(struct entry a,struct entry b)
{
	return a.nr[0]==b.nr[0] ? (a.nr[1]<b.nr[1]) : (a.nr[0]<b.nr[0]);
}
int lcp[mx],final[mx];
void computelcp()
{
	for(int i=0;i<n-1;i++)
	{
		int low=0;
		int high=n;
		int mid;
		int i1=final[i],i2=final[i+1];
		while(high>=low)
		{
			mid=(low+high)/2;
			if(i1+mid<=n && i2+mid<=n && a.substr(i1,mid)==a.substr(i2,mid))
				low=mid+1;
			else
				high=mid-1;
		}
		lcp[i]=high;
	}
}
int main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
	cin>>a;
	n=a.length();
	for(int i=0;i<n;i++)
		p[0][i]=a[i]-'a';
	for(stp=1,cnt=1;cnt<n;stp++,cnt<<=1)
	{
		for(int i=0;i<n;i++)
		{
			l[i].nr[0]=p[stp-1][i];
			l[i].nr[1]=i+cnt<n ? p[stp-1][i+cnt] : -1;
			l[i].x=i;
		}
		sort(l,l+n,compare);
		for(int i=0;i<n;i++)
		{
			p[stp][l[i].x]= i>0 && l[i].nr[0]==l[i-1].nr[0] && l[i].nr[1]==l[i-1].nr[1] ? p[stp][l[i-1].x]:i ;
		}
	}
	map <int,int> rmap;
	for(int i=0;i<n;i++)
		rmap[p[stp-1][i]]=i;
	int u=0;
	for(auto k:rmap)
		final[u++]=k.ss;
	// for(int i=0;i<n;i++)
	// 	cout<<final[i]<<" ";
	// cout<<endl;
	computelcp();
	lcp[n-1]=0;
	int total=0;
	 for(int i=0;i<n;i++)
	 	total+=lcp[i];
	 cout<<(n*(n+1))/2-total<<endl;
	}

}

