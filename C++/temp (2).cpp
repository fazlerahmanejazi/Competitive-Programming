#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int m, s, sum, pos ;
  cin>> m >> sum ;
  vector<int> num_min(m, 0) ;
  vector<int> num_max(m, 0) ;
  if(m*9<sum || (sum==0 && m!=1))
  {
    cout<< "-1 -1" ;
    return 0 ;
  }
  pos=m-1 ;
  s=sum ;
  while(pos>=0)
  {
    if(s>9)
    {
      s=s-9 ;
      num_min[pos]+=9 ;
      pos-- ;
    }
    else
    {
      s=s-1 ;
      num_min[0]+=1 ;
      num_min[pos]+=s ;
      pos-- ;
      break ;
    }
  }
  pos=0 ;
  s=sum ;
  while(pos<m)
  {
    if(s>9)
    {
      num_max[pos]=9 ;
      s=s-9 ;
      pos++ ;
    }
    else
    {
      num_max[pos]=s ;
      s=0 ;
      pos++ ;
      break ;
    }
  }

  for(int i=0 ; i<m ; i++)
   cout<< num_min[i] ;
  cout<< " " ;
  for(int i=0 ; i<m ; i++)
   cout<< num_max[i] ;
return 0;
}
