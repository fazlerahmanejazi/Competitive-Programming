#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    int n, tot=0 ;
    string s ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> s ;
        if(s=="Tetrahedron") tot+=4 ;
        else if(s=="Cube") tot+=6 ;
        else if(s=="Octahedron") tot+=8 ;
        else if(s=="Dodecahedron") tot+=12 ;
        else if(s=="Icosahedron") tot+=20 ;
      }
    cout<< tot ;
  }
