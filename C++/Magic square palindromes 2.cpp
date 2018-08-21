#include <bits/stdc++.h>
using namespace std ;
int main()
{ char s[1000], r[1000] ;
  cin.getline(s,100) ;
  int q=0, f=1, k ;
  for(int i=0 ; i<strlen(s) ; i++)
  { s[i]=tolower(s[i]) ;
    if(s[i]>='a' && s[i]<='z') { r[q]=s[i] ; q++ ; }
  }

  k=q-1 ;
  for( int i=0; i<q ; i++)
  {
    if(r[i]!=r[k]) f=0 ;
    k-- ;
  }

  if(f==0) {cout<< "No magic :(" ; exit(0) ;}

  k=floor(sqrt(q)) ;

  if(k*k==q)
  { q=0 ;
    char u[100][100] ;
    for(int i=0 ; i<k ; i++)
    {
      for(int j=0 ; j<k ; j++)
      {
        u[i][j]=r[q] ; q++ ;
      }
    }
    for(int i=0 ; i<k ; i++)
    {
      for(int j=0 ; j<k ; j++)
      {
        if(u[i][j]!=u[j][i]) f=0 ;
      }
    }
    if(f==0) cout<< "No magic :(" ;
    else cout<< k ;
  }
  else cout<< "No magic :(" ;
  return 0 ;
}
