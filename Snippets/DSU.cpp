int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }
bool same(int i, int j)
  {
    return find(i)==find(j) ;
  }
void unionset(int i, int j)
  {
    int x=find(i) ; int y=find(j) ;
    if(x!=y) p[x]=y ;
  }

template<class T, int SZ> struct DSU
  {
    T p[SZ+1] ;
    DSU() { for(int i=0 ; i<=SZ ; i++) p[i]=i ; }
    T find(T i)
      {
        if(i!=p[i]) p[i]=find(p[i]) ;
        return p[i] ;
      }
    bool same(T i, T j) { return find(i)==find(j) ; }
    void unionset(T i, T j)
      {
        T x=find(i) ; T y=find(j) ;
        if(x!=y) p[x]=y ;
      }
  } ;

template<class T> struct DSU
  {
    map<T, T> par ;
    T comp_sz=n ; //initial component size
    T get(T u)
      {
        if(par.find(u)==par.end()) return u ;
        return par[u]=get(par[u]) ;
      }
    void unite(T x, T y)
      {
        T X=get(x), Y=get(y) ;
        if(X==Y) return ;
        par[Y]=X ;
        --comp_sz ;
      }
  } ;
