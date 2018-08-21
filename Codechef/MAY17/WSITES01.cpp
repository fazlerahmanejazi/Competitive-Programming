#include <bits/stdc++.h>
using namespace std ;

int n, x ;
char t ;
string s, temp ;
bool check, possible ;

struct node
  {
    struct node* child[30] ;
  } *head ;

void insert(string word)
  {
    node *curr=head ;
    for(int i=0 ; i<word.length() ; i++)
      {
        x=word[i]-'a' ;
        if(curr->child[x]==NULL) curr->child[x]=new node() ;
        curr=curr->child[x] ;
      }
  }

bool search(string word)
  {
    node *curr=head ;
    for(int i=0 ; i<word.length() ; i++)
      {
        if(curr->child[word[i]-'a']==NULL) return false ;
        curr=curr->child[word[i]-'a'] ;
      }
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin.tie(0) ;
    cin>> n ;
    possible=true ;
    head=new node() ;
    set<string> ans ;
    set<string>::iterator it ;
    vector<string> blocked ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> t >> s ;
        if(t=='+') insert(s) ;
        else blocked.push_back(s) ;
      }
    for(int i=0 ; i<blocked.size() ; i++)
      {
        s=blocked[i] ;
        check=false ;
        for(int j=1 ; j<=s.size() ; j++)
          {
            temp=s.substr(0, j) ;
            if(search(temp)==false)
              {
                ans.insert(temp) ;
                check=true ;
                break ;
              }
          }
        if(!check) possible=false ;
      }
    if(possible)
      {
        cout<< ans.size() << endl ;
        it=ans.begin() ;
        while(it!=ans.end())
          {
            cout<< *it << endl ;
            it++ ;
          }
      }
    else cout<< -1 ;
  }
