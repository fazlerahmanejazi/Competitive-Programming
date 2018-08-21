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

char arr[] = { '^','>','v','<' } ;
int idx ;

char right(int idx, int x)
  {
    while(x--)
      {
        if(idx==3) idx=0 ;
        else idx++ ;
      }
    return arr[idx] ;
  }

char left(int idx, int x)
  {
    while(x--)
      {
        if(idx==0) idx=3 ;
        else idx-- ;
      }
    return arr[idx] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    arr[0]='<' ; arr[1]='^' ; arr[2]='>' ; arr[3]='v' ;
    int n, x ;
    char s, e ;
    cin>> s >> e ;
    cin>> n ;
    n=n%4 ;
    for(int i=0 ; i<4 ; i++)
      if(arr[i]==s)
        {
          idx=i ;
          break ;
        }
    x=(idx-n+4)%4 ;
    if(arr[(n+idx)%4]==e && arr[x]==e) cout << "undefined" ;
  	else if (arr[(n+idx)%4]==e) cout << "cw" ;
  	else if (arr[x]==e) cout << "ccw" ;
  	else cout<<"undefined";
  }
