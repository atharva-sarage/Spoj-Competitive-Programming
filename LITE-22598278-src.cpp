#include<bits/stdc++.h>
using namespace std;
# define mx 100005
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
struct node
{
	int on,off;
};
int lo[4*mx+1],hi[4*mx+1],a[mx],delta[4*mx+1];
struct node tree[4*mx+1];
void init(int i,int a,int b)
{
	delta[i]=0;
	lo[i]=a;
	hi[i]=b;
	if(a==b)
		return;
	int m=(a+b)/2;
	init(2*i,a,m);
	init(2*i+1,m+1,b);
}
void merge(int i0,int i1,int i2)
{
	tree[i0].on=(delta[i1])?tree[i1].off:tree[i1].on;
	tree[i0].on+=(delta[i2])?tree[i2].off:tree[i2].on;
	tree[i0].off=(delta[i1])?tree[i1].on:tree[i1].off;
	tree[i0].off+=(delta[i2])?tree[i2].on:tree[i2].off;
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		tree[i].on=0;
		tree[i].off=1;
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
void prop(int i)
{
	delta[2*i]=delta[i]^delta[2*i];
	delta[2*i+1]=delta[i]^delta[2*i+1];
	delta[i]=0;
}
void increment(int i,int a,int b) // INCREMENT ALL VALUES IN RANGE A TO B
{
	if(b<lo[i] || hi[i]<a)
		return ;
	if(a<=lo[i] && hi[i]<=b)
		{
		delta[i]=delta[i]^1;
		return ;
		}
	prop(i);
	increment(2*i,a,b);
	increment(2*i+1,a,b);
	merge(i,2*i,2*i+1);
}
int query(int i,int l,int r)
{
	if(r<lo[i] || hi[i]<l)
		{
		return 0;
		}
	if(l<=lo[i] && hi[i]<=r)
	{
		return (delta[i])?(tree[i].off):(tree[i].on);
	}

	prop(i);
	int rr=query(2*i,l,r);
	int ll=query(2*i+1,l,r);
	merge(i,2*i,2*i+1);
	return rr+ll;
}

int main()
{
	IOS;
	int n,q;
	cin>>n>>q;
	init(1,1,n);
	build(1);
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x==0)
		{
			increment(1,y,z);
		}
		else
		{
			cout<<query(1,y,z)<<endl;
		}
	}
	
}
