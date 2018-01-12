/* Name- Fazle Rahman Ejazi
   Roll No- 1601CS13
   Objective- Program to print the perfect squares between a given range(boundary points inclusive)
   Date-31-1-2017
*/

#include<stdio.h>
#include<math.h> //To use functions such as sqrt() and ceil()

int main()
{
  int lower_bound, upper_bound, check=1, i ; //lower_bound and upper_bound stores the range between which perfect squares are to be printed
  printf("Enter the range of numbers:") ;
  while(check)  //check variable checks whether there exists atleast one perfect square in the given range or not
  {
    scanf("%d-%d", &lower_bound, &upper_bound) ; //Taking input
    lower_bound=ceil(sqrt(lower_bound)) ;
    upper_bound=sqrt(upper_bound) ;
    if(upper_bound<lower_bound) //If this happens, no perfect square in the given range exists
     {
       printf("No perfect square exists. Please enter another range: ") ;
       continue ;
     }
    //Further code gets executed only if atleast one perfect square exists between the specified range
    //Printing the answers
    printf("The perfect squares in the given range are: ") ;
    printf("%d" , (lower_bound)*(lower_bound)) ;
    for(i=lower_bound+1 ; i<=upper_bound ; i++)
    {
      if(i<upper_bound) printf(", %d", i*i) ;
      else printf(" and %d" , i*i) ;
    }
    check=0 ; //Since we have got atleast one perfect square in the specified range, loop will not be executed again, hence program will end
  }
 return 0 ;
}
