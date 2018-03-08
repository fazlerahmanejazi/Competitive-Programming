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

int q, l1, l2, r1, r2, l, r, t ;
set<pii> L, R ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> q ;
    while(q--)
      {
        cin>> t ;
        if(t==1)
          {
            cin>> l >> r ;
            L.insert(mp(l, r)) ;
            R.insert(mp(r, l)) ;
          }
        else if(t==2)
          {
            cin>> l >> r ;
            L.erase(mp(l, r)) ;
            R.erase(mp(r, l)) ;
          }
        else
          {
            cin>> l1 >> r1 >> l2 >> r2 ;
            if(l1>l2) swap(l1, l2), swap(r1, r2) ;
            if(l1==l2 && r1==r2) cout<< 0 << endl ;
            else if(r1<l2) cout<< 1 << endl ;
            else
              {
                auto it1=L.upper_bound(mp(max(r1, r2), inf)) ;
                auto it2=R.begin() ;
                if(it1!=L.end() || (*it2).fi<l1) cout<< 2 << endl ;
                else
                  {
                    it1=L.upper_bound(mp(r1, inf)) ;
                    if(it1!=L.end() && (*it2).fi<l2) cout<< 3 << endl ;
                    else cout<< -1 << endl ;
                  }
              }
          }
      }
  }
