
/* Vector of stacks is used in this program. Also the algorithm followed is bit tricky. There are other combinations
of containers so as to minimize the no. of stacks. Though I have used vector of stacks, there is no need of that
as at every step, we are concerned about only the topmost element of a stack. So a linear vector can also do the job
by replacing the element at every step. */


#include <bits/stdc++.h>
using namespace std ;

int main()
{ vector< stack<char> > a ;
  stack<char> temp;
  string s ;
  int c=1, n, check ;
  while(cin>> s && s!="end")
  { n=1 ;
    a.clear() ;
    a.push_back(temp); // This is used to add a element at the end of the vector, hence increasing it's size.
    a[0].push(s[0]) ;
      for(int i=1 ; i<s.length() ; i++)
       {   check=-1 ;
           for(int j=0 ; j<n ; j++)
           {
             if(a[j].top()>=s[i]) { check=j ; break ; }
           }
           if(check!=-1) a[check].push(s[i]) ;
           else
           {
             n++ ;
             a.push_back(temp);
             a[a.size() - 1].push(s[i]); ;
           }
      }
    cout<< "Case " << c++ << ": " << n << endl ;
 }
   return 0 ;
}
