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

int n, k ;
bool notPos ;
string x, u, v ;
vi p, cnt(26, 0) ;
vector<string> s, temp ;

bool check(string &r)
  {
    for(int i=0 ; i<k ; i++)
      {
        int c=0, same=0 ;
        vi cnt(27, 0) ;
        for(int j=0 ; j<n ; j++)
          {
            if(r[j]!=s[i][j]) c++ ;
            cnt[s[i][j]-'a']++ ;
            if(cnt[s[i][j]-'a']>=2) same=1 ;
          }
        if(!same && !c) return false ;
        if(c>2 || c==1) return false ;
      }
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> k >> n ;
    u="" ; v="" ;
    for(int i=0 ; i<k ; i++)
      {
        cin>> x ;
        if(u=="") u=x ;
        if(u!="" && v=="" && x!=u) v=x ;
        s.pb(x) ;
        sort(all(x)) ;
        temp.pb(x) ;
      }
    if(v=="")
      {
        swap(u[0], u[1]) ;
        cout<< u ;
      }
    else
      {
        for(int i=0 ; i<n ; i++) if(u[i]!=v[i]) p.pb(i) ;
        for(int i=1 ; i<k ; i++) if(temp[i]!=temp[0]) notPos=1 ;
        if(p.size()>4 || notPos)
          {
            cout<< -1 ;
            return 0 ;
          }
        for(int i=0 ; i<n ; i++)
          for(auto j:p)
            if(i!=j)
              {
                x=u ;
                swap(x[i], x[j]) ;
                if(check(x))
                  {
                    cout<< x ;
                    return 0 ;
                  }
              }
        cout<< -1 ;
      }
  }
