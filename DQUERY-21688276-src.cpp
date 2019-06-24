#include<bits/stdc++.h>
using namespace std;
int block;
struct query
{
	int l,r,index,ans;
};
bool compare(query x,query y)
{
	if(x.l/block!=y.l/block)
		return x.l / block< y.l / block;
	return x.r<y.r;
}
bool compare1(query x,query y)
{
	return x.index<y.index;
}
void queryresult(int a[],int n,query q[],int m)
{
	block=(int)sqrt(n);
	sort(q,q+m,compare);
	int curl=0,curr=0,dis=0;
	int freq[1000005]={0};
	for(int i=0;i<m;i++)
	{
		int L=q[i].l,R=q[i].r;
		while(curl<L)
		{
			freq[a[curl]]--;
			if(freq[a[curl]]==0)
				dis--;

			curl++;
		}
		while(curl>L)
		{
			freq[a[curl-1]]++;
			if(freq[a[curl-1]]==1)
				dis++;
			curl--;
		}
		while(curr<=R)
		{
			freq[a[curr]]++;

			if(freq[a[curr]]==1)
				dis++;
			curr++;
		}
		while(curr>R+1)
		{
			freq[a[curr-1]]--;
			if(freq[a[curr-1]]==0)
				dis--;
			curr--;
		}
		q[i].ans=dis;
	}

}

void printres( query q[],int m)
{
	sort(q,q+m,compare1);
	for(int i=0;i<m;i++)
		printf("%d\n",q[i].ans );
}
int main()
{
	int n;
	int a[30005];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int m;
	query q[200005];
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		q[i].l=x-1;
		q[i].r=y-1;
		q[i].index=i;
	}
	queryresult(a,n,q,m);
	printres(q,m);

}