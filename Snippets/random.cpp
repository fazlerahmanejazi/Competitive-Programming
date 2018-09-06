static random_device rd ;
static mt19937 rng(rd()) ;

lli dice()
  {
    uniform_int_distribution<lli> uid(l, r) ; //specify range (l, r)
    return uid(rng) ;
  }
