#include<stdio.h>
 
#define MAX 30
 
typedef struct edge
{
    int u,v,w;
}edge;
 
typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;
 
edgelist elist;
 
int G[MAX][MAX],n;
edgelist spanlist;
 
void kruskal();
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();
 
int main()
{
    int i,j,total_cost;
    
    printf("\nEnter number of vertices:");
    
    scanf("%d",&n);
    
    printf("\nEnter the adjacency matrix:\n");
    
    // for(i=0;i<n;i++)
    //     for(j=0;j<n;j++)
    //         scanf("%d",&G[i][j]);

    G[0][0] = 0;
    G[0][1] = 3;
    G[0][2] = 1;
    G[0][3] = 6;
    G[0][4] = 0;
    G[0][5] = 0;

    G[1][0] = 3;
    G[1][1] = 0;
    G[1][2] = 5;
    G[1][3] = 0;
    G[1][4] = 3;
    G[1][5] = 0;

    G[2][0] = 1;
    G[2][1] = 5;
    G[2][2] = 0;
    G[2][3] = 5;
    G[2][4] = 6;
    G[2][5] = 4;

    G[3][0] = 6;
    G[3][1] = 0;
    G[3][2] = 5;
    G[3][3] = 0;
    G[3][4] = 0;
    G[3][5] = 2;

    G[4][0] = 0;
    G[4][1] = 3;
    G[4][2] = 6;
    G[4][3] = 0;
    G[4][4] = 0;
    G[4][5] = 6;

    G[5][0] = 0;
    G[5][1] = 0;
    G[5][2] = 4;
    G[5][3] = 2;
    G[5][4] = 6;
    G[5][5] = 0;
            
    kruskal();
    print();

    return 0;
}
 
void kruskal()
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;
 
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }
 
    sort();
    
    for(i=0;i<n;i++) {
        belongs[i]=i;
        //printf("%d", i);
    }
        
    spanlist.n=0;
    
    for(i=0;i<elist.n;i++)
    {
        cno1=find(belongs,elist.data[i].u);
        cno2=find(belongs,elist.data[i].v);
        
        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n=spanlist.n+1;
            union1(belongs,cno1,cno2);
        }
    }
}
 
int find(int belongs[],int vertexno)
{
    return(belongs[vertexno]);
}
 
void union1(int belongs[],int c1,int c2)
{
    int i;
    
    for(i=0;i<n;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;

    printf("[%d, %d, %d, %d, %d, %d]\n", belongs[0], belongs[1], belongs[2], belongs[3], belongs[4], belongs[5]);
}
 
void sort()
{
    int i,j;
    edge temp;
    
    for(i=1;i<elist.n;i++)
        for(j=0;j<elist.n-1;j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
}
 
void print()
{
    int i,cost=0;
    
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }
 
    printf("\n\nCost of the spanning tree=%d\n",cost);
}