#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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

int query(string s)
  {
    int x ;
    cout<< s << endl ;
    cin>> x ;
    return x ;
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string s="a" ;
    int qa=query(s) ;
    if(!qa) return 0 ;
    s="b" ;
    int qb=query(s) ;
    if(!qb) return 0 ;
    if(qb>qa) s="a" ;
    int m=min(qa, qb) ;
    while(m)
      {
        while(m)
          {
            int x=query(s+"a") ;
            if(!x) return 0 ;
            if(x-m==-1) s+"a" ;
            else if(x-m==2) s+="b" ;
            else if(x-m==1) break ;
          }
        while(m)
          {
            int x=query("a"+s) ;
            if(!x) return 0 ;
            if(x-m<0) s=s+"a" ;
            if(x-m>0) s+=s+"b" ;
          }
      }
    query(s) ;
  }
