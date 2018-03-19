#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, x ;
lli res=0 ;
vvi V ;
vi ans, indegree ;
vb visited ;

void allTopo(vvi V,vi de,int n,vector<int>&ans,vb visited)
{
        if(ans.size()==n)
        {
                res++ ;
                return;
        }
        for(int i=0;i<n;i++)

                if(indegree[i]==0 && visited[i]==false)
                {
                        visited[i]=true;
                        ans.push_back(i);
                        for(int k=0;k<V[i].size();k++)
                                indegree[V[i][k]]--;

                        allTopo(V,indegree,n,ans,visited);

                        for(int k=0;k<V[i].size();k++)
                                indegree[V[i][k]]++;

                        visited[i]=false;
                        ans.pop_back();
                }

        return;
}
int main(void)
  {
    int n ;
    cin>> n ;
    V.resize(n+1) ;
    indegree.assign(n+1, 0) ;
    visited.assign(n+1, false) ;
    for(int i=0 ; i<n-1 ; i++)
      {
        cin>> x ;
        if(x==1)
          {
            V[i].pb(i+1) ;
            indegree[i+1]++ ;
          }
        else
          {
            V[i+1].pb(i) ;
            indegree[i]++ ;
          }
      }
    allTopo(V,indegree,n,ans,visited);
    cout<< res ;
    return 0;
  }
