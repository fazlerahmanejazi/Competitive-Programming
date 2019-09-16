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

int attack(tuple<int, int, int> &temp)
  {
    return get<1>(temp) ;
  }

int health(tuple<int, int, int> &temp)
  {
    return get<0>(temp) ;
  }

int index(tuple<int, int, int> &temp)
  {
    return get<2>(temp) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, a, h, x, y, l, r, m, idx, res=0, ans1=0, ans2=1, curr=0, pos ;
    cin>> n ;
    vector<tuple<int, int, int>> creatures ;
    vector<pair<int, int>> mx(n) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> h ;
        creatures.pb(mt(h, a, i)) ;
      }
    sort(all(creatures)) ;
    mx[0]=mp(0, -1) ;
    if(attack(creatures[1])>attack(creatures[0])) mx[1]=mp(1, 0) ;
    else mx[1]=mp(0, 1) ;
    for(int i=2 ; i<n ; i++)
      {
        tie(x, y)=mx[i-1] ;
        if(attack(creatures[i])>attack(creatures[x])) y=x, x=i ;
        else if(attack(creatures[i])>attack(creatures[y])) y=i ;
        mx[i]=mp(x, y) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        tie(h, a, idx)=creatures[i] ;
        l=0 ; r=n-1 ;
        pos=-1 ;
        curr=0 ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            if(health(creatures[m])<=a) l=m+1, pos=m ;
            else r=m-1 ;
          }
        if(pos!=-1)
          {
            tie(x, y)=mx[pos] ;
            if(index(creatures[x])==idx) x=y ;
            if(x!=-1)
              {
                curr=attack(creatures[x]) ;
                if(attack(creatures[x])>=h) curr+=a ;
                if(curr>res) res=curr, ans1=idx, ans2=index(creatures[x]) ;
              }
          }
      }
    cout<< res << endl << ans1+1 << " " << ans2+1 << endl ;
    }
