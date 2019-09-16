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

int n, a[1000010], c[1000010], check[1000010], p, q, res, l, r ;
vi idx[4], temp ;
string s ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.size() ;
    temp.pb(1) ; temp.pb(2) ; temp.pb(3) ;
    for(int i=1 ; i<=n ; i++)
      {
        a[i]=s[i-1]-'a'+1 ;
        idx[a[i]].pb(i) ;
      }
    while(next_permutation(all(temp)))
      {
        p=temp[0] ; q=temp[1] ;
        res=0 ;
        for(int i=0 ; i<1000010 ; i++) check[i]=0 ;
        for(int i=1 ; i<=n ; i++)
          if(a[i]==p) res++, check[i]=1 ;
          else c[i]=res ;
        l=0 ; r=idx[q].size()-1 ;
        while(l<=r)
          {
            if(c[idx[q][l]]+c[idx[q][r]]==res)
              {
                c[idx[q][l+1]]=c[idx[q][r]]=1 ;
                l++ ;
                r-- ;
              }
            else if(c[idx[q][l]]+c[idx[q][r]]>res) r-- ;
            else l++ ;
          }
        res=0 ;
        for(int i=1 ; i<=n ; i++) if(check[i]) res++ ;
        if(res>=n/2)
          {
            for(int i=1 ; i<=n ; i++) if(check[i]) cout<< s[i-1] ;
            return 0 ;
          }
      }
    cout<< "IMPOSSIBLE" ;
  }
