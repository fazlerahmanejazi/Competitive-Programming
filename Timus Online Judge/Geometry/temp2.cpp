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
using pii = pair<lli, lli> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<lli, lli>> ;

int numCPUCycles(int n, int d, int c1, int c2) {
    long long int ans=0, x ;
    while(n>1)
    {
        if(n%d)
        {
            x=n%d ;
            n-=x ;
            ans+=c1*x ;
        }
        while(!(n%d) && (n-n/d)*c1>=c2)
        {
            n/=d ;
            ans+=c2 ;
        }
    }
    return ans ;

}


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, d, c1, c2 ;
    cin>> n >> d >> c1 >> c2 ;
    cout<< numCPUCycles(n, d, c1, c2) ;
  }
