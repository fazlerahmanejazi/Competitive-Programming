//returns a list of Ps on the convex hull in counter-clockwise order.
typedef double T;

struct P {
	T x, y;

	bool operator <(const P &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 3D cross product of OA and OB vectors, (i.e z-component of their "2D" cross product, but remember that it is not defined in "2D").
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the Ps are collinear.
coord2_t cross(const P &O, const P &A, const P &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<P> convex_hull(vector<P> P)
{
	size_t n = P.size(), k = 0;
	if (n <= 3) return P;
	vector<P> H(2*n);

	sort(P.begin(), P.end());

	// Build lower hull
	for (size_t i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (size_t i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= 0) k--;
		H[k++] = P[i-1];
	}

	H.resize(k-1);
	return H;
}
