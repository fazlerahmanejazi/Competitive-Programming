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
    int k, n1, n2, n3, t1, t2, t3, ans=0, curr ;
    cin>> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3 ;
    priority_queue<int, vi, greater<int>> wash, dry, fold ;
    for(int i=1 ; i<=n1 ; i++) wash.push(0) ;
    for(int i=1 ; i<=n2 ; i++) dry.push(0) ;
    for(int i=1 ; i<=n3 ; i++) fold.push(0) ;
    for(int i=1 ; i<=k ; i++)
      {
        curr=wash.top() ;
        if(dry.top()>curr+t1) curr+=(dry.top()-curr-t1) ;
        if(fold.top()>curr+t1+t2) curr+=(fold.top()-curr-t1-t2) ;
        wash.pop() ; dry.pop() ; fold.pop() ;
        wash.push(curr+t1) ; dry.push(curr+t1+t2) ; fold.push(curr+t1+t2+t3) ;
        ans=max(ans, curr+t1+t2+t3) ;
      }
    cout<< ans ;
  }
