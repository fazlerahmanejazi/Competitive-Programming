#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n, m, x ;
    vector<int> p, a, b, buyer ;
    priority_queue<int, vector<int>, greater<int>> one, two, three ;
    map<int, bool> avail ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        p.push_back(x) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        a.push_back(x) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        b.push_back(x) ;
      }
    cin>> m ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> x ;
        buyer.push_back(x) ;
      }
    for(int i=0 ; i<n ; i++)
      {
        avail[p[i]]=true ;
        if(a[i]==1) one.push(p[i]) ;
        else if(a[i]==2) two.push(p[i]) ;
        else if(a[i]==3) three.push(p[i]) ;
        if(b[i]==1) one.push(p[i]) ;
        else if(b[i]==2) two.push(p[i]) ;
        else if(b[i]==3) three.push(p[i]) ;
      }
    for(int i=0 ; i<m ; i++)
      {
        bool check=true ;
        if(buyer[i]==1)
          {
            if(one.empty()) cout<< -1 << " " ;
            else
              {
                x=one.top() ;
                while(check && avail[x]==false)
                  {
                    one.pop() ;
                    if(one.empty()) check=false ;
                    x=one.top() ;
                  }
                if(check)
                  {
                    avail[x]=false ;
                    cout<< x << " " ;
                  }
                else cout<< -1 << " " ;
              }
          }
        else if(buyer[i]==2)
          {
            if(two.empty()) cout<< -1 << " " ;
            else
              {
                x=two.top() ;
                while(check && avail[x]==false)
                  {
                    two.pop() ;
                    if(two.empty()) check=false ;
                    x=two.top() ;
                  }
                if(check)
                  {
                    avail[x]=false ;
                    cout<< x << " " ;
                  }
                else cout<< -1 << " " ;
              }
          }
        else if(buyer[i]==3)
          {
            if(three.empty()) cout<< -1 << " " ;
            else
              {
                x=three.top() ;
                while(check && avail[x]==false)
                  {
                    three.pop() ;
                    if(three.empty()) check=false ;
                    x=three.top() ;
                  }
                if(check)
                  {
                    avail[x]=false ;
                    cout<< x << " " ;
                  }
                else cout<< -1 << " " ;
              }
          }
      }
  }
