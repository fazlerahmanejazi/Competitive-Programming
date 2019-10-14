#include <bits/stdc++.h>
using namespace std ;

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

lli gcd(lli a, lli b, lli &x, lli &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    lli x1, y1;
    lli d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(lli a, lli b, lli c, lli &x0, lli &y0, lli &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(lli & x, lli & y, lli a, lli b, lli cnt) {
    x += cnt * b;
    y -= cnt * a;
}

lli find_all_solutions(lli a, lli b, lli c, lli minx, lli maxx, lli miny, lli maxy) {
    lli x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    lli sign_a = a > 0 ? +1 : -1;
    lli sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    lli lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    lli rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    lli lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    lli rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    lli lx = max(lx1, lx2);
    lli rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    lli curr_x=lx ;
    lli num1=a, num2=curr_x, den=b, g1, g2 ;
    g1=__gcd(num1, den) ;
    num1/=g1 ;
    den/=g1 ;
    g2=__gcd(num2, den) ;
    num2/=g2 ;
    den/=g2 ;
    lli curr_y=(c-num1*num2)/den, k=1 ;
    while(curr_x<=rx)
      {
        if(curr_x+curr_y<=maxx && curr_x*a+curr_y*b==c)
          {
            cout<< curr_y << " " << curr_x << " " << maxx-curr_x-curr_y << endl ;
            return 1 ;
          }
        curr_x=curr_x+k*(b/g) ;
        num1=a, num2=curr_x, den=b ;
        g1=__gcd(num1, den) ;
        num1/=g1 ;
        den/=g1 ;
        g2=__gcd(num2, den) ;
        num2/=g2 ;
        den/=g2 ;
        curr_y=(c-num1*num2)/den, k=1 ;
        k++ ;
      }
    return 0 ;
}

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, p, d, w, x, y, z, g ;
    cin>> n >> p >> d >> w ;
    if(!p) cout<< 0 << " " << 0 << " " << n << endl ;
    else if(!find_all_solutions(w, d, p, 0, n, 0, n)) cout<< -1 << endl ;
  }
