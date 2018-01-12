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

string s ;
int n, x, y, cnt[2] ;

void reconstruct(int t, int c)
  {
    if(!cnt[t]) return ;
    int val=(t?y:x)-c ;
    while(val && cnt[t] && cnt[t]>=cnt[1-t]) s+=(t+'a'), cnt[t]--, val-- ;
    if(cnt[1-t]>1) s+=(1-t+'a'), cnt[1-t]--, reconstruct(1-t, 1) ;
    else if(cnt[1-t]==1) s+=(1-t+'a'), cnt[1-t]--, reconstruct(t, 0) ;
    else if(!cnt[1-t] && cnt[t]) s+='*', reconstruct(t, 0) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> s >> x >> y ;
        n=s.length() ;
        memset(cnt, 0, sizeof cnt) ;
        for(int i=0 ; i<n ; i++) cnt[s[i]-'a']++ ;
        s="" ;
        if(cnt[0]>cnt[1]) reconstruct(0, 0) ;
        else reconstruct(1, 0) ;
        cout<< s << endl ;
      }
  }
