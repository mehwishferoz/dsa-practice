#include<stdio.h>
#include<stdlib.h>
#define V 4
#define INF 99999

void floyd(int g[][V]);
void printDist(int g[][V]);

void floyd(int g[][V])
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int  j = 0; j < V; j++)
            {
                if(g[i][j]> g[i][k] + g[k][j])
                g[i][j] = g[i][k] + g[k][j];
            }            
        }        
    }
}

void printDist(int g[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(g[i][j] == INF)
            printf("%s ", "INF");
            else
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int g[V][V] = 
    {
        {0,3,INF,5},
        {2,0,INF,4},
        {INF,1,0,INF},
        {INF,INF,2,0}
    };
    floyd(g);
    printDist(g);
    return 0;
}