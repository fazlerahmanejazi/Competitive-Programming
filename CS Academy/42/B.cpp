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
    string s, a, b ;
    cin>> s ;
    cin>> a ;
    cin>> b ;
    int i=0 ;
    while(i<s.length())
      {
        bool check=true ;
        int j ;
        for(j=0 ; j<a.length() && i+j<s.length() ; j++)
          if(s[i+j]!=a[j])
            check=false ;
        if(j!=a.length()) check=false ;
        if(check)
          {
            for(j=0 ; j<b.length() ; j++, i++)
              s[i]=b[j] ;
          }
        bool A, B ;
        if(check) A=true ;
        else A=false ;
        if(i<s.length())
          {
            check=true ;
            for(j=0 ; j<b.length() && i+j<s.length() ; j++)
              if(s[i+j]!=b[j])
                check=false ;
            if(j!=b.length()) check=false ;
            if(check)
              {
                for(j=0 ; j<b.length() ; j++, i++)
                  s[i]=a[j] ;
              }
            if(check) B=true ;
            else B=false ;
          }
        if(!A && !B) i++ ;
      }
    cout<< s ;
  }
