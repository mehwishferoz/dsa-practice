#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define INFINITE 9999999

void prims(int g[5][5], int n)
{
    int selected[n];
    int no_edges=0, x, y;
    memset(selected,false,sizeof(selected));
    selected[0]=true;
    while(no_edges<n-1)
    {
        int min = INFINITE;
        x = y = 0;
        for (int i = 0; i < n; i++)
        {
            if(selected[i])
            for (int j = 0; j < n; j++)
            {
                if (!selected[j] && g[i][j])
                {
                    if(min>g[i][j])
                    {
                        min = g[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d -> %d : %d\n", x, y, g[x][y]);
        no_edges++;
        selected[y]=true;
    }
}

int main()
{
    int g[5][5] = 
    {{0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};
    
    printf("Edge : Weight\n");
    prims(g,5);

    return 0;
}