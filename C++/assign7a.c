/* Name- Fazle Rahman Ejazi
   Roll No- 1601CS13
   Objective- Program to check whether the given matrix is square matrix and further find it's highest minor and inverse(if exists)
   Date- 7th March, 2017
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> //To use pow() function

#define inf 100000

int determinant(int matrix[50][50], int n) //Function to find the determinant of a square matrix
{
  // ans stores the value of determinant
  // temp stores the temporary matrix formed
  // i, j, a, b, c are used to traverse the matrices
  int ans=0, temp[50][50], i, j, a, b, c;
  if (n==1) return (matrix[0][0]); //If order of matrix is one simply return the only element of matrix
  for(c=0 ; c<n ; c++)
   {
    a=0 ; b=0 ;
    for(i=0 ; i<n ; i++)
      {
        for(j=0 ; j<n ; j++)
          {
            if(i!=0 && j!=c)
             {
               temp[a][b++]=matrix[i][j];
               if(b==n-1) { a++ ; b=0 ; }
               }
           }
         }
      ans+=pow(-1,c)*(matrix[0][c]*determinant(temp, n-1)); //Recursively calling the determinant function again
    }
    return ans ;  //Returning the value of determinant
}

int main()
	 {
      // n, m are used to stores the dimensions of matrix
      // i, j, a, b, x, y are used for loops and traversing matrices
      // det stores the determinant of the matrix given
      // minor stores the highest minor value
      // minorX and minorY stores the position of highest minor
      // buffer behaves as temporary variable
      // c stores the comma and space while taking input
      // mat stores the given matrix
      // adj stores the adjoint of the matrix
      // temp is used while calculating adjoint of the matrix
			int n, m, i, j, a, b, x, y, det, minor, minorX, minorY, buffer ;
			int mat[50][50], adj[50][50], temp[50][50] ;
			char c ;
      //Taking inputs
			printf("\nEnter the size of the matrix (nxm) ") ;
			scanf("%d, %d", &n, &m) ;
      for(i=0 ; i<n ; i++)
			{
			    printf("Enter the elements of row %d =", i+1) ;
				for(j=0 ; j<m ; j++)
					{
						scanf("%d", &buffer) ;
						mat[i][j]=buffer ;
						if(j!=m-1) scanf("%c", &c) ;
						scanf("%c", &c) ;
					}
			}
      if(n!=m) //Checking whether the matrix is square or not
        {
          printf("\nThe entered matrix is not invertible") ;
          printf("\nThe entered matrix is not a square matrix.") ;
        }
      else
        {
          det=determinant(mat, n) ; //Calculating the determinant of the matrix
          minor=-inf ;
          //Calculating Adjoint of the matrix
          for (x=0 ; x<n ; x++)
           {
             for (y=0 ; y<n ; y++)
               {
                 a=0 ; b=0 ;
                 for (i=0 ; i<n ; i++)
                   {
                     for (j=0 ; j<n ; j++)
                       {
                         temp[0][0] ;
                         if (i!=x && j!=y)
                           {
                             temp[a][b++]=mat[i][j];
                             if(b==n-1) { a++ ; b=0 ; }
                           }
                       }
               adj[y][x]=pow(-1, x+y)*determinant(temp, n - 1); //Taking the transpose together with calculating the co-factors by exchanging x and y
                   }
               }
            }
            if(n==1) adj[0][0]=1 ;
          //Calculating the highest minor
          for(i=0 ; i<n ; i++)
    				for(j=0 ; j<m ; j++)
              {
                if(minor<pow(-1,i+j)*adj[i][j])
                  {
                    minor=pow(-1,i+j)*adj[i][j] ;
                    minorX=j ;
                    minorY=i ;
                  }
              }
          if(det==0) printf("\nThe entered matrix is not invertible") ; //If inverse does not exists.
          else
            {
              printf("\nThe entered matrix is invertible. The inverse matrix is: \n") ;
              //Printing the inverse of the matrix
              for(i=0 ; i<n ; i++)
                {
                  for(j=0 ; j<n ; j++)
                      printf("%d/%d " , adj[i][j], det);
                  printf("\n") ;
                }
            }
            printf("\nThe entered matrix is a square matrix.") ;
            printf("\nThe position of the element with highest minor is i=%d, j=%d\n", minorX+1, minorY+1) ;
        }
    return 0 ;
	 }
