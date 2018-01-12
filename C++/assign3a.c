/* Name- Fazle Rahman Ejazi
   Roll No- 1601CS13
   Objective- Program to find the number of choices a Boat building company has to build boats given the time.
   Date- 1/24/2017
*/

#include<stdio.h>

/*This function calculates the number of choices by using the fact that number of choices for nth day is equal to the
  sum of number of choices for (n-1)th day and (n-2)th day. On observing carefully, it can be seen that the number of choices
  on nth day forms fibonacci sequence which is 1, 2, 3, 5, 8, 13, 21, 34, 55 and so on, where the sum of the nth element is equal to sum
  of (n-1)th and (n-2)th element.
*/
int count(int n) //This function calculates the number of choices.
{
  if(n==2) return 2 ;
  if(n==1) return 1 ;
  return count(n-1)+count(n-2) ; //Number of choices for nth day is sum of number of choices for (n-1)th day and (n-2)th day.
}

int main()
{
  int n, ans ; //'n' represents number of days, 'ans' stores the result.
  printf("Enter the month after which the area is to be closed: ") ;
  scanf("%d", &n) ; //Taking input

  ans= count(n) ; //This function is called to count the number of choices.

  printf("There are %d choices of plan.", ans) ; //Printing the answer
return 0 ;
}
