/* Name- Fazle Rahman Ejazi
	 Roll No- 1601CS13
	 Objective- Program to print the different permutations of a set of words
   Date- 14 February 2017
*/


#include<stdio.h>
#include<stdlib.h>

// n stores the number of words
// i, j, k are used for loops
// comma is used for determining whether to print comma after a word or not
// letters array stores the given set of letters
// temp is used to detect the end of input
// ans array stores the answer to be printed
// prev array stores all those unique permutations of letters which have been printed already
// taken array stores whether any element is used or not
int n, i, k, j, comma ;
long long int count ;
char letters[100], temp, ans[100], taken[100], prev[10000000][100] ;

int cmpfunc (const void * a, const void * b)    //This comparator function is used to sort the array
{
   return ( *(char*)a - *(char*)b );
}

int duplicate() //This function checks whether the current permutation of letters has already been printed or not
  {
    int check, q ;
    long long int w ;
    for(w=0 ; w<count ; w++)
      {
        check=0 ;
        for(q=0 ; q<n ; q++)
          if(ans[q]==prev[w][q])
            check++ ;
        if(check==n) return 1 ; //returns 1 if there is duplicacy
      }
    return 0 ; //returns 0 if there is not any duplicacy
  }

void permutations() //This recursive function calculates all the permutations of the given set of letters
	{
		if(k==n)
			{
				if(comma==1)
					{
						if(duplicate()) return ;
						else printf(", ") ;
					}
				for(j=0 ; j<n ; j++) //Printing the permutation
					{
						printf("%c", ans[j]) ;
						prev[count][j]=ans[j] ;
					}
				count++ ;
        comma=1 ;
			}
		int z ;
		for(z=0 ; z<n ; z++)
			{
				if(taken[z]==1)
					{
						k++ ; //Increasing the letter count
						taken[z]=0 ; //Marking the element as taken
						ans[k-1]=letters[z] ;
						permutations() ; //Recursive call to the function
						k-- ; //Decreasing the letter count
						taken[z]=1 ; //Marking the element as not taken
					}
			}
	}

int main()
{
  //Taking inputs
	printf("Number of letters: ") ;
	scanf("%d%*c", &n) ;
	printf("Enter the letters: ") ;
	i=0 ;
	while(1)
		{
			scanf("%c", &temp) ;
			letters[i]=temp ;
			taken[i]=1 ; //Setting all the elements as not taken
			scanf("%c", &temp) ;
			if(temp!=',') break ;
			i++ ;
		}
	qsort(letters, n, sizeof(char), cmpfunc) ; //Sorting the array
	k=0 ;
	comma=0 ;
	count=0 ;
	permutations() ; //Calling the function
	return 0 ;
}
