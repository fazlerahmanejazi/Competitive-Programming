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

string s, r ;
vi cnt(27, 0), start, check ;
int maxm=0, x, curr, ans ;

int count(string temp)
  {
    int res=0, idx ;
    for(int j=0 ; j<start.size() ; j++)
      {
        bool c=true ;
        idx=start[j] ;
        for(int i=idx ; i<temp.length()+idx ; i++)
          if(temp[i-idx]!=s[i])
            c=false ;
        if(c) res++ ;
        else return res ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    for(int i=0 ; i<s.length() ; i++)
      {
        cnt[s[i]-'a']++ ;
        maxm=max(maxm, cnt[s[i]-'a']) ;
      }
    for(int i=0 ; i<26 ; i++)
      if(cnt[i]==maxm)
        check.pb(i) ;
    r="" ;
    x=check[0] ;
    char buf=x+'a' ;
    r+=buf ;
    for(int k=0 ; k<check.size() ; k++)
      {
        x=check[k] ;
        start.clear() ;
        for(int i=0 ; i<s.length() ; i++)
          if(s[i]-'a'==x)
            start.pb(i) ;
        for(int i=0 ; i<s.length() ; i++)
          if(s[i]-'a'==x)
            {
              string temp="" ;
              char buf=x+'a' ;
              temp+=buf ;
              int end=s.length() ;
              if(start.size()>1) end=start[1] ;
              for(int j=i+1 ; j<end ; j++)
                {
                  temp+=s[j] ;
                  if(s.length()-temp.length()+1<maxm) break ;
                  curr=count(temp) ;
                  if(curr==maxm && temp.length()>r.length()) r=temp ;
                }
              break ;
            }
      }
    cout<< r ;
  }
