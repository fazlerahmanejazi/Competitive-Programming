#include <bits/stdc++.h>
#include <string>
#define SYNC ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ull unsigned long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 10000000000
#define in(a,b) ((b).find(a)!=(b).end())
#define fill(a,v) memset(a,v,sizeof(a))
#define rec(a,b) return !a ? b : gcd(b % a, a)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef pair<int, int> iPair;

int main()
{
	SYNC
	ll n,m;
	cin>>n>>m;

	ll arr[n+2];
	ll i;
	arr[0]=0;
	map<ll,ll> m1;
	m1[0]++;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
		m1[arr[i]]++;
	}
	arr[n+1]=m;
	m1[m]++;

	ll cum[n+6];
	for(i=n;i>=0;i--)
	{
		if(i==n||i==n-1)	cum[i]=arr[i+1]-arr[i];
		else
			cum[i]=cum[i+2]+arr[i+1]-arr[i];
	}
	cum[n+1]=0;
	cum[n+2]=0;
	cum[n+3]=0;
	cum[n+4]=0;
	cum[n+5]=0;
	//for(i=0;i<=n+1;i++)
	//	cout<<cum[i]<<"\n";
	ll res=cum[0];
	ll ans;
	for(i=0;i<=n+1;i++)
	{
		ll x1=arr[i]+1;
		if(x1<=m&&m1[x1]==0)
		{
			if(i%2==0)
			{
				ans=cum[0]-cum[i];
				ans+=1;
				ans+=cum[i+1];
				res=max(res,ans);
			}
			else
			{
				ans=cum[0]-cum[i+1];
				if(i<=n)
					ans+=arr[i+1]-(arr[i]+1);
				ans+=cum[i+2];
				res=max(ans,res);
			}
		}
		ll x2=arr[i]-1;
		if(x2>=0&&m1[x2]==0)
		{
			if(i%2==0)
			{
				ans=cum[0]-cum[i];
				ans+=1;
				ans+=cum[i+1];
				res=max(res,ans);
			}
			else
			{
				ans=cum[0]-cum[i-1];
				if(i>=1)
					ans+=(arr[i]-1)-arr[i-1];
				ans+=cum[i];
				res=max(res,ans);
			}
		}
	}
	cout<<res;
	return 0;
}
