#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  int n;
  int temp,sum=0;
  ifstream read;
  read.open("input.txt");
  while(!read.eof())
  {
    read>>n;
    for(int i=0;i<n;i++)
    {
      read>>temp;  
      sum+=temp;       
    }                  
  }
  cout<<sum;
  system("pause");
  return 0;
}
