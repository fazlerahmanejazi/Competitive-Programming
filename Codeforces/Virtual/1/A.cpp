#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string a, b, kill, rep ;
    int n ;
    cin>> a >> b ;
    cin>> n ;
    cout<< a << " " << b << endl ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> kill >> rep ;
        if(kill==a) a=rep ;
        else if(kill==b) b=rep ;
        cout<< a << " " << b << endl ;
      }
  }
