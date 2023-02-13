#include <stdio.h>
#include "queue.h"

void BFS(int G[][6], int start, int n)
{
    int i = start;
    int visited[6] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][6], int start, int n)
{
    static int visited[6] = {0};
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (int j = 0; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{                // 1  2  3  4  5  6 
    int G[6][6] = {{0, 1, 1, 0, 0, 0}, //1
                   {1, 0, 1, 0, 0, 0}, //2
                   {1, 1, 0, 1, 1, 0}, //3
                   {0, 0, 1, 0, 0, 0}, //4
                   {0, 0, 1, 0, 0, 1}, //5
                   {0, 0, 0, 0, 1, 0}};//6
    BFS(G,1,6);
    printf("\n");
    DFS(G,1,6);
    return 0;
}