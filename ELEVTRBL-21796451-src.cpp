#include<bits/stdc++.h>
using namespace std;
vector <int> adj[1000005];

int dist[1000005];

void bfs(int a)
{
	memset(dist,-1,sizeof(dist));
	vector<bool> visited(1000005, false);		
	queue <int> q;
	q.push(a);	
	visited[a]=true;
	dist[a]=0;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(int i=0;i<adj[f].size();i++)
		{
			
			if(visited[adj[f][i]]==false)
			{
				q.push(adj[f][i]);
				visited[adj[f][i]]=true;
				dist[adj[f][i]]=dist[f]+1;
			}
		}
	}
}
int main()
{
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	for(int i=1;i<=f;i++)
	{
		if(i+u<=f)
			adj[i].push_back(i+u);
		if(i-d>=0)
			adj[i].push_back(i-d);
	}
	bfs(s);
	if(dist[g]==-1)
		cout<<"use the stairs"<<endl;
	else
		cout<<dist[g]<<endl;
}