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

vb isprime(20000000, true) ;

void seive()
  {
    isprime[1]=isprime[0]=false ;
    isprime.assign(100000, true) ;
    for(int i=2 ; i*i<=10000000 ; i++)
      if(isprime[i])
        for(int j=i+i ; j<=10000000 ; j+=i)
          isprime[j]=false ;
  }


  int main()
    {
      ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
      vector<string> matrix ;
      int N ;
      string qq ;
      cin>> N ;
      for(int i=0 ; i<N ; i++) cin>> qq, matrix.pb(qq) ;
      seive() ;
      set<int> s ;
      int ans=0, n=matrix[0].size(), m=matrix.size() ;
      for(int a=0 ; a<n ; a++)
        for(int b=0 ; b<n ; b++)
          for(int c=0 ; c<n ; c++)
            for(int d=0 ; d<n ; d++)
              for(int e=0 ; e<n ; e++)
                for(int f=0 ; f<n ; f++)
                  for(int g=0 ; g<n ; g++)
                    {
                      string r="" ;
                      r+=matrix[0][a] ;
                      if(1<m) r+=matrix[1][b] ;
                      if(2<m) r+=matrix[2][c] ;
                      if(3<m) r+=matrix[3][d] ;
                      if(4<m) r+=matrix[4][e] ;
                      if(5<m) r+=matrix[5][f] ;
                      if(6<m) r+=matrix[6][g] ;
                      int x=stoi(r) ;
                      if(isprime[x]) s.insert(x) ;
                    }
      ans=s.size() ;
      cout<< ans ;
    }
