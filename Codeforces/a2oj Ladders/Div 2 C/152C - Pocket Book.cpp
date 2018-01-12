#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, m, curr ;
    long long int ans=1 ;
    cin>> n >> m ;
    string s[n] ;
    for(int i=0 ; i<n ; i++)
      cin>> s[i] ;
    for(int i=0 ; i<m ; i++)
      {
        curr=0 ;
        map<char, bool> taken ;
        for(int j=0 ; j<n ; j++)
          if(!taken[s[j][i]])
            {
              curr++ ;
              taken[s[j][i]]=true ;
            }
        ans=(ans*curr)%1000000007 ;
      }
    cout<< ans ;
  }
