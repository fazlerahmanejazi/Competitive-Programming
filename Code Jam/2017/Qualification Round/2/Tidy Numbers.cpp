#include <bits/stdc++.h>
using namespace std ;

int T ;
string s ;
long long int n, x, l ;
bool check ;

bool tidy()
  {
    string temp=s ;
    sort(temp.begin(), temp.end()) ;
    if(temp==s) return true ;
    else return false ;
  }

void modify(int pos)
  {
    s[pos]=s[pos]-1 ;
    for(int i=pos+1 ; i<l ; i++)
      s[i]='9' ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        cin>> s ;
        l=s.length() ;
        check=false ;
        for(int i=0 ; i<=l ; i++)
          {
            for(int j=0 ; j<l-1 ; j++)
              if(s[j+1]<s[j])
                {
                  modify(j) ;
                  if(tidy())
                    {
                      check=true ;
                      break ;
                    }
                }
            if(check) break ;
          }
        stringstream ss(s);
        ss>> n ;
        cout<< "Case #" << tc << ": " << n << endl ;
      }
  }
