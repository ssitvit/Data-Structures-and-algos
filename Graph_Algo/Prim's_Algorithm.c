#include<stdio.h>
#define INFINITY 999

int main()
{
    int a,b,u,v,n,i,j,ne=1;
    int visited[10]= {0},cost[10][10];
    int min,mincost=0;

    printf("Prims Algo. Implementation\n");
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the Cost Matrix: \n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INFINITY;
        }
    }
    visited[1]=1;
    printf("\n");

    while(ne<n)
    {
        for(i=1,min=INFINITY; i<=n; i++)
            for(j=1; j<=n; j++)
                if(cost[i][j]<min)
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }

        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n Edge %d:(%d %d) cost : %d",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=INFINITY;
    }
    printf("\n Minimun Cost of Spanning Tree = %d",mincost);
    return 0;
}
