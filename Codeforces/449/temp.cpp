#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
#define ll long long int
vector<long long int>vec;
string str;
ll n,mod;

ll init(int x)
{
    for(int i=1; i<=x; i++){
        stringstream ss;
        ss<<i;
        string temp = ss.str();
        string t = temp;
        int l = temp.size();
        for(int j=l-1; j>=0; j--){
            t+=temp[j];
        }
        ll y = stol(t);
        vec.push_back(y);
    }
    ll sum=0;
    for(int i=0; i<vec.size(); i++){
        sum=((sum%mod)+(vec[i]%mod))%mod;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>mod;
    cout<<init(n);
}
