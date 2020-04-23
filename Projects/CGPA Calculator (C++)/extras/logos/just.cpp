#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
  int j=0,i=0,h=0,k=0;
  cout<<"\n\n\t\t\t\t";
  cout<<" P R O C E S S I N G ";
  cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
  while(j!=19)
  {
    cout<<"\xDB";
    Sleep(200); 
    j++;    
  }
  cout<<"\n\n\t\t\t\t";
  while(i!=20)
  {
    cout<<"\xDB";
    Sleep(200); 
    i++;    
  }
  cout<<"\n\t\t\t\t";
  while(h!=20)
  {
    cout<<" ";
    h++;            
  }
  while(k!=20)
  {
    cout<<"\b\xDB\b";
    Sleep(200); 
    k++;    
  } 
  cout<<"\n\n";
  system("pause");
  return 0;
}
