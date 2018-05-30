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

string fractionToDecimal(int A, int B) {
    long long int a=A, b=B ;
    int neg=0 ;
    if((a<0 && b>0) || (a>0 && b<0)) neg=1 ;
    a=abs(a) ; b=abs(b) ;
    long long int p=a/b, rem ;
    string ans="", temp="" ;
    if(neg) ans+='-' ;
    ans+=to_string(p) ;
    map<long long int, int> hash ;
    rem=a%b ;
    while(rem && hash.find(rem)==hash.end())
        {
            hash[rem]=temp.length() ;
            rem*=10 ;
            temp+=to_string(rem/b) ;
            rem%=b ;
        }
    if(rem)
        {
            ans+='.' ;
            for(int i=0 ; i<hash[rem] ; i++) ans+=temp[i] ;
            ans+='(' ;
            for(int i=hash[rem] ; i<temp.length() ; i++) ans+=temp[i] ;
            ans+=')' ;
            return ans ;
        }
    if(temp!="") ans=ans+'.'+temp ;
    return ans ;
}


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int a, b ;
    cin>> a >> b ;
    cout<< fractionToDecimal(a, b) << endl ;
  }
