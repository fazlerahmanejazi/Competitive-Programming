#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lng length

typedef long long lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef pair<lli, int> pli;
typedef pair<int, lli> pil;

const int mod=1e9+7, N=1e6+5;
int n, k, tab[N];
lli wyn=0;
pii lim[N], sorted[N];
set<int>blep;
set<int>::iterator it, itb;

int binsearch(int x, int y)
{
    int pocz=1, kon=x;
    while(pocz<kon)
    {
        int akt=(pocz+kon)/2;
        if(1+akt*(k-1)>y+1-(1+akt*(k-1)))kon=akt;
        else pocz=akt+1;
    }
    return kon;
}

lli solve(int x, int y)
{
    if(y<x)return 0LL;
    lli p=1+x*(k-1), q=1+y*(k-1), ret=(p+q)*(y-x+1)/2;
    return ret%mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
        sorted[i]=mp(tab[i], i);
    }
    sort(sorted+1, sorted+n+1);
    blep.insert(0);
    blep.insert(n+1);
    for(int i=n;i>=1;i--)
    {
        int x=sorted[i].nd;
        it=blep.upper_bound(x);
        itb=it;
        itb--;
        lim[x]=mp((*itb)+1, (*it)-1);
        blep.insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        int a=lim[i].st, b=lim[i].nd, l=(b-a+1), il=(l-1)/(k-1);
        lli pom=(lli)(l+1)*il-solve(1, il);
        lli poma, pomb;
        il=(i-a)/(k-1);
        poma=(lli)(i-a+1)*il-solve(1, il);
        il=(b-i)/(k-1);
        pomb=(lli)(b-i+1)*il-solve(1, il);
        pom=((pom-poma-pomb)%mod+mod)%mod;
        wyn=(wyn+pom*tab[i])%mod;
    }
    cout<<wyn<<endl;
	return 0;
}
