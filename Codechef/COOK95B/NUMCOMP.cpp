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
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int a, b, n ;
        cin>> a >> b >> n ;
        if(a>0 && b>0)
          {
            if(a==b) cout<< 0 << endl ;
            else if(a>b) cout<< 1 << endl ;
            else cout<< 2 << endl ;
          }
        else if(a>0 && b<0)
          {
            if(n%2) cout<< 1 << endl ;
            else
              {
                b=abs(b) ;
                if(a==b) cout<< 0 << endl ;
                else if(a>b) cout<< 1 << endl ;
                else cout<< 2 << endl ;
              }
          }
        else if(a<0 && b<0)
          {
            a=abs(a) ;
            b=abs(b) ;
            if(n%2)
              {
                swap(a, b) ;
                if(a==b) cout<< 0 << endl ;
                else if(a>b) cout<< 1 << endl ;
                else cout<< 2 << endl ;
              }
            else
              {
                if(a==b) cout<< 0 << endl ;
                else if(a>b) cout<< 1 << endl ;
                else cout<< 2 << endl ;
              }
          }
        else if(a<0 && b>0)
          {
            if(n%2) cout<< 2 << endl ;
            else
              {
                a=abs(a) ;
                if(a==b) cout<< 0 << endl ;
                else if(a>b) cout<< 1 << endl ;
                else cout<< 2 << endl ;
              }
          }
        else if(a==0 && b!=0)
          {
            if(b>0) cout<< 2 << endl ;
            else if(n%2) cout<< 1 << endl ;
            else cout<< 2 << endl ;
          }
        else if(a!=0 && b==0)
          {
            if(a>0) cout<< 1 << endl ;
            else if(n%2) cout<< 2 << endl ;
            else cout<< 1 << endl ;
          }
        else if(!a && !b) cout<< 0 << endl ;
      }
  }
