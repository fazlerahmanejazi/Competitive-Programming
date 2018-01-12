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
    string s ;
    int n ;
    cin>> s ;
    bool pos=true ;
    if(s.length()<7) cout<< "no" ;
    else
      {
        n=s.length() ;
        for(int i=0 ; i<n ; i++)
          if(s[i]=='1')
            {
              int c=0 ;
              for(int j=i+1 ; j<n ; j++)
                if(s[j]=='0') c++ ;
              if(c>=6)
                {
                  cout<< "yes" ;
                  return 0 ;
                }
            }
        cout<< "no" ;
      }
  }
