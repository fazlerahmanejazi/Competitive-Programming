#include <bits/stdc++.h>
using namespace std ;

int n, q, f, ans, last, temp ;
string s ;
char c ;
vector<int> tree, seq ;

int prev(int idx)
  {
    if(idx==0) return n-1 ;
    else return idx-1 ;
  }

int sum(int idx)
  {
    int sum=0 ;
    idx++ ;
    while(idx>0)
      {
        sum+=tree[idx] ;
        idx-=idx&(-idx) ;
      }
    return sum ;
  }
void update(int n, int idx, int val)
  {
    idx++ ;
    while(idx<=n)
      {
        tree[idx]+=val ;
        idx+=idx&(-idx) ;
      }
  }

void construct(int n)
  {
    tree.assign(n+1, 0) ;
    for(int i=0 ; i<n ; i++)
      update(n, i, seq[i]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> n >> f >> q ;
    if(f>n) f=n ;
    seq.assign(n, 0) ;
    for(int i=0 ; i<n ; i++)
      cin>> seq[i] ;
    cin>> s ;
    construct(n) ;
    for(int k=0 ; k<s.length() ; k++)
      {
        c=s[k] ;
        if(c=='?')
          {
            ans=sum(f-1) ;
            for(int i=1 ; i+f<=n ; i++)
              ans=max(ans, sum(f+i-1)-sum(i-1)) ;
            cout<< ans << endl ;
          }
        else
          {
            last=seq[n-1] ;
            for(int i=0 ; i<n ; i++)
              {
                if(last==1 && seq[i]==0) update(n, i, 1) ;
                else if(last==0 && seq[i]==1) update(n, i, -1) ;
                temp=seq[i] ;
                seq[i]=last ;
                last=temp ;
              }
          }
      }
  }
