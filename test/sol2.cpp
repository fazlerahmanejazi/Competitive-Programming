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

string a, b ;
string temp ;

char get(char c)
  {
    int idx ;
    char mx='.' ;
    for(int i=0 ; i<temp.length() ; i++)
      if(temp[i]!='.' && temp[i]<=c)
        {
          if(mx=='.') mx=temp[i], idx=i ;
          else if(temp[i]>mx) mx=temp[i], idx=i ;
        }
    return idx ;
  }

bool check(int idx, int ign)
  {
    string p="", q="" ;
    for(int i=0 ; i<temp.length() ; i++) if(temp[i]!='.' && i!=ign) p+=temp[i] ;
    for(int i=idx ; i<b.length() ; i++) q+=b[i] ;
    sort(all(p)) ;
    if(p<=q) return true ;
    else return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    while(cin>> a >> b)
      {
        temp=a ;
        if(a.length()<b.length())
          {
            sort(all(a)) ;
            reverse(all(a)) ;
            cout<< a ;
          }
        else
          {
            string ans="", r="", xx ;
            for(int i=0 ; i<b.length() ; i++)
              {
                int pos=get(b[i]), m=0 ;
                char c=temp[pos] ;
                if(check(i+1, pos)) ans+=c ;
                else
                  {
                    pos=get(b[i]-1) ;
                    c=temp[pos] ;
                    ans+=c ;
                    m=1 ;
                  }
                temp[pos]='.' ;
                xx=temp ;
                if(c<b[i] || m) break ;
              }
            xx=temp ;
            for(int i=0 ; i<temp.length() ; i++) if(temp[i]!='.') r+=temp[i] ;
            if(r!="")
              {
                sort(all(r)) ;
                reverse(all(r)) ;
                ans+=r ;
              }
            cout<< ans << endl ;
          }
      }
  }
