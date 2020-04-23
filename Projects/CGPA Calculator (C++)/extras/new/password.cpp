#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
 while(1){ 
  system("cls");
  int i=0,n;
  string pswrd="sagar";
  char ch,pass[50]={},fal=' ';
  bool match=false;
  int b=0,p=0;
  cout<<"\n\n\npassword is ("<<pswrd<<")";
  cout<<"\n\n\n\t\t\tPassword : ";
  ch=getch();
  while(ch!=13)
  {
      
      if(ch=='\b')
      { b++;
        if(i>0){
           cout<<"\b \b";  
           i-=2;  
        }          
      }
      else if(ch!='\b'){
       if(i<0) i=0;
         pass[i]=ch;
         cout<<"*"; 
         i++; 
         p++; 
      }
      ch=getch();         
  }
  n=i;
  cout<<"\n\n\n\t\t\tPassword : "<<(string)pass;
  cout<<"\n\t\t\tLenght   : "<<i;
  for(int j=0;j<pswrd.size();j++){
    if(pswrd[j]!=pass[j])
       fal='n';
    n--;
    }
  if(fal!='n' && n==0){
    cout<<"\n\t\t\tPassword Matched....\n";
    match=true;
  }
  else
    cout<<"\n\t\t\tNOT Matched....\n";
  system("pause");
 }  
  system("pause");
  return 0;
}
