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
    int n, A, x, B ;
    list<int> color ;
    list<int>::iterator it ;
    bool possible=true ;
    vi freq(1000010, 0) ;
    vb avail(1000010, true) ;
    cin>> n >> A ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        if(x==A)
          {
            freq[x]++ ;
            it=color.begin() ;
            while(it!=color.end())
              {
                if(freq[*it]<freq[A])
                  {
                    avail[*it]=false ;
                    it=color.erase(it) ;
                  }
                else it++ ;
              }
            if(color.empty())
              {
                possible=false ;
                break ;
              }
          }
        else
          {
            if(freq[x]>=freq[A] && avail[x])
              {
                freq[x]++ ;
                color.push_back(x) ;
              }
            else avail[x]=false ;
          }
      }
    if(possible)
      {
        it=color.begin() ;
        B=*it ;
        cout<< B ;
      }
    else cout<< -1 ;
  }
