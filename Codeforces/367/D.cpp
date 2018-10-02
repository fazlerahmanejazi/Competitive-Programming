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

const int MaxN=2e5*32+100 ;

int sz, nxt[2][MaxN], created[MaxN] ;

void insert(int n)
  {
    int v=0 ;
    for(int i=30 ; i>=0 ; i--)
      {
        int c=((n>>i)&1) ;
        if(!created[nxt[c][v]]) nxt[c][v]=++sz ;
        created[nxt[c][v]]++ ;
        v=nxt[c][v] ;
      }
  }

int search(int n)
  {
    int v=0, ans=0 ;
    for(int i=30 ; i>=0 ; i--)
      {
        int c=((n>>i)&1) ;
        if(created[nxt[1-c][v]]) ans+=(1<<i), v=nxt[1-c][v] ;
        else v=nxt[c][v] ;
      }
    return ans ;
  }

void del(int n)
  {
    int v=0 ;
    for(int i=30 ; i>=0 ; i--)
      {
        int c=((n>>i)&1) ;
        created[nxt[c][v]]-- ;
        v=nxt[c][v] ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int q, x ;
    char c ;
    insert(0) ;
    cin>> q ;
    while(q--)
      {
        cin>> c >> x ;
        if(c=='+') insert(x) ;
        else if(c=='-') del(x) ;
        else cout<< search(x) << endl ;
      }
  }
