#include <bits/stdc++.h>
using namespace std ;

#define ff first
#define ss second

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, n, d, x, u ;
    double speed, t, curr ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> d >> n ;
        speed=DBL_MAX ;
        vector<pair<int, int> > data ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x >> u ;
            data.push_back(make_pair(x, u)) ;
          }
        data.push_back(make_pair(d, 0)) ;
        sort(data.begin(), data.end()) ;
        for(int i=0 ; i<n ; i++)
          {
            if(data[i].ss <= data[i+1].ss )
              {
                t=(double)(d-data[i].ff)/data[i].ss ;
                curr=(double)data[i].ff/t ;
                speed=min(speed, curr+data[i].ss) ;
                break ;
              }
            t=(double)(data[i+1].ff-data[i].ff)/(data[i].ss-data[i+1].ss) ;
            curr=(double)data[i].ff/t ;
            curr=curr+data[i].ss ;
            speed=min(speed, curr) ;
          }
        cout<< "Case #" << tc << ": " << fixed << setprecision(6) << speed << endl ;
      }
  }
