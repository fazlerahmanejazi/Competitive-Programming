lli n, q, l, r, curr, idx, pos, len, x, y ;
cin>> n >> q ;
vlli a(n+1), b(q+1), pge(n+1), nge(n+1), temp, sum ;
map<lli, lli> done ;
map<lli, lli> cnt, B ;
for(int i=1 ; i<=n ; i++) cin>> a[i] ;
nextGreater(a, nge, n) ;
prevGreater(a, pge, n) ;
l=1 ;
/*while(l<=n)
  {
    r=l ;
    while(r+1<=n && a[l]==a[r+1]) r++ ;
    len=r-l+1 ;
    x=pge[l]+1 ; y=nge[l]-1 ;
    cnt[a[l]]+=(l-x+1)*(y-l+1) ;
    cnt[a[l]]+=len-1 ;
    l=r+1 ;
  }*/
for(int i=1 ; i<=n ; i++)
  {
    x=pge[i]+1 ; y=nge[i]-1 ;
    if(done[a[i]]) x=max(done[a[i]]+1, x) ;
    cnt[a[i]]+=(i-x+1)*(y-i+1) ;
    done[a[i]]=i ;
  }
for(auto i:cnt)
  {
    curr=1 ;
    for(int j=1 ; j<=sqrt(i.fi) ; j++)
      if(j*j==i.fi) curr=(curr*j)%mod ;
      else if(!(i.fi%j)) curr=(curr*j)%mod, curr=(curr*(i.fi/j))%mod ;
    B[curr]+=i.se ;
  }
//for(auto i:B) cout<< i.fi << " " << i.se << endl ;
for(int i=1 ; i<=q ; i++) cin>> b[i] ;
for(auto i:B) temp.pb(i.fi) ;
reverse(all(temp)) ;
for(auto i:temp) sum.pb(B[i]) ;
for(int i=1 ; i<sum.size() ; i++) sum[i]+=sum[i-1] ;
for(int i=1 ; i<=q ; i++)
  {
    idx=lower_bound(all(sum), b[i])-sum.begin() ;
    cout<< temp[idx] << endl ;
  }
