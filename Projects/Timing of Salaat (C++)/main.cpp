#include<iostream>
using namespace std;
#include "Globel.h"
#include "Class.h"
int main()
{   system("color 0D");
 	SalaatTime time;  
    line(); 
	cout<< "\n\t\t\tCALCULATE THE TIMING OF SALAAT\n" ;
	//FormulaOfZuhr();
    //	FormulaOfMaghrib();
	time.InputData();
    time.CalculateZuhrTime();
    time.CalculateMaghribTime();
    time.CalculateIshaTime();
    time.CalculateFajarTime();
   //time.CalculateAsrTime();
  cout<<"\n";	
  system("pause");
  return 0;
}
