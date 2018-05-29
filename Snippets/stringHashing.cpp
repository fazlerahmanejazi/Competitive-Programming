lli n, b=31, p2[400400], hsh[400400], hsh2[400400] ;
string s, r ;

void hash_init()
  {
    p2[0]=1 ;
    for(int i=1 ; i<400400 ; i++) p2[i]=(p2[i-1]*b)%mod ;
    for(int i=1 ; i<=n ; i++)
      {
        hsh[i]=(hsh[i-1]+(s[i]-'a')*p2[i])%mod ;
        hsh2[i]=(hsh2[i-1]+(r[i]-'a')*p2[i])%mod ;
      }
  }

lli get_hsh(int l, int r)
  {
    return ((hsh[r]-hsh[l-1]+mod)*p2[n-l])%mod ;
  }

lli get_hsh2(int l, int r)
  {
    return ((hsh2[r]-hsh2[l-1]+mod)*p2[n-l])%mod ;
  }

bool is_pal(int l,int r)
  {
    return get_hsh(l, r)==get_hsh2(n-r+1, n-l+1) ;
  }
