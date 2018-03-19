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
    int a, b, l, r, len, x, range, ans=0 ;
    cin>> a >> b >> l >> r ;
    set<string> B ;
    string s="" ;
    char c ;
    for(int i=0 ; i<a ; i++)
      {
        c='a'+i ;
        s+=c ;
      }
    len=a ;
    while(1)
      {
        c=s[len-1] ;
        s.append(a, c) ;
        len+=a ;
        vb taken(26, false) ;
        taken[c-'a']=true ;
        for(int i=len-a-1 ; i>=max(len-b, 0) ; i--)
          taken[s[i]-'a']=true ;
        x=b ;
        string temp="" ;
        for(int i=0 ; i<26, x>0 ; i++)
          {
            c='a'+i ;
            if(!taken[i])
              {
                temp+=c ;
                x-- ;
              }
          }
        if(B.find(temp)!=B.end()) break ;
        s+=temp ;
        B.insert(temp) ;
        len+=b ;
      }
    s+=s ;
    if(r-l>=len) r=l+len-1 ;
    /*range=r-l ;
    if(l>len)
      {
        l=len+l%len ;
        r=r%len ;
        if(r==0)
      }*/
    while(l>len)
      {
        l-=len ;
        r-=len ;
      }
    vb taken(26, false) ;
    for(int i=l-1 ; i<r ; i++)
      taken[s[i]-'a']=true ;
    for(int i=0 ; i<26 ; i++)
      if(taken[i]) ans++ ;
    cout<< ans ;
  }
