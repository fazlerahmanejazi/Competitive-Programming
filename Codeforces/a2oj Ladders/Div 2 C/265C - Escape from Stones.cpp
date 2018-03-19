#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string s ;
    cin>> s ;
    list<int> ans ;
    list<int>::iterator it ;
    int n=2 ;
    ans.push_back(1) ;
    it=ans.begin() ;
    for(int i=0 ; i<s.length()-1 ; i++)
      {
        if(s[i]=='l') it=ans.insert(it, n++) ;
        else it=ans.insert(++it, n++) ;
      }
    it=ans.begin() ;
    while(it!=ans.end())
      {
        cout<< *it << '\n' ;
        it++ ;
      }
  }
