#include <iostream>
using namespace std;
void line()
{
   cout<<"\n_______________________________________________________________________________\n"; 	 
}

void FormulaOfFajar()
{
 	cout<<"\n";
	cout<<""; 
}
void FormulaOfZuhr()
{
    char a=183;
	cout<<"\n";
	cout<<"\tZ = 12^h + ("<<a<<"zonetime - "<<a<<"local)/15 + Eqt/60 + Semi diameter of Sun\n\n";
	cout<<"\tWhere : \n\n\t\t"<<a<<" is represent 'Lambda' or Longitude \n\n";	 
}
void FormulaOfAsr()
{
 	 
}
void FormulaOfMaghrib()
{   char a=235;
 	cout<< "Maghrib = Zuhar + (1/15) cos^-1[(-sin D - sin \x9B sin "<<a<<")/(cos \x9B cos "<<a<<")]\n\n"; 
    cout<<"\tWhere : \n\n\t\t\x9B is represent 'phi' or longitude and \n\n\t\t"<<a<<"is represent latitude \n\n";

}
void FormulaOfIsha()
{
    char a=235;
    cout<< "Esha = Zuhar + (1/15) cos^-1[(-sin (AIT) - sin \x9B sin "<<a<<")/(cos \x9B cos "<<a<<")]\n\n"; 
    cout<<"\tWhere : \n\n\t\t\x9B is represent 'phi' or longitude and \n\n\t\t"<<a<<"is represent latitude \n\n";
	cout<<"\t\tAIT is Astronomical Twilight of Karachi is 180\xF8\n\n" ;
}

