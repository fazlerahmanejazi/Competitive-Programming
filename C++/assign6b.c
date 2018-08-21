/* Name- Fazle Rahman Ejazi
	 Roll No- 1601CS13
	 Objective- Program to print the different combinations of distribution of overs between different bowlers
   Date- 14 February 2017
*/

#include<stdio.h>

// n, i, j are used for loops
// count is used for storing the bowler count
// bowlers stores the total number of bowlers available
// maximum stores the maximum number of overs one bowler can bowl
// ans stores the anwers to be printed
// sum is current sum of overs distributed to the bowlers
int n, i, j, count, bowlers, maximum, total, ans[10], sum ;

void combinations(int k) //This recursive function prints all different combinations
	{
		if(count>n || sum>total) return ;
		if(count==n && sum==total)
			{
				for(j=0 ; j<n ; j++)
					printf("%d ", ans[j]) ; //Printing the combination
				printf("\n") ;
				return ;
			}
		int z ;
		for(z=k ; z>=0 ; z--)
			{
						count++ ; //Increasing the bowler count
						ans[count-1]=z ;
						sum=sum+z ; //Increasing the sum of overs distributed to the bowlers
						combinations(z) ; //Recursively calling the function
						count-- ; //Decreasing the bowler count
						sum=sum-z ; //Decreasing the sum of overs distributed to the bowlers
			}
	}

int main()
{
	//Taking input
	printf("Total overs: ") ;
	scanf("%d%*c", &total) ;
        printf("Maximum number of overs for one bowler: ") ;
	scanf("%d%*c", &maximum) ;
        printf("Number of bowlers: ") ;
	scanf("%d%*c", &bowlers) ;
	count=0 ;
	n=bowlers ;
	sum=0 ;
	combinations(maximum) ; //Calling the function
	return 0 ;
}
