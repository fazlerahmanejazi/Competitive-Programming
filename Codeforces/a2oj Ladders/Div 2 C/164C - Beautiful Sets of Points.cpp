#include <bits/stdc++.h>
using namespace std ;

#define x first
#define y second

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int n, m, t ;
    cin>> n >> m ;
    t=min(m, n) ;
    vector<pair<int, int> > point ;
    for(int i=0 ; i<=t ; i++)
      point.push_back(make_pair(i,t - i)) ;
    cout<< t+1 << endl ;
    for(int i=0 ; i<=t ; i++)
      cout<< point[i].x << " " << point[i].y << endl ;
  }
