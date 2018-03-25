#include <bits/stdc++.h>
using namespace std ;

#define ll long long int
int main()
{
string s ;
map<char, int> c ;
cin>> s ;
for(int i=0 ; i<s.length() ; i++) c[s[i]]++ ;
if(c.size()>4) cout<< "YES" ;
else if(c.size()==1) cout<< "NO" ;
else
{
int x=0 ;
for(auto i:c)
if(i.second==1)
x++ ;
if(c.size()==2 && x>0)
{
cout<< "NO" ;
return 0 ;
}
else if(c.size()==3 && x>=3)
{
cout<< "NO" ;
return 0 ;
}
cout<< "YES" ;
}
}
