#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <long long> b;
    long long num;
    for(long long i = 0; i < n; ++i){
        cin >> num;
        b.push_back(num);
    }
    sort(b.begin(), b.end());
    long long pre, now;
    long long k = 0;
    vector <long long> ans;
    vector <long long> second;
    for(long long i = 1; i < n-1; ++i){
        if(b[i] == b[i-1] && b[i] == b[i+1]){
            k++;
            ans.push_back(b[i]);
        }
        else second.push_back(b[i]);
    }
    for(long long i = 1; i < n; ++i){
        if(b[i] == b[i-1]){
            k++;
            ans.push_back(b[i]);
        }
    }
    cout << k;
    for(int i = 0; i < k; ++i){
        cout << ans[i] << ' ';
    }
    return 0;
}
