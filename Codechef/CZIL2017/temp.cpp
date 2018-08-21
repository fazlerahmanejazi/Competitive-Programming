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

void nextGreater(int arr[], int n, int next[], char order)
  {
    stack<int> S;
    for (int i=n-1; i>=0; i--)
      {
        while(!S.empty() && ((order=='G')? arr[S.top()]<=arr[i]:arr[S.top()]>=arr[i])) S.pop() ;
        if(!S.empty()) next[i]=S.top() ;
        else next[i]=-1 ;
        S.push(i) ;
      }
  }

lli solve(int arr[], int n)
{
    int NG[n];
    int RS[n];
    nextGreater(arr, n, NG, 'G') ;
    for(int i=0 ; i<n ; i++)
      {
        if(NG[i]==-1) NG[i]=n-1-i ;
        else NG[i]=NG[i]-i-1 ;
      }
    reverse(arr, arr+n) ;
    nextGreater(arr, n, RS, 'G') ;
    reverse(arr, arr+n) ;
    for(int i=0 ; i<n ; i++)
      {
        if(RS[i]==-1) RS[i]=n-1-i ;
        else RS[i]=RS[i]-i-1 ;
      }
    reverse(RS, RS+n) ;
    lli res=0 ;
    for(int i=0 ; i<n ; i++)
      {
        lli l, r, x ;
        l=RS[i] ; r=NG[i] ; x=arr[i] ;
        res+=(l+1)*(r+1)*x ;
      }
    return res ;
}
int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        int n ;
        cin>> n ;
        int arr[n] ;
        for(int i=0 ; i<n ; i++) cin>> arr[i] ;
        cout<< solve(arr, n) << endl ;
      }
  }
