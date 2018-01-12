#include <bits/stdc++.h>
using namespace std ;

int main()
{ long long int N ;
    cin>> N ;
    vector<long long int> a(N) ;
    for(long int i=0 ; i<N ; i++)
    {
        cin>>a[i] ;
    }
    sort(a.begin(), a.end()) ;
    cout<< a[N-1]*a[N-2] ;
    return 0 ;
}
 
