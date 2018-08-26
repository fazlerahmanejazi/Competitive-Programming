#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif



#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef PRINTERS
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

vector<vi>pos;
int x[9];
int y[9];
int sums[3];
int sums2[3];
void solve(){
	static int testcase = 1;
	cout << "Case #" << testcase++ <<": ";
	int N;
	cin>>N;
	rep(i,0,3*N){
		cin>>x[i];
	}
	rep(i,0,3*N){
		cin>>y[i];
	}
	long double ans=0;
	for(auto i:pos){
		sums[0]=sums[1]=sums[2]=0;
		rep(j,0,9){
			sums[i[j]]+=x[j];
		}
		int good=0;
		int total=0;
		for(auto j:pos){
			sums2[0]=sums2[1]=sums2[2]=0;
			total++;
			rep(k,0,9){
				sums2[j[k]]+=y[k];
			}
			int done=0;
			rep(k,0,3)done+=(sums[k]>sums2[k]);
			if(done>1)good++;
		}
		ans=max(ans,1.0l*good/total);
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int power=1;
	rep(i,0,9){
		power*=3;
	}
	rep(i,0,power){
		int temp=i;
		vi alpha;
		vi cnt(3);
		rep(j,0,9){
			alpha.pb(temp%3);
			cnt[temp%3]++;
			temp/=3;
		}
		if(cnt[0]==3 and cnt[1]==3 and cnt[2]==3)pos.pb(alpha);
	}
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}