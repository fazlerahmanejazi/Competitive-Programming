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
    long double h, m, s, t1, t2 ;
    bool pos=false ;
    cin>> h >> m >> s >> t1 >> t2 ;
    s*=6 ; if(s>=360) s-=360 ;
    m=m*6+(s/60.0) ; if(m>=360) m-=360 ;
    h=h*30+(m/60.0) ; if(h>=360) h-=360 ;
    t1=t1*30 ;
    t2=t2*30 ;
    vector<long double> O={s, m, h} ;
    sort(all(O)) ;
    if(t1<O[0]) t1+=360 ;
    if(t2<O[0]) t2+=360 ;
    t1-=O[0] ; t2-=O[0] ; O[1]-=O[0] ; O[2]-=O[0] ; O[0]=0 ;
    if(t1>t2) swap(t1, t2) ;
    if(t1>=O[0] && t1<=O[1] && t2>=O[0] && t2<=O[1]) pos=true ;
    if(t1>=O[1] && t1<=O[2] && t2>=O[1] && t2<=O[2]) pos=true ;
    if(t1>=O[2] && t1<=360 && t2>=O[2] && t2<=360) pos=true ;
    if(pos) cout<< "YES" ;
    else cout<< "NO" ;
  }
