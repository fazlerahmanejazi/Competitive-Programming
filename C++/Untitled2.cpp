#include <bits/stdc++.h>
using namespace std ;
#define PI 3.14159265

double solve(int x, int y)
{
  if(y==50)
   {
     if(x>=50) return 90 ;
     else return 270 ;
   }
   else
   {
     if(x>=50 && y>=50)
      return (atan(fabs(x-50)/fabs(y-50)))*180/PI ;

     else if(x>=50 && y<=50)
      return 180 - (atan(fabs(x-50)/fabs(y-50)))*180/PI ;

     else if(x<=50 && y<=50)
      return 180 + (atan(fabs(x-50)/fabs(y-50)))*180/PI ;

     else if(x<=50 && y>=50)
      return 360 - (atan(fabs(x-50)/fabs(y-50)))*180/PI ;
   }
}


int main()
{
  ios_base::sync_with_stdio (false) ;
  ifstream file;
  file.open("Progress Pie.txt");
  ofstream file2;
  file2.open("output.txt") ;
  int x, y, T, P ;
  file>> T ;
  for(int tc=1 ; tc<=T ; tc++)
  {
    file>> P >> x >> y ;
    double U, angle, r ;
    U= (P*360)/100 ;
    r= sqrt( (x-50)*(x-50) + (y-50)*(y-50) ) ;
    if(r==0 && P==0) { file2 << "Case #" <<tc<< ": white" << endl ; continue ; }
    angle= solve(x, y) ;
    if(angle<=U && r<=50) file2 << "Case #" <<tc<< ": black" << endl ;
    else file2 << "Case #" <<tc<< ": white" << endl ;
  }
  return 0 ;
}
