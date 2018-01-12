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
    lli n, x, ans=-2*INF ;
    cin>> n ;
    vlli a(n), sumL(n+1, 0), sumR(n+1, 0) ;
    priority_queue<lli,vector<lli>,greater<lli>> lq;
    priority_queue<lli> rq;
    for(int i=1 ; i<=n ; i++)
      {
        cin>>x ;
        sumL[0]+=x ;
        lq.push(x);
      }
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        sumR[n]+=x ;
        rq.push(x);
      }
    for(int i=0 ; i<n ; i++)
      {
        lq.push(a[i]) ;
        sumL[i+1]=sumL[i]+a[i]-lq.top() ;
        lq.pop() ;
        rq.push(a[n-1-i]) ;
        sumR[n-1-i]=sumR[n-i]+a[n-1-i]-rq.top() ;
        rq.pop();
      }
    for(int i=0 ; i<=n ; i++)
      ans=max(ans, sumL[i]-sumR[i]) ;
    cout<< ans ;
  }
