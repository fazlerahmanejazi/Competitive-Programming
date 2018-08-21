#include <bits/stdc++.h>
using namespace std ;


int P(vector<int> seq, vector<int> &T, int l, int r,  int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (seq[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int main()
{ ios_base::sync_with_stdio (false) ;
   int n, temp, L ;
   vector<int> seq ;
   int pos ;
   while(cin>>temp)
     seq.push_back(temp) ;
   n=seq.size() ;
   vector<int> last(n, 0) ;
   vector<int> prev(n, -1) ;
   L=1 ;
   for(int i=1 ; i<n ; i++)
   {
     if(seq[last[0]]>seq[i])
     {
       last[0]=i ;
     }
     else if(seq[last[L-1]]<seq[i])
     {
       prev[i]=last[L-1] ;
       last[L++]=i ;
     }
     else
     {
      /* for(int j=0 ; j<L ; j++)
       {
         if(seq[i]<seq[last[j]])
         {
           prev[i]=last[j-1] ;
           last[j]=i ;
           break ;
         }
       }*/
         int pos = P(seq, last, 0,
                                   L-1, seq[i]);

            prev[i] = last[pos-1];
            last[pos] = i;

       }

     }

   vector<int> ans ;
    for (int i = last[L-1]; i >= 0; i = prev[i])
        ans.push_back(seq[i]) ;
         cout << L << endl << "-" << endl ;
    for(int i=ans.size()-1 ; i>=0 ; i--)
      cout<< ans[i] << endl ;


        return 0 ;
      }
