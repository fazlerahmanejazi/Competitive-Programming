#include<cstdio>
#include<cstring>
#define MOD 1000000007

using namespace std;
int Q,test,n,k, ras,m, mi, put[1000010];
char s[1000010];

int main() {

//freopen("input", "r", stdin);
//freopen("output", "w", stdout);
put[0] = 2;
for(int i =1; i <= 1000000; i++)
put[i] = put[i-1]*2 % MOD;
scanf("%d", &Q);
test =0;

while(Q--) {
test++;
printf("Case #%d: ", test);
scanf("%d %d\n", &n, &k);
//gets(s);
scanf("%s", &s);
mi= 0;
ras =0;
for(int i = n-1; i>= 0;i--){
if(mi < 0) mi = 0;
if(s[i] == 'B'){
if(mi == k){
ras = (ras + put[i]) % MOD;
mi--;}
else
mi++;
}
else
mi --;
}
printf("%d\n", ras);
}
return 0;
}
