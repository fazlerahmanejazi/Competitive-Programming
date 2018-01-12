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
    lli n, k, four, two, one, x, y ;
    bool check ;
    cin>> n >> k ;
    four=n;
    two=2*n;
    one=0 ;
    vi a(k+1) ;
    for(int i=1 ; i<=k ; i++)
      cin>> a[i] ;
    x=1 ; y=1 ;
    for(int i=1 ; i<=k ; i++)
      {
        for(int j=1 ; j<=a[i] ; j++)
          {
            if(y<8) y++ ;
            else if(y==8)
              {
                x++ ;
                y=1 ;
              }
          }
        if(y!=1 && i<k-1)
          {
            if(y<8)
              {
                if(y==2 || y==4 || y==5 || y==6) y++ ;
              }
            else if(y==8)
              {
                x++ ;
                y=1 ;
              }
          }
      }
    sort(a.begin()+1, a.end()) ;
    reverse(a.begin()+1, a.end()) ;
    if(x>n && y>1) check=false ;
    for(int i=1 ; i<=k ; i++)
      {
      	x=a[i] ;
      	if(four>=(x/4))
          {
            four-=(x/4) ;
            x%=4 ;
          }
        else
          {
            x-=(four*4) ;
            four=0 ;
          }
      	if(two>=((x+1)/2)) two-=((x+1)/2) ;
        else if(four>0 && x==3) four--;
        else if(four>0 && x==2)
          {
            four--;
            one++;
          }
        else if(x==1 && one>0) one--;
        else if(x==1 && four>0)
          {
            four-- ;
            two++ ;
          }
        else
      	 {
           cout<<"NO"<<endl ;
           return 0 ;
         }
      }
    cout<< "YES" << endl ;
    return 0 ;
}
