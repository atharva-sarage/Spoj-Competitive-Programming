/*Author
		Atharva Sarage
		IIT Hyderabad */

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;	
	while(n!=0)
	{
		int long max=0,l[2001],sum=0;
		int i,j;
		for(int i=0;i<n;i++)
		{
			cin>>l[i];
			if(l[i]>max)
			max=l[i];
		}
		sort(l,l+n);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				int	u1=upper_bound(l,l+n,l[i]+l[j])-l;
				//cout<<"upper bound"<<u1<<"i"<<i<<"j"<<j<<endl;
				if(l[i]+l[j]<max)
				{
					
				//cout<<l[i]+l[j]<<" "<<l[u1-1]<<" "<<endl;
				if(l[u1-1]==l[i]+l[j])
				{
					sum=sum+n-u1;
					//cout<<l[i]<<" "<<l[j]<<" "<<l[u1-1]<<endl;
				}
				
				else if(l[i]+l[j]>l[u1-1])
				{
					sum=sum+n-u1;
					//cout<<l[i]<<" "<<l[j]<<" "<<l[u1-1]<<endl;
					
				}
			}
			}
		}
		cout<<sum<<endl;
		cin>>n;
	}
}