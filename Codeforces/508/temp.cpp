#include<bits/stdc++.h>
#define For(i, a, b)  for(int i = a; i <= b; ++i)
#define Ford(i, a, b) for(int i = a; i >= b; --i)
#define ll            long long
#define ld            long double
#define ull           unsigned long long
#define pb            push_back
#define X             first
#define Y             second

using namespace std;

template <typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
const int N = 1e6 + 7;
const int M = 1e8;
const int mod = 9901;

ll n, a[N], s = 0, m;

void Enter()
{
     cin >> n;
     int neg=0, pos=0 ;
     m = 1e18;
     For(i, 1, n)
      {
        cin >> a[i], s += abs(a[i]), m = min(m, abs(a[i]));
        if(a[i]<0) neg=1 ;
        if(a[i]>=0) pos=1 ;
      }
     if(n==1)
     {
       cout<< s ;
       return ;
     }
     sort(a + 1, a + n + 1);
     if(pos && neg)
     {
         cout << s;
         exit(0);
     }
     else
     {
         cout << s - 2 * m;
         exit(0);
     }
}

void Solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Enter();
    Solve();

    return 0;
}
