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

bool isSuffix(string &a, string&b)
  {
    if(a.length()>b.length()) return false ;
    for(int i=a.length(), j=b.length() ; i>=0 ; i--, j--)
      if(a[i]!=b[j])
        return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m ;
    cin>> n ;
    map<string, vector<string>> rec ;
    string name, phone, curr, nxt ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> name >> m ;
        for(int j=0 ; j<m ; j++)
          {
            cin>> phone ;
            rec[name].pb(phone) ;
          }
        sort(all(rec[name])) ;
      }
    for(auto i:rec)
      {
        name=i.fi ;
        for(int i=0 ; i<rec[name].size() ; i++)
          {
            for(int j=0 ; j<rec[name].size() ; j++)
              {
                if(i!=j && isSuffix(rec[name][i], rec[name][j]))
                  {
                    rec[name][i]="" ;
                    break ;
                  }
              }
          }
      }
    cout<< rec.size() << endl ;
    for(auto i:rec)
      {
        name=i.fi ;
        vector<string> ans ;
        for(auto j:rec[name]) if(j!="") ans.pb(j) ;
        cout<< name << " " << ans.size() << " " ;
        for(auto j:ans) cout<< j << " " ;
        cout<< endl ;
      }
  }
