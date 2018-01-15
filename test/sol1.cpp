#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int a[18],b[18],ans[18];
bool d = false; int count1,count2;bool used[18] = {0}; ull ret = 0;

int back(int ind,int p,int dd)
{
    int c; ull t = 0; int tt = p;
    if(ind == count2)
        return 1;
    if(dd == 1)
    {
        for(int i = count1-1;i>=0;i--)
        {
            if(!used[i])
            {
                ans[tt] = a[i];
                tt++;
            }
        }
        ull mult = 1;
        for(int k = count1-1 ; k >= 0 ; k--)
            {
                t += ans[k]*mult;
                mult *= 10;
            }
        ret = max(ret,t);
        return 1;
    }
    bool f = false;
    for(int i = count1-1;i>=0;i--)
    {
        if(used[i])
            continue;
        if(a[i]<=b[ind])
        {
            ans[p] = a[i]; used[i] = true;
            int s = 0;
            if(a[i] < b[ind])
                s = 1;
            c = back(ind+1,p+1,s); used[i] = false;
            if(c == 1)
            {
                f = true; ull mult = 1; t =0;
                for(int k = count1-1 ; k >= 0 ; k--)
                {
                    t += ans[k]*mult;
                    mult *= 10;
                }
                ret = max(ret,t);
                return 1;
            }
        }
    }
    if(!f)
        return -1;
}
int main()
{
    SYNC
      ull x,y;
    while(cin>> x >> y)
      {d=false ; count1=count2=0 ; memset(used, false, sizeof used) ; ret=0 ;
      memset(a, 0, sizeof a) ;
      memset(b, 0, sizeof b) ;
      memset(ans, 0, sizeof ans) ;
        ull t1 = x,t2 = y;
        count1 = 0;
        while(x != 0)
        {
            x /= 10;
            ++count1;
        }
        for(int i = count1-1 ; i >= 0 ; i--)
        {
            a[i] = t1%10; t1/=10;
        }
        count2 = 0;
        while(y != 0)
        {
            y /= 10;
            ++count2;
        }
        for(int i = count2-1 ; i >= 0 ; i--)
        {
            b[i] = t2%10; t2/=10;
        }
        sort(a,a+count1); int mark = 0;
        if(count2 > count1)
        {
            for(int i = count1-1 ; i >= 0 ; i--)
            {
                cout << a[i];
            }
            cout << endl; return 0;
        }
        back(0,0,0);
        cout << ret << endl;
      }

}
