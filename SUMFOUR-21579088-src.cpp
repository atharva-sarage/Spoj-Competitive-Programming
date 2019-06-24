#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	scanf("%d",&n);
	vector <int long> a1,b1,c1,d1,x1,y1;
	for(i=0;i<n;i++)
	{
		int long a,b,c,d;
		scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
		a1.push_back(a);
		b1.push_back(b);
		c1.push_back(c);
		d1.push_back(d);
	}
	int long final=0;
	

	sort(a1.begin(),a1.end());
	sort(b1.begin(),b1.end());
	sort(c1.begin(),c1.end());
	sort(d1.begin(),d1.end());

	for(i=0;i<a1.size();i++)
	{
		for(j=0;j<b1.size();j++)
			x1.push_back(a1[i]+b1[j]);
	}
	for(i=0;i<c1.size();i++)
	{
		for(j=0;j<d1.size();j++)
			y1.push_back(c1[i]+d1[j]);
	}
	sort(x1.begin(),x1.end());
	sort(y1.begin(),y1.end());

	for(i=0;i<x1.size();i++)
	{
		int long c2=x1[i]*-1;
		vector <int long> :: iterator l1,u1;
		u1=upper_bound(y1.begin(),y1.end(),c2);
		l1=lower_bound(y1.begin(),y1.end(),c2);
		final=final+u1-l1;
	}
	printf("%ld\n",final);

}