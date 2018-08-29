#include <bits/stdc++.h>
using namespace std  ;

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
using lli = long long int  ;
using pii = pair<int, int>  ;
using vi = vector<int>  ;
using vb = vector<bool>  ;
using vvi = vector<vector<int>>  ;
using vlli = vector<long long int>  ;
using vpii = vector<pair<int, int>>  ;

const int N=2e5 ;
int n, A[N] ;
lli B[N] ;

int main()
  {
    ios_base::sync_with_stdio (false)  ; cin.tie(0)  ; cout.tie(0)  ;
    cin>>n ;
    for(int i=1 ; i<=n ; i++) cin>> A[i] ;
    A[0]=A[n] ;
    A[n+1]=A[1] ;
    for(int i=1 ; i<=n ; i++)
      {
        if(A[i]>A[i-1])
          {
            B[i]=A[i] ;
            if(i==1) B[n+1]=B[1] ;
            if(i==n) B[0]=B[n] ;
            for(int j=i-1 ; j>i-n ; j--)
              {
                int a=(j+n)%n ;
                if(a==0) a=n ;
                B[a]=B[a+1]+A[a] ;
                while(B[a]<=(lli) A[a-1]) B[a]+=B[a+1] ;
                if(j==1) B[n+1]=B[1] ;
                if(j==n) B[0]=B[n] ;
              }
            cout<< "YES" << endl ;
            for(int j=1 ; j<=n ; j++) cout<< B[j] << ' ' ;
            cout<< endl ;
            return 0 ;
          }
      }
    if(A[1]==0)
      {
        cout<< "YES" << endl ;
        for(int i=1 ; i<=n ; i++) cout<< 1 << ' ' ;
        cout<< endl ;
        return 0 ;
      }
    cout<< "NO" << endl ;
  }
