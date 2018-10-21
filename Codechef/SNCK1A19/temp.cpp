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
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, idx1=0, one=0, other=0, p ;
        bool pos ;
        vi ones ;
        cin>> n ;
        vi a(n+1) ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> a[i] ;
            if(a[i]==1) idx1=i, one++ ;
            else if(a[i]!=-1) other++ ;
          }
        if(idx1)
          {
            if(one==1)
              {
                pos=true ;
                for(int i=2 ; i<=n ; i++)
                  if(a[i]==-1)
                    {
                      if(a[i-1]==p) a[i]=1 ;
                      else a[i]=a[i-1]+1 ;
                    }
                for(int i=n-1 ; i>=1 ; i--)
                  if(a[i]==-1)
                    {
                      if(a[i+1]==1) a[i]=p ;
                      else a[i]=a[i+1]-1 ;
                    }
                for(int i=2 ; i<=n ; i++)
                  if(a[i]==1 && a[i-1]!=p) pos=false ;
                  else if(a[i]!=1 && a[i-1]!=a[i]-1) pos=false ;
                if(pos) cout<< "inf" << endl ;
                else cout<< "impossible" << endl ;
              }
            else
              {
                for(int i=1 ; i<=n ; i++) if(a[i]==1) ones.pb(i) ;
                set<int> temp ;
                for(int i=1 ; i<ones.size() ; i++) temp.insert(ones[i]-ones[i-1]) ;
                p=*temp.begin() ;
                auto it=temp.begin() ; it++ ;
                while(it!=temp.end()) if((*it)%p==0) temp.erase(it) ;
                if(temp.size()>1) cout<< "impossible" << endl ;
                else
                  {
                    pos=true ;
                    for(int i=2 ; i<=n ; i++)
                      if(a[i]==-1)
                        {
                          if(a[i-1]==p) a[i]=1 ;
                          else a[i]=a[i-1]+1 ;
                        }
                    for(int i=n-1 ; i>=1 ; i--)
                      if(a[i]==-1)
                        {
                          if(a[i+1]==1) a[i]=p ;
                          else a[i]=a[i+1]-1 ;
                        }
                    for(int i=2 ; i<=n ; i++)
                      if(a[i]==1 && a[i-1]!=p) pos=false ;
                      else if(a[i]!=1 && a[i-1]!=a[i]-1) pos=false ;
                    if(!pos) cout<< "impossible" << endl ;
                    else cout<< p << endl ;
                  }
              }
          }
        else
          {
            if(!other) cout<< "inf" << endl ;
            else
              {
                for(int i=n-1 ; i>=1 ; i--) if(a[i]==-1 & a[i+1]>=2) a[i]=1 ;
                for(int i=1 ; i<=n ; i++) if(a[i]==1) ones.pb(i) ;
                if(ones.empty())
                  {
                    pos=true ;
                    for(int i=2 ; i<=n ; i++) if(a[i]==-1 && a[i-1]!=-1) a[i]=a[i-1]+1 ;
                    for(int i=n-1 ; i>=1 ; i--) if(a[i]==-1 && a[i+1]!=-1) a[i]=a[i+1]-1 ;
                    for(int i=2 ; i<=n ; i++) if(a[i]==-1 && a[i-1]!=-1) a[i]=a[i-1]+1 ;
                    for(int i=n-1 ; i>=1 ; i--)
                      if(a[i]==-1)
                        {
                          if(a[i+1]==1) a[i]=p ;
                          else a[i]=a[i+1]-1 ;
                        }
                    for(int i=2 ; i<=n ; i++)
                      if(a[i]==1 && a[i-1]!=p) pos=false ;
                      else if(a[i]!=1 && a[i-1]!=a[i]-1) pos=false ;
                    if(pos) cout<< "impossible" << endl ;
                    else cout<< p << endl ;
                  }
                else
                  {
                    set<int> temp ;
                    temp.insert(ones[0]+n-ones.back()) ;
                    for(int i=1 ; i<ones.size() ; i++) temp.insert(ones[i]-ones[i-1]) ;
                    p=*temp.begin() ;
                    auto it=temp.begin() ; it++ ;
                    while(it!=temp.end()) if((*it)%p==0) temp.erase(it) ;
                    if(temp.size()>1) cout<< "impossible" << endl ;
                    else
                      {
                        pos=true ;
                        for(int i=2 ; i<=n ; i++)
                          if(a[i]==-1)
                            {
                              if(a[i-1]==p) a[i]=1 ;
                              else a[i]=a[i-1]+1 ;
                            }
                        for(int i=n-1 ; i>=1 ; i--)
                          if(a[i]==-1)
                            {
                              if(a[i+1]==1) a[i]=p ;
                              else a[i]=a[i+1]-1 ;
                            }
                        for(int i=2 ; i<=n ; i++)
                          if(a[i]==1 && a[i-1]!=p) pos=false ;
                          else if(a[i]!=1 && a[i-1]!=a[i]-1) pos=false ;
                        if(!pos) cout<< "impossible" << endl ;
                        else cout<< p << endl ;
                      }
                  }
              }
          }
      }
  }
