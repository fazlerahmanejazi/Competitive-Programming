#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, x, ans=0, nxt ;
    cin>> n ;
    priority_queue<int> boxes ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        boxes.push(-x) ;
      }
    while(1)
      {
        x=-boxes.top() ; boxes.pop() ;
        ans+=x/2 ;
        x-=x/2 ;
        if(boxes.empty()) break ;
        nxt=-boxes.top() ; boxes.pop() ;
        if(nxt+x<=1000) boxes.push(-(nxt+x)) ;
      }
    ans+=x ;
    cout<< ans ;
  }
