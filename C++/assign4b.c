/* Name- Fazle Rahman Ejazi
   Roll No- 1601CS13
   Objective- Program to print Binary representation, Hamming distance, Hamming weight, Hexadecimal representation of two given numbers
   Date-31-1-2017
*/

#include<stdio.h>
#include<math.h> //Included to use log2(), sqrt(), ceil() functions

int main()
{
  // number[2] stores the two given numbers
  // digitBinary[2] stores the number of digits in the binary representations of the given two numbers
  // hammer[2] stores hamming weight of the two binary numbers
  // hexa[2][10] stores the hexadecimal representations of the two given numbers
  // digitHexa[2] stores the number of digits in the hexadecimal representations of the two given numbers
  // binary[2] stores the binary representations of the two given numbers
  // hammer_distance stores the hamming distance between binary representations of the two given numbers
  // i, j are defined for loops
  // digit and temp are used while calculating binary and hexadecimal representations
  int number[2], digitBinary[2], hammer[2]={0}, hexa[2][10], digitHexa[2], binary[2][33] ;
  int hammer_distance=0, digit, temp, i, j ;
  char convert[6]={'A', 'B', 'C', 'D', 'E', 'F'} ; //This array is used for writing hexadecimal representations of the two given numbers

  //Taking inputs
  printf("Enter two decimal integers: ") ;
  scanf("%d, %d", &number[0], &number[1]) ;

  digitBinary[0]=log2(number[0]) ;
  digitBinary[1]=log2(number[1]) ;

  for(j=0 ; j<2 ; j++) //Decimal to Binary conversion for the two given numbers
   {
    temp=number[j] ;
    for(i=digitBinary[j] ; i>=0 && temp!=0 ; i--)
     {
      digit=temp%2 ;
      if(digit==1) hammer[j]++ ;
      temp=temp/2 ;
      binary[j][i]=digit ;
     }
   }

  digitHexa[0]=ceil(digitBinary[0]/4) ;
  digitHexa[1]=ceil(digitBinary[1]/4) ;

  for(j=0 ; j<2 ; j++) //Binary to Hexadecimal conversion for the two given numbers
  {
    temp=digitBinary[j] ;
    while(temp!=-1)
     {
       digit=0 ;
       if(temp>=0) { digit+=binary[j][temp]*1 ; temp-- ; }
       if(temp>=0) { digit+=binary[j][temp]*2 ; temp-- ; }
       if(temp>=0) { digit+=binary[j][temp]*4 ; temp-- ; }
       if(temp>=0) { digit+=binary[j][temp]*8 ; temp-- ; }

       if(digit>9)
         {
           hexa[j][digitHexa[j]]=convert[digit-10] ;
           digitHexa[j]-- ;
         }
       else
         {
           hexa[j][digitHexa[j]]=digit+'0' ;
           digitHexa[j]-- ;
         }
     }
  }
  //Printing binary representations
  for(j=0 ; j<2 ; j++)
    { printf("The binary representation for %d is ", number[j]) ;
      for(i=0 ; i<=digitBinary[j] ; i++)
        printf("%d", binary[j][i]) ;
      printf("\n") ;
    }

  //Printing hamming weights
  printf("Hamming weight for the first string = %d\n", hammer[0]) ;
  printf("Hamming weight for the second string = %d\n", hammer[1]) ;

  //Printing hamming distance if lengths of binary strings are equal
  if(digitBinary[0]==digitBinary[1])
    { for(i=0 ; i<=digitBinary[0] ; i++)
        if(binary[0][i]!=binary[1][i])
          hammer_distance++ ;
      printf("Hamming distance between the two strings = %d\n" , hammer_distance) ;
    }

  //Printing hexadecimal representations
  printf("The hexadecimal representation for the first string = ") ;
    for(i=0 ; i<=ceil(digitBinary[0]/4) ; i++)
      printf("%c" , hexa[0][i]) ;
  printf("\n") ;

  printf("The hexadecimal representation for the first string = ") ;
    for(i=0 ; i<=ceil(digitBinary[1]/4) ; i++)
      printf("%c" , hexa[1][i]) ;
  printf("\n") ;

return 0 ;
}
