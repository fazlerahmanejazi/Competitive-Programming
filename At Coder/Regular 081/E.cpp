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

int n, last, len=inf ;
string s, ans ;
int cnt[27][200010] ;
vvi pos(26) ;
//int Next[200010] ;

void form(string curr, int l)
  {
    if(curr.length()>len) return ;
    int c=inf, idx ;
    priority_queue<pair<int, int>> pq ;
    for(int i=0 ; i<26 ; i++)
      {
        idx=i ; c=cnt[i][n]-cnt[i][l-1] ;
        pq.push(mp(-c, idx)) ;
      }
    while(!pq.empty())
      {
        tie(c, idx)=pq.top() ; pq.pop() ;
        c=-c ;
        string temp=curr ;
        temp+=('a'+idx) ;
        auto nxt=upper_bound(all(pos[idx]), l) ;
        if(nxt==pos[idx].end() && c==0)
          {
            if(temp.length()<len)
              {
                ans=temp ;
                len=ans.length() ;
              }
            else if(temp.length()==len && temp<ans)
              {
                ans=temp ;
                len=ans.length() ;
              }
          }
        else if(nxt==pos[idx].end())
          {
            temp+=(idx+'a') ;
            if(temp.length()<len)
              {
                ans=temp ;
                len=ans.length() ;
              }
            else if(temp.length()==len && temp<ans)
              {
                ans=temp ;
                len=ans.length() ;
              }
          }
        else form(temp, *nxt) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    s='#'+s ;
    ans=s ;
    n=s.length() ;
    memset(cnt, 0, sizeof cnt) ;
    //memset(next, 0, sizeof next) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=0 ; j<26 ; j++)
        if(s[i]==j+'a') cnt[j][i]=cnt[j][i-1]+1 ;
        else cnt[j][i]=cnt[j][i-1] ;
    for(int i=0 ; i<26 ; i++)
      {
        last=0 ;
        for(int j=1 ; j<=n ; j++)
          if(s[j]==i+'a')
            {
              //next[last]=j ;
              //last=j ;
              pos[i].pb(j) ;
            }
      }
    form("", 1) ;
    cout<< ans ;
  }
