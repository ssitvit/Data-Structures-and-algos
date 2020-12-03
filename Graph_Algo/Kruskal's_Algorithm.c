#include<stdio.h>
int uniquedata(int p,int q,int parent[])
{
    if(p!=q)
    {
        parent[q]=p;
        return 1;
    }
    return 0;
}
int searchparent(int i,int parent[])
{
    while(parent[i]!=-1)
        {
            i=parent[i];

        }
    return i;
}
void main()
{
    int size,i,j,mini,minj,k=1,mincost=0,total=0,p,q;
    printf("\nEnter the number of elements in graph:");
    scanf("%d",&size);
    char name[size][10];
    int graph[size][size],parent[size];

    //input zone;
    printf("\nEnter the elements?\n");
    for(i=0;i<size;i++)
        scanf("%s",&name[i]);

    printf("\nEnter the graph?\n");
    for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
                {
                    scanf("%d",&graph[i][j]);

                    if(graph[i][j]==0)
                        graph[i][j]=999;

                }
                parent[i]=-1;
        }

    while(k<size)
    {
        mini=0;
        minj=0;
        for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                    {
                        if(graph[i][j]<graph[mini][minj])
                        {
                            mini=i;
                            minj=j;
                            mincost=graph[i][j];
                        }
                    }
            }

            p=searchparent(mini,parent);
            q=searchparent(minj,parent);
            if(uniquedata(p,q,parent))
            {
                printf("\n%d-edge (%s,%s) =%d\n",k++,name[mini],name[minj],mincost);
                total+=mincost;
            }
             graph[mini][minj]=999;
             graph[minj][mini]=999;

    }
    printf("\nTotal minimum cost=%d.\n",total);
}

