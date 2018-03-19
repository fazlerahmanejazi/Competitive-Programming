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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, x, l, r, c, l1, l2, c1, c2, d1, d2, r1, r2 ;
    lli ans=2*INF, curr ;
    vector<tuple<int, int, int, int>> vouc ;
    tuple<int, int, int, int> a, b ;
    cin>> n >> x ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> l >> r >> c ;
        vouc.pb(mt(r-l+1, l, r, c)) ;
      }
    sort(all(vouc)) ;
    int i=0, j=n-1 ;
    while(i<n)
      {
        while(j>0)
          {
            tie(d1, l1, r1, c1)=vouc[i] ;
            tie(d2, l2, r2, c2)=vouc[j] ;
            if(d1+d2>x) j-- ;
            else if(d1+d2==x)
              {
                if((l2>l1 && r2>r1 && l2>r1) || (l1>l2 && r1>r2 & l1>r2))
                  {
                    if(c1+c2<ans)
                      ans=c1+c2 ;
                  }
                else continue ;
              }
            else if(d1+d2<x)
              {
                if(j+1<n) j++ ;
                break ;
              }
          }
        i++ ;
      }
    if(ans!=2*INF) cout<< ans ;
    else cout<< -1 ;
  }
