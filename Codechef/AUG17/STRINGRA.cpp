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

int n, q, l, r, x, cnt, sum, s ;
bool check ;
vi a, to, ans ;
vvi v ;
vb avail ;
map<pii, bool> done ;

void init(int n)
  {
    ans.assign(n+1, 1) ;
    to.assign(n+1, 0) ;
    avail.assign(n+1, true) ;
    a.assign(n+1, 1) ;
    v.clear() ; v.resize(n+1) ;
    done.clear() ;
    check=true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> q ;
        init(n+1) ;
        for(int i=1 ; i<=q ; i++)
          {
            cin>> l >> r ;
            to[l]++ ;
            if(done[mp(l, r)]) check=false ;
            else done[mp(l, r)]=true ;
            if(l>=r) check=false ;
            else v[l].pb(r) ;
          }
        for(int i=0 ; i<n ; i++)
          {
						avail[i]=false ;
            sort(all(v[i])) ;
						s=a[i] ;
						for(int j=0 ; j<v[i].size() ; j++)
							if(avail[v[i][j]])
								{
									ans[v[i][j]]=a[v[i][j]]=s++ ;
									avail[v[i][j]]=false ;
								}
          }
				avail.assign(n+1, true) ;
        avail[ans[n]]=false ; sum=0, cnt=1 ;
        for(int i=n-1 ; i>=0 ; i--)
          {
            sum+=cnt ;
            if(cnt!=to[i]) check=false ;
            if(avail[a[i]]) avail[a[i]]=0, cnt++ ;
          }
        if(sum!=q) check=false ;
        if(check)
          {
            for(int i=1 ; i<=n ; i++)
              cout<< ans[i] << " " ;
            cout<< endl ;
          }
        else cout<< -1 << endl ;
      }
  }
