#include<bits/stdc++.h>
# define mx 20005
using namespace std;
typedef long long ll;
ll parent[mx];
ll ranks[mx];
vector <ll > adj[mx];
void addedge(ll x,ll y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
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

int  main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
	cin>>n;
	vector <pair<ll,ll> > e;
	ll flag[mx]={0};
	ll flag2[mx]={0};
	for(ll i=0;i<n;i++)
	{
		ranks[i]=1;
		parent[i]=i;
	}
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		x--;y--;
		e.push_back(make_pair(x,y));
	}
	cin>>m;
	stack <char> st;
	stack <ll> val;
	for(ll i=0;i<m;i++)
	{
		char x;
		cin>>x;
		if(x=='Q')
			st.push('Q');
		else
		{
			ll y;
			cin>>y;
			y--;
			st.push('R');
			val.push(y);
			flag[y]=1;
		}
	}
	// now we have scanned all the queries
	ll ans=0;
	for(ll i=0;i<n-1;i++)
	{
		if(flag[i]==0)//  validedge
			{
				addedge(e[i].first,e[i].second);
				unite(e[i].first,e[i].second);
			}
	}
	for(ll i=0;i<n;i++)
	{
		if(flag2[find(i)]==0)
		{
			ans+=ranks[find(i)]*ranks[find(i)];
			flag2[find(i)]=1;
		}
	}
	//ans=(n*n-ans)/2;
	stack <ll> final;

	for(ll i=0;i<m;i++)
	{
		if(st.top()=='Q')
		{
			final.push((n*n-ans)/2);
		}
		else
		{
			ll y=val.top();
			ll u=e[y].first;
			ll v=e[y].second;
			ans+=2*ranks[find(u)]*ranks[find(v)];
			unite(u,v);
			val.pop();
		}
		st.pop();

	}
	ll size=final.size();
	for(ll i=0;i<size;i++)
	{
		cout<<final.top()<<endl;
		final.pop();
	}

	
	e.clear();
	for(int i=0;i<n;i++)
		adj[i].clear();
	}
	
}