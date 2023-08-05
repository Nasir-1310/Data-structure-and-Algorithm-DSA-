#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a,b,c,t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        if(a+b==c || a+c==b || b+c==a)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
