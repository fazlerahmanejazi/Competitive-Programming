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
    int k, l, r, m, x, len, last, curr, lines, ans=inf ;
    cin>> k ;
    string s ;
    getline(cin, s) ;
    getline(cin, s) ;
    l=1 ; r=1e9 ;
    len=s.length() ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        bool check=true ;
        x=0 ;
        curr=1 ;
        lines=1 ;
        last=-1 ;
        while(x<len)
          {
            if(curr==m)
              {
                if(last==-1)
                  {
                    check=false ;
                    break ;
                  }
                curr=x-last ;
                lines++ ;
                last=-1 ;
              }
            if(s[x]==' ' || s[x]=='-') last=x ;
            curr++ ;
            x++ ;
          }
        if(check && lines<=k)
          {
            ans=min(ans, m) ;
            r=m-1 ;
          }
        else l=m+1 ;
      }
    cout<< ans-1 ;
  }
