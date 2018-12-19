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
    int n, l ;
    string s, r ;
    cin>> n >> s ;
    for(int i=0 ; i<n ; i++)
      {
        vi cnt(26, 0) ;
        r="" ;
        for(int j=i ; j<n ; j++)
          {
            l=(j-i+1)/2 ;
            r+=s[j] ;
            cnt[s[j]-'a']++ ;
            bool check=true ;
            for(int k=0 ; k<26 ; k++) if(cnt[k]>l) check=false ;
            if(check) return cout<< "YES" << endl << r, 0 ;
          }
      }
    cout<< "NO" ;
  }
