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

int n, m, a, b, l, r, mid, len, curr ;
vi ans(205) ;
string x ;
vector<string> s ;

bool check(int idx, int k)
  {
    unordered_set<string> temp ;
    for(int i=0 ; i+k-1<s[idx].length() ; i++) temp.insert(s[idx].substr(i, k)) ;
    if(temp.size()==1<<k) return true ;
    return false ;
  }

int solve(int idx)
  {
    l=1 ; r=20 ; curr=0 ;
    while(l<=r)
      {
        mid=(l+r)/2 ;
        if(check(idx, mid)) l=mid+1, curr=mid ;
        else r=mid-1 ;
      }
    return curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        s.pb(x) ;
        ans[i]=solve(i) ;
      }
    cin>> m ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> a >> b ;
        s.pb(s[a-1]+s[b-1]) ;
        len=s[n+i].length() ;
        if(len>1000) s[n+i]=s[n+i].substr(0, 500)+s[n+i].substr(len-500, 500) ;
        ans[n+i]=max({solve(n+i), ans[a-1], ans[b-1]}) ;
        cout<< ans[n+i] << endl ;
      }
  }
