#include <bits/stdc++.h>
using namespace std ;

int n ;
long long int k, x, c ;
vector<long long int> seq, a, b ;

long long int combine(long long int prod)
  {
    long long int s=0, e=b.size()-1, m ;
    while(s<e)
      {
        m=(s+e)/2 ;
        if(b[m]<=prod) s=m+1 ;
        else e=m ;
      }
    return (b[e]>prod)?e:e+1 ;
  }

void power(int size, vector<long long int> &p, int s)
  {
    int i ;
    for(long long int mask=1 ; mask<pow(2,size) ; mask++)
      {
        x=1 ;
        for(i=0 ; i<size ; i++)
          if(mask&(1<<i))
            {
              if(seq[s+i]<=k/x) x=x*seq[s+i] ;
              else break ;
            }
        if(i==size) p.push_back(x) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> n >> k ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        seq.push_back(x) ;
      }
    power(n/2, a, 0) ;
    sort(a.begin(), a.end()) ;
    power(n-n/2, b, n/2) ;
    sort(b.begin(), b.end()) ;
    c=a.size()+b.size() ;
    for(long long int i=0 ; i<a.size() ; i++)
      c+=combine(k/a[i]) ;
    cout<< c ;
  }
