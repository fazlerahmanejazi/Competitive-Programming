#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

lli n, k, M, ans=0, tot=0, x, curr, remain ;
vlli t ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k >> M ;
    t.resize(k+1) ;
    for(int i=1 ; i<=k ; i++)
      {
        cin>> t[i] ;
        tot+=t[i] ;
      }
    sort(t.begin()+1, t.end()) ;
    for(int i=0 ; i<=n ; i++)
      if(tot*i<=M)
        {
          curr=i*(k+1) ;
          remain=M-tot*i ;
          for(int j=1 ; j<=k ; j++)
            for(int l=1 ; l+i<=n ; l++)
              if(t[j]<=remain)
                remain-=t[j], curr++ ;
          ans=max(curr, ans) ;
        }
    cout<< ans ;
  }
