#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  int n, a, b ;
  cin>> n ;
  vector<pair<int, int> > date(n);
  for(int i=0 ; i<n ; i++)
    {
      cin>> a >> b ;
      date[i]=make_pair(a,b) ;
    }
  sort(date.begin(), date.end()) ;
  a=-1 ;
  for(int i=0 ; i<n ; i++)
  	{
  		if(date[i].second>=a) a=date[i].second ;
  		else a=date[i].first ;
  	}
  cout<< a ;
  return 0 ;
}
