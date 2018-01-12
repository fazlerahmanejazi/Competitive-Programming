#include <bits/stdc++.h>
using namespace std ;

int a, b, node ;
long long int result ;
set<int> child ;
vector<int> dp ;

int max(int c)
  {
    map<int, int> cnt ;
    int maxm, val=1 ;
    maxm=-1 ;
    while(c%2==0)
      {
        cnt[2]++ ;
        c=c/2;
      }
    if(cnt[2]>maxm)
      {
        maxm=cnt[2] ;
        val=2 ;
      }
    for(int i=3 ; i<=sqrt(c) ; i=i+2)
      {
        while(c%i==0)
          {
            cnt[i]++ ;
            c=c/i;
          }
        if(cnt[i]>maxm)
          {
            maxm=cnt[i] ;
            val=i ;
          }
      }
    return val ;
  }

void modify()
  {
    set<int>::iterator it ;
    int temp, t ;
    it=child.begin() ;
    it++ ;
    t=max(node) ;
    while(it!=child.end())
      {
        temp=*it ;
        if(temp%t==0)
          {
            temp=*it/t ;
            it=child.erase(it) ;
            if(temp!=0) child.insert(temp) ;
          }
        else it++ ;
      }
    child.erase(node/t) ;
    node=node/t ;
  }

void init(int c)
  {
    child.clear() ;
    child.insert(1) ;
    node=c ;
    for(int i=2 ; i<=sqrt(c) ; i++)
      if(c%i==0)
        {
          child.insert(i) ;
          if(c/i!=i) child.insert(c/i) ;
        }
  }

long int solve(int c)
  {
    if(c==1) return 0 ;
    if(dp[c]!=-1) return dp[c] ;
    long int ans=0 ;
    init(c) ;
    ans+=child.size() ;
    while(child.size()>1)
      {
        modify() ;
        if(dp[node]!=-1)
          {
            ans+=1+dp[node] ;
            return ans ;
          }
        ans+=1+child.size() ;
      }
    dp[c]=ans+1 ;
    return ans+1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> a >> b ;
    result=0 ;
    dp.assign(b+1, -1) ;
    dp[1]=1 ;
    for(int i=a ; i<=b ; i++)
      result+=solve(i) ;
    cout<< result ;
  }
