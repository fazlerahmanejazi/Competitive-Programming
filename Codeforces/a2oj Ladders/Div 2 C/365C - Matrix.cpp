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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli a, ways=0, curr=0, l ;
    string s ;
    vlli dig ;
    map<lli, lli> cnt ;
    cin>> a >> s ;
    l=s.length() ;
    for(int i=0 ; i<l ; i++)
      dig.pb(s[i]-'0') ;
    for(int i=0 ; i<l ; i++)
      {
        curr=0 ;
        for(int j=i ; j<l ; j++)
          {
            curr+=dig[j] ;
            cnt[curr]++ ;
          }
      }
    if(!a) ways=2*cnt[0]*(((l*(l+1))/2)-cnt[0]) + cnt[0]*cnt[0] ;
    for(int i=1 ; i<=sqrt(a) ; i++)
      if(a%i==0)
        if(a/i==i) ways+=(cnt[i]*cnt[i]) ;
        else ways+=2*(cnt[i]*cnt[a/i]) ;
    cout<< ways ;
  }
