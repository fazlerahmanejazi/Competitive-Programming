#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[200005];
vector<int> vec[200005],vec1[200005];
bool visit[200005];
int b[200005];
map<pair<int,int>,int> mp;
map<pair<int,int>,int> :: iterator it;
string s="";
vector<int> vec3;
int z,size;
vector<string> vec4;
void dfs(int index)
{
	if(size>=k)
		return;
	if(index==z)
	{
		size++;
		vec4.push_back(s);
		return;
	}
	for(int i=0;i<vec1[vec3[index]].size();i++)
	{
		s[vec1[vec3[index]][i]]='1';
		dfs(index+1);
		s[vec1[vec3[index]][i]]='0';
		if(size>=k)
			return;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

  	cin>>n>>m>>k;
  	if(n==1)
  	{
  		if(n==0)
  			cout<<"0\n";
  			return 0;
	  }
  	memset(visit,false,sizeof(visit));
  	memset(a,-1,sizeof(a));
  	memset(b,0,sizeof(b));
  	for (int i = 0; i < m; ++i)
  	{
  		int x,y;
  		cin>>x>>y;
  		mp[make_pair(x,y)]=i;
  		mp[make_pair(y,x)]=i;
  		vec[x].push_back(y);
  		vec[y].push_back(x);
  	//	a[i+1]=-1;
  //		b[i+1]=0;
  		visit[i+1]=false;
  		s+="0";
  	}
  	queue<int> q;
  	int count=1,qwe=1;
  	q.push(1);
  	bool is=false;
  	int level=0;
  	b[1]=1;
  	while(!q.empty()){
  		int l=q.size();
  		level++;
  		while(l--){
  			int g=q.front();
  			q.pop();
  			for(int i=0;i<vec[g].size();i++){
  				if(a[vec[g][i]]!=-1 && a[vec[g][i]]<level)
  					continue;
  				if(a[vec[g][i]]==-1)
  					a[vec[g][i]]=level,b[vec[g][i]]=b[g],q.push(vec[g][i]),count++,qwe++,vec1[vec[g][i]].push_back(mp[make_pair(g,vec[g][i])]);
  				else
  					b[vec[g][i]]+=b[g],vec1[vec[g][i]].push_back(mp[make_pair(vec[g][i],g)]);
  			}
  		}
  	}
  	if(qwe<n)
  	{
  		cout<<"0\n";
  		return 0;
	  }
  	for(int i=2;i<=n;i++)
  	{
  		if(vec1[i].size()>1)
  			vec3.push_back(i);
  		else if(vec1[i].size()==1)
  			s[vec1[i][0]]='1';
  		else
  		{
  			cout<<"0\n";
  			return 0;
		  }
  	}
  	if(vec3.empty())
  	{
  		cout<<"1\n"<<s<<endl;
  		return 0;
	  }
  	else
  	{
  		z=vec3.size();
  		dfs(0);
  	}
  	int x=vec4.size();
  	x=min(x,k);
  	cout<<x<<endl;
  	for (int i = 0; i < x; ++i)
  	{
  		/* code */
  		cout<<vec4[i]<<endl;
  	}
  	return 0;
}
