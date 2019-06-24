#include<stack>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{

	int i,l,j=1,t=0,flag=1;
	
	stack <int> road;
	int a[1001];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		

	while(!road.empty() && road.top()==j)
		{		
			
			//cout<<"*"<<endl;
			road.pop();
			j++;
		
		}
		
		if(a[i]!=j)
		{
			
			road.push(a[i]);
			//cout<<j<<endl;
			t++;
		}
		else if(a[i]==j)
		{
			//cout<<a[i]<<"**"<<endl;
			j++;
			//cout<<j<<"///"<<endl;
		}
	}

	while(!road.empty() && road.top()==j)
		{		
			
			//cout<<"*"<<endl;
			road.pop();
			j++;
		
		}

	
	if(t==1)
	{
		cout<<"yes"<<endl;
		return 0;
	}
	
	

	if(road.empty())
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	cin>>n;

}

}