#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
		int n, t, s, lim=0, overtake=1, ans=0, curr, cntNO=0, maxM=310 ;
    stack<int> speeds ;
		cin>> n ;
		cin>> t >> s ;
		curr=s ;
    speeds.push(maxM) ;
		for(int i=1 ; i<n ; i++)
			{
				cin>> t ;
				if(t==1)
					{
						cin>> s ;
						curr=s ;
						if(lim)
							{
                while(!speeds.empty())
                  if(curr>speeds.top())
                    ans++, speeds.pop() ;
                  else break ;
							}
					}
				else if(t==2)
					{
						if(!overtake) ans+=cntNO ;
						cntNO=0 ;
					}
				else if(t==3)
					{
						cin>> s ;
						lim=s ;
						if(lim && curr>lim) ans++ ;
						else speeds.push(s) ;
					}
				else if(t==4)
					{
						overtake=1 ;
						cntNO=0 ;
					}
				else if(t==5)
					{
						lim=0 ;
            speeds.push(maxM) ;
					}
				else if(t==6)
					{
						overtake=0 ;
						cntNO++ ;
					}
			}
		cout<< ans ;
	}
