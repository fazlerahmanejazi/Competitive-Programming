#include<iostream>
#include<string>

using namespace std ;

using namespace std ;

int main()
{  string s ;
cin>> s ;
int n = s.length() ;

for(int i=0 ; i<n ; i++)
 { s[i]=tolower(s[i]) ;
 }
  
for(int i=0 ; i<n ; i++)
  {
  if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||s[i]=='y'|| s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'||s[i]=='Y')
  continue;
  
  cout<< "." << s[i] ;
}
return 0 ;
}
