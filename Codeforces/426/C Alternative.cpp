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

lli n, a, b, c, x, A, B, aN, bN, pos ;
vlli prime(1000100, 0), cubes ;
bool check ;

void preprocess()
  {
    prime[1]=1 ;
    for(int i=2 ; i<=1000000 ; i++)
      if(!prime[i])
        for(int j=i ; j<=1000000 ; j+=i)
          prime[j]=i ;
    for(lli i=1 ; i<=1e6 ; i++)
      cubes.pb(i*i*i) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    preprocess() ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b ;
        x=a*b ;
        pos=lower_bound(all(cubes), x)-cubes.begin() ;
        c=pos+1 ;
        if(x!=c*c*c) check=false ;
        else
          {
            check=true ;
            while(c>1)
              {
                x=prime[c] ;
                c/=x ;
                aN=bN=0 ;
                while(a%x==0)
                  {
                    a/=x ;
                    aN++ ;
                  }
                while(b%x==0)
                  {
                    b/=x ;
                    bN++ ;
                  }
                if(2*aN>=bN && 2*bN>=aN && (2*aN-bN)%3==0 && (2*bN-aN)%3==0 && (aN+bN)%3==0) continue ;
                else
                  {
                    check=false ;
                    break ;
                  }
              }
          }
        if(check) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
