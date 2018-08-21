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

int n, h, x, u, idx ;
vi a(200005)  ;
bool check=true ;

void print(int p)
  {
    queue<int> q ;
    vi prev, curr ;
    for(int i=2 ; i<=n ; i++) q.push(i) ;
    cout<< 0 << " " ;
    prev.pb(1) ;
    for(int i=1 ; i<=h ; i++)
      {
        curr.clear() ;
        int pos=0 ;
        x=a[i] ;
        while(x--)
          {
            u=q.front() ; q.pop() ;
            curr.pb(u) ;
            cout<< prev[pos] << " " ;
            if(p && i==idx) pos=(pos+1)%prev.size() ;
          }
        prev=curr ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> h ;
    for(int i=0 ; i<=h ; i++) cin>> a[i], n+=a[i] ;
    for(int i=0 ; i<h ; i++)
      if(a[i]>=2 && a[i+1]>=2)
        {
          idx=i+1 ;
          check=false ;
        }
    if(check) cout<< "perfect" ;
    else
      {
        cout<< "ambiguous" << endl ;
        print(1) ;
        cout<< endl ;
        print(0) ;
      }
  }
