#include <bits/stdc++.h>
using namespace std ;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
  {
    if(a.first==b.first) return abs(a.second)<abs(b.second) ;
    else return abs(a.first)<=abs(b.first) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, x, y, c=0 ;
    cin>> n ;
    vector<pair<int, int>> points ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y ;
        if(x) c+=2 ;
        if(y) c+=2 ;
        points.push_back(make_pair(x, y)) ;
      }
    sort(points.begin(), points.end(), cmp) ;
    c+=2*n ;
    cout<< c << '\n'  ;
    for(int i=0 ; i<n ; i++)
      {
        x=points[i].first ; y=points[i].second ;
        if(x)
          {
            cout<< 1 << " " << abs(x) << " " ;
            if(x>0) cout<< 'R' << '\n'  ;
            else cout<< 'L' << '\n'  ;
          }
        if(y)
          {
            cout<< 1 << " " << abs(y) << " " ;
            if(y>0) cout<< 'U' << '\n'  ;
            else cout<< 'D' << '\n'  ;
          }
        cout<< 2 << endl ;
        if(x)
          {
            cout<< 1 << " " << abs(x) << " " ;
            if(x>0) cout<< 'L' << '\n'  ;
            else cout<< 'R' << '\n'  ;
          }
        if(y)
          {
            cout<< 1 << " " << abs(y) << " " ;
            if(y>0) cout<< 'D' << '\n'  ;
            else cout<< 'U' << '\n'  ;
          }
        cout<< 3 << '\n'  ;
      }
  }
