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
    int k, ans=0, curr=0 ;
    string s ;
    cin>> k >> s ;
    sort(all(s)) ;
    for(int i=0 ; i<s.length() ; i++)
      curr+=(s[i]-'0') ;
    k-=curr ;
    for(int i=0 ; i<s.length(), k>0 ; i++)
      {
        k-=('9'-s[i]) ;
        ans++ ;
      }
    cout<< ans ;
  }
