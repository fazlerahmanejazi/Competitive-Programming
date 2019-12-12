#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-9;

typedef double T;

int sgn(T x) { return (x > EPS) - (x < -EPS);}


struct PT3 {
  T x, y, z;
  //PT3() {}
  PT3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
  PT3(const PT3 &p) : x(p.x), y(p.y), z(p.z) {}
  PT3 operator + (const PT3 &p) const { return PT3(x+p.x, y+p.y, z+p.z); }
  PT3 operator - (const PT3 &p) const { return PT3(x-p.x, y-p.y, z-p.z); }
  PT3 operator * (T c) const { return PT3(x*c, y*c, z*c); }
  PT3 operator / (T c) const { return PT3(x/c, y/c, y/c); }
  bool operator ==(const PT3 &p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS && fabs(z - p.z) < EPS; }
};

T dot(PT3 p, PT3 q) { return p.x*q.x+p.y*q.y+p.z*q.z; }
T dist2(PT3 p, PT3 q) { return dot(p-q,p-q); }
PT3 cross(PT3 v, PT3 w) { return PT3(v.y*w.z-v.z*w.y, v.z*w.x-v.x*w.z, v.x*w.y-v.y*w.x); }



struct LINE {
  PT3 p, v;
  LINE(){};
  LINE(const PT3& p, const PT3& v) : p(p), v(v) {}
  bool on(const PT3& pt) const{ return cross(pt - p, v) == PT3(0, 0, 0); }
};

struct PLANE {
  PT3 n;
  T d;
  PLANE() : d(0) {}
  PLANE(const PT3 &p1, const PT3 &p2, const PT3 &p3) {
    n = cross(p2 - p1, p3 - p1);
    d = -dot(n, p1);;
  }
};

int intersect(const LINE& l1, const LINE& l2, PT3& res){
  if (cross(l1.v,l2.v) == PT3(0, 0, 0)){
    if (cross(l1.v, l1.p - l2.p) == PT3(0, 0, 0)) return 2; // same
    return 0; // parallel
  }
  PT3 n = cross(l1.v,l2.v);
  PT3 p = l2.p - l1.p;
  if (sgn(dot(n,p))) return 0; // skew
  T t;
  if (sgn(n.x)) t = (p.y * l2.v.z - p.z * l2.v.y) / n.x;
  else if (sgn(n.y)) t = (p.z * l2.v.x - p.x * l2.v.z) / n.y;
  else if (sgn(n.z)) t = (p.x * l2.v.y - p.y * l2.v.x) / n.z;
  res = l1.p + l1.v * t;
  assert(l1.on(res)); assert(l2.on(res));
  return 1; // intersects
}

T dist(const LINE& l1, const LINE& l2){
  PT3 ret = l1.p - l2.p;
  ret = ret - l1.v * (dot(l1.v, ret) / dot(l1.v, l1.v));
  PT3 tmp = l2.v - l1.v * (dot(l1.v,l2.v) / dot(l1.v, l1.v));
  if (sgn(dot(tmp, tmp))) ret = ret - tmp * (dot(tmp,ret) / dot(tmp, tmp));
  return sqrt(dot(ret, ret));
}

void closest(const LINE& l1, const LINE& l2, PT3& p1, PT3& p2){
  if (cross(l1.v, l2.v) == PT3(0, 0, 0)){
    p1 = l1.p;
    p2 = l2.p - l1.v * (dot(l1.v,l2.p - l1.p) / dot(l1.v, l1.v));
    return;
  }
  PT3 p = l2.p - l1.p;
  T t1 = (dot(l1.v, p) * dot(l2.v, l2.v) - dot(l1.v, l2.v) * dot(l2.v, p)) / dot(cross(l1.v, l2.v), cross(l1.v, l2.v));
  T t2 = (dot(l2.v, l1.v) * dot(l1.v, p) - dot(l2.v, p) * dot(l1.v, l1.v)) / dot(cross(l2.v, l1.v), cross(l2.v, l1.v));
  p1 = l1.p + l1.v * t1;
  p2 = l2.p + l2.v * t2;
}

int main() {
  
}
