//Nightmare05

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

#define sp << " " <<
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define int long long
#define double long double
#define INF (1e18 + 13)
#define mod2 998244353
#define PI 3.1415926535898
#define ff first
#define ss second

int power(int p, int j)
{
    int res = 1;
    p = p % mod;
    while (j > 0)
    {
        if (j & 1)
            res = (res * p) % mod;
        j = j >> 1;
        p = (p * p) % mod;
    }
    return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dice(int d, int p)
{
    uniform_int_distribution<int> uid(d, p);
    return uid(rng);
}

#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

/*
int read()
{
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int dp = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          dp = dp * 10 + cc - '0';
          cc = getc(stdin);
       }
      return dp;
}

inline void print(int n)
{
  if (n == 0)
  {
    putchar('0');
    putchar('\n');
  }
  else if (n == -1)
  {
    putchar('-');
    putchar('1');
    putchar('\n');
  }
  else
  {
    char buf[20];
    buf[19] = '\n';
    int i = 18;
    while (n)
    {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n')
      putchar(buf[++i]);
  }
}

int n;

vector<vector<int>> mat_mul(vector<vector<int>> a,vector<vector<int>> b)
{
    int n=2;
    vector<vector<int>> dp2(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                dp2[i][j]+=((a[i][k]*b[k][j])%mod);
                dp2[i][j]%=mod;
            }
        }
    }
    return dp2;
}

vector<vector<int>> pow_mat(vector<vector<int>> mat_a,int p)
{
    if(p==1)
        return mat_a;
    vector<vector<int>> temp=pow_mat(mat_a,p/2);
    vector<vector<int>> res=mat_mul(temp,temp);
    if(p&1)
        res=mat_mul(res,mat_a);
    return res;
}
*/

struct point
{
    int x,y,z;
};

bool operator< (const point &lhs, const point &rhs)
{
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    if (lhs.z != rhs.z) return lhs.z < rhs.z;
    return false;
}

map<pair<point,point>,vector<int>> dp;

void magic(point a,point b,int n)
{
    if(b<a)
        swap(a,b);
    dp[mp(a,b)].pb(n);
}

int parent[100013],sz[100013];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve()
{
    dp.clear();
    for(int i=0;i<100000;i++)
        parent[i]=sz[i]=0;
    int n;
    cin >> n;
    point a[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cin >> a[i][j].x >> a[i][j].y >> a[i][j].z;
        magic(a[i][0],a[i][1],i);
        magic(a[i][0],a[i][2],i);
        magic(a[i][2],a[i][1],i);
    }
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
    for(auto i:dp)
    {
        int m=i.second.size();
        for(int j=0;j<m-1;j++)
            union_sets(i.second[j],i.second[j+1]);
    }
    sort(sz,sz+100013);
    reverse(sz,sz+100013);
    // cout << sz[0] << endl;
    if(sz[0]==n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("triangles.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    int y=t;
    while(t--)
    {
        //cout << "Case #" << y-t << ": ";
        solve();
    }
    return 0;
}
