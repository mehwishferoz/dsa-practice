#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// #define loop(a, b, c) for (int a = b; a < c; a++)
int gp[100][100];
int INF = 1e9 + 10;
struct nodeGraph
{
    int sr;
    int nbr;
    int dist;
};
int bfss(char place1[25], char place2[25])
{
    int n = strlen(place1);
    int m = strlen(place2);
    int i = 0;
    if (m != n)
        return 0; 
    for (i = 0; i < n; i++)
    {
        if (place1[i] == place2[i])
        {
            return 1;
        }
    }
    return 0;
}
void isPresent(char place[25])
{
    int i = 0;
    char places[6][10] = {"Hospital", "School", "Post", "Bank", "Grocery"};
    for (i = 0; i < 6; i++)
    {
        int t = bfss(place, places[i]);
        if (t == 1)
        {
            printf("Its present at node %c\n", (char)(i + 65));
            return;
        }
    }
    printf("Its nOt Present\n");
    return;
}

void sorting(int n, int e)
{
    struct nodeGraph gptemp[e];
    int k = -1;
    int i = 1, j = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (gp[i][j] != 0)
            {
                k++;
                gptemp[k].sr = i;
                gptemp[k].nbr = j;
                gptemp[k].dist = gp[i][j];
            }
        }
        printf("\n");
    }
    printf("Before Sorting\n");
    for (i = 0; i < e; i++)
    {
        printf("%d --> ", gptemp[i].sr);
        printf("%d  distance is ", gptemp[i].nbr);
        printf("%d\n", gptemp[i].dist);
    }

    for (i = 0; i < e; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (gptemp[j].dist > gptemp[j + 1].dist)
            {
                struct nodeGraph temp = gptemp[j];
                gptemp[j] = gptemp[j + 1];
                gptemp[j + 1] = temp;
            }
        }
    }
    printf("After Sorting\n");
    for (i = 0; i < e; i++)
    {
        printf("%d --> ", gptemp[i].sr);
        printf("%d  distance is ", gptemp[i].nbr);
        printf("%d\n", gptemp[i].dist);
    }
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
void floydwarshall(int n)
{
    int i = 1, j = 1, k = 1;
    int dist[n + 1][n + 1];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (gp[i][j] == 0 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = gp[i][j];
        }
    }

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    // for (i = 1; i <= n; i++)
    // {
    //     for (j = 1; j <= n; j++)
    //     {
    //         if (dist[i][j] <= 1000)
    //             printf("   %d   ", dist[i][j]);
    //         else
    //             printf("  INF  ");
    //     }
    //     printf("\n");
    // }
    printf("Enter the Source Place(with in Number of vertices)\n");
    int sr;
    scanf("%d", &sr);
    for (i = 1; i <= n; i++)
    {
        if (dist[sr][i] != INF)
        {
            printf("%c --> %c Minimum distance is %d\n", (char)(sr + 64), (char)(i + 64), dist[sr][i]);
        }
        else
        {
            printf("%c --> %c Minimum distance is INF\n", (char)(sr + 64), (char)(i + 64));
        }
    }
}
int main()
{

    printf("Enter the number of vertices\n");
    int n;
    scanf("%d", &n);
    printf("Enter the number of edges\n");
    int e;
    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        int v1, v2, d;
        scanf("%d %d %d", &v1, &v2, &d);
        gp[v1][v2] = d;
    }
    for (;;)
    {
        printf("Enter 1 to sort based on distance\n");
        printf("Enter 2 to search place\n");
        printf("Enter 3 to find min cost/dist path\n");
        printf("Enter 4 to Exit\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            sorting(n, e);
        }
        else if (ch == 2)
        {

            printf("Enter Name of place that you want to search\n");
            char place[25];
            scanf("%s", place);
            isPresent(place);
        }
        else if (ch == 3)
        {
            floydwarshall(n);
        }
        else if (ch == 4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Choice Enter Right Choice\n");
        }
    }
    return 0;
}
