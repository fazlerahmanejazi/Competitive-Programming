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

const int N=5 ;

int count(vi a)
  {
    vi b(N) ;
    int cnt=0 ;
    for(int i=0 ; i<N ; i++) b[i]=i+1 ;
    do {
      bool chk=true ;
      for(int i=0 ; i<N ; i++) if(a[i]<b[i]) chk=false ;
      if(chk) cnt++ ;
    } while(next_permutation(all(b))) ;
    return cnt ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int res ;
    vi a(N) ;
    map<int, vi> ans ;
    for(int i=1 ; i<=N ; i++)
      for(int j=max(i, 2) ; j<=N ; j++)
        for(int k=max(j, 3) ; k<=N ; k++)
          for(int l=max(k, 4) ; l<=N ; l++)
            {
              a[0]=i ;
              a[1]=j ;
              a[2]=k ;
              a[3]=l ;
              a[4]=N ;
              res=count(a) ;
              if(ans.find(res)==ans.end()) ans[res]=a ;
            }
    cout<< ans.size() << endl ;
    for(auto i:ans)
      {
        cout<< N << " " ;
        //for(auto j:i.se) cout<< j << " " ;
        //cout<< " : " ;
        cout<< i.fi ;
        cout<< endl ;
      }
  }
