#include<bits/stdc++.h>
using namespace std;
# define mx 100005
struct node
{
	int x,y,z;
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
	struct node i3,i4;
	i3.x=tree[i1].x;
	i3.y=tree[i1].y;
	i3.z=tree[i1].z;
	i4.x=tree[i2].x;
	i4.y=tree[i2].y;
	i4.z=tree[i2].z;

	if(delta[i1]%3==2)
	{
		swap(i3.x,i3.y);
		swap(i3.y,i3.z);
	}
	if(delta[i2]%3==2)
	{
		swap(i4.x,i4.y);
		swap(i4.y,i4.z);
	}
	if(delta[i1]%3==1)
	{
		swap(i3.x,i3.z);
		swap(i3.y,i3.z);
	}
	if(delta[i2]%3==1)
	{
		swap(i4.x,i4.z);
		swap(i4.y,i4.z);
	}
	tree[i0].x=i3.x+i4.x;
	tree[i0].y=i3.y+i4.y;
	tree[i0].z=i3.z+i4.z;
	
	
}
void build(int i)
{
	int l=lo[i];
	int r=hi[i];
	if(l==r)
	{
		if(a[l]%3==0)
			tree[i].x=1;
		if(a[l]%3==1)
			tree[i].y=1;
		if(a[l]%3==2)
			tree[i].z=1;
		return;
	}
	build(2*i);
	build(2*i+1);
	merge(i,2*i,2*i+1);
}
void prop(int i)
{
	delta[2*i]+=delta[i];
	delta[2*i+1]+=delta[i];
	delta[i]=0;
}
void increment(int i,int a,int b,int val) // INCREMENT ALL VALUES IN RANGE A TO B
{
	if(b<lo[i] || hi[i]<a)
		return ;
	if(a<=lo[i] && hi[i]<=b)
		{
		delta[i]+=val;
		return ;
		}
	prop(i);
	increment(2*i,a,b,val);
	increment(2*i+1,a,b,val);
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

		if(delta[i]%3==0)
			{
			return tree[i].x;
			}
		else if(delta[i]%3==1)
			{
			return tree[i].z;
			}
		else
			return tree[i].y;
	}
	prop(i);
	int rr=query(2*i,l,r);
	int ll=query(2*i+1,l,r);
	merge(i,2*i,2*i+1);
	return rr+ll;
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		a[i]=0;
	}
	init(1,1,n);
	build(1);
	while(q--)
	{
		int f,g,h;
		scanf("%d %d %d",&f,&g,&h);
		g++;h++;
		if(f==0)
			increment(1,g,h,1);
		else
			printf("%d\n",query(1,g,h));
	}
}
