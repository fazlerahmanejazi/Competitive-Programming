#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    string s;
    cin>> s ;
    int a=0;
    int b=0;
    
    int z=s.length() ;
    
    for(int i=0 ; i<z ; i++)
    { a=i+1 ;
      if(s[i]=='h') { b=b+1 ;
	  break ;	}
	}
	
	for(int i=a ; i<z ; i++)
    { a=i+1 ;
      if(s[i]=='e') { b=b+1;
	  break ;	}
	}
	
	
	for(int i=a ; i<z ; i++)
    { a=i+1 ;
      if(s[i]=='l') { b=b+1;
	  break ;	}
	}
	
		for(int i=a ; i<z ; i++)
    { a=i+1 ;
      if(s[i]=='l') { b=b+1;
	  break ;	}
	}
	
	
		for(int i=a ; i<z ; i++)
    { a=i+1 ;
      if(s[i]=='o') { b=b+1;
	  break ;	}
	}
	
	if(b==5) cout<< "YES" ;
	else cout<< "NO" ;
	 return 0;
}
