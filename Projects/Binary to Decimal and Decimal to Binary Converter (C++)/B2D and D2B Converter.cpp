#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
void line(){
     cout<<"\n________________________________________________________________________________\n";    
}
void binaryTodecimal(int binary){
    double decimal=0;
    int i=0,mod;
    int num=binary;
    while(num!=0)
    {
      mod=num%10;
      decimal+=mod*pow(2,i); 
      num/=10;
      i++;
    }
    cout<<"\n\tDecimal = "<<decimal;  
}
void decimalTobinary(int dec){
    int decimal=dec;
    int binary[10];
    int size=0;
    while(decimal!=0)
    {
       binary[size]=decimal%2;
       decimal=decimal/2;
       size++;
    }
    cout<<"\n\tBinary = "; 
    for(int i=size-1;i>=0;i--){
        cout<<binary[i];
    }
    cout<<endl;
}
int main()
{
    char ch;  
 do{
    system("cls");     
    int number;
    char choice;
    line();
    cout<<"\t\t      ...:: C O N V E R T E R  T O O L ::...";
    line();
    cout<<"\n\t\t\t 1. Binary To Decimal";
    cout<<"\n\n\t\t\t 2. Decimal To Binary";
    cout<<"\n\n\t\t\t 3. Exit Program\t\t";
    line();
    cout<<"\n\t\tEnter Choice : ";
    choice=getch();
    cout<<choice;
    line();
    switch(choice){
         case '1':
               cout<<"\n\t\tEnter Binary Number = ";
               cin>>number;
               line();
               cout<<"\n\tBinary = "<<number<<endl;
               binaryTodecimal(number);
               break; 
         case '2':
               cout<<"\n\t\tEnter Decimal Number = ";
               cin>>number;
               line();
               cout<<"\n\tDecimal = "<<number<<endl;
               decimalTobinary(number);  
               break;
         case '3': 
               exit(0);
               break;   
         default:
               cout<<"\n\t\tInvalid Choice..\n";
         break;
    }
    line();
    cout<<"\nDo you want to Continue(y/n) : ";
    ch=getch();
  }while(ch!='n');
    line();
    system("pause");
    return 0;
}   
