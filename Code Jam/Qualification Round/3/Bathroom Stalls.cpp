#include <bits/stdc++.h>
using namespace std ;

int T ;
long long int n, k, curr, temp ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        priority_queue<long long int> pq ;
        cin>> n >> k ;
        pq.push(n) ;
        for(int i=1 ; i<k ; i++)
          {
            curr=pq.top() ;
            pq.pop() ;
            if(curr%2==0)
              {
                temp=curr/2 ;
                pq.push(temp) ;
                pq.push(temp-1) ;
              }
            else
              {
                temp=curr/2 ;
                pq.push(temp) ;
                pq.push(temp) ;
              }
          }
        curr=pq.top() ;
        if(curr%2==0)
          {
            temp=curr/2 ;
            cout<< "Case #" << tc << ": " << temp << " " << temp-1 << endl ;
          }
        else
          {
            temp=curr/2 ;
            cout<< "Case #" << tc << ": " << temp << " " << temp << endl ;
          }
      }
  }
