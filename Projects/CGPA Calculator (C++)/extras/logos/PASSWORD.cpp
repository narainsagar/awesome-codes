#include<iostream>
#include<conio.h>
using namespace std;
void line()
{
  cout<<"\n________________________________________________________________________________\n";     
}
void PASSWORD(string pswrd)
{
  int i=0,n;
  char ch,pass[50],fal=' ';
  bool match=false;
  line();
  cout<<"\tpassword is ("<<pswrd<<")";
  cout<<"\n\n\t\t\tPassword : ";
  ch=getch();
  while(ch!=13)
  {  
      pass[i]=ch; 
      if(ch=='\b')
      {
        cout<<"\b \b";  
        i-=2;          
      }
      else{
         cout<<"*";   
      }
      i++;
      ch=getch();         
  }
  n=i;
  for(int j=0;j<pswrd.size();j++){
    if(pswrd[j]!=pass[j])
       fal='n';
    n--;
  }
  if(fal!='n' && n==0)
    match=true;
  line();
  if(match)
    cout<<"\t\t\t\tCORRECT PASSWORD";         
  else
    cout<<"\t\t\t\tINCORRECT PASSWORD";
  line();     
}

int main()
{
  PASSWORD("sagar");
  system("pause");
  return 0;
}
