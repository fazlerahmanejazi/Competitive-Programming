#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int main()
{
    long long n, x, y;
    long long ans;
    cin >> x >> y >> n;
    if (n % 6 == 0) ans = x - y ;
    if (n % 6 == 1) ans = x ;
    if (n % 6 == 2) ans = y;
    if (n % 6 == 3) ans =  y - x;
    if (n % 6 == 4) ans = -x;
    if (n % 6 == 5) ans = -y ;
    while (ans < 0)ans += 1000000007;
    cout << ans % 1000000007 << "\n";
    return 0;
}
