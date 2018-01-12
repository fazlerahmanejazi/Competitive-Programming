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
    int n, firstA, firstB, secondA, secondB, a, b, f, s ;
    cin>> n ;
    vi points(n, 0) ;
    vvi arr(n, vi(n)) ;
    vpii ans ;
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<n ; j++)
          cin>> arr[i][j] ;
        sort(all(arr[i])) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        for(int j=i+1 ; j<n ; j++)
          {
            f=0, s=0 ;
            while(f<n && s<n)
              {
                if(arr[i][f]==arr[j][s]) break ;
                else if(arr[i][f]>arr[j][s]) s++ ;
                else f++ ;
              }
            if(f==n || s==n)
              {
                points[i]++ ;
                points[j]++ ;
                continue ;
              }
            else
              {
                firstA=f ;
                secondA=s ;
              }
            f=n-1 ; s=n-1 ;
            while(f>=0 || s>=0)
              {
                if(arr[i][f]==arr[j][s]) break ;
                else if(arr[i][f]>arr[j][s]) f-- ;
                else s-- ;
              }
            firstB=f ;
            secondB=s ;
            if(firstB-firstA==secondB-secondA)
              {
                points[i]++ ;
                points[j]++ ;
              }
            else if(firstB-firstA<secondB-secondA) points[i]+=2 ;
            else points[j]+=2 ;
          }
      }
    for(int i=0 ; i<n ; i++)
      ans.pb(mp(-points[i], i+1)) ;
    sort(all(ans)) ;
    for(int i=0 ; i<n ; i++)
      cout<< ans[i].se << endl ;
  }
