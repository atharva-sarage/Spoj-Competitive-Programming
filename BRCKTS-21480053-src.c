/*
	Author-Atharva Sarage
		IIT HYDERABAd
		*/

#include<stdio.h>
#include<string.h>
struct segtree
{
	int flag;
	int open;
	int close;
};
int min(int a,int b)
{
	if(a>=b)
		return b;
		return a;
}
char reverese(char a)
{
	if(a==')')
		return '(';
	else
		return ')';
}

struct  segtree tree[100005];
char a[100005];

void buildtree(int start,int end,int treenode)
{
	if(start==end) // base case
	{
		tree[treenode].flag=0;
		if(a[start]=='(')
			{
				tree[treenode].open=1;
				tree[treenode].close=0;
			}
		else
		{
			tree[treenode].open=0;
			tree[treenode].close=1;
		}

		return;
	}
	else
	{
		int mid=(start+end)/2;
		buildtree(start,mid,2*treenode);
		buildtree(mid+1,end,2*treenode+1);

		int change=min(tree[2*treenode].open,tree[treenode*2+1].close);

		tree[treenode].open=tree[2*treenode].open+tree[2*treenode+1].open-change;
		tree[treenode].close=tree[2*treenode].close+tree[2*treenode+1].close-change;
		
		if(tree[treenode].open==0 && tree[treenode].close==0)
				tree[treenode].flag=1;
		else
			tree[treenode].flag=0;


	}

}
void update(int i,int start,int end,int treenode)
{
	
	if(i>end || i<start || start>end)
		return;

	if(start==i && end==i)
			{
				if(tree[treenode].open==1)
						{
							tree[treenode].open=0;
							tree[treenode].close=1;
							a[i]=reverese(a[i]);
						}
				else
				{
					tree[treenode].open=1;
					tree[treenode].close=0;
					a[i]=reverese(a[i]);
				}
				return;
			}
	else
	{
		int mid=(start+end)/2;
		update(i,start,mid,2*treenode);
		update(i,mid+1,end,2*treenode+1);

		
		// check condition test case ())((()))(()
	int change=min(tree[2*treenode].open,tree[treenode*2+1].close);

		tree[treenode].open=tree[2*treenode].open+tree[2*treenode+1].open-change;
		tree[treenode].close=tree[2*treenode].close+tree[2*treenode+1].close-change;
		
		if(tree[treenode].open==0 && tree[treenode].close==0)
				tree[treenode].flag=1;
		else
			tree[treenode].flag=0;
	}
}

int main()
{
	int k;
	for(k=1;k<=10;k++)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",a);
				
		buildtree(0,n-1,1);

		int m;
		scanf("%d",&m);

		printf("Test %d:\n",k);
		while(m--)
		{
			int x;
			scanf("%d",&x);
			if(x==0)
				{
					if(tree[1].flag==1)
						printf("YES\n");
					else
						printf("NO\n");
				}
			else
			{
				update(x-1,0,n-1,1);
				int i;
				/*for(i=1;i<=2*n;i++)
					printf("%d--%d\n",i,tree[i].flag);*/
			}
		}
		int j;
		for(j=1;j<=2*n+4;j++)
			{
				tree[j].flag=0;
				tree[j].close=0;
				tree[j].open=0;
			}
			

	}
	

}