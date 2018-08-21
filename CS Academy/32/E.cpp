#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;
#define pi 3.14159265358979323846

pair<double, double> p, last, curr, temp ;
double angle ;

double rads(double x)
  {
    return (pi*x)/180.0 ;
  }

pair<double, double> rotate(pair<double, double> q,  double  angle, pair<double, double> p)
  {
    double s = sin(angle);
    double c = cos(angle);

    p.x -= q.x;
    p.y -= q.y;

    double xnew = p.x * c - p.y * s;
    double ynew = p.x * s + p.y * c;

    p.x = xnew + q.x;
    p.y = ynew + q.y;
    return p;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    cin>> n ;
    p.x=0 ; p.y=0 ;
    angle=rads(360.0/n) ;
    last.x=0 ; last.y=0 ;
    curr.x=1 ; curr.y=0 ;
    cout<< last.x << " " << last.y << endl ;
    for(int i=1 ; i<n ; i++)
      {
        cout<< curr.x << " " << curr.y << endl ;
        double slope=atan((curr.y-last.y)/(curr.x-last.x)) ;
        last=curr ;
        curr.x+=cos(slope) ;
        curr.y+=sin(slope) ;
        curr=rotate(last, angle, curr) ;
      }

  }
