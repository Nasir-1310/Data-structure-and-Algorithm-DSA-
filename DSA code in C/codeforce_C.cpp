#include<bits/stdc++.h>
using namespace std;
int main()
{

    int b,c,t;
    cin>>t;
    cout<<endl;
    int count=0;
    char a[9][9];
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<8;j++)
        {//printf("Nasir\n");
            cin>>a[j];
        }


        for(int j=0;j<8;j++)
        {
           // printf("uddin\n");
                if(a[j][0]=='R' || a[j][1]=='R')
                {
                    if(strcmp(a[j],"RRRRRRRR")==0)
                    {
                        printf("R\n");
                        count++;
                        break;
                    }
                }


        }
        if(count==0)
            printf("B\n");
            count=0;

    }

    return 0;
}
