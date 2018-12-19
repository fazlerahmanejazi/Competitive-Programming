mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ;

lli dice()
  {
    uniform_int_distribution<lli> uid(l, r) ; //specify range (l, r)
    return uid(rng) ;
  }
