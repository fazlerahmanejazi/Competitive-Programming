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

vector<string> s ;

int one()
  {
    int c=0 ;
    for(int i=0 ; i<3 ; i++)
      for(int j=0 ; j<3 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ;
  }

int two()
  {
    int c=0 ;
    for(int i=0 ; i<3 ; i++)
      for(int j=4 ; j<7 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int three()
  {
    int c=0 ;
    for(int i=0 ; i<3 ; i++)
      for(int j=8 ; j<11 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int four()
  {
    int c=0 ;
    for(int i=3 ; i<6 ; i++)
      for(int j=0 ; j<3 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int five()
  {
    int c=0 ;
    for(int i=3 ; i<6 ; i++)
      for(int j=4 ; j<7 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int six()
  {
    int c=0 ;
    for(int i=3 ; i<6 ; i++)
      for(int j=8 ; j<11 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int seven()
  {
    int c=0 ;
    for(int i=6 ; i<9 ; i++)
      for(int j=0 ; j<3 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int eigth()
  {
    int c=0 ;
    for(int i=6 ; i<9 ; i++)
      for(int j=4 ; j<7 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int nine()
  {
    int c=0 ;
    for(int i=6 ; i<9 ; i++)
      for(int j=8 ; j<11 ; j++)
        if(s[i][j]=='.') s[i][j]='!', c++ ;
    return c ; ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int x, y, z ;
    char c ;
    string r ;
    vector<string> w ;
    for(int i=1 ; i<=11 ; i++)
      {
        getline(cin, r) ;
        if(r!="") w.pb(r) ;
      }
    s=w ;
    cin>> x >> y ;
    while(x>3) x-=3 ;
    while(y>3) y-=3 ;
    if(x==1 && y==1) z=one() ;
    if(x==1 && y==2) z=two() ;
    if(x==1 && y==3) z=three() ;
    if(x==2 && y==1) z=four() ;
    if(x==2 && y==2) z=five() ;
    if(x==2 && y==3) z=six() ;
    if(x==3 && y==1) z=seven() ;
    if(x==3 && y==2) z=eigth() ;
    if(x==3 && y==3) z=nine() ;
    if(!z)
      {
        one() ; two() ; three() ;
        four() ; five() ; six() ;
        seven() ; eigth() ; nine() ;
      }
    for(int i=0 ; i<9 ; i++)
      {
        cout<< s[i] << endl ;
        if(i==2 || i==5) cout<< endl ;
      }
  }
