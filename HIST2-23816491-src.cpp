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
pair<ll,ll> dp[mx][20];
ll a[mx];
int main()
{
	IOS;
	ll x;
	cin>>x;
	while(x)
	{	
		memset(dp,0,sizeof(dp));
		for(ll i=0;i<x;i++)
			cin>>a[i];
		ll c1=1<<x;
		ll final=0,fullyfinal=0,finalcount=0;
		for(ll i=0;i<c1;i++)
		{
			for(ll j=0;j<x;j++)
			{
				if(i==0)
				{
					dp[1<<j][j]={1+a[j],1};
					if(i|1<<j==c1-1)
						final=max(final,dp[i|1<<j][j].ff+a[j]);
					continue;
				}
				if(i&(1<<j))continue;
				for(ll k=0;k<x;k++)				
				{
					if((i&(1<<k))==0)continue;
					if(dp[i|1<<j][j].ff==dp[i][k].ff+1+abs(a[k]-a[j]))
						dp[i|1<<j][j].ss+=dp[i][k].ss;
					else if (dp[i|1<<j][j].ff<dp[i][k].ff+1+abs(a[k]-a[j]))
						{dp[i|1<<j][j].ff=max(dp[i|1<<j][j].ff,dp[i][k].ff+1+abs(a[k]-a[j]));
						 dp[i|1<<j][j].ss=dp[i][k].ss;}
				}
					//cout<<(i|1<<j)<<" "<<i<<" "<<j<<" "<<dp[i|1<<j][j].ff<<"???"<<endl;
				if(i|1<<j==c1-1)
					final=max(final,dp[i|1<<j][j].ff+a[j]);
			}
		}
		for(ll i=0;i<x;i++)
		{
			if(final==dp[c1-1][i].ff+a[i])
				finalcount+=dp[c1-1][i].ss;
		}
		cout<<final+x<<" "<<finalcount<<endl;		
		cin>>x;
	}
}
