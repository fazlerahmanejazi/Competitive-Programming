struct node
  {
    node *left, *right ;
    node() { left=right=NULL ; }
  } *root ;

void insert(node *root, int n)
  {
    int x ;
    for(int i=20 ; i>=0 ; i--)
      {
        x=(n>>i)&1 ;
        if(x)
          {
            if(root->right==NULL) root->right=new node() ;
            root=root->right ;
          }
        else
          {
            if(root->left==NULL) root->left=new node() ;
            root=root->left ;
          }
      }
  }

int query(node *root, int q)
  {
    int x, ans ;
    for(int i=20 ; i>=0 ; i--)
      {
        x=(q>>i)&1 ;
        if(x)
          {
            //
          }
        else
          {
            //
          }
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    root=new node() ;
  }
