void buildTree(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e)
      {
        tree[idx]=a[s] ;
        return ;
      }
    buildTree(2*idx, s, (s+e)/2) ;
    buildTree(2*idx+1, (s+e)/2+1, e) ;
    tree[idx]=max(tree[2*idx], tree[2*idx+1]) ;
  }

int query(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return 0 ;
    if(s>=qs && e<=qe) return tree[idx] ;
    return max(query(2*idx, s, (s+e)/2, qs, qe), query(2*idx+1, (s+e)/2+1, e, qs, qe));
  }

void updateNode(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e)
      {
        tree[idx]=max(tree[idx], val) ;
        return ;
      }
    updateNode(2*idx, s, (s+e)/2, pos, val) ;
    updateNode(2*idx+1, (s+e)/2+1, e, pos, val) ;
    tree[idx]=max(tree[2*idx],tree[2*idx+1]) ;
  }
