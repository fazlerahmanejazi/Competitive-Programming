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

#define sz(x) ((lli)(x).size())

lli n, k, q, len[100005] ;
string s0="What are you doing at the end of the world? Are you busy? Will you save us?" ;
string s1="What are you doing while sending \"" ;
string s2="\"? Are you busy? Will you send \"" ;
string s3="\"?" ;

char solve(lli n, lli k)
  {
    if (k>=len[n]) return '.' ;
    else if (!n) return s0[k] ;
    else if (k<sz(s1)) return s1[k] ;
    else if (k<sz(s1)+len[n-1]) return solve(n-1, k-sz(s1)) ;
    else if (k<sz(s1)+len[n-1]+sz(s2)) return s2[k-len[n-1]-sz(s1)] ;
    else if (k<sz(s1)+len[n-1]+sz(s2)+len[n-1]) return solve(n-1, k-sz(s2)-len[n-1]-sz(s1)) ;
    else return s3[k-len[n-1]-sz(s2)-len[n-1]-sz(s1)] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    len[0]=sz(s0) ;
    for(int i=1 ; i<=100000 ; i++) len[i]=min(len[i-1]*2+sz(s1)+sz(s2)+sz(s3), INF) ;
    cin>> q ;
    while(q-- && cin>> n >> k ) cout<< solve(n, k-1) ;
  }
