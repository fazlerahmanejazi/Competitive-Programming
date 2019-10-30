#include<iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    int a[n],b[n],y=0;
    bool q[n]={0};

    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)  cin>>b[i];

    int j=0;
    for(int i=0;i<n;i++)
    {
        while(q[a[j]]==1) j++;

        if(a[j]==b[i]) { q[a[j]]=1; j++; continue; }
        y++;
        q[b[i]]=1;
    }
    cout<<y;

    return 0;
}
