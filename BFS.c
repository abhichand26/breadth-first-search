#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 20
#define BIG 1000

/*
** Program to do a breadth first search
** Made by - Abhishek Chand
*/


int dis[N], num=0, comp[N], f=0,r=0;

typedef struct NODE
{
	int v;
	struct NODE* next;
}node;


void enqueue(int *Q,int x)
{
	Q[r++]=x;
}

int dequeue(int *Q)
{
	int x=Q[f];
	f++;
	return x;
}

int isempty(int *Q)
{
	if(f==r)
		return 1;
	else
		return 0;
}

void BFS(node *L[], int n,int s)
{
	int pre[N],i,u,v;
	
	for(i=1;i<n+1;i++)
	{
		pre[i]=-1;
	}
	
	dis[s]=0; //assuming source vertex is 1
	int Q[N];
	printf("\nBFS:");
	enqueue(Q,s);
	while(!isempty(Q))
	{
		u=dequeue(Q);
		printf("%d  ",u);
		comp[u]=num;
		node *p=L[u];
		while(p!=NULL)
		{
			v=p->v;
			if(dis[v]==-1)
			{
				dis[v]=dis[u]+1;
				pre[v]=u;
				enqueue(Q,v);
			}
			p=p->next;
		}	
	}
}

int main()
{
	int u,v,i,j,k,w,n,e;
	
	printf("\nEnter the no. of vertex:");
	scanf("%d",&n);
	printf("\nEnter the no. of edges:");
	scanf("%d",&e);
	node *List[N]={NULL};
	
	for(k=0;k<e;k++)
	{
		node *t = (node *)malloc(sizeof(node));
		printf("\nEnter an edge(in form i j):");
		scanf("%d %d",&i,&j);
		t->v=j;
		t->next = List[i];
		List[i] = t;
		
		/*
		**for undirected graph
		*/
		t = (node *)malloc(sizeof(node));
		t->v=i;
		t->next=List[j];
		List[j]=t;
	}
	
	printf("\nInput Graph:\n");
	for(i=1;i<n+1;i++)
	{
		comp[i]=0;
		dis[i]=-1;
		printf("\n\n%d",i);
		node *p=List[i];
		while(p!=NULL)
		{
			printf("->%d",p->v);
			p=p->next;
		}
	}
	
	for(i=1;i<n+1;i++)
	{
		if(dis[i]==-1)
		{
			num++;
			BFS(List,n,i);
		}	
		
	}
	printf("\nComponets: ");
	for(i=1;i<n+1;i++)
		printf("%d ",comp[i]);
	
	return 0;
}
