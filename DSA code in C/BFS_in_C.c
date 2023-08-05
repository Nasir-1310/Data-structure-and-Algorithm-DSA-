#include<stdio.h>
#define max_size 50
#define Infinity 999999;
int G[max_size][max_size],Parent[max_size],Distance[max_size],front=0,rear=0,queue[max_size];
char Colour[max_size];

void enqueue(int value)
{
 queue[rear]=value;
 rear++;
}
int dequeue()
{
    int x=queue[front];
    front++;
    return x;
}
int queue_size()
{
    if(front>=rear)
        return 1;
    else
        return 0;
}
void BFS(int source,int v)
{
    Colour[source]='g';
    Distance[source]=0;
    Parent[source]=-1;

    enqueue(source);

    while(!queue_size())
    {
        int u=dequeue();
        for(int i=1;i<=v;i++)
        {
            if(G[u][i]==1 && Colour[i]=='w')
            {
                enqueue(i);
                Colour[i]='g';
                Parent[i]=u;
                Distance[i]=Distance[u]+1;
            }
        }
        Colour[u]='B';
    }
}

void print_final_BFS_list(int v)
{
    printf("Vertex   :");
    for(int i=1;i<=v;i++)
    {
        printf("%d\t",G[0][i]);

    }
    printf("\nColour   :");
    for(int i=1;i<=v;i++)
    {
        printf("%c\t",Colour[i]);
    }
    printf("\nParent  :");
    for(int i=1;i<=v;i++)
    {
      printf("%d\t",Parent[i]);
    }
    printf("\nDistance :");
    for(int i=1;i<=v;i++)
    {
        printf("%d\t",Distance[i]);
    }
    printf("\n");
}
void print_matrix(int v)
{
    for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++)
    {
        printf("%d ",G[i][j]);
    }
    printf("\n");
}
}
int main()
{
    printf("Enter number of Vertex\n");
    int v;
    scanf("%d",&v);
    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<=v;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=1;i<=v;i++)
    {
        Colour[i]='w';
        Distance[i]=Infinity;
        Parent[i]=-1;
    }
    printf("Enter name of the Vertex\n");
    int a,b,name;
    for(int i=1;i<=v;i++)
    {
        scanf("%d",&name);
        G[0][i]=name;
        G[i][0]=name;
    }

    printf("Enter Number of Edges\n");
    int ed,source;
    scanf("%d",&ed);
    printf("Enter Edges\n");
    while(ed--)
    {
        scanf("%d%d",&a,&b);
        G[a][b]=1;
    }
    print_matrix(v);
    printf("Enter Sources\n");
    scanf("%d",&source);
    BFS(source,v);
    print_final_BFS_list(v);
    return 0;
}
