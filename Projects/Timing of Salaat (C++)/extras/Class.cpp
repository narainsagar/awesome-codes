#include<iostream>
#include "Class.h"
SalaatTime::SalaatTime()
{
    lambda_zone=0.0;
    longitude=0.0;
    latitude=0.0;
    Eqt=0.0;
    semi_diameter=1.0;
    AIT=18;
	D=0.8333;
	zuhar_time=0.0;	 						 
}
void SalaatTime::printTime(string s,int hh,int mm,int ss)
{
     line();
	 cout<<"\n\t\t\t"<<s<<"TIME\n   ";
	 line();
     cout<<"\n\t\t\t"<<hh<<" : "<<mm<<" : "<<ss<<"\n";
	 line();	  
}
void SalaatTime::InputData()
{   double zone;
 	fflush(stdin);
 	line();
 	cout<<"\n\t\t\tPLEASE INPUT THE VALID FOLLOWING DATA\n";
   	line();
    cout<<"\n\nEnter time zone = ";cin>>zone;
   	cout<<"\nEnter G.M.T = ";cin>>gmt;
   	cout<<"\nEnter longitude (lambda)= ";cin>>longitude;
   	cout<<"\nEnter latitude (phi) = ";cin>>latitude;
    cout<<"\nEnter Equation of time (E)= ";cin>>Eqt;	 
    cout<<"\nEnter Declinition of the sun (rho) = ";cin>>declinition_of_sun;	 
    lambda_zone=zone*gmt; 
}



void SalaatTime::CalculateZuhrTime()
{  
    double lambda,E,total,mins,secs,hrs;
    int hours,minutes,seconds;
	      
	lambda=(lambda_zone-longitude)/15;
	E=Eqt/60;
//	calc=(lambda+E)*60;//+semi_diameter;
	
	total=12+lambda+E+semi_diameter;
	zuhar_time=total;
//	cout<<"Total = "<<total<<"\n\n";
	hrs=floor(total);
	hours=int(hrs);
	mins=(total-hours)*60;
//	calc=mins;
//	cout<<"\n\ncalc = "<<calc<<"\nmins="<<mins;
	minutes=int(floor(mins));
//	cout<<"\n\nminutes = "<<minutes;
	secs=(mins-minutes)*60;
//	cout<<"\n\nsecs = "<<secs;
	seconds=int(secs);
	printTime(" ZUHAR ",hours,minutes,seconds);
/*	
cout<<"\n\n\t\t\tZUHAR TIME\n\n";
   cout<<"\nHours   = "<<hours;	
   cout<<"\nMinutes = "<<minutes;	
   cout<<"\nSeconds = "<<seconds;	*/
}

void SalaatTime::CalculateMaghribTime()
{
 	double H,calc,total,mins,secs,hrs;
	int hours,minutes,seconds; 
//	cout<<"\nD="<<D<<"\nlatitude ="<<latitude<<"\ndeclinition = "<<declinition_of_sun;
	H=(((-1*sin(D))-((sin(latitude)*sin(declinition_of_sun))))/(cos(latitude)*cos(declinition_of_sun))) ; 
//	cout<<"\nH ="<<H;
	calc=(acos(H)*57.296);
//	cout<<"\ncalc ="<<calc;
cout<<"\n***ZHAR TIME "<<zuhar_time<<"\n";
	total=(zuhar_time+(calc/15));
	
	hrs=floor(total);
	hours=int(hrs);
	mins=(total-hours)*60;
	
	minutes=int(floor(mins));
//	cout<<"\n\nminutes = "<<minutes;
	secs=(mins-minutes)*60;
//	cout<<"\n\nsecs = "<<secs;
	seconds=int(secs);
	printTime(" MAGHRIB ",hours,minutes,seconds);

/*	
cout<<"\n\n\t\t\tMAGHRIB TIME\n\n";
    cout<<"\nHours   = "<<hours;	
    cout<<"\nMinutes = "<<minutes;	
    cout<<"\nSeconds = "<<seconds;	*/
}

void SalaatTime::CalculateIshaTime()
{
    double H,calc,total,mins,secs,hrs;
	int hours,minutes,seconds; 
//	cout<<"\nAIT="<<AIT<<"\nlatitude ="<<latitude<<"\ndeclinition = "<<declinition_of_sun;
	H=(((-1*sin(AIT))-((sin(latitude)*sin(declinition_of_sun))))/(cos(latitude)*cos(declinition_of_sun))) ; 
//	cout<<"\nH ="<<H;
	calc=(acos(H)*57.296);
//	cout<<"\ncalc ="<<calc;
cout<<"\n***ZHAR TIME "<<zuhar_time<<"\n";	
	total=(zuhar_time+(calc/15));
	
	hrs=floor(total);
	hours=int(hrs);
	mins=(total-hours)*60;
	
	minutes=int(floor(mins));
//	cout<<"\n\nminutes = "<<minutes;
	secs=(mins-minutes)*60;
//	cout<<"\n\nsecs = "<<secs;
	seconds=int(secs);
	printTime(" ISHA ",hours,minutes,seconds);
	
/*	
cout<<"\n\n\t\t\tISHA TIME\n\n";
    cout<<"\nHours   = "<<hours;	
    cout<<"\nMinutes = "<<minutes;	
    cout<<"\nSeconds = "<<seconds;	 */
}

void SalaatTime::CalculateFajarTime()
{
    double H,calc,total,mins,secs,hrs;
	int hours,minutes,seconds; 
//	cout<<"\nAIT="<<AIT<<"\nlatitude ="<<latitude<<"\ndeclinition = "<<declinition_of_sun;
	H=(((-1*sin(AIT))-((sin(latitude)*sin(declinition_of_sun))))/(cos(latitude)*cos(declinition_of_sun))) ; 
//	cout<<"\nH ="<<H;
	calc=(acos(H)*57.296);
//	cout<<"\ncalc ="<<calc;
cout<<"\n***ZHAR TIME "<<zuhar_time<<"\n";
	total=(zuhar_time-(calc/15));
	
	hrs=floor(total);
	hours=int(hrs);
	mins=(total-hours)*60;
	
	minutes=int(floor(mins));
//	cout<<"\n\nminutes = "<<minutes;
	secs=(mins-minutes)*60;
//	cout<<"\n\nsecs = "<<secs;
	seconds=int(secs);
	
	printTime(" FAJAR ",hours,minutes,seconds);
	
	/*
   cout<<"\n\n\t\t\tFAJAR TIME\n\n";
    cout<<"\nHours   = "<<hours;	
    cout<<"\nMinutes = "<<minutes;	
    cout<<"\nSeconds = "<<seconds;	*/ 
}
