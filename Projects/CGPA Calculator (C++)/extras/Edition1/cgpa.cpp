#include<conio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   char ch;
   int n;
   do
   {
   cout<<"\tHOW MANY SUBJECT YOU HAVE IN THIS SEMESTER  : ";cin>>n;
   float i,sub[n],cdthr[n],sgpa=0,tc;
   cout<<"\ntotal credit hour ="; cin>>tc; 
   for(i=0;i<n;i++)
   {
      cout<<"\nEnter gpa of subject : "<<i+1<<"= ";  cin>>sub[n];               
      cout<<"\ncredit hour : ";   cin>>cdthr[n];
      sgpa+=(sub[n]*cdthr[n])/tc;
   }
   cout<<"\ttotal CGPA is : "<<sgpa<<endl<<endl;
   cout<<"Do u want to continue (y/n)\n";
   cin>>ch;
   }while(ch!='n');
system("pause");
return 0; 
}
