#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    int tc ;
    cin>> tc ;
    while(tc--)
      {
        lli n, x, ans, y=0, sum=0, cnt=0, idx ;
        cin>> n ;
        vlli pos, neg ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> x ;
            if(x<0) neg.pb(x) ;
            else
              {
                sum+=x ;
                cnt++ ;
              }
          }
        ans=sum*cnt ;
        sort(neg.begin(), neg.end()) ;
        reverse(neg.begin(), neg.end()) ;
        idx=0 ;
        while(idx<neg.size())
          {
            x=neg[idx]*(cnt+1)+sum ;
            if(x>=0)
              {
                sum+=neg[idx] ;
                ans+=x ;
                cnt++ ;
                idx++ ;
              }
            else break ;
          }
        for(int i=idx ; i<neg.size() ; i++)
          ans+=neg[i] ;
        cout<< ans << endl ;
      }
  }
