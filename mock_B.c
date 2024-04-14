#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define v 5
#define e 6

/*cost in decreasing order
search if city name is present
dsign a path that keeps all these cities connected*/

void swap(int graph[e][3],int a,int b)
{
    int temp=graph[a][b];
    graph[a][b]=graph[a+1][b];
    graph[a+1][b]=temp;
}

void sort(int graph[e][3])
{
    for(int i=0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(graph[j][2]<graph[j+1][2])
            {
                swap(graph,j,0);
                swap(graph,j,1);
                swap(graph,j,2);
            }
        }
    }
}

void sort2(int graph[e][3])
{
    for(int i=0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(graph[j][2]>graph[j+1][2])
            {
                swap(graph,j,0);
                swap(graph,j,1);
                swap(graph,j,2);
            }
        }
    }
}

void search(char city[20],char city_list[5][20])
{
    int c=0;
    for(int i=0;i<v;i++)
    {
        if(!strcasecmp(city,city_list[i]))
            {
                c++;
                printf("city present\n");
            }
    }
    if(!c)
        printf("city not present\n");
}

int find(int ar[],int a,int b)
{
    if(ar[a]==ar[b])
        return 1;
    else
    {
        return 0;
    }

}

void union_(int ar[],int n,int a,int b)
{
    int temp=ar[a];
    for(int i=0;i<n;i++)
    {
        if(ar[i]==temp)
            ar[i]=ar[b];
    }
}

void path(int graph[e][3])
{
    sort2(graph);
    int ar[v],edge=0,x,cost=0;
    for(int i=0;i<v;i++)
    {
        ar[i]=i;
    }
    for(int i=0;i<e && edge!=v-1;i++)
    {
        x=find(ar,graph[i][0],graph[i][1]);
        if(x==0)
        {
            printf("%c-->%c\n",graph[i][0]+65,graph[i][1]+65);
            union_(ar,v,graph[i][0],graph[i][1]);
            edge++;
            cost=cost+graph[i][2];
            printf("\n");
        }
    }

}

int main()
{
    int cost[v][v]={{0,0,12,60,0},
                    {10,0,0,0,0},
                    {0,20,0,32,0},
                    {0,0,0,0,0},
                    {7,0,0,0,0}};

    int graph[e][3]={{0,2,12},
                    {0,3,60},
                    {1,0,10},
                    {2,1,20},
                    {2,3,32},
                    {4,0,7}};

    char city_list[5][20]={{"Omnagar"},
                           {"srinagar"},
                           {"Sainagar"},
                           {"Kalyannagar"},
                           {"Anandnagar"}};

    while(1)
    {
        printf("menu\n1.cost in decreasing order\n2.search if city name is present\n3.design a path that keeps all these cities connected\n4.exit\n");
        int choice;
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            sort(graph);
            printf("sorted cost is:\n");
            printf("from\tto\tcost\n");
            for(int i=0;i<e;i++)
                printf("%c\t%c\t%d\n",graph[i][0]+65,graph[i][1]+65,graph[i][2]);
            break;

        case 2:
            printf("enter the city name to be searched\n");
            char city[20];
            scanf("%s",city);
            search(city,city_list);
            break;

        case 3:
            path(graph);
            break;

        case 4:
            exit(0);

        default:
            printf("wrong choice\n");
            break;
        }
    }
}
