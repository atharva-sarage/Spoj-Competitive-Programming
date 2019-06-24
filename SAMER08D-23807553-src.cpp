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
# define mx 1005
string str,str2;
int x,l1,l2;
int dp[mx][mx][2];
int solve(int s1,int s2,int flag)
{
	//cout<<s1<<" "<<s2<<" "<<flag<<"??"<<endl;
	if(s1==l1 || s2==l2)
		return 0;
	int &w=dp[s1][s2][flag];
	if(w!=-1)
		return w;
	int count=0;
	if(flag==1)
	{
		if(str[s1]==str2[s2])
			{w=max({1+solve(s1+1,s2+1,1),solve(s1+1,s2,0),solve(s1,s2+1,0)});}
		else
			w=max(solve(s1+1,s2,0),solve(s1,s2+1,0));
	}
	else // first match first k characters
	{
		while(s1+count<l1 && s2+count<l2 && count<x && str[s1+count]==str2[s2+count])
			count++;
		if(count==x)
			w=max({x+solve(s1+x,s2+x,1),solve(s1+1,s2,0),solve(s1,s2+1,0)});
		if(count<x)
			w=max(solve(s1+1,s2,0),solve(s1,s2+1,0));
	}	
	//cout<<s1<<" "<<s2<<" "<<flag<<" "<<w<<"##"<<endl;
	return w;
	
}
int main()
{
	IOS;
	cin>>x;
	while(x!=0)
	{
		memset(dp,-1,sizeof(dp));
		cin>>str>>str2;
		l1=str.length();l2=str2.length();
		cout<<solve(0,0,0)<<endl;
		cin>>x;

	}
}
