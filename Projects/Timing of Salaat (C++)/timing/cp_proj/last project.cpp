#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
  int gmt;
  double longitude_of_your_area; //longitude_of_your_area
  double equation_of_time;
  double phi;                //phi
  double declination_of_sun; //declination of the sun
  double D;                  //D
  double AIT, a, AH;         //AIT
  double zonetime;
  int dayoftheyear;
  double B;
  double AB;

  int hours;
  int minutes;
  int seconds;
  int semidiameter_of_sun;
  double H, I;
  double zuhar;
  double maghrib;
  double Isha;
  double Fajar;
  double asar;
  int day;
  int month;

  cout << "AIT:";
  cin >> AIT;
  cout << "\n\nday"
       << ":";
  cin >> day;
  cout << endl
       << endl;
  cout << "month"
       << ":";
  cin >> month;
  cout << endl
       << endl;

  if (month == 1)
    dayoftheyear = day;
  if (month == 2)
    dayoftheyear = day + 31;
  if (month == 3)
    dayoftheyear = day + 59;
  if (month == 4)
    dayoftheyear = day + 90;
  if (month == 5)
    dayoftheyear = day + 120;
  if (month == 6)
    dayoftheyear = day + 151;
  if (month == 7)
    dayoftheyear = day + 181;
  if (month == 8)
    dayoftheyear = day + 212;
  if (month == 9)
    dayoftheyear = day + 243;
  if (month == 10)
    dayoftheyear = day + 273;
  if (month == 11)
    dayoftheyear = day + 304;
  if (month == 12)
    dayoftheyear = day + 335;

  B = ((6.283185306 * dayoftheyear) / 365) * 0.01745; //Beta angle

  equation_of_time = 229.18 * (0.000075 + (0.001868 * cos(B)) - (0.032077 * sin(B)) - (0.014615 * cos(2 * B)) - (0.040849 * (sin(2 * B))));
  //cout<<"\\n\nequation_of_time ="<<equation_of_time<<"\n\n\n";
  vector<string> myvector;
  string name_of_the_city, string1, string2, string3, string4, str;

  cout << "Enter city's name: ";
  cin >> name_of_the_city;
  ifstream myReadFile;
  myReadFile.open("variableslist.txt");
  if (myReadFile.is_open())
  {
    while (!myReadFile.eof())
    {
      myReadFile >> string3;
      myvector.push_back(string3);
    }
  }
  for (int i = 0; i < myvector.size(); i++)
  {
    if (myvector[i] == name_of_the_city)
    {
      str = myvector[i + 1];
      string2 = myvector[i + 2];
      string4 = myvector[i + 3];
      cout << "The Longitude of " << myvector[i] << "is " << myvector[i + 1] << endl;
      cout << "The gmt of " << myvector[i] << "is " << myvector[i + 2] << endl;
      cout << "The phi of " << myvector[i] << "is " << myvector[i + 3] << endl;
    }
  }
  longitude_of_your_area = atof(str.c_str());

  // longitude_of_your_area = atof(str.c_str());
  gmt = atoi(string2.c_str());
  //gmt=atof(str.c_str());
  phi = atof(string4.c_str()); // #include<sstream>
  //phi= atof(str.c_str());
  myReadFile.close();
  cout << endl;
  zonetime = gmt * 15;
  phi = phi * 0.0174;
  D = D * 0.0174;
  declination_of_sun = declination_of_sun * 0.0174;
  AIT = AIT * 0.0174;
  //ZUHAR PRAYER TIMINGS
  zuhar = 12 + ((zonetime - longitude_of_your_area) / 15) + (equation_of_time / 60);
  double m = 1 + ((zonetime - longitude_of_your_area) / 15) + ((equation_of_time / 60)) * 60;
  double s = ((equation_of_time / 60)) * 60;
  hours = int(zuhar);
  // hours=zuhar;
  minutes = int(1 + (zuhar - hours) * 60);
  cout << "*****************Zuhar prayer time is**********************" << endl
       << endl
       << endl;

  cout << "\t"
       << "\t"
       << "\t" << hours << ":" << minutes << "pm" << endl;

  //MAGHRIB PRAYER TIMINGS

  H = acos((-sin(D) - (sin(phi) * sin(declination_of_sun))) / (cos(phi) * cos(declination_of_sun)));
  AB = (H * 57.295) / 15;
  maghrib = zuhar + AB;
  hours = int(maghrib);
  minutes = int((maghrib - hours) * 60);
  cout << "*****************maghrib prayer time is**********************" << endl
       << endl
       << endl;
  cout << "\t"
       << "\t"
       << "\t" << hours << ":" << minutes << "pm" << endl;

  // cout<<"H="<<(H*57.295)<<endl;
  //FAJAR ....................................................
  /* double a=sin(AIT);
              cout<<"a="<<a<<endl;
              double b=sin(phi);
              cout<<"b="<<b<<endl;
              double c=sin(declination_of_sun);
              cout<<"c="<<c<<endl;
             
              double d=cos(phi);
              cout<<"d="<<d<<endl;
               double e=cos(declination_of_sun);
              cout<<"e="<<e<<endl;
               I=(a-(b*c))/(d*e);
              cout<<"I="<<I*57.295<<endl;*/

  I = acos((sin(AIT) - (sin(phi) * sin(declination_of_sun))) / (cos(phi) * (cos(declination_of_sun)))); //0.534
  cout << "I=" << (I * 57.295) / 15 << endl;
  double CD = (I * 57.295) / 15;
  //cout<<"AB="<<AB<<endl;
  //*************************FAJAR PRAYER TIMING***************************************
  Fajar = zuhar - CD;
  hours = int(Fajar);
  minutes = int((Fajar - hours) * 60);
  cout << "*****************FAJAR prayer time is**********************" << endl
       << endl
       << endl;
  cout << "\t"
       << "\t"
       << "\t" << hours << ":" << minutes << "am" << endl;
  //*************************ASAR PRAYER TIMING***********************************
  a = tan(2 + tan(phi - declination_of_sun));

  double pq = phi - declination_of_sun;
  cout << "pq=" << pq << endl;
  double p = (tan(pq));
  cout << "p=" << p << endl;
  double q = 2 + p;
  cout << "q=" << q << endl;
  double r = tan(q);
  cout << "r=" << r * 57.295 << endl;

  H = (acos((sin(p) - (sin(phi) * sin(declination_of_sun)) / (cos(phi) * cos(declination_of_sun))))) / 15;
  asar = zuhar - (H * 57.295);
  hours = int(asar);
  minutes = int((asar - hours) * 60);

  cout << "*****************ASAR prayer time is**********************" << endl
       << endl
       << endl;
  cout << "\t"
       << "\t"
       << "\t" << hours << ":" << minutes << "pm" << endl;

  system("pause");
  return 0;
}
