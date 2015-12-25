#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a;
    bool binary[10];
    int i=0;
    int decimal;
    cout<<"\n\n\tEnter the decimal number  : ";
    cin>>decimal;
    while(decimal!=0)
    {
       binary[i]=decimal%2;
       decimal=decimal/2;
       i++;
    }
    cout<<"\n\n\tThe binary number is      : ";
    for(int n=i-1;n>=0;n--)
      cout<<binary[n];
    cout<<endl;   
    system("pause");
}                
