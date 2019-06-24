#include<limits.h>
#include<stdio.h>
int max(int a,int b)
{
	if(a>=b)
		return a;
		return b;
}
struct segtree
{
	int maxsum,sum,prefix,suffix;
};
	struct segtree tree[4*50010];
	int a[50010];
	
void buildtree(int start,int end,int treenode)
{
	if(start==end)
		{
			tree[treenode].maxsum=a[start];
			tree[treenode].suffix=a[start];
			tree[treenode].prefix=a[start];
			tree[treenode].sum=a[start];
			
			return;	
		}
	else
	{
		int mid=(start+end)/2;
		buildtree(start,mid,2*treenode);
		buildtree(mid+1,end,2*treenode+1);
		
		tree[treenode].sum=tree[2*treenode].sum+tree[2*treenode+1].sum;
		tree[treenode].suffix=max(tree[2*treenode+1].suffix,tree[2*treenode].suffix+tree[2*treenode+1].sum);
		tree[treenode].prefix=max(tree[2*treenode].prefix,tree[2*treenode+1].prefix+tree[2*treenode].sum);
		tree[treenode].maxsum=max(max(tree[2*treenode].maxsum,tree[2*treenode+1].maxsum),tree[2*treenode].suffix+tree[2*treenode+1].prefix);		
		
	
		
	}		
}
struct segtree query(int x,int y,int start,int end,int treenode)

{
	struct segtree result;
	result.sum=result.prefix=INT_MIN;
	result.suffix=result.maxsum=INT_MIN;
	
	if(start>end || start>y || end<x)	
		return result;
	if(start>=x && end<=y)
		{
			return tree[treenode];
		}
	int mid=(start+end)/2;
	if(x>mid)
	{
		return query(x,y,mid+1,end,2*treenode+1);
	}
	if(y<=mid)
	{
		return query(x,y,start,mid,2*treenode);
	}
	struct segtree q1=query(x,y,start,mid,2*treenode);
	struct segtree q2=query(x,y,mid+1,end,2*treenode+1);
	
	result.sum=q1.sum+q2.sum;
	result.suffix=max(q2.suffix,q2.sum+q1.suffix);
	result.prefix=max(q1.prefix,q1.sum+q2.prefix);
	result.maxsum=max(max(q1.maxsum,q2.maxsum),q1.suffix+q2.prefix);
	
	return result;
}

int main()
{
	int n,m,b,i;
   scanf("%d",&n);   
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);   

	buildtree(0,n-1,1);
	int x;
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&b);
		printf("%d\n",query(x-1,b-1,0,n-1,1).maxsum);
	}
	
	
}
