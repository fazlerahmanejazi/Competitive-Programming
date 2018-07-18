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
    int n, ans=0, x ;
    cin>> n ;
    string a, b ;
    cin>> a >> b ;
    for(int i=0 ; i<n ; i++)
      if(i==n-i-1)
        {
          if(a[i]!=b[i]) ans++ ;
        }
      else if(i<n-i-1)
        {
          set<char> temp ;
          temp.insert(a[i]) ; temp.insert(a[n-i-1]) ;
          temp.insert(b[i]) ; temp.insert(b[n-i-1]) ;
          if(temp.size()==2)
            {
              if(a[i]==a[n-i-1] && b[i]!=b[n-i-1]) ans++ ;
              else if(b[i]==b[n-i-1] && a[i]!=a[n-i-1]) ans++ ;
            }
          if(temp.size()==3)
            {
              if(a[i]==a[n-i-1]) ans+=2 ;
              else if(b[i]==b[i-n-1]) ans++ ;
              else ans++ ;
            }
          else if(temp.size()==4) ans+=2 ;
        }
    cout<< ans ;
  }
