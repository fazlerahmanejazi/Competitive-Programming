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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, m, x, y, val, x1, x2, idx1, idx2, ans=0, curr ;
    cin>> n >> m ;
    vector<vlli> farm(n), farm1, sum(n, vlli(m)) ;
    vlli rs(n), cs(m) ;
    priority_queue<tuple<lli, lli, lli>> pq ;
    priority_queue<pair<lli, lli>> r, c, temp ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<m ; j++)
        cin>> x, farm[i].pb(x) ;
    farm1=farm ;
    for(int i=0 ; i<n ; i++)
      {
        x=0 ;
        for(int j=0 ; j<m ; j++) x+=farm[i][j] ;
        r.push(mp(x, i)) ;
      }
    for(int i=0 ; i<m ; i++)
      {
        x=0 ;
        for(int j=0 ; j<n ; j++) x+=farm[j][i] ;
        c.push(mp(x, i)) ;
      }
    for(int i=0 ; i<4 ; i++)
      {
        tie(x1, idx1)=r.top() ;
        tie(x2, idx2)=c.top() ;
        if(x1>x2)
          {
            ans+=x1 ;
            r.pop() ;
            r.push(mp(0, idx1)) ;
            while(!c.empty())
              {
                tie(x2, idx2)=c.top() ;
                x2-=farm1[idx1][idx2] ;
                farm1[idx1][idx2]=0 ;
                temp.push(mp(x2, idx2)) ;
                c.pop() ;
              }
            while(!temp.empty()) c.push(temp.top()), temp.pop() ;
          }
        else
          {
            ans+=x2 ;
            c.pop() ;
            c.push(mp(0, idx2)) ;
            while(!r.empty())
              {
                tie(x1, idx1)=r.top() ;
                x1-=farm1[idx1][idx2] ;
                farm1[idx1][idx2]=0 ;
                temp.push(mp(x1, idx1)) ;
                r.pop() ;
              }
            while(!temp.empty()) r.push(temp.top()), temp.pop() ;
          }
      }
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
     for(int i=0 ; i<n ; i++)
       for(int j=0 ; j<m ; j++)
         {
           sum[i][j]=rs[i]+cs[j]-farm[i][j] ;
           pq.push(mt(sum[i][j], i, j)) ;
         }
     while(!pq.empty())
       {
         tie(val, x, y)=pq.top() ; pq.pop() ;
         for(int i=0 ; i<n ; i++)
           for(int j=0 ; j<m ; j++)
               {
                 if(i==x && j==y) curr=val ;
                 else if(i==x) curr=val+cs[j]-farm[i][j] ;
                 else if(j==y) curr=val+rs[i]-farm[i][j] ;
                 else curr=val+sum[i][j]-farm[x][j]-farm[i][y] ;
                 ans=max(ans, curr) ;
               }
       }
    cout<< ans ;
  }
