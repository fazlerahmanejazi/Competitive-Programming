#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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
    int T, n ;
    string a, b ;
    bool check, flag ;
    cin>> T ;
    while(T--)
      {
        vi cntA(27, 0), cntB(27, 0) ;
        cin>> a >> b ;
        n=a.length() ;
        check=false ;
        flag=true ;
        for(int i=0 ; i<n ; i++)
          {
            cntA[a[i]-'a']++ ;
            cntB[b[i]-'a']++ ;
          }
        for(int i=0 ; i<26 ; i++)
          if(!cntA[i] && cntB[i])
            flag=0 ;
        for(int i=0 ; i<26 ; i++)
          if(cntA[i]>=2 && !cntB[i]) check=true ;
          else if(cntA[i]==1 && !cntB[i] && flag) check=true ;
        if(check) cout<< "A" << endl ;
        else cout<< "B" << endl ;
      }
  }
