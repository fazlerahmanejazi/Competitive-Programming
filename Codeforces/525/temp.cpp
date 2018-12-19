#include <iostream>
using namespace std;
int a[2005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("%d\n",n+1);
    int sum=0;
    for (int i=n-1;i>=0;i--)
    {
        int add=(i-(a[i]+sum)%n+n)%n;
        printf("1 %d %d\n",i+1,add);
        sum+=add;
    }
    printf("2 %d %d",n,n);
}
