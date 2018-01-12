#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> BIT;
void insert(int idx)
{
    for(int i=idx;i<BIT.size();i+=i&(-i))
    {
        BIT[i]++;
    }
}
int query(int idx)
{
    int ans = 0;
    for(int i = idx;i>0;i-=i&(-i))
        ans += BIT[i];
    return ans;
}
int gidx(int x)
{
    int start = 1, end = BIT.size()-1;
    while(start<end)
    {
        int mid = (start+end)/2;
        int val = mid - query(mid);
        if(val < x)
            start = mid+1;
        else
            end = mid;
    }
    return end;
}
int32_t main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m2,l,r;
    string s;
    char ch;
    cin>>n>>m2>>s;
    BIT.resize(n+1);
    map<char,set<int> > m;
    vector<int> del;
    for(int i=0;i<n;i++)
        m[s[i]].insert(i+1);
    for(int i=0;i<m2;i++)
    {
        cin>>l>>r>>ch;
        l = gidx(l);
        r = gidx(r);
        auto &wut = m[ch];
        auto x = wut.lower_bound(l);
        while(x!= wut.end() && (*x)<=r)
        {
            insert(*x);
            del.push_back(*x);
            x = wut.erase(x);
        }
    }
    sort(del.begin(), del.end());
    int chk = 0, tmp = del.size();
    for(int i=0;i<n;i++)
    {
        if((chk<tmp)&&del[chk]==(i+1))
        {
            chk++;
            continue;
        }
        cout<<s[i];
    }
    return 0;
}
