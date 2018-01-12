#include<stdio.h>
int totalover,bowler,maxover, a[10000] ;
void fx(int sum, int l)
{
	int k, j ;

	if(l==bowler && sum==totalover)
	{
		{
	     	for(k=0;k<bowler;k++)
			{
				printf("%d ",a[k]);
			}
			printf("\n") ;

	    }
	}
	else if(l>bowler || sum>totalover) return ;
	else
	{

			for(j=maxover;j>=0;j--)
			{
				a[l]=j;
				fx(sum+j,l+1);
			}

	}
}
int main()
{

	printf("Total overs:");
	scanf("%d",&totalover);
	printf("Maximum number of overs for one bowler: ");
	scanf("%d",&maxover);
	printf("Number of bowlers:");
	scanf("%d",&bowler);
	fx(0,0);

}
