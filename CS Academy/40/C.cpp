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

int n ;
lli ans=0 ;
vi tree ;

int query(int i)
  {
    int temp=0 ;
    for( ; i>=0 ; i=(i&(i+1))-1)
      temp+=tree[i] ;
    return temp ;
  }

void update(int i, int val)
  {
    for( ; i<n+1 ; i=(i|(i+1)))
      tree[i]+=val ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    tree.assign(n+10, 0) ;
    string s ;
    cin>> s ;
    vi stat(n+1, 0) ;
    for(int i=1 ; i<=s.length() ; i++)
      {
        stat[i]+=(s[i-1]-'0')+stat[i-1] ;
        update(i, (s[i-1]-'0')) ;
      }
    vi cost(n+1), range(n+1) ;
    for(int i=1 ; i<=n ; i++)
      cin>> range[i] ;
    range[0]=0 ;
    for(int i=1 ; i<=n ; i++)
      cin>> cost[i] ;
    for(int i=1 ; i<=n ; i++)
      {
        if(((s[i-1]-'0')+query(i)-stat[i])%2)
          {
            ans+=cost[i] ;
            update(i, 1) ;
            update(range[i]+1, -1) ;
          }
      }
    cout<< ans ;
  }
