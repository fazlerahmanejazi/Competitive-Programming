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

struct node
  {
    node *left, *right ;
    node() { left=right=NULL ; }
  } *root ;

void insert(node *root, int n)
  {
    int x ;
    for(int i=20 ; i>=0 ; i--)
      {
        x=(n>>i)&1 ;
        if(x)
          {
            if(root->right==NULL) root->right=new node() ;
            root=root->right ;
          }
        else
          {
            if(root->left==NULL) root->left=new node() ;
            root=root->left ;
          }
      }
  }

int query(node *root, int q)
  {
    int x, ans=0 ;
    for(int i=20 ; i>=0 ; i--)
      {
        x=(q>>i)&1 ;
        if(x)
          {
            if(root->right==NULL) ans=ans|(1<<i), root=root->left ;
            else root=root->right ;
          }
        else
          {
            if(root->left==NULL) ans=ans|(1<<i), root=root->right ;
            else root=root->left ;
          }
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, x, q=0 ;
    root=new node() ;
    vb taken(1<<20+1, false) ;
    cin>> n >> m ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        taken[x]=true ;
      }
    for(int i=0 ; i<=1<<20 ; i++)
      if(!taken[i])
        insert(root, i) ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> x ;
        q^=x ;
        cout<< query(root, q) << endl ;
      }
  }
