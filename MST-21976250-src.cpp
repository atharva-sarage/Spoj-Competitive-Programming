#include<bits/stdc++.h>
# define mx 100005
# define INF 0x3f3f3f3f
using namespace std;
// prims algorithm
typedef int long long ll;
typedef pair<ll,ll> ipair;
ll parent[mx];

ll visited[mx];
vector <ipair> adj[mx];
void addedge(int x,int y,int wt)
{
	adj[x].push_back(make_pair(wt,y));
	adj[y].push_back(make_pair(wt,x));
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll x,y,wt;
		cin>>x>>y>>wt;
		x--;y--;
		addedge(x,y,wt);
	}
	priority_queue <ipair,vector<ipair>,greater<ipair> > pq;
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	vector<ll> dist(n,INF);
	
	pq.push(make_pair(0,0));
	dist[0]=0;
	while(!pq.empty())
	{
		ll a=pq.top().second;
		pq.pop();
		visited[a]=true;

		for(int i=0;i<adj[a].size();i++)
		{
			
			ll wt=adj[a][i].first;
			ll u=adj[a][i].second;
			if(dist[u]>wt && visited[u]==false)
			{

				dist[u]=wt;
				pq.push(make_pair(dist[u],u));
				parent[u]=a;
			}
		}
	}
	ll ans=0;
	
	for(int i=1;i<n;i++)
	{
		// add the weights
		
		for(int j=0;j<adj[i].size();j++)
		{
			if(adj[i][j].second==parent[i])
				{
					ans+=adj[i][j].first;
					break;
				}
		}
	}
	cout<<ans<<endl;

}