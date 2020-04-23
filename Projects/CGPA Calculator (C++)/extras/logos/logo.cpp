#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
void PASSWORD(string pswrd);
void line()
{
  cout<<"\n________________________________________________________________________________\n";     
}
void bline()
{
  cout<<"\n\t";
  for(int i=0;i<60;i++)
    cout<<"\xDF"; 
  cout<<"\n";    
}
void dline()
{
  cout<<"\t";
  for(int i=0;i<60;i++)
    cout<<"\xCD";     
}
int main()
{system("color 0C");
  cout<<"\n\n\n\n\n\n";
  string me="PROGRAMMER    :   N A R A I N  S A G A R";
  line();
  bline();
  cout<<"\t\t\t   \4\4\4  C O D E D  B Y  \4\4\4\n";
  dline();
  cout<<"\n\t";
  for(int i=0;i<60;i++)
    cout<<"\xDC";
  cout<<"\n\t";
  for(int i=0;i<60;i++)
    cout<<"\xDB";
  cout<<"\n\t\xDB\xDB\xDB\xDB\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\n";
  cout<<"\t\xDB\xDB\xDB\xDB\t  ";
  for(int i=0;i<me.size();i++){
    cout<<me[i];
  }
  cout<<"\t\xDB\xDB\xDB\xDB";
  cout<<"\n\t\xDB\xDB\xDB\xDB\t\t\t\t\t\t\t\xDB\xDB\xDB\xDB\n\t";
  for(int i=0;i<60;i++)
    cout<<"\xDB";
  bline();
  dline();
  cout<<"\n\t\t\4\4\4  F A S T - N U C E S - K A R A C H I  \4\4\4\n";
  bline();
  line();
  cout<<"\t   \xAF\xAF\xAF\xAF PLEASE PROVIDE CORRECT INFORMATION FOR LOG IN \xAE\xAE\xAE\xAE";
  PASSWORD("sagar");
  cout<<"\n";
  system("pause");
  return 0;
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
