#include<stdio.h>
#include "pr.h"

void BFS(int g[][10], int i, int j, int rep)
{
    int x = g[i][j];
    int visited[10] = {0};
    visited[x] = 1;
    enqueue(x);
    while(!isEmpty())
    {
        int m = dequeue();
        g[i][j] = rep;
        for (int i = 0; i < 10; i++)
        {
            for(int j=0;j<10;j++)
            {
            if(g[i][j] == x && !visited[i])
            {
                enqueue(g[i][j]);
                g[i][j] = rep;
            }
            }
        }
    }
}

/*
BFS (starting-pixel, replacement-color):
1. Create an empty queue.
2. Enqueue starting pixel and mark it as processed.
3. Loop till queue is empty
    I. Dequeue the front node and process it.
    II. Replace the color of the current pixel (popped node) with that of
    the replacement.
    III. Process all eight adjacent pixels of the current pixel and enqueue
    each valid pixel that has the same color as that of the current
    pixel.
*/

void display(int g[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int g[10][10] = 
{
{ 1, 1, 1, 2, 2, 2, 2, 2, 2, 2},
{ 1, 1, 1, 1, 1, 1, 2, 3, 3, 3},
{ 2, 2, 2, 2, 2, 2, 2, 3, 3, 3},
{ 4, 4, 4, 4, 4, 2, 2, 2, 2, 3},
{ 4, 5, 5, 5, 5, 5, 2, 3, 3, 3},
{ 4, 4, 4, 5, 5, 2, 2, 3, 3, 3},
{ 4, 6, 4, 5, 5, 5, 5, 5, 5, 3},
{ 4, 6, 6, 6, 6, 5, 5, 3, 3, 3},
{ 4, 6, 6, 3, 6, 6, 6, 6, 3, 3},
{ 4, 6, 6, 3, 3, 3, 3, 3, 3, 3}
};
    
    //y - 1, g - 2, x - 3, w - 4, r - 5, b - 6, c - 7
    BFS(g,3,9,7);
    display(g);

    return 0;
}
