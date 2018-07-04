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

vb isprime(20000000, true) ;

void seive()
  {
    isprime[1]=isprime[0]=false ;
    isprime.assign(100000, true) ;
    for(int i=2 ; i*i<=10000000 ; i++)
      if(isprime[i])
        for(int j=2*i ; j<=10000000 ; j+=i)
          isprime[j]=false ;
  }


class EllysPrimesMatrix {
    public:
    int getCount(vector<string> matrix) {
      seive() ;
      set<int> s ;
      int ans=0, n=matrix[0].size(), m=matrix.size() ;
      for(int a=0 ; a<n ; a++)
        for(int b=0 ; b<n ; b++)
          for(int c=0 ; c<n ; c++)
            for(int d=0 ; d<n ; d++)
              for(int e=0 ; e<n ; e++)
                for(int f=0 ; f<n ; f++)
                  for(int g=0 ; g<n ; g++)
                    {
                      string r="" ;
                      r+=matrix[0][a] ;
                      if(1<m) r+=matrix[1][b] ;
                      if(2<m) r+=matrix[2][c] ;
                      if(3<m) r+=matrix[3][d] ;
                      if(4<m) r+=matrix[4][e] ;
                      if(5<m) r+=matrix[5][f] ;
                      if(6<m) r+=matrix[6][g] ;
                      int x=stoi(r) ;
                      if(isprime[x]) s.insert(x) ;
                    }
      ans=s.size() ;
      return ans ;
    }
};

// CUT begin
ifstream data("EllysPrimesMatrix.sample");

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

bool do_test(vector<string> matrix, int __expected) {
    time_t startClock = clock();
    EllysPrimesMatrix *instance = new EllysPrimesMatrix();
    int __result = instance->getCount(matrix);
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
        vector<string> matrix;
        from_stream(matrix);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(matrix, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530372962;
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
        cout << "EllysPrimesMatrix (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
