#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
		int n;
		cin>>n;
		int a[2*n+1];
		int visited[n+1],final[n+1];
		memset(visited,0,sizeof(visited));
		for(int i=0;i<2*n;i++)
			cin>>a[i];
		stack<int> s;
		for(int i=0;i<2*n;i++)
		{
			if(!visited[a[i]])
			{
				s.push(a[i]);
				visited[a[i]]=1;
			}
			else
			{
				int count1=0;
				while(s.top()!=a[i])
				{
					count1++;
					s.pop();
					if(s.empty())
						break;
				}
				final[a[i]]=count1;
				s.pop();
				s.push(-1);
			}

		}
		cout<<"Case "<<i1<<":"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<" -> "<<final[i+1]<<endl;
		}
	}
}