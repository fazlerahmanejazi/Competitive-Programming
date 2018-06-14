template<class T, int size> struct fenwick
  {
    T a[size] ;
    /* precondition: pos > 0 */
    void add(int pos, const T& val)
      {
        while(pos<size)
          {
            a[pos]+=val ;
            pos+=pos&-pos ;
          }
      }

    T sum(int pos)
      {
        T ret=T() ;
        while(pos>0)
          {
            ret+=a[pos] ;
            pos-=pos&-pos ;
          }
        return ret ;
      }
  } ;
