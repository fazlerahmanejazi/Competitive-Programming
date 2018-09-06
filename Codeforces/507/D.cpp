#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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

lli n, k, l, r, m, L, R, x, mx=1000000000000000000 ;
string q ;

static random_device rd ;
static mt19937 rng(rd()) ;

lli dice()
  {
      uniform_int_distribution<lli> uid(L, R) ;
      return uid(rng) ;
  }

void query(lli l, lli r)
  {
    cout<< l << " " << r << endl ;
    cin>> q ;
  }

lli getR()
  {
    lli res=mx ;
    l=1 ; r=mx ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        query(1, m) ;
        if(q[0]=='Y') res=min(res, m), r=m-1 ;
        else l=m+1 ;
      }
    return min(mx, res+100*k) ;
  }

lli getL()
  {
    lli res=0 ;
    l=1 ; r=mx ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        query(m, mx) ;
        if(q[0]=='Y') res=max(res, m), l=m+1 ;
        else r=m-1 ;
      }
    return max(1LL, res-100*k) ;
  }

void solve()
  {
    L=getL() ; R=getR() ;
    while(1)
      {
        x=dice() ;
        query(x, x) ;
        if(q[0]=='Y') return ;
      }
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> mx >> k ;
    solve() ;
  }
