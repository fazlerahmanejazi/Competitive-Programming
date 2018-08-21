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
    string s, ans ;
    char x ;
    cin>> s ;
    map<int, int> cnt ;
    ans="" ;
    stack<char> st ;
    int len=s.length(), l, r ;
    for(int i=0 ; i<len ; i++)
      cnt[s[i]-'a']++ ;
    l=r=0 ;
    for(int i=0 ; i<len ; i++)
      {
        st.push(s[i]) ;
        cnt[s[i]-'a']-- ;
        while(!st.empty())
          {
            x=st.top() ;
            bool check=true ;
            for(int j=x-'a'-1 ; j>=0 ; j--)
              if(cnt[j])
                check=false ;
            if(check)
              {
                st.pop() ;
                ans+=x ;
              }
            else break ;
          }
      }
    while(!st.empty())
      {
        x=st.top() ;
        st.pop() ;
        ans+=x ;
      }
    cout<< ans ;
  }
