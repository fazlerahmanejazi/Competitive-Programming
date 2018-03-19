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
