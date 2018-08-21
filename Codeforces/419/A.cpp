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

bool check(int curr)
  {
    int m=curr%60 ;
    int h=curr/60 ;
    h=h%24 ;
    if(h<10 && h==m/10 && m%10==0) return false ;
    else if(h/10==m%10 && h%10==m/10) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int h, m, curr, ans=0 ;
    char c ;
    cin>> h >> c >> m ;
    curr=h*60+m ;
    while(check(curr+ans))
      ans++ ;
    cout<< ans ;
  }
