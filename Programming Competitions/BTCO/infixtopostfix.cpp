#include<iostream>
using namespace std;
int main()
{
  string str="(a+b)*c+d+e*f-g";
 // string str="a+(b*c)/f";
  cout<<"\n\n input : "<<str<<endl;
  for(int i=0;i<str.size();i++){
    if(str[i]=='(' && str[i+4]==')'){
      swap(str[i+3],str[i+2]);   
     i+=4;  
    }
    else{
     swap(str[i],str[i+1]);   
     i+=1; 
    }     
  }
  cout<<"\n\noutput : "<<str<<endl;
  system("pause");
  return 0;
}
