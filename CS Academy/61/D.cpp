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
vector<int> arr ;

int binary(int insert , int ei )
{
    int l = -1 ; int r = ei ;
    int in = ei+1 ;
    while (r-l>1){
        int m = (r+l)/2 ;
        if(arr[m]<=insert){
            l = m ;
        }
        else if (arr[m]>insert){
            in = min(in,m) ;
        }
    }
    return in ;
}

int lis(int n){
    vector<int> s(n+1) ;
    int si = 0 ;
    while (si < n ){
        if(arr[si]>0){
            s[0] = arr[si] ;
            break ;
        }
        else
           si++ ;
    }
    s[0] = arr[0] ;
    int ei = 1 ;
    for(int i=si+1;i<n;i++){
        if (arr[i]>0){
            if(arr[i]>=s[ei-1]){
                 s[ei] = arr[i] ;
                 ei++;
            }
            else if (arr[i]<s[0]){
                s[0] = arr[i] ;
             }
             else {
                 int in = binary (arr[i],ei) ;
                 s[in] = arr[i] ;
             }

        }
    }
    return ei ;
}

int main()
{
    int tc ;
        int n ; cin>>n;
        arr.clear() ;
        arr.resize(n+1) ;
        for(int i=0;i<n;i++){
            cin>> arr[i] ;
            arr[i] = arr[i]-i;
           // cout << arr[i] ;
        }
        cout << n-lis(n)<<endl;


}
