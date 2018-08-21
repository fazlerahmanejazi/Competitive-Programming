#include <bits/stdc++.h>
using namespace std ;

int n, m, temp1, temp2 ;
vector<int> color ;
vector<vector<int> > l ;
bool check ;
int T, ans ;

int BFS(int s)
{
	queue<int> q;
	q.push(s);
	color[s]=1;
	int total=0,black=0;

	while (!q.empty())
  {
		int u=q.front();
		q.pop();
		total++;
		if (color[u]==1) black++;
		for (int i=0;i<l[u].size();i++)
		{
			int v=l[u][i];
			if (color[v]==2)
            {
				      color[v]=1-color[u];
			      	q.push(v);
			      }
			else if (color[v]==color[u]) return -1;
		}
	}
	if (total==1) return 1;
	return min(black,total-black);
}
int main()
{
  ios_base::sync_with_stdio (false) ;
  cin>> T ;
  while(T--)
  {
    ans=0 ;
    cin>> n >> m ;
    color.assign(n, 2) ;
    l.clear() ;
    l.resize(n) ;
    for(int i=0 ; i<m ; i++)
    {
      cin>> temp1 >> temp2 ;
      l[temp1].push_back(temp2) ;
      //l[temp2].push_back(temp1) ; No need of this.
    }
    check=true ;
    for(int i=0 ; i<n && check ; i++)
      if(color[i]==2)
        {
           int x=BFS(i) ;
           if(x==-1) check=false ;
           else ans=ans+x ;
        }
    if(check) cout<< ans<< endl ;
    else cout<< -1 << endl ;
  }
    return 0 ;
}
