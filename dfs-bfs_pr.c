#include<stdio.h>
#include "pr.h"

void bfs(int g[5][5], int start, int n)
{
    int i = start;
    int visited[5]={0};
    visited[i] = 1;
    printf("%d ", i);
    enqueue(i);
    while(!isEmpty())
    {
        i = dequeue();
        for (int j = 0; j < n; j++)
        {
            if(!visited[j] && g[i][j])
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void dfs(int g[5][5], int start, int n)
{
    static int visited[5]={0};
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && g[start][i])
        dfs(g,i,n);
    }
}

int main()
{
    int g[5][5] =  {{0,1,1,1,0},
                    {1,0,0,1,1},
                    {1,0,0,0,0},
                    {1,1,0,0,0},
                    {0,1,0,0,0}};
    int u = 0;
    dfs(g,u,5);
}