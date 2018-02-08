#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
	ll grid[100][100], n, m, r, k, c ;
	ld ans=0 ;
	cin>> n >> m >> r >> k ;
	r-- ;
	c=(n-r)*(m-r) ;
  memset(grid, 0, sizeof grid) ;
	priority_queue<ld> pq ;
  for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=m ; j++)
      if(i+r<=n && j+r<=m)
        for(int k=i ; k<=i+r ; k++)
          for(int l=j ; l<=j+r ; l++)
            grid[k][l]++ ;
	for(int i=1 ; i<=n ; i++, cout<< endl)
    for(int j=1 ; j<=m ; j++)
			cout<< grid[i][j] << "     " ;
  for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=m ; j++)
				pq.push(grid[i][j]) ;
	while(k--)
		{
			ans+=pq.top() ;
			pq.pop() ;
		}
	cout<< fixed << setprecision(9) << ans/c ;
  }
