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
# define mx 200005
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
int main()
{
	string str;
	while(getline(cin,str))
	{
		string str2=str;
		reverse(str2.begin(),str2.end());
		str2+='$';
		str2+=str;
		zalgo(str2,str2.length());
		int j;
		for(int i=0;i<str2.length();i++)
		{
			if(str2[i]=='$')
				{j=i+1;break;}
		}
		int ans=0;
		for(int i=j;i<str2.length();i++)
		{
			if(z[i]>=str2.length()-i){ans=z[i];break;}
		}
		string str3=str.substr(0,str.length()-ans);
		reverse(str3.begin(),str3.end());
		str+=str3;
		cout<<str<<endl;

	}
	
}
