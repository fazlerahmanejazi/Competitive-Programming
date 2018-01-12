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
    string good, s, x, left="", right="" ;
    int n, idx, l, r, temp ;
    vb check(27, false) ;
    bool possible, star=false ;
    cin>> good >> s ;
    idx=s.length() ;
    for(int i=0 ; i<s.length() ; i++)
      if(s[i]!='*')
        left+=s[i] ;
      else
        {
          idx=i+1 ;
          star=true ;
          break ;
        }
    for(int i=idx ; i<s.length() ; i++)
      if(s[i]!='*')
        right+=s[i] ;
    for(int i=0 ; i<good.length() ; i++)
      if(good[i]!='?' && good[i]!='*')
        check[good[i]-'a']=true ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        possible=true ;
        l=0 ; r=x.length()-1 ;
        if(right.length()==0 && x.length()>left.length() && !star) possible=false ;
        else if(x.length()<left.length()+right.length()) possible=false ;
        else
          {
            for(int j=0 ; j<left.length() ; j++)
              {
                if(left[j]!=x[j])
                  {
                    if(left[j]=='?' && !check[x[j]-'a']) possible=false ;
                    else if(left[j]>='a' && left[j]<='z') possible=false ;
                  }
                l++ ;
              }
            temp=right.length()-1 ;
            for(int j=x.length()-1 ; j>=0 && temp>=0 ; j--)
              {
                if(right[temp]!=x[j])
                  {
                    if(right[temp]=='?' && !check[x[j]-'a']) possible=false ;
                    else if(right[temp]>='a' && right[temp]<='z') possible=false ;
                  }
                temp-- ;
                r-- ;
              }
            for(int j=l ; j<=r ; j++)
              if(check[x[j]-'a'])
                possible=false ;
          }
        if(possible) cout<< "YES" << endl ;
        else cout<< "NO" << endl ;
      }
    }
