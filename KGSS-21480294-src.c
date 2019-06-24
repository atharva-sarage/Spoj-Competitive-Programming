/*
	Auhtor-Atharva Sarage
		IIT HYDERABAD
		*/

#include<stdio.h>
#include<limits.h>
struct segtree
{
	int x,y;
};
int max(int a,int b)
{
	if(a>=b)
		return a;
		return b;
}
struct segtree tree[3*100005];
int a[100005];

void build(int start,int end,int treenode)
{
	if(start==end)
		{
			tree[treenode].x=a[start];
			tree[treenode].y=INT_MIN;
			return ;
		}
	int mid=(start+end)/2;

	build(start,mid,2*treenode);
	build(mid+1,end,2*treenode+1);

	/*tree[treenode]=max(max(tree[2*treenode].x+tree[2*treenode].y , tree[2*treenode+1].x+tree[2*treenode+1].y  ),
							max(tree[2*treenode].x,tree[2*treenode].y)+max(tree[2*treenode+1].x,tree[2*treenode+1].y));*/
	tree[treenode].x=max(tree[2*treenode].x,tree[2*treenode+1].x);
	if(tree[treenode].x==tree[2*treenode].x)
		tree[treenode].y=max(tree[2*treenode].y,tree[2*treenode+1].x);
	else
		tree[treenode].y=max(tree[2*treenode+1].y,tree[2*treenode].x);


}
void update(int start,int end,int treenode,int i,int val)
{
	if(i>end || i<start || start>end)
		return;
	else if(start==i && end==i)
	{
		tree[treenode].x=val;
		return;
	}
	int mid=(start+end)/2;
	if(i<=mid)
	update(start,mid,2*treenode,i,val);
	if(i>mid)
	update(mid+1,end,2*treenode+1,i,val);

	tree[treenode].x=max(tree[2*treenode].x,tree[2*treenode+1].x);
	if(tree[treenode].x==tree[2*treenode].x)
		tree[treenode].y=max(tree[2*treenode].y,tree[2*treenode+1].x);
	else
		tree[treenode].y=max(tree[2*treenode+1].y,tree[2*treenode].x);


}
struct segtree query(int start,int end,int treenode,int x,int y)
{
	struct segtree result;
	if(start>end || start>y || end<x)	
		return result ;
	if(start>=x && end<=y)
		{
			return tree[treenode];
		}
	int mid=(start+end)/2;
	if(x>mid)
	{
		return query(mid+1,end,2*treenode+1,x,y);
	}
	if(y<=mid)
	{
		return query(start,mid,2*treenode,x,y);
	}
	struct segtree q1=query(start,mid,2*treenode,x,y);
	struct segtree q2=query(mid+1,end,2*treenode+1,x,y);

	result.x=max(q1.x,q2.x);
	if(result.x==q1.x)
		result.y=max(q1.y,q2.x);
	else
		result.y=max(q2.y,q1.x);

	return result;

}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	build(0,n-1,1);
	int o;
	scanf("%d",&o);
	for(j=1;j<=o;j++)
	{
		//printf("%d**\n",j);
		char type;
		int c,d;
		scanf(" %c %d %d",&type,&c,&d);
		if(type=='Q')
			printf("%d\n",query(0,n-1,1,c-1,d-1).x+query(0,n-1,1,c-1,d-1).y);
		else if(type=='U')
			update(0,n-1,1,c-1,d);
	}
}
