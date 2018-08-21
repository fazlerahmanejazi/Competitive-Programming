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

bool pos ;
lli n, idx, curr, len, h1, h2, k1, k2, b1=31, b2=71, l, r, p1[400400], p2[400400], hsh1[400400], hsh2[400400] ;

void hash_init(string s)
  {
    int len=s.length()-1 ;
    for(int i=0 ; i<=len ; i++) hsh1[i]=hsh2[i]=0 ;
    for(int i=1 ; i<=len ; i++)
      {
        hsh1[i]=(hsh1[i-1]+(s[i]-'a'+1)*p1[i])%mod ;
        //cout<< i << " " << hsh1[i] << endl ;
        hsh2[i]=(hsh2[i-1]+(s[i]-'a'+1)*p2[i])%mod ;
        //cout<< i << " " << hsh2[i] << endl ;
      }
  }

lli get_hsh1(int l, int r)
  {
    return ((hsh1[r]-hsh1[l-1]+mod)*p1[len-l])%mod ;
  }

lli get_hsh2(int l, int r)
  {
    return ((hsh2[r]-hsh2[l-1]+mod)*p2[len-l])%mod ;
  }

lli fast_exp(lli base, lli exp)
  {
    lli res=1 ;
    while(exp>0)
      {
        if(exp%2) res=(res*base)%mod ;
        base=(base*base)%mod ;
        exp/=2;
      }
    return res%mod ;
  }

lli findLCM(vlli &t)
  {
    map<lli, lli> cnt ;
    for(int i=0 ; i<t.size() ; i++)
      {
        for(lli j=2 ; j<=sqrt(t[i]) ; j++)
          if(t[i]%j==0)
            {
              lli curr=0 ;
              while(t[i]%j==0) t[i]/=j, curr++ ;
              cnt[j]=max(cnt[j], curr) ;
            }
        cnt[t[i]]=max(cnt[t[i]], 1LL) ;
      }
    lli ans=1 ;
    for(auto i:cnt) ans=(ans*fast_exp(i.fi, i.se))%mod ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    p1[0]=p2[0]=1 ;
    for(int i=1 ; i<400400 ; i++) p1[i]=(p1[i-1]*b1)%mod ;
    for(int i=1 ; i<400400 ; i++) p2[i]=(p2[i-1]*b2)%mod ;
    cin>> n ;
    vlli b, t(n) ;
    b.pb(1) ;
    idx=2 ;
    for(lli i=2 ; i<=100000 ; i++) b.pb((i*(i+1))/2) ;
    vector<string> a(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i], a[i]+=a[i] ;
    for(int i=0 ; i<n ; i++)
      {
        len=a[i].size() ;
        a[i]='#'+a[i] ;
        hash_init(a[i]) ;
        idx=0 ;
        pos=true ;
        while(pos)
          {
            curr=b[idx]%(len/2) ;
            l=(len/2)-curr+1 ; r=len-curr  ;
            h1=get_hsh1(l, r) ;
            h2=get_hsh2(l, r) ;
            k1=get_hsh1(1, (len/2)) ;
            k2=get_hsh2(1, (len/2)) ;
            if(h1==k1 && h2==k2)
              {
                t[i]=idx+1 ;
                pos=false ;
                break ;
              }
            idx++ ;
          }
      }
    //for(int i=0 ; i<n ; i++) cout<< t[i] <<  " " ;
    cout<< findLCM(t) ;
}
