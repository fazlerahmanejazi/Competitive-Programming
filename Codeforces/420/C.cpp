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
    int n, curr=1, x, ans=0, top=inf ;
    bool change=false ;
    cin>> n ;
    string s ;
    vi prev(n+1, 0) ;
    set<int> boxes ;
    set<int>::iterator it ;
    for(int i=1 ; i<=2*n ; i++)
      {
        cin>> s ;
        if(s[0]=='a')
          {
            cin>> x ;
            prev[x]=top ;
            if(x>top) change=true ;
            top=x ;
            boxes.insert(x) ;
          }
        else
          {
            x=curr ;
            if(change && top!=curr)
              {
                ans++ ;
                it=boxes.begin() ;
                top=*it ;
                change=false ;
              }
            boxes.erase(x) ;
            if(change==false)
              {
                it=boxes.begin() ;
                if(it!=boxes.end()) top=*it ;
                else top=inf ;
              }
            else top=prev[x] ;
            curr++ ;
          }
      }
    cout<< ans ;
  }
