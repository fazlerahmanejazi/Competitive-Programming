#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;
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

class ProductThreshold {
    public:
    long long subarrayCount(lli N, lli limit, vector<lli> Aprefix, lli spread, lli offset) {
    vlli a=Aprefix ;
    lli seed=abs(a[a.length()-1]), ans=0 ;
    for(int i=Aprefix.length() ; i<N ; i++)
      {
        seed=(seed*1103515245+12345)%2147483648 ;
        a.pb((seed%spread)+offset) ;
      }
    vlli nxtOne(n), nxtNeg(n) ;
    curr=n ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        nxtOne[i]=curr ;
        if(a[i]!=1) curr=i ;
      }
    curr=n ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        nxtNeg[i]=curr ;
        if(a[i]<0) curr=i ;
      }
    for(int i=0 ; i<n ; i++)
      {
        p=1 ;
        int idx=0 ;
        while(idx<n)
          {
            p*=a[idx] ;
            if(p>limit) break ;
          }
      }
};

// CUT begin
ifstream data("ProductThreshold.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int N, int limit, vector<int> Aprefix, int spread, int offset, long long __expected) {
    time_t startClock = clock();
    ProductThreshold *instance = new ProductThreshold();
    long long __result = instance->subarrayCount(N, limit, Aprefix, spread, offset);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int N;
        from_stream(N);
        int limit;
        from_stream(limit);
        vector<int> Aprefix;
        from_stream(Aprefix);
        int spread;
        from_stream(spread);
        int offset;
        from_stream(offset);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, limit, Aprefix, spread, offset, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530979889;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ProductThreshold (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
