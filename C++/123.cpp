#include <bits/stdc++.h>
using namespace std ;

long long int ways(int m, int n, int x)
{
    long long int table[n + 1][x + 1];
    memset(table, 0, sizeof(table));
    for (int j = 1; j <= m && j <= x; j++)
        table[1][j] = 1;


    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k < j; k++)
                table[i][j] += table[i-1][j-k];

    return table[n][x];
}

int main()
{
  int T, d, n, temp, U, L ;
  long long int sum ;
  double ans, max, curr ;
  char dump ;
  cin>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  {
    max=0 ;
    scanf("%d %d", &d, &n) ;
    vector<int> x(n), y(n), z(n, 0) ;
    int a, b ;
    for(int i=0 ; i<n ; i++)
    {
     scanf("%dd%d", &a, &b) ;
     x[i]=a ; y[i]=b ;
     dump=getchar() ;
     if(dump=='-') { scanf("%d ", &a) ; z[i]=-a ; }
     else if(dump=='+') { scanf("%d ", &a) ; z[i]=a ; }
    }
    for(int i=0 ; i<n ; i++)
    {
      sum=0 ; ans=0 ;
      temp=d-z[i] ;
      U=y[i]*x[i] ;
      L=x[i] ;
      if(z[i]>=d) continue ;
      for(long long int j=temp ; j<=U; j++)
        sum+=ways(y[i], x[i], j) ;

      ans=sum ;
      ans=ans/double(pow(y[i],x[i])) ;

     if(max<ans) max=ans ;

    }
    cout<< "Case #"<<tc<< ": " << fixed << setprecision(6) << max << endl ;
  }
  return 0 ;
}
