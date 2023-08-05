#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int sum=0;
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
       long long int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            if(a==0)
            {
                for(int i=0;i<n;i++)
                {
                    if(arr[i]%2==0)
                    {
                        arr[i]+=b;
                        sum+=arr[i];
                    }
                    else sum+=arr[i];
                }
                cout<<sum<<endl;
                sum=0;
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(arr[i]%2!=0)
                    {
                        arr[i]+=b;
                        sum+=arr[i];
                    }
                    else
                        sum+=arr[i];
                }
                cout<<sum<<endl;
                sum=0;
            }
        }
    }
    return 0;
}
