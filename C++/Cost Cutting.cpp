#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std ;

int main()
{  long long int s[3] ;
   int n ;
   cin>> n ;
   for(int i=0 ; i<n ; i++)
   {
     cin>> s[0] >> s[1] >> s[2] ;
     s[4]=s[0] ;
     sort(s,s+3) ;
     cout<< "Case" << " " << i+1 << ":" <<  " " << s[1] << endl ;
   }
   return 0 ;
 }
   
