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
    lli n, k, x, cnt, hash1, hash2, p=31, q=71, a, b;
    set<pair<lli, lli>> ans ;
    string s, t, temp ;
    cin>> s >> t >> k ;
    n=s.length() ;
    for(int i=0 ; i<n ; i++)
      {
        cnt=hash1=hash2=0 ;
        a=b=1 ;
        for(int j=i ; j<n ; j++)
          {
            hash1=(hash1+(s[j]-'a'+1)*a)%mod ;
            hash2=(hash2+(s[j]-'a'+1)*b)%mod ;
            a=(p*a)%mod ;
            b=(q*b)%mod ;
            if(t[s[j]-'a']=='0') cnt++ ;
            if(cnt<=k) ans.insert(mp(hash1, hash2)) ;
            else break ;
          }
      }
    cout<< ans.size() ;
  }
