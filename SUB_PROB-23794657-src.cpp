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
# define mx 500005
const int k=100;
struct vertex {
	int next[k];
	bool leaf=false;
	int p=-1;
	char pch;
	int link=-1;
	int go[k];
	vertex(int p=-1,char ch='$') : p(p),pch(ch) 
		{
			fill(begin(next),end(next),-1);
			fill(begin(go),end(go),-1);
		}
};
vector <vertex> t(1);
vector <int> r[mx];
bool ans[mx];
void add_string(string const&str,int i)
{
	int v=0;
	for(char ch:str)
	{
		int c=ch-'A';
		if(t[v].next[c]==-1)
		{
			//printf("*\n");
			t[v].next[c]=t.size();
			t.emplace_back(v,ch);
		}
		v=t[v].next[c];
	}
	t[v].leaf=true;
	r[v].pb(i);
}
int go(int v,char ch);
int get_link(int v)
{
	if(t[v].link==-1)
	{
		if(v==0 || t[v].p==0)
			t[v].link=0;
		else
			t[v].link=go(get_link(t[v].p),t[v].pch);
	}
	return t[v].link;
}
int go(int v,char ch)
{
	int c=ch-'A';
	if(t[v].go[c]==-1)
	{
		if(t[v].next[c]!=-1)
			t[v].go[c]=t[v].next[c];
		else
			t[v].go[c]=v==0?0 : go(get_link(v),ch);
	}
	return t[v].go[c];
}
//A suffix link for a vertex p is a edge that points to the
// longest proper suffix of the string corresponding to the vertex p.
// The only special case is the root of the t, the suffix link will point to itself
int main()
{
	IOS;
	string text;
	cin>>text;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		add_string(str,i);		
	}
	int v=0;
	for(char ch:text)
	{
		v=go(v,ch);
		if(t[v].leaf==true)
		{
			for(auto k:r[v])
				ans[k]=true;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i])
			cout<<"Y"<<"\n";
		else
			cout<<"N"<<"\n";
	}

	
}
