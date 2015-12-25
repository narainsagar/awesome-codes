#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double decimal=0;
    int binary,num,i=0,mod;
    cout<<"\tEnter the binary number"<<endl;
    cin>>binary;
    num=binary;
    while(num!=0)
    {
      mod=num%10;
      decimal+=mod*pow(2,i); 
      num/=10;
      i++;
    }
   cout<<"\tThe decimal number is : "<<decimal;
   cout<<endl;   
   system("pause");
   return 0;
}                
