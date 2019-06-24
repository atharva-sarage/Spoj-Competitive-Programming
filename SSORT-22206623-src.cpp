#include<bits/stdc++.h>
#define mx 1005
using namespace std;
int n,sum,min1,final,size;
int visited[mx];
int par[mx];
int a[mx],b[mx],c[mx];
vector <int> vec;
void dfs(int u,int parent)
{
	visited[u]=true;
	par[u]=parent;
	if(visited[b[u]])
	{
		int v=b[u];
		sum=v;
		min1=v;
		while(u!=v)
		{
			size++;
			sum+=u;
			min1=min(min1,u);
			u=par[u];
		}
		size++;
		return;
	}
	else
	dfs(b[u],u);
}
void DFS()
{
	for(int i=1;i<=n;i++)
	{
		if(!visited[a[i]])
			{
			sum=0;
			size=0;
			dfs(a[i],-1);
			//cout<<sum<<endl;
			if(size==1)
			{
				continue;
			}
			
			final+=(sum+min1*(size-2));
			if(c[1]-min1*size+3*min1+c[1]*size<0)
				final+=c[1]-min1*size+3*min1+c[1]*size;
			}
	}
}
int main()
{
	cin>>n;
	int count=1;
	while(n!=0)
	{
		final=0;
	memset(visited,false,sizeof(visited));
	memset(b,-1,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		b[c[i]]=a[i];
	}
	//cout<<b[1]<<" "<<b[2]<<" "<<b[4]<<endl;
	DFS();
	cout<<"Case "<<count<<":"<<" "<<final<<endl;
	cin>>n;
	count++;
	}
}