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
    int k, end=-1, x, ans=0, remain ;
    cin>> k ;
    vb taken(1000010, false) ;
    for(int i=0 ; i<k ; i++)
      {
        cin>> x ;
        taken[x]=true ;
        end=max(end, x) ;
      }
    remain=25-k ;
    for(int i=1 ; i<=1000000, remain>0 ; i++)
      if(!taken[i])
        {
          taken[i]=true ;
          remain-- ;
          end=max(end, i) ;
        }
    for(int i=end ; i>=1 ; i--)
      if(!taken[i])
        ans++ ;
    if(end<=25) ans=0 ;
    cout<< ans ;
  }
