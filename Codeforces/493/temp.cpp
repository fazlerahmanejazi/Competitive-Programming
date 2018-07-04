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

lli n, ans, d[]={0, 1, 5, 10, 50} ;
map<lli, bool> check ;

void brute(lli idx, lli curr)
  {
    if(idx==n)
      {
        if(!check[curr])
          {
            check[curr]=true ;
            ans++ ;
          }
        return ;
      }
    for(int i=1 ; i<=4 ; i++) brute(idx+1, curr+d[i]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    brute(0, 0) ;
    cout<< ans ;
  }
