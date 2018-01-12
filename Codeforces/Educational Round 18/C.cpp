#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    char temp ;
    int n=0, sum=0, count, mod, ans=1000000, deleted ;
    vector<int> num ;
    vector<bool> del ;
    vector<vector<int> > digits(10) ;
    while(cin>>temp)
      {
        n++ ;
        num.push_back(temp-'0') ;
        sum+=temp-'0' ;
        digits[temp-'0'].push_back(n-1) ;
      }
    mod=sum%3 ;
    if(mod) cout<< 0 ;
    for(int i=mod ; i<10 ; i=i+mod)
      {
        for(int j=mod ; j>0 ; j--)
          {
            if(digits[j].size()*j>=mod && mod%j==0)
              {
                int t=mod/j ;
                if(t<ans)
                  {
                    del.assign(n, true) ;
                    deleted=0 ;
                    for(int k=0 ; k<t ; k++)
                      {
                        del[digits[j][digits[j].size()-k-1]]=false ;
                        deleted++ ;
                      }
                    ans=t ;
                  }
              }
          }
      }
    if(ans==1000000)
      {
        cout<< -1 ;
        return 0 ;
      }
    for(int i=0 ; i<n ; i++)
      if(num[i]==0 && del[i])
        {
          del[i]=false ;
          deleted++ ;
          break ;
        }
    if(deleted==n)
    	{
    		cout<< 0 ;
    		return 0 ;
    	}
    int zero=0;
    for(int i=0 ; i<n ; i++)
    	if(del[i] && num[i]) cout<< num[i] ;

  }
