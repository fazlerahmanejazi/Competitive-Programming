#include <cstdio>
#include <cmath>
#include <vector>
#include <unordered_map>

struct ratio
{
    int x, y;

    ratio(int x, int y) : x(x), y(y) { }
    ratio() { }

    bool operator== (const ratio& p) const
    {
        return x == p.x && y == p.y;
    }
};

struct ratiohash // for std::unordered_map
{
    std::size_t operator()(const ratio &x) const
    {
        return x.x*31498571 + x.y;
    }
};

struct segment // structure representing a line segment
{
    int v1, v2, mul; // interval start, end, and number of entries along this line so far

    segment(int v1, int v2, int mul) : v1(v1), v2(v2), mul(mul) { }
};

int gcd(int a, int b)
{
    if(!a)
        return b;
    return gcd(b % a, a);
}

double calcLength(ratio slope, int x1, int x2)
{
    int dx = x2-x1;
    int dy = (dx*slope.y)/slope.x;
    double length = std::sqrt(double(dx*dx) + double(dy*dy));
    return length;
}

typedef ratio pos;

int main()
{
    int n;
    scanf("%d", &n);
    std::vector<pos> cities(n);

    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        cities[i] = pos(x, y);
    }

    double result = 0.f;
    for(auto it = cities.begin(); it < cities.end(); it++)
    {
        std::unordered_map<ratio, segment, ratiohash> h;
        h.reserve(300);
        for(auto it2 = cities.begin(); it2 < cities.end(); it2++)
        {
            if(it == it2)
                continue;
            pos c1 = *it, c2 = *it2;
            if(c2.x < c1.x) // c2 must always refers to the rightmost (or topmost) city
                std::swap(c1, c2);
            int dx = c2.x - c1.x;
            int dy = c2.y - c1.y;
            if(dx != 0)
            {
                // We map each slope to its (reduced) ratio
                int g = gcd(dx, dy);
                ratio slope = ratio(dx/g, dy/g);
                auto it = h.find(slope);
                if(it != h.end())
                {
                    int& np = it->second.mul; // Number of other cities along this line
                    int& x1 = it->second.v1;
                    int& x2 = it->second.v2;

                    // We update the result, so remove the old one
                    result -= calcLength(slope, x1, x2)/np;
                    if(c2.x > x2) // Possibly expand the interval
                        x2 = c2.x;
                    else if(c1.x < x1)
                        x1 = c1.x;
                    np++;
                    // We have to divide the result by the number of cities along this line since
                    // we will be recalculating it each time the outer loop encounters such a city
                    result += calcLength(slope, x1, x2)/double(np);
                }
                else
                {
                    // This is the first other city found along this slope. If there turns out to
                    // be only two cities along this line, we will be overestimating the result by
                    // 2 since our outer loop will reach the other city, so preemptively divide by 2
                    h.insert(std::make_pair(slope, segment(c1.x, c2.x, 2)));
                    result += calcLength(slope, c1.x, c2.x)/2.0f;
                }
            }
            else // dx = 0 - in this case the interval is not along the x axis but the y axis
            {    // so we adjust accordingly
                auto it = h.find(pos(0, 1));
                if(c2.y < c1.y)
                    std::swap(c1, c2);
                if(it != h.end())
                {
                    int& np = it->second.mul;
                    int& y1 = it->second.v1;
                    int& y2 = it->second.v2;
                    double dy = y2-y1;

                    result -= dy/np;
                    if(c2.y > y2)
                        y2 = c2.y;
                    else if(c1.y < y1)
                        y1 = c1.y;
                    np++;
                    result += (y2-y1)/double(np);
                }
                else
                {
                    h.insert(std::make_pair(pos(0, 1), segment(c1.y, c2.y, 2)));
                    result += std::abs(dy)/2.f;
                }
            }
        }
    }
    std::printf("%.0lfn", result);
    return 0;
}
