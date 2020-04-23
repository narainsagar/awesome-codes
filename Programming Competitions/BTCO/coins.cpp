#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  int n,dimes=0,quts=0,nickels=0,penis=0;
  int temp,sum=0;
  ifstream read;
  bool end=false;
  read.open("coins.txt");
  while(!read.eof()&& !end)
  {
    read>>n;
    if(n==0)
     end=true;
    else{
      quts=n/25; 
      n-=(quts*25);
      dimes=n/10;
      n-=(dimes*10); 
      nickels=n/5;
      n-=(nickels*5);
      penis=n/1;
      n-=(penis*1); 
      cout<<"\nQuarters : "<<quts;
      cout<<"\ndimes : "<<dimes;
      cout<<"\nnickels : "<<nickels;
      cout<<"\npenies : "<<penis<<endl<<endl;
    }                 
  }
  cout<<sum;
  system("pause");
  return 0;
}
