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

lli k, x, n, m, x1, x2, x1Min, x2Min, x1Max, x2Max ;
string s1, s2 ;

lli getMin(lli n, lli t)
  {
    if(t==1) return 1 ;
    else return 0 ;
  }

lli getMax(lli n, lli t)
  {
    if(t==3) return (n-2)/2 ;
    else return n/2 ;
  }

string getString(lli t)
  {
    if(t==1) return "AC" ;
    else if(t==2) return "AA" ;
    else if(t==3) return "CA" ;
    else return "CC" ;
  }

string reconstruct(lli p, lli t, lli l)
  {
    string res="" ;
    lli x ;
    if(t==1)
      {
        for(int i=1 ; i<=l ; i++) res+="AC" ;
        x=p-res.length() ;
        while(x--) res+='C' ;
        return res ;
      }
    else if(t==2)
      {
        for(int i=1 ; i<=l ; i++) res+="AC" ;
        x=p-res.length() ;
        while(x--) res+='A' ;
        return res ;
      }
    else if(t==3)
      {
        res+='C' ;
        for(int i=1 ; i<=l ; i++) res+="AC" ;
        x=p-res.length() ;
        while(x--) res+='A' ;
        return res ;
      }
    else
      {
        res+='C' ;
        for(int i=1 ; i<=l ; i++) res+="AC" ;
        x=p-res.length() ;
        while(x--) res+='C' ;
        return res ;
      }
  }

bool solve(string s1, string s2)
  {
    string temp ;
    lli curr ;
    for(int i=3 ; i<=k ; i++)
      {
        temp=s1[0]+s2[1] ;
        curr=x1+x2+(s1[1]=='A' && s2[0]=='C') ;
        s1=s2 ; x1=x2 ;
        s2=temp ; x2=curr ;
      }
    return x2==x ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> k >> x >> n >> m ;
    for(int i=1 ; i<=4 ; i++)
      {
        s1=getString(i) ;
        tie(x1Min, x1Max)=mp(getMin(n, i), getMax(n, i)) ;
        if(n==1) s1=(s1[0]+s1[0]), x1Min=x1Max=0 ;
        for(int j=1 ; j<=4 ; j++)
          {
            s2=getString(j) ;
            tie(x2Min, x2Max)=mp(getMin(m, j), getMax(m, j)) ;
            if(m==1) s2=(s2[0]+s2[0]), x2Min=x2Max=0 ;
            for(int l1=x1Min ; l1<=x1Max ; l1++)
              for(int l2=x2Min ; l2<=x2Max ; l2++)
                {
                  tie(x1, x2)=mp(l1, l2) ;
                  if(solve(s1, s2))
                    {
                      s1=reconstruct(n, i, l1) ;
                      s2=reconstruct(m, j, l2) ;
                      if(n!=1) cout<< s1 << endl ;
                      else cout<< s1[0] << endl ;
                      if(m!=1) cout<< s2 ;
                      else cout<< s2[0] << endl ;
                      return 0 ;
                    }
                }
          }
      }
    cout<< "Happy new year!" ;
  }
