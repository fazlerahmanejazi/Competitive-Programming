#define end _end
#define next _nxt

const int MaxN=500500 ;

int sz, next[27][MaxN], end[MaxN] ;
bool created[MaxN];

void insert(string &s)
  {
    int v=0 ;
    for(int i=0 ; i<s.size() ; i++)
      {
        int c=s[i]-'a' ;
        if(!created[next[c][v]])
          {
            next[c][v]=++sz ;
            created[sz]=true ;
          }
        v=next[c][v] ;
      }
    ++end[v] ;
  }

bool search(string tmp)
  {
    int v=0 ;
    for(int i=0 ; i<tmp.size() ; i++)
      {
        int c=tmp[i]-'a' ;
        if(!created[next[c][v]]) return false ;
        v=next[c][v] ;
      }
    return end[v]>0 ;
  }
