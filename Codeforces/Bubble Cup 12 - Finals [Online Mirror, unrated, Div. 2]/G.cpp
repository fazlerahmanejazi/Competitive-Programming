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

void input_farm(vector<vlli> &farm, lli &n, lli &m)
  {
    lli x ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        cin>> x, farm[i].pb(x) ;
    if(n<=m) return ;
    vector<vlli> temp(m) ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        temp[j].pb(farm[i][j]) ;
    farm=temp ;
    swap(n, m) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, m, x, y, val, x1, x2, idx1, idx2, ans=0, curr ;
    cin>> n >> m ;
    vector<vlli> farm(n) ;
    input_farm(farm, n, m) ;
    vlli rs(n), cs(m) ;
    for(int i=0 ; i<n ; i++)
      {
         x=0 ;
         for(int j=0 ; j<m ; j++) x+=farm[i][j] ;
         rs[i]=x ;
      }
    for(int i=0 ; i<m ; i++)
      {
         x=0 ;
         for(int j=0 ; j<n ; j++) x+=farm[j][i] ;
         cs[i]=x ;
      }
    if(n<5 || m<5)
      {
        for(int i=0 ; i<n ; i++)
          for(int j=0 ; j<m ; j++)
            ans+=farm[i][j] ;
      }
    else
      {
        for(int i=0 ; i<n ; i++)
          for(int j=i+1 ; j<n ; j++)
            {
              curr=rs[i]+rs[j] ;
              lli mx1=cs[0]-farm[i][0]-farm[j][0], mx2=cs[1]-farm[i][1]-farm[j][1], mx ;
              if(mx1<mx2) swap(mx1, mx2) ;
              for(int k=2 ; k<m ; k++)
                {
                  mx=cs[k]-farm[i][k]-farm[j][k] ;
                  if(mx>mx1) mx2=mx1, mx1=mx ;
                  else if(mx>mx2) mx2=mx ;
                }
              curr+=mx1+mx2 ;
              ans=max(ans, curr) ;
            }
        for(int i=0 ; i<n ; i++)
          {
            curr=rs[i] ;
            vlli temp ;
            for(int k=0 ; k<m ; k++) temp.pb(cs[k]-farm[i][k]) ;
            sort(all(temp)) ;
            curr+=temp[m-1]+temp[m-2]+temp[m-3] ;
            ans=max(ans, curr) ;
          }
        for(int i=0 ; i<m ; i++)
          {
            curr=cs[i] ;
            vlli temp ;
            for(int k=0 ; k<n ; k++) temp.pb(rs[k]-farm[k][i]) ;
            sort(all(temp)) ;
            curr+=temp[m-1]+temp[m-2]+temp[m-3] ;
            ans=max(ans, curr) ;
          }
        sort(all(rs)) ;
        curr=rs[n-1]+rs[n-2]+rs[n-3]+rs[n-4] ;
        ans=max(ans, curr) ;
        sort(all(cs)) ;
        curr=cs[m-1]+cs[m-2]+cs[m-3]+cs[m-4] ;
        ans=max(ans, curr) ;
      }
    cout<< ans ;
  }
