#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int B, n, sum=0 ;
  cin>> B >> n ;
  vector<int> color(n) ;
  for(int i=0 ; i<n ; i++)
    cin>> color[i] ;
  double ans ;
  for(int i=1 ; i<n ; i++)
    sum=sum+color[i] ;
  if(color[0]>=B)
    {
      ans=(1/(double)B)*(((double)sum)/(double)(sum+color[0]-B+1)) ;
      ans=1-ans ;
    }
  else ans=(double)color[0]*(1/(double)B) ;
  if(ans>1) ans=1 ;
  cout<< fixed << setprecision(6) << ans ;
  return 0 ;
}
