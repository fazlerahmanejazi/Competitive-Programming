#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, cnt, idx, x, y ;
    cin>> n >> k ;
    vi p(n), q(300) ;
    vb done(300, false) ;
    for(int i=0 ; i<256 ; i++) q[i]=i ;
    for(int i=0 ; i<n ; i++) cin>> p[i] ;
    for(int i=0 ; i<n ; i++)
      if(!done[p[i]])
        {
          cnt=k-1 ;
          idx=p[i] ;
          bool check=false ;
          while(idx>0 && cnt>0)
            {
              x=q[idx] ;
              y=idx ;
              idx-- ;
              cnt-- ;
              if(x!=y)
                {
                  check=true ;
                  break ;
                }
            }
          if(check)
            {
              if(p[i]-q[idx]<=k-1) q[p[i]]=q[idx] ;
              else q[p[i]]=idx+2 ;
            }
          else
            {
              if(q[idx]==idx) q[p[i]]=idx ;
              else q[p[i]]=idx+1 ;
            }
          for(int j=q[p[i]] ; j<=p[i] ; j++) q[j]=q[p[i]], done[j]=true ;
        }
    for(int i=0 ; i<n ; i++) cout<< q[p[i]] << " " ;
  }
