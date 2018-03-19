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
    lli n, W, sum=0, ans=0, idx=1, w1=0, w2=0, w3=0, w4=0 ;
    cin>> n >> W ;
    vlli w(n), v(n) ;
    vector<vector<lli>> weight(5) ;
    map<lli, lli> cnc, ncn ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> w[i] >> v[i] ;
        sum+=w[i] ;
        if(!cnc[w[i]])
          {
            cnc[w[i]]=idx ;
            ncn[idx++]=w[i] ;
          }
      }
    for(int i=0 ; i<n ; i++)
      weight[cnc[w[i]]].pb(v[i]) ;
    for(int i=1 ; i<=4 ; i++)
      {
        weight[i].pb(0) ;
        sort(weight[i].begin(), weight[i].end()) ;
        reverse(weight[i].begin()+1, weight[i].end()) ;
      }
    for(lli i=0 ; i<weight[1].size() ; i++)
      {
        w1+=weight[1][i] ; w2=w3=w4=0 ;
        for(lli j=0 ; j<weight[2].size() ; j++)
          {
            w2+=weight[2][j] ; w3=w4=0 ;
            for(lli k=0 ; k<weight[3].size() ; k++)
              {
                w3+=weight[3][k] ; w4=0 ;
                for(lli l=0 ; l<weight[4].size() ; l++)
                  {
                    w4+=weight[4][l] ;
                    if(i*ncn[1]+j*ncn[2]+k*ncn[3]+l*ncn[4]<=W)
                      ans=max(ans, w1+w2+w3+w4) ;
                  }
              }
          }
      }
    cout<< ans ;
  }
