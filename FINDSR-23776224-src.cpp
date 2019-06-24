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
int z[mx];
int main()
{
	IOS;
	string pattern;
	string temp="*";
	cin>>pattern;
	while(pattern!=temp)
	{
		int l=0,r=0,n=pattern.length();
		for(int i=1;i<n;i++)
		{
			if(i>r)
			{
				int j=0,k=i;
				while(k<n && pattern[k]==pattern[j])
					{k++;j++;}
				k--;z[i]=j;
				if(k>r)	{r=k;l=i;}
			}
			else
			{
				int k=i;
				int k1=k-l;
				int b=r-k+1;
				if(z[k1]<b)
					z[k]=z[k1];
				else if(z[k1]>b)
					z[k]=b;
				else
				{
					k=r+1;				
					while(k<n && pattern[k]==pattern[b])
						{k++;b++;}
					k--;
					if(k>r)
						{r=k;l=i;}
					z[i]=b+r-k;
				}
			}
		}
		bool done=false;
		for(int i=1;i<=n/2;i++)
		{
			if(n%i==0)
			{
				int flag=0;
				for(int k=i;k<n;k+=i)
					if(z[k]<i)
						{flag=1;break;}
				if(flag==0)
				{
					cout<<n/i<<endl;
					done=true;
					break;
				}
			}
		}		
		if(done==false)
			cout<<1<<endl;
		cin>>pattern;
	}
}
