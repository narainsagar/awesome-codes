#include<iostream>
#include<cmath>
class SalaatTime
{
  private:
  	double lambda_zone,
	       longitude,
	  	   Eqt,
      	   semi_diameter,
	  	   latitude,
	  	   AIT,
	  	   D,
      	   declinition_of_sun,
	  	   gmt,
      	   zuhar_time;	  
  public:
	 SalaatTime();
	 void InputData();
	 void CalculateZuhrTime();
	 void CalculateAsrTime();
	 void CalculateMaghribTime();
	 void CalculateIshaTime();	
     void CalculateFajarTime();   
	 void printTime(string s,int hh,int mm,int ss);
};
#include "Class.cpp"
