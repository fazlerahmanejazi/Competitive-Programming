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

char animal[100005] ;
string s ;

char change(char s1)
  {
    if(s1=='S') return 'W' ;
    else return 'S' ;
  }

int check(char s1, char s2, int length)
  {
  	animal[0]=s1 ;
  	animal[1]=s2 ;
  	s[length]=s[0] ;
  	for(int j=2 ; j<=(length+1) ; j++)
      {
      	if(s[j-1]=='o' && animal[j-1]=='S') animal[j]=animal[j-2] ;
      	else if (s[j-1]=='o'&& animal[j-1]=='W') animal[j]=change(animal[j-2]) ;
      	else if (s[j-1]=='x' && animal[j-1]=='W') animal[j]=animal[j-2] ;
      	else animal[j]=change(animal[j-2]);
      }
  	if(animal[length]==s1 && animal[length+1]==s2) return 1 ;
  	else return 0 ;
  }

int main()
  {
  	ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, len ;
    cin>> n ;
    cin>> s ;
    len=s.length() ;
  	if(check('S', 'S', len))
    	for(int i=0 ; i<len ; i++)
        cout<< animal[i] ;
    else if(check('S', 'W', len))
    	for(int i=0 ; i<len ; i++)
        cout<< animal[i] ;
    else if(check('W', 'S', len))
    	for(int i=0 ; i<len ; i++)
        cout<< animal[i] ;
    else if(check('W', 'W', len))
    	for(int i=0 ; i<len ; i++)
        cout<< animal[i] ;
  	else cout<< -1 ;
  }
