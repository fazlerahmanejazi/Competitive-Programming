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

int x, y ;
vi a(26), b ;

bool check()
  {
    int col ;
    for(int i=1 ; i<=24; i+4)
      {
        col=b[i] ;
        for(int j=i ; j<=i+3 ; j++)
          if(b[j]!=col) return false ;
      }
    return true ;
  }

bool check1()
  {
    bool pos=false ;
    if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3] && a[8]==a[9] && a[9]==a[10] && a[10]==a[11])
      {
        if(a[20]==a[21] && a[18]==a[20] && a[18]==a[19] && a[6]==a[7] && a[7]==a[16] && a[16]==a[17] && a[4]==a[5] && a[5]==a[14] && a[14]==a[15] && a[12]==a[13] && a[13]==a[22] && a[22]==a[23])
          pos=true ;
        else if (a[12]==a[13] && a[13]==a[6] && a[6]==a[7] && a[4]==a[5] && a[5]==a[18] && a[18]==a[19] && a[16]==a[17] && a[17]==a[22] && a[22]==a[23] && a[14]==a[15] && a[15]==a[20] && a[20]==a[21])
          pos=true ;
      }
    return pos ;
  }

bool check2()
  {
    bool pos=false ;
    if(a[12]==a[13] && a[13]==a[14] && a[14]==a[15] && a[16]==a[17] && a[17]==a[18] && a[18]==a[19])
      {
      if(a[0]==a[2] && a[2]==a[5] && a[5]==a[7] && a[4]==a[6] && a[6]==a[9] && a[9]==a[11] && a[8]==a[10] && a[10]==a[20] && a[20]==a[22] && a[21]==a[23] && a[23]==a[1] && a[1]==a[3])
        pos=true ;
      else if (a[1]==a[3] && a[3]==a[4] && a[4]==a[6] && a[5]==a[7] && a[7]==a[8] && a[8]==a[10] && a[9]==a[11] && a[11]==a[20] && a[20]==a[22] && a[21]==a[23] && a[23]==a[0] && a[0]==a[2])
        pos=true ;
      }
    return pos ;
  }

bool check3()
  {
    bool pos=false ;
    if(a[4]==a[5] && a[5]==a[6] && a[6]==a[7] && a[20]==a[21] && a[21]==a[22] && a[22]==a[23])
      {
      if(a[13]==a[15] && a[15]==a[10] && a[10]==a[11] && a[8]==a[9] && a[9]==a[17] && a[17]==a[19] && a[16]==a[18] && a[18]==a[0] && a[0]==a[1] && a[2]==a[3] && a[3]==a[12] && a[12]==a[14])
        pos=true ;
      else if(a[13]==a[15] && a[15]==a[0] && a[0]==a[1] && a[2]==a[3] && a[3]==a[17] && a[17]==a[19] && a[16]==a[18] && a[18]==a[10] && a[10]==a[11] && a[8]==a[9] && a[9]==a[12] && a[12]==a[14])
        pos=true ;
      }
    return pos ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    for(int i=0 ; i<24 ; i++) cin>> a[i] ;
    if(check3() || check2() || check1()) cout<< "YES" ;
    else cout<< "NO" ;
    return 0;
 }
