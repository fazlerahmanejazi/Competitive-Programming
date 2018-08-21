/* Name- Fazle Rahman Ejazi
   Roll No- 1601CS13
   Objective- Program to print the last two digits of Roll No in seven segment display.
   Date- 1/24/2017
*/

#include<stdio.h>

char num[7][5], character ; // 'num' array stores the output which the shape of the number in seven segment display. 'character' stores the character user has entered.
int i, j ; // These are declared for loops.

void top(char temp) //This function fills the uppermost line of the seven segment display.
{
 if(temp=='1') return ;
 for(i=0 ; i<5 ; i++)
  num[0][i]=character ;
 return ;
}

void bottom(char temp) //This function fills the bottommost line of the seven segment display.
{
 if(temp=='1' || temp=='4' || temp=='7' || temp=='9') return ;
 for(i=0 ; i<5 ; i++)
  num[6][i]=character ;
 return ;
}

void left(char temp) //This function fills the leftmost line of the seven segment display.
{
 if(temp=='2')
 {
  for(i=3 ; i<7 ; i++)
   num[i][0]=character ;
  return ;
 }

 if(temp=='4' || temp=='5' || temp=='9')
 {
  for(i=0 ; i<4 ; i++)
   num[i][0]=character ;
  return ;
 }

 if(temp=='0' || temp=='6' || temp=='8')
 {
  for(i=0 ; i<7 ; i++)
   num[i][0]=character ;
  return ;
 }
}

void right(char temp) //This function fills the rightmost line of the seven segment display.
{
 if(temp=='2')
 {
  for(i=0 ; i<4 ; i++)
   num[i][4]=character ;
  return ;
 }

 if(temp=='5' || temp=='6')
 {
  for(i=3 ; i<7 ; i++)
   num[i][4]=character ;
  return ;
 }

 for(i=0 ; i<7 ; i++)
  num[i][4]=character ;
 return ;

}

void middle(char temp) //This function fills the middle line of the seven segment display.
{
 if(temp=='0' || temp=='1' || temp=='7') return ;
 for(i=0 ; i<5 ; i++)
  num[3][i]=character ;
 return ;

}

void draw(char temp) //This function draws the ouput in seven segment display.
{
 top(temp) ;
 bottom(temp) ;
 left(temp) ;
 right(temp) ;
 middle(temp) ;
return ;
}

void clear() //This function clears the num array by alloting " " character to it.
{
  for(i=0 ; i<7 ; i++)
    for(j=0 ; j<5 ; j++)
     num[i][j]=' ' ;
}

int main()
{
 char first, second ; //'first' stores the first number of the roll number. 'second' stores the second number of roll number.

 //Taking input
 printf("Enter last two digits of your Roll.No: ") ;
 scanf("%c%c" , &first, &second) ;
 scanf("%c" , &character) ;
 printf("Enter the Character for display: ") ;
 scanf("%c" , &character) ;
 printf("\n") ;

 clear() ; //Calling function to clear the num array.
 draw(first) ; //Calling function to to draw the first number in seven segment display.

 //Printing ouput of first number
 for(i=0 ; i<7 ; i++)
  {
    for(j=0 ; j<5 ; j++)
    {
     printf("%c", num[i][j]) ;
    }
   printf("\n") ;
  }

 printf("\n") ;

 clear() ; //Calling function to clear the num array.
 draw(second) ; //Calling function to to draw the first number in seven segment display.

 //Printing output of second number
 for(i=0 ; i<7 ; i++)
  {
    for(j=0 ; j<5 ; j++)
    {
     printf("%c", num[i][j]) ;
    }
   printf("\n") ;
  }
 return 0 ;
}
