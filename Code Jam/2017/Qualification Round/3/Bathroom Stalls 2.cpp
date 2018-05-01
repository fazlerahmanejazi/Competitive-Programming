#include <bits/stdc++.h>
using namespace std ;

int T ;
long long int n, k, a, b, curr, p, temp, i, x, y ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        map<int, int> cnt ;
        cin>> n >> k ;
        if(n%2==0)
          {
            cnt[n/2]++ ;
            cnt[(n/2)-1]++ ;
            a=n/2 ; b=n/2-1 ;
          }
        else
          {
            cnt[n/2]+=2 ;
            a=b=n/2 ;
          }
        if(k==1)
          {
            if(n%2==0) cout<< "Case #" << tc << ": " << n/2 << " " << n/2-1 << endl ;
            else cout<< "Case #" << tc << ": " << n/2 << " " << n/2 << endl ;
            continue ;
          }
        curr=3 ;
        i=1 ;
        p=1 ;
        while(curr<k)
          {
            i++ ;
            if(a!=b)
              {
                if(a%2==0 && a!=0)
                  {
                    cnt[a/2]+=cnt[a] ;
                    cnt[(a/2)-1]+=cnt[a] ;
                    a=a/2 ;
                  }
                else
                  {
                    cnt[a/2]+=2*cnt[a] ;
                    a=a/2 ;
                  }
                if(b%2==0 && b!=0)
                  {
                    cnt[b/2]+=cnt[b] ;
                    cnt[(b/2)-1]+=cnt[b] ;
                    b=(b/2)-1 ;
                  }
                else
                  {
                    cnt[b/2]+=2*cnt[b] ;
                    b=b/2 ;
                  }
              }
            else
              {
                if(a%2==0 && a!=0)
                  {
                    cnt[a/2]+=cnt[a] ;
                    cnt[(a/2)-1]+=cnt[a] ;
                    a=a/2 ;
                    b=a-1 ;
                  }
                else
                  {
                    cnt[a/2]+=2*cnt[a] ;
                    b=a=a/2 ;
                  }
              }
            p=curr ;
            temp=pow(2, i);
            curr+=temp ;
            x=cnt[a] ; y=cnt[b] ;
          }
        temp=k-p ;
        if(temp<=cnt[a])
          {
            if(a%2==0 && a!=0) cout<< "Case #" << tc << ": " << a/2 << " " << a/2 -1 << endl ;
            else cout<< "Case #" << tc << ": " << a/2 << " " << a/2 << endl ;
          }
        else
          {
            if(b%2==0 && b!=0) cout<< "Case #" << tc << ": " << b/2 << " " << b/2 -1 << endl ;
            else cout<< "Case #" << tc << ": " << b/2 << " " << b/2 << endl ;
          }
      }
  }
