#include<iostream>
#include<fstream>
using namespace std;
int main()
{ string temp;
  ifstream read;
  read.open("doubleWords.txt");
  while(!read.eof())
  {bool contain=false;
    read>>temp;
    for(int i=0;i<temp.size();i++)
      if(temp[i]==temp[i+1])  
        contain=true;  
    if(contain)
      cout<<temp<<" ";                   
  }
  system("pause");
  return 0;
}
