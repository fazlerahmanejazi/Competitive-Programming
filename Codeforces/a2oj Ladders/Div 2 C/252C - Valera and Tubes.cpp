#include <bits/stdc++.h>
using namespace std ;

#define x first
#define y second

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, m, k, a, b ;
    cin>> n >> m >> k ;
    vector<pair<int, int> > points ;
    a=(n*m)/k ;
    b=a+(n*m)%k ;
    for(int i=1 ; i<=n ; i++)
      {
        if(i%2)
            for(int j=1 ; j<=m ; j++)
                points.push_back(make_pair(i, j)) ;
        else
            for(int j=m ; j>=1 ; j--)
                points.push_back(make_pair(i, j)) ;
      }
    int c=0 ;
    for(int i=1 ; i<=k ; i++)
      {
        if(i<k)
          {
            cout<< a << " " ;
            for(int j=0 ; j<a ; j++)
              {
              	cout<< points[c].x << " " << points[c].y << " " ;
              	c++ ;
              }
          }
        else
          {
            cout<< b << " " ;
            for(int j=0 ; j<b ; j++)
              {
                cout<< points[c].x << " " << points[c].y << " " ;
                c++ ;
              }
          }
        cout<< endl ;
      }
  }
