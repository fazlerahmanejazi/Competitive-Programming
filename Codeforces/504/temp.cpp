//EVIEBOT

#include <bits/stdc++.h>


#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define fastIO ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define clr(xxx) memset(xxx, 0, sizeof(xxx));

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;



int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	string s, t;
	int n, m;
	cin >> n >> m >> s >> t;
	if(s == "*"){
		cout << "YES\n";
		return 0;
	}else if((n-1) > m){
		cout << "NO\n";
		return 0;
	}
	int pos = -1;
	for(int i = 0; i < n; ++i){
		if(s[i] == '*')
			pos = i;
	}
	if(pos == -1){
		if(s == t)
			cout << "YES\n";
		else
			cout << "NO\n";
		return 0;
	}

	for(int i = 0; i < pos; ++i){
		if(s[i] != t[i]){
			cout << "NO\n";
			return 0;
		}
	}
	for(int i = n-1, j = m-1; i > pos; --i, --j){
		if(s[i] != t[j]){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}
