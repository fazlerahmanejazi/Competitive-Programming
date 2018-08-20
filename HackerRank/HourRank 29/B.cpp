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

const int MX=1000 ;

template<class T, int SZ> struct DSU
  {
    T p[SZ+1] ;
    DSU() { for(int i=0 ; i<=SZ ; i++) p[i]=i ; }
    T find(T i)
      {
        if(i!=p[i]) p[i]=find(p[i]) ;
        return p[i] ;
      }
    bool same(T i, T j) { return find(i)==find(j) ; }
    void unionset(T i, T j)
      {
        T x=find(i) ; T y=find(j) ;
        if(x!=y) p[x]=y ;
      }
  } ;

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        vb isprime(MX+10, true), taken(MX+10, false) ;
        isprime[1]=false ;
        DSU<lli, MX+10> p ;
        lli n, x, tot=0, cnt[MX+10] ;
        vlli a ;
        memset(cnt, 0, sizeof cnt) ;
        cin>> n ;
        for(int i=1 ; i<=n ; i++) cin>> x, a.pb(x), cnt[x]++ ;
        for(int i=2 ; i<=MX ; i++)
          if(isprime[i])
            {
              vi temp ;
              if(cnt[i]) temp.pb(i) ;
              for(int j=2*i ; j<=MX ; j+=i)
                if(cnt[j])
                  {
                    temp.pb(j) ;
                    isprime[j]=false ;
                  }
              for(int j=1 ; j<temp.size() ; j++) if(!p.same(temp[j], temp[j-1])) p.unionset(temp[j], temp[j-1]) ;
            }
          for(auto i:a) if(i!=1 && !taken[p.find(i)]) tot++, taken[p.find(i)]=true ;
          tot+=cnt[1] ;
          cout<< (fast_exp(2, tot)-2+mod)%mod << endl ;
      }
  }
