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

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli n, x, mx=408983066, s=mx, b, ans ;
bool pos=true ;
string q ;
set<lli> temp, aux ;

void add()
  {
    aux.insert(x) ;
    if(b<=x && x<=s)
      {
        temp.insert(x) ;
        ans++ ;
      }
  }

void accept()
  {
    if(temp.find(x)!=temp.end())
      {
        for(auto i:temp)
          if(i<x) b=max(b, i), ans-- ;
          else if(i>x) s=min(s, i), ans-- ;
        temp.clear() ;
      }
    else
      {
        if(x<b || s<x) pos=false ;
        else
          {
            if(x==b)
              {
                ans=0 ;
                temp.clear() ;
                auto it=aux.find(x) ;
                if(it==aux.begin()) b=0 ;
                else b=*(--it) ;
                it=aux.find(x) ;
                it++ ;
                if(it==aux.end()) s=mx ;
                else s=*it ;
              }
            else
              {
                ans=0 ;
                temp.clear() ;
                auto it=aux.find(x) ;
                it++ ;
                if(it==aux.end()) s=mx ;
                else s=*it ;
                it=aux.find(x) ;
                if(it==aux.begin()) b=0 ;
                else b=*(--it) ;
              }
          }
      }
    aux.erase(x) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> q >> x ;
        if(q=="ADD") add() ;
        else accept() ;
        if(!pos) return cout<< 0, 0 ;
      }
    cout<< fast_exp(2, ans) ;
  }
