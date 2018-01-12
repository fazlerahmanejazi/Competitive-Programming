#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int b, q, l, m , temp, count=0 ;
    cin>> b >> q >> l >> m ;
    map<int, bool> bad ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> temp ;
        bad[temp]=true ;
      }
    if(q==0 && b!=0)
      {
        if(bad[0] && bad[b])
          {
            cout<< 0 ;
            return 0 ;
          }
        else if(bad[b] && !bad[0])
          {
            cout<< "inf" ;
            return 0 ;
          }
        else if(bad[0] && !bad[b])
          {
            cout<< 1 ;
            return 0 ;
          }
        else
          {
            cout<< "inf" ;
            return 0 ;
          }
      }
    else if(b==0 && q!=0)
      {
        if(bad[0])
          {
            cout<< 0 ;
            return 0 ;
          }
        else
          {
            cout<< "inf" ;
            return 0 ;
          }
      }
    else if(b>0 && q>0)
      {
        if(q==1)
          {
            if(bad[b])
              {
                cout<< 0 ;
                return 0 ;
              }
            else
              {
                cout<< "inf" ;
                return 0 ;
              }
          }
      }
    else if(b>0 && q<0)
      {
        if(q==-1)
          {
            if(bad[b] && bad[-b])
              {
                cout<< 0 ;
                return 0 ;
              }
            else
              {
                cout<< "inf" ;
                return 0 ;
              }
          }
      }
    else if(b<0 && q<0)
      {
        if(q==-1)
          {
            if(bad[b] && bad[-b])
              {
                cout<< 0 ;
                return 0 ;
              }
            else
              {
                cout<< "inf" ;
                return 0 ;
              }
          }
      }
    else if(b<0 && q>0)
      {
        if(q==1)
          {
            if(bad[b])
              {
                cout<< 0 ;
                return 0 ;
              }
            else
              {
                cout<< "inf" ;
                return 0 ;
              }
          }
      }
    long long int k=b ;
    for( ; abs(k)<=l ; k=k*q)
        if(!bad[k]) count++ ;
    cout<< count ;
  }
