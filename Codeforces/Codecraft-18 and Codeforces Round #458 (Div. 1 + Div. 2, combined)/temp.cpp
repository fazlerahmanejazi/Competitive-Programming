#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

long a[1000001], cnt[1000001];

int main ()
{

	 int n;
	 cin >> n;
	 for(int i=0; i<n; i++){
			 cin >> a[i];
			 cnt[a[i]]++;
	 }
	 sort(a, a+n);
	 if(cnt[a[n-1]] & 1){
			 cout << "Conan" << endl;
	 }
	 else{
			 cout << "Agasa" << endl;
	 }

	 return 0;
}
