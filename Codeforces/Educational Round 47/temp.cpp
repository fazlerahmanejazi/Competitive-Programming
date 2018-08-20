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
map<int,int>m[N];
vector<int>G[N];
int d[N],res[N];

void dfs(int x,int fa)
{
    d[x]=d[fa]+1;
    res[x]=d[x];
    m[x][d[x]]++;
    for (auto t:G[x])
    {
        if (t==fa)continue;
        dfs(t,x);
        if (m[x].si()<m[t].si()) swap(m[x],m[t]),res[x]=res[t];
        for (auto v:m[t])
        {
            m[x][v.first]+=v.second;
            if (m[x][v.first]+(v.first<res[x])>m[x][res[x]])res[x]=v.first;
        }
        m[t].clear();
    }
}

int main()
{
    IO
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int j,k;
        cin>>j>>k;
        G[j].pb(k);G[k].pb(j);
    }
    {dfs(1,0);}
    for (int i=1;i<=n;i++) cout<<res[i]-d[i]<<endl;
    return 0;
}
