#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a,b,c,t;
    int count=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        int arr[a];
        for(int j=0;j<a;j++)
        {
            cin>>arr[j];

        }
        sort(arr,arr+a);
        for(int j=0;j<a-1;j++)
        {
            if(arr[j]==arr[j+1])
            {
                cout<<"NO"<<endl;
                count++;
                break;
            }


        }
        if(count==0)
            {
                cout<<"YES"<<endl;
            }
            count=0;

    }
    return 0;
}

