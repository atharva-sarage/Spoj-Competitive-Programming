// kruskals

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ranks[100005];
ll parent[100005];
ll parent1[100005];
struct edge
{
	ll u,v,wt;
};
bool compare(edge a,edge b)
{
	return a.wt<b.wt;
}
ll find(ll a)
{
	if(a==parent[a])	return a;
	ll x=find(parent[a]);
	parent[a]=x;
	
	return x;
}

void unite(ll a, ll b)
{
	ll x=find(a),y=find(b);
	
	if(x==y)	return ;
	
	if(ranks[x]>ranks[y])
		swap(x,y);
	
	parent[x]=y;
	ranks[y]+=ranks[x];
	return ;
	
}

int main()
{
	ll n,m;
	cin>>n>>m;
	struct edge e[100005];
	for(ll i=0;i<m;i++)
	{
		ll x,y,wt;
		cin>>x>>y>>wt;
		e[i].u=x;e[i].v=y;e[i].wt=wt;
	}
	sort(e,e+m,compare);
	for(ll i=0;i<n;i++)
	{
		parent[i]=i;
		ranks[i]=1;
		parent1[i]=-1;
	}
	long long ans=0;
	for(ll i=0;i<m;i++)
	{
		//printf("%lld %lld %lld\n",e[i].u,e[i].v,e[i].wt );
		if(find(e[i].u)!=find(e[i].v))
			{
				unite(e[i].u,e[i].v);
				ans+=e[i].wt;
			}
	}
	cout<<ans<<endl;	

	}

