#include <bits/stdc++.h>
using namespace std ;


int main()
{
  ios_base::sync_with_stdio (false) ;
  string s, temp ;
  int r=0, b=0, y=0 , g=0 ;
  cin>> s ;
  temp=s ;
  for(int i=0 ; i<s.length()-4 ; i++)
    if(temp[i]=='!') temp[i]=temp[i+4] ;
  for(int i=s.length()-1 ; i>=4 ; i--)
    if(temp[i]=='!') temp[i]=temp[i-4] ;
  for(int i=s.length()-5 ; i>=0 ; i--)
    if(temp[i]=='!') temp[i]=temp[i+4] ;
  for(int i=4 ; i<s.length() ; i++)
    if(temp[i]=='!') temp[i]=temp[i-4] ;
  for(int i=0 ; i<s.length()-4 ; i++)
    if(temp[i]=='!') temp[i]=temp[i+4] ;
  for(int i=s.length()-1 ; i>=4 ; i--)
    if(temp[i]=='!') temp[i]=temp[i-4] ;

  for(int i=0 ; i<s.length() ; i++)
    {
      if(s[i]=='!')
      {
        if(temp[i]=='R') r++ ;
        else if(temp[i]=='B') b++ ;
        else if(temp[i]=='Y') y++ ;
        else if(temp[i]=='G') g++ ;
      }
    }
   cout<< r << " " << b << " " << y << " " << g ;
   return 0 ;
 }
