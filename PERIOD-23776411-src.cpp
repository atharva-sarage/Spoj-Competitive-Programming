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
# define mx 1000005
int z[mx];
void zalgo(string str,int n)
{
	int l=0,r=0;
	z[0]=n;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			int j=0,k=i;
			while(k<n && str[k]==str[j])
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
				while(k<n && str[k]==str[b])
					{k++;b++;}
				k--;
				if(k>r)
					{r=k;l=i;}
				z[i]=b+r-k;
			}
		}
	}
}
bool mark[mx];
int main()
{
	IOS;
	int t1;
	cin>>t1;
	for(int t=1;t<=t1;t++)	
	{
		cout<<"Test case #"<<t<<endl;
		int n;cin>>n;
		string str;
		cin>>str;
		zalgo(str,n);
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<n;j+=i)
			{
				if(z[j]>=i)
					{
						if(mark[j+i]==true)continue;
						cout<<j+i<<" "<<(j+i)/i<<endl;mark[j+i]=true;}
				else
					break;
			}
		}
		memset(mark,false,sizeof(mark));
	}

}
