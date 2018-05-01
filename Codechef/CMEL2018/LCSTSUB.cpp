#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
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

struct node ;
node *newNode() ;

struct node
  {
    int lv, rv, val ;
    node *left, *right ;

    node() : left(NULL), right(NULL), val(0) {}

    inline void init(int l, int r)
      {
        lv=l ;
        rv=r ;
      }

    inline void extend()
      {
        if(!left)
          {
            int m=(lv+rv)/2 ;
            left=newNode() ;
            right=newNode() ;
            left->init(lv, m) ;
            right->init(m+1, rv) ;
          }
      }

    int query(int l, int r)
      {
        if(r<lv || rv<l) return 0 ;
        if(l<=lv && rv<=r) return val ;
        extend() ;
        return max(left->query(l, r),right->query(l, r)) ;
      }

    void update(int p, int newVal)
      {
        if(lv==rv)
          {
            val=max(val, newVal) ;
            return ;
          }
        extend() ;
        (p<=left->rv ? left : right)->update(p, newVal) ;
        val=max(left->val, right->val) ;
      }
  } ;

node *newNode()
  {
    static int bufSize=1e7 ;
    static node buf[(int) 1e7] ;
    assert(bufSize) ;
    return &buf[--bufSize] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    node *f=newNode() ;
    f->init(0, 1e9) ;
    int n, ans=0, x, y, curr ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x >> y ;
        x^=ans ;
        y^=ans ;
        curr=1+f->query(max(x-y, 0), min(x+y, (int)1e9)) ;
        ans=max(ans, curr) ;
        f->update(x, curr) ;
        cout<< ans << endl ;
      }
  }
