#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
const int slep=5;
const int load=20;
string me="\xDB\xDB\xDB\xDB\xDB \xAF\xAF\xAF  PROGRAMMER  :  \xA5 A R A I \xA5 - S A G A R  \xAE\xAE\xAE \xDB\xDB\xDB\xDB\xDB";
string coded="\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \t  \4\4\4  C O D E D  B Y  \4\4\4        \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
string fast="\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \4\4\4  F A S T - N U C E S   \4\4\4\t  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
string welcome=" W E L C \3 M E ";
void line();
void bline();
void uline(int s);
void dline(int s);
void loading();
void logo();
void PASSWORD(string pswrd);
int main()
{ char c;
//system("color 0D");
  cout<<"\n\n\n\n\n\n\n\n\t\t\tPRESS ESC   -  TO EXIT \n\n\t\t\tPRESS ENTER -  TO CONTINUE ";
  c=getch();
 if(c=='\e')
   exit(0);
 else
 {
  loading();
  PASSWORD("sagar");
 }
 cout<<"\n\n";
 system("pause");
 return 0;
}

// functions......
void line()
{
  cout<<"\n________________________________________________________________________________\n";     
}
void bline()
{
  for(int i=0;i<59;i++){
    cout<<"\xDD"; 
    Sleep(slep);
  }   
}
void uline(int s)
{
  cout<<"\n\t";
  for(int i=0;i<60;i++){
    cout<<"\xDF";
    Sleep(s);
  }    
}
void dline(int s)
{
  cout<<"\n\t";
  for(int i=0;i<60;i++){
    cout<<"\xDC";
    Sleep(s);
  }    
}
void loading()
{
  int k=0;
  cout<<"\n\n\n\n\n\n\n\n\t\t\t    ";
  cout<<"  L  O  A  D  I  N  G ";
  cout<<"\n\t\t\t     ";       
  for(int i=0;i<21;i++)
    cout<<"\xDD"; 
  cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
  while(k!=20)
  {
    cout<<"\xDB";
    Sleep(load); 
    k++;    
  }
  cout<<"\n";
  Sleep(500);
  cout<<"\n\n";
  system("pause");     
}
void logo()
{
  system("cls");
  cout<<"\n\n\n\n\n\n\n\n\n\t\t\t    ";
  uline(slep);
  cout<<"\n";
  for(int i=0;i<coded.size();i++){
    Sleep(slep);
    cout<<coded[i];
  }
  dline(slep);
  cout<<"\n\t\xDB";
  bline();
  cout<<"\b\xDB\n\t";
  for(int i=0;i<60;i++){
    cout<<"\xDB";
   Sleep(slep);
  } 
  cout<<"\n\t";
  for(int i=0;i<60;i++){
    cout<<" ";
  }
  for(int i=0;i<60;i++){
    cout<<"\b\xDB\b";
   Sleep(slep);
  }
  cout<<"\n\t";
  for(int i=0;i<5;i++){
    cout<<"\xDB";
   Sleep(slep);
  }
  for(int i=0;i<50;i++){
    cout<<" ";
  }
  for(int i=0;i<5;i++){
    cout<<"\xDB";
   Sleep(slep);
  }
  cout<<"\n\t";
  for(int i=0;i<me.size();i++){
    Sleep(slep);
    cout<<me[i];
  }
  cout<<"\n\t";
  for(int i=0;i<5;i++){
    cout<<"\xDB";
   Sleep(slep);
  }
  for(int i=0;i<50;i++){
    cout<<" ";
  }
  for(int i=0;i<5;i++){
    cout<<"\xDB";
   Sleep(slep);
  }
  cout<<"\n\t";
  for(int i=0;i<60;i++){
    cout<<" ";
  } 
  for(int i=0;i<60;i++){
    cout<<"\b\xDB\b";
   Sleep(slep);
  } 
  cout<<"\n\t";
  for(int i=0;i<60;i++){
    cout<<"\xDB";
   Sleep(slep);
  }
  cout<<"\n\t\xDB";
  bline();
  cout<<"\b\xDB";
  uline(slep);
  cout<<"\n";
  for(int i=0;i<fast.size();i++){
    Sleep(slep);
    cout<<fast[i];
  }  
  dline(slep);
  cout<<"\n\n";     
}

void PASSWORD(string pswrd)
{
  int i=0,n;
  char ch,check,pass[50],fal=' ';
  bool match=false;
label:  
  system("cls");
  logo();
  uline(0);
  cout<<"\n\t   \xAF\xAF\xAF\xAF PLEASE PROVIDE CORRECT INFORMATION FOR LOG IN \xAE\xAE\xAE\xAE";  
  dline(0);
  cout<<"\n\n\tpassword is ("<<pswrd<<")";
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
  cout<<"\n";
  if(fal!='n' && n==0)
    match=true;
  uline(0);
  if(match)
    cout<<"\n\t\t\t   CORRECT PASSWORD";         
  else
    cout<<"\n\t\t\t   INCORRECT PASSWORD";
  dline(0);
  cout<<"\n\n\t\tDO YOU WANT TO GO BACK ON PASSWORD'S CHECK (y/n)  ";
  check=getch();
  if(check=='n')
    exit(0);
  else
    goto label; 
}
