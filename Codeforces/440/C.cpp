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
    int q, n, x, ans, curr ;
    cin>> q ;
    while(q--)
      {
        cin>> n ;
        if(n<=3 || n==5 || n==7) cout<< -1 << endl ;
        else if(n>=4)
          {
            curr=n/4 ;
            x=n%4 ;
            if(x)
              {
                if(x==1)
                  {
                    if(curr>=2)
                      {
                        x=n-9 ;
                        curr=x/4 ;
                        cout<< curr+1 << endl ;
                        continue ;
                      }
                  }
                else if(x==2)
                  {
                    cout<< curr << endl ;
                    continue ;
                  }
                else if(x==3)
                  {
                    if(curr>=3)
                      {
                        x=n-15 ;
                        curr=x/4 ;
                        cout<< curr+2 << endl ;
                        continue ;
                      }
                  }
              }
            else
              {
                cout<< curr << endl ;
                continue ;
              }
            cout<< -1 << endl ;
          }
      }
  }
