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

int get(char c)
  {
    if(c=='d' || c=='f') return 0 ;
    else return 1 ;
  }

int calc(string s)
  {
    int res=2 ;
    for(int i=1 ; i<s.length() ; i++)
      if(get(s[i])!=get(s[i-1])) res+=2 ;
      else res+=4 ;
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, ans=0, curr ;
        map<string, bool> used ;
        string s ;
        cin>> n ;
        while(n-- && cin>> s)
          {
            curr=calc(s) ;
            if(used[s]) curr/=2 ;
            ans+=curr ;
            used[s]=true ;
          }
        cout<< ans << endl ;
      }
  }
