#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
  int min=0,sec=0,hr=0;
  while(1){
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n     \t\t\t\t";
    if(sec==59)
    {
       min++;
       sec=0;           
    }
    if(min<10 && sec<10)
      cout<<"0"<<min<<" :0"<<sec;
    else if(min>=10 && sec<10)
      cout<<min<<" : 0"<<sec;
    else if(min>=10 && sec>=10)
      cout<<min<<" : "<<sec;
    else if(min<10 && sec>=10)
      cout<<"0"<<min<<" : "<<sec;
    sec++;
    Sleep(1000);
  }

  system("pause");
  return 0;
}
