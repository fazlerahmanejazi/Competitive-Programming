#include <bits/stdc++.h>
using namespace std ;

long long int n, k, d, curr ;
bool possible ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    cin>> n >> k >> d ;
    curr=1 ;
    possible=false ;
    for(int i=1 ; i<=d ; i++)
      {
        curr=curr*k ;
        if(curr>=n)
          {
            possible=true ;
            break ;
          }
      }
    if(possible)
      {
        long long int a[1010][1010] ;
        for (int i=1;i<=d;i++) a[i][1]=1;
        int i=2;
        while (i<=n)
          {
            int j=d; int t=1;
            while (j>=1)
              {
                a[j][i]=a[j][i-1]+t;
                if (a[j][i]>k)
                  {
                    t=1;
                    a[j][i]=1;
                  }
                else t=0;
                j--;
              }
            i++;
          }
        for (int i=1;i<=d;i++)
          {
            for (int j=1;j<=n;j++)  cout<<a[i][j]<<" ";
            cout <<endl;
          }
      }
    else cout<< -1 ;
  }
