#include <bits/stdc++.h>
using namespace std ;

#define x first
#define y second

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int T, n, temp, p, q ;
    bool valid ;
    cin>> T ;
    while(T--)
      {
        pair<int, int> aS, aE, bS, bE ;
        char a, b ;
        cin>> aS.x >> aS.y >> aE.x >> aE.y ;
        cin>> bS.x >> bS.y >> bE.x >> bE.y ;
        if(aS.x==aE.x) a='y' ;
        else a='x' ;
        if(bS.x==bE.x) b='y' ;
        else b='x' ;
        valid=false ;
        if(aS!=aE && bS!=bE)
          {
            if(a=='x' && b=='x' && aS.y==bS.y)
              {
                p=min({aS.x, aE.x, bS.x, bE.x}) ;
                q=max({aS.x, aE.x, bS.x, bE.x}) ;
                temp=abs(p-q) ;
                if(temp<abs(aE.x-aS.x)+abs(bE.x-bS.x)) valid=true ;
              }
            else if(a=='y' && b=='y' && aS.x==bS.x)
              {
                p=min({aS.y, aE.y, bS.y, bE.y}) ;
                q=max({aS.y, aE.y, bS.y, bE.y}) ;
                temp=abs(p-q) ;
                if(temp<abs(aE.y-aS.y)+abs(bE.y-bS.y)) valid=true ;
              }
            else if(a!=b)
              {
                if(aS==bS || aS==bE || aE==bS || aE==bE) valid=true ;
              }
          }
        else if(bE==bS && aE==aS && aE==bS) valid=true ;
        else if(aE==aS)
          {
            if(b=='x' && aS.y==bS.y && aS.x<=max(bS.x, bE.x) && aS.x>=min(bS.x, bE.x)) valid=true ;
            else if(b=='y' && aS.x==bS.x && aS.y<=max(bS.y, bE.y) && aS.y>=min(bS.y, bE.y)) valid=true ;
          }
        else if(bE==bS)
          {
            if(a=='x' && bS.y==aS.y && bS.x<=max(aS.x, aE.x) && bS.x>=min(aS.x, aE.x)) valid=true ;
            else if(a=='y' && bS.x==aS.x && bS.y<=max(aS.y, aE.y) && bS.y>=min(aS.y, aE.y)) valid=true ;
          }
        cout<< ((valid)? "yes" : "no") << endl;
      }
  }
