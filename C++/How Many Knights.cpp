#include <bits/stdc++.h>
using namespace std ;
int main()
{float n, m, K ;
int M ;
 while(cin>> n >> m && (n!=0 || m!=0))
 {
   if(m==0 || n==0) K=0 ;
   else if(m==1 || n==1) K=max(m,n) ;
   else if((m==2 && n==3) || (n==2 && m==3)) K=4 ;
   else if(m==2 && n==2) K=4 ;
   else if((m==2 && n>=4) || (m>=4 && n==2))
   { if(max((int)m,(int)n)%2==0)
     {
       M=max(m,n) ;
       if((M/2)%2!=0) K= M+2 ;
       else K=M ;
     }
     else K=max(m,n)+1 ;  }
   else if(m==3 && n==3) K=5 ;
   else K=ceil((m*n)/2) ;
   cout<< K<<" knights may be placed on a "<<n<<" row "<<m<<" column board." << endl ;
 }
 return 0 ;
}
