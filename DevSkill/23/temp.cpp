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

lli n, ans=0 ;
map<lli, vector<vlli>> cnt ;

void solve(lli curr, lli idx, vlli a)
  {
    if(idx>n)
      {
        if(!a.empty()) cnt[curr].pb(a) ;
        return ;
      }
    solve(curr, idx+1, a) ;
    a.pb(idx) ;
    curr*=idx ;
    solve(curr, idx+1, a) ;
  }

bool check(vlli a, vlli b)
  {
    for(int i=0 ; i<a.size() ; i++)
      for(int j=0 ; j<b.size() ; j++)
        if(a[i]==b[j])
          return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    for(int i=1 ; i<=T ; i++)
      {
        cnt.clear() ;
        ans=0 ;
        vlli a ;
        n=i ;
        solve(1, 1, a) ;
        for(auto i:cnt)
          {
            vector<vlli> temp=i.se ;
            for(int j=0 ; j<temp.size() ; j++)
              for(int k=j+1 ; k<temp.size() ; k++)
                if(check(temp[j], temp[k]))
                  ans++ ;
          }
        cout<< ans << "," ;
      }

  }
