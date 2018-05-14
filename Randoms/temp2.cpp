/*
СТРОИМ СТЕНУ РАБОТЯГИ!
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>



using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
const int MAXN = 1 + 500000;


int n, m;
vector<vector<int> > g;
vector<vector<int> > powers;
int podSZ[MAXN];
bool solved[MAXN];
vector<int > counts;
long long cntAlive;
long long sumDamage;
long long ans[MAXN];



void dfs(int u, int parent = -1) {
    podSZ[u] = 1;
    for(auto h: g[u]) {
        if(!solved[h] && h != parent) {
            dfs(h, u);
            podSZ[u] += podSZ[h];
        }
    }
}


int findCentroid(int u, int parent, int size) {
    for(auto h: g[u]) {
        if(!solved[h] && h != parent && podSZ[h] > size / 2) {
            return findCentroid(h, u, size);
        }
    }
    return u;
}


inline void AddPowers(int u, int parent, int distance) {
    for (auto power: powers[u]) {
        if (power > distance) {
            if (power - distance < sz(counts)) {
                counts[power - distance]++;
            }
            cntAlive++;
            sumDamage += (power - distance);
        }
    }
    for (auto h: g[u]) {
        if (!solved[h] && h != parent) {
            AddPowers(h, u, distance + 1);
        }
    }
}


inline void RemovePowers(int u, int parent, int distance) {
    for (auto power: powers[u]) {
        if (power > distance) {
            if (power - distance < sz(counts)) {
                counts[power - distance]--;
            }
            cntAlive--;
            sumDamage -= (power - distance);
        }
    }
    for (auto h: g[u]) {
        if (!solved[h] && h != parent) {
            RemovePowers(h, u, distance + 1);
        }
    }
}


inline void Updateanss(int u, int parent, int distance) {
    sumDamage -= 1LL * distance * counts[distance]; cntAlive -= counts[distance];
    ans[u] += sumDamage - 1LL * cntAlive * distance;
    for (auto h: g[u]) {
        if (!solved[h] && h != parent) {
            Updateanss(h, u, distance + 1);
        }
    }
    sumDamage += 1LL * distance * counts[distance]; cntAlive += counts[distance];
}


inline void centroidDecomposition(int root) {
    dfs(root);
    int centroid = findCentroid(root, root, podSZ[root]);
    solved[centroid] = true;
    counts = vector<int> (podSZ[root], 0);
    sumDamage = cntAlive = 0;
    for (auto h: g[centroid]) {
        if (!solved[h]) {
            AddPowers(h, centroid, 1);
        }
    }
    for (auto power: powers[centroid]) {
        if (power < sz(counts)) {
            counts[power]++;
        }
        cntAlive++;
        sumDamage += power;
    }
    ans[centroid] += sumDamage;
    for (auto h: g[centroid]) {
        if (!solved[h]) {
            RemovePowers(h, centroid, 1);
            Updateanss(h, centroid, 1);
            AddPowers(h, centroid, 1);
        }
    }
    for (auto h: g[centroid]) {
        if (!solved[h]) {
            centroidDecomposition(h);
        }
    }
}


int main() {
    n = readInt(), m = readInt();
    g.resize(n + 1);
    powers.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int x = readInt();
        g[x].push_back(i);
        g[i].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        int u = readInt(), power = readInt();
        powers[u].push_back(power);
    }
    centroidDecomposition(1);
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
