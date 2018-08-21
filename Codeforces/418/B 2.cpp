#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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

vi solve(vi a, vi b, int n)
  {
    vi ans(n+1) ;
    vb takenA(n+1, false) ;
    vb takenB(n+1, false) ;
    map<int, int> cntA, cntB ;
    for(int i=0 ; i<n ; i++)
      {
        cntA[a[i]]++ ;
        cntB[b[i]]++ ;
        takenA[a[i]]=true ;
        takenB[b[i]]=true ;
      }
    for(int i=0 ; i<n ; i++)
      if(a[i]==b[i])
        ans[i]=a[i] ;
    for(int i=0 ; i<n ; i++)
      if(ans[i]==0)
        {
          if(cntA[a[i]]>=2)
            {
              for(int j=1 ; j<=n ; j++)
                if(!takenA[j])
                  {
                    ans[i]=j ;
                    break ;
                  }
              break ;
            }
        }
    for(int i=0 ; i<n ; i++)
      if(ans[i]==0)
        {
          if(cntB[b[i]]>=2)
            {
              for(int j=1 ; j<=n ; j++)
                if(!takenB[j])
                  {
                    ans[i]=j ;
                    break ;
                  }
              break ;
            }
        }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, c=0 ;
    cin>> n ;
    vi a(n), b(n), ans(n, 0) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<n ; i++)
      cin>> b[i] ;
    for(int i=0 ; i<n ; i++)
      if(a[i]!=b[i])
        c++ ;
    if(c==1)
      {
        vb taken(n+1, false) ;
        for(int i=0 ; i<n ; i++)
          {
            taken[a[i]]=true ;
            taken[b[i]]=true ;
          }
        for(int i=0 ; i<n ; i++)
          if(a[i]!=b[i])
            {
              for(int j=1 ; j<=n ; j++)
                if(!taken[j])
                  a[i]=j ;
              for(int i=0 ; i<n ; i++)
                cout<< a[i] << " " ;
              return 0 ;
            }
      }
    else
      {
        ans=solve(a, b, n) ;
        for(int i=0 ; i<n ; i++)
          if(ans[i]==0)
            {
              ans=solve(b, a, n) ;
              break ;
            }
        for(int i=0 ; i<n ; i++)
          cout<< ans[i] << " " ;

      }
  }
