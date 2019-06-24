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
# define mod 5000000
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 100010
ll table[55][mx+5];
ll query(ll i,ll index1)
{
	ll res=0;
	while(index1>0)
	{
		res+=table[i][index1];
		res%=mod;
		index1-=(index1&-index1);
	}
	return res;
}
void update(ll i,ll index1,ll delta)
{
	while(index1<=mx)
	{
		table[i][index1]+=delta;
		index1+=(index1&(-index1));
	}
}
int main()
{
	IOS;
	ll n,k,x,final=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		{
			cin>>x;
			x++;
			update(1,x,1);
			for(ll l=2;l<=k;l++)
			{
				ll temp=query(l-1,x-1);
				update(l,x,temp);				
			}
		}
	cout<<query(k,99999)<<endl;
}
  