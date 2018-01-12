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
    lli a, b, f, k, ans, curr, fuel ;
    cin>> a >> b >> f >> k ;
    bool pos=false ;
    if(k==1 && b>=f && b>=a-f) pos=true ;
    else if(k==2 && b>=f && b>=2*(a-f)) pos=true ;
    else if(b>=2*f && b>=2*(a-f)) pos=true ;
    if(pos)
      {
        curr=ans=0 ;
        fuel=b ;
        while(1)
          {
            if(curr==k-1)
              {
                if(a>fuel) ans++ ;
                break ;
              }
            if(curr%2==0)
              {
                if(2*a-f>fuel) ans++, fuel=b-(a-f) ;
                else fuel-=a ;
              }
            else
              {
                if(f+a>fuel) ans++, fuel=b-f ;
                else fuel-=a ;
              }
            curr++ ;
          }
      }
    else ans=-1 ;
    cout<< ans ;
  }
