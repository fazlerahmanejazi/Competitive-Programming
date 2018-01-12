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
    lli q ;
    cin>> q ;
    while(q--)
      {
        lli n, ans=0, l=1, r=1, tot=1 ;
        vi cnt(27, 0 ) ;
        string s ;
        cin>> s ;
        n=s.length() ;
        s='#'+s ;
        cnt[s[1]-'a']++ ;
        while(l<=n && r<=n)
          {
            while(r<=n && tot<26)
              {
                cnt[s[++r]-'a']++ ;
                if(cnt[s[r]-'a']==1) tot++ ;
              }
            if(tot==26 && r<=n)
              {
                while(l<=n && r<=n && tot==26)
                  {
                    if(cnt[s[l]-'a']==1)
                      {
                        cnt[s[++r]-'a']++ ;
                        break ;
                      }
                    cnt[s[l++]-'a']-- ;
                  }
                ans+=l ;
              }
          }
        cout<< ans << endl ;
      }
  }
