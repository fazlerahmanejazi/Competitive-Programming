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
    int n, cnt ;
    char prev ;
    cin>> n ;
    string s, r ;
    bool pos ;
    for(int k=0 ; k<n ; k++)
      {
        cin>> s >> r ;
        int i=0, j=0, x, y ;
        pos=true ;
        while(i<s.size() && j<r.size())
          {
            x=y=0 ;
            if(s[i]!=r[j])
              {
                pos=false ;
                break ;
              }
            while(i+1<s.size() && s[i]==s[i+1]) i++, x++ ;
            while(j+1<r.size() && r[j]==r[j+1]) j++, y++ ;
            if(y<x)
              {
                pos=false ;
                break ;
              }
            i++ ;
            j++ ;
          }
        if(i!=s.size() || j!=r.size()) pos=false ;
        if(pos) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
  }
