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
        int n, l, r, ans=0 ;
        string s ;
        cin>> s ;
        n=s.length() ;
        s='#'+s ;
        for(int i=0 ; i<n ; i++)
          {
            string temp=s ;
            for(int j=1 ; j<=n-i ; j++) temp[j]=s[i+j] ;
            for(int j=n-i+1 ; j<=n ; j++) temp[j]=s[j-n+i] ;
            bool pos=true ;
            l=1 ; r=n ;
            while(l<r) if(temp[l++]!=temp[r--]) pos=false ;
            if(pos) ans++ ;
          }
        cout<< ans << endl ;
      }
  }
