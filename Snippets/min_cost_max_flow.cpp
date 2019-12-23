/*Find the maximum flow, and among all maximal flows, find the one with the least cost.
  This is the minimum-cost maximum-flow problem.
  source is 0 and sink is N+1.
*/

template <int xn, int xe> struct mcmf
  {
    int head[xn], next[xe], to[xe], fl[xe], N, E, q[xn], fa[xn], ent[xn], in[xn];
    double dis[xe], co[xe];
    inline void add(int u, int v, int f, double c)
      {
        next[E]=head[u], to[E]=v, fl[E]=f, co[E]=c, head[u]=E++;
        next[E]=head[v], to[E]=u, fl[E]=0, co[E]=-c, head[v]=E++;
      }
    void clear(int n)
      {
        N=n, E=0;
        for (int i=0; i < n; i++)
        head[i]=-1;
      }
    bool spfa()
      {
        for(int i=0; i < N; i++) dis[i]=1e10, in[i]=0;
        dis[0]=0;
        in[0]=1;
        q[0]=0;
        int H=-1, T=0;
        while(H!=T)
          {
            if(++H==xn)
            H=0;
            int u=q[H];
            in[u]=0;
            for(int e=head[u]; ~e; e=next[e])
              if(fl[e] && dis[to[e]]>dis[u]+co[e])
                {
                  dis[to[e]]=dis[u]+co[e];
                  fa[to[e]]=u;
                  ent[to[e]]=e;
                  if(!in[to[e]])
                    {
                      if(++T==xn)
                      T=0;
                      in[q[T]=to[e]]=1;
                    }
                }
          }
        return dis[N-1] < 5e9;
      }
    std::pair<int, double> operator () ()
      {
        int f=0;
        double r=0;
        while (spfa())
          {
            f++;
            r+=dis[N-1];
            for(int i=N-1; i; i=fa[i])
              {
                fl[ent[i]]--;
                fl[ent[i]^1]++;
              }
          }
        return {f, r};
      }
  };
