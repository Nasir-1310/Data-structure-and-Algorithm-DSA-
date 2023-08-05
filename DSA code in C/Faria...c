#include<stdio.h>
const int max_size=7;
int mtx[6][6];
char color[6];
int parent[6];

void DFS(int node)
{
    int i;
     printf("%d->\n",node);
      for(i=0;i<max_size-1;i++)//max size 7 kintu array size 6 disis tai -1 korsi
    {
        printf("color[%d] = %c\n",i,color[i]);
        printf("parent[%d] = %d\n",i,parent[i]);
    }

    printf("-----------------------------------------\n");

    color[node]= 'g';
     for(i=0;i<max_size-1;i++)// max size nia same kahini korsis ^^
    {
        int adj=i;
        if(mtx[node][adj] == 1 && color[adj]== 'w')// age color[node]== 'w'   disili kintu   color[adj]== 'w'  hove bujsis ? (^^)
      {
          parent[adj] = node;
          DFS( adj ) ;
      }
    }
    color[ node ] = 'b';
}


int main()
{
    int i,j,v,x,y,s,ed;
    printf("Enter the num of vertices:\n");
    scanf("%d",&v);
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            mtx[i][j]=0;
        }
    }

    printf("Enter the num of edges:\n");
    scanf("%d",&ed);
    while(ed--)
    {
        printf("enter vertices share edge:\n");
        scanf("%d %d",&x,&y);
        mtx[x][y]=1;

    }
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            printf("%d ",mtx[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<max_size-1;i++)//max size 7 kintu array size 6 disis tai -1 korsi
    {
        color[i]='w';
        parent[i]=-1;
    }
    printf("Enter source:\n");
    scanf("%d",&s);
    DFS(s);
    parent[s]=-1;
    printf("Final:\n");
      for(i=0;i<max_size-1;i++) //max size 7 kintu array size 6 disis tai -1 korsi
    {
        printf("color[%d] = %c\n",i,color[i]);
        printf("parent[%d] = %d\n",i,parent[i]);
    }
      return 0;
}
