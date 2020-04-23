// Copyrights @ Narain-Sagar (k11-2368)  22/11/2013 11:35 a.m  EE-Lab6 (Completed...)
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
 while(1){ 
back:  
  system("cls");
  int i=0,n;
  string pswrd="narain.sagar";
  char ch,fal=' ',pass[45]={};
  bool match=false;
  int b=0,p=0;
  cout<<"\n\n\nPassword is ("<<pswrd<<")";
  cout<<"\n\n\n\t\t\tPassword : ";
  ch=getch();
  while(ch!=13)
  {  if(p<0) p=0;
          if(ch=='\b' && p>0){ 
            cout<<"\b \b";  
            pass[i]=char(NULL);
            i-=2;  
            p--;        
          }
          else if(ch!='\b'){
           if(i<=0){ i=0; p=0;}
           pass[i]=ch;
           cout<<"*"; 
           i++; 
           p++; 
          }
          ch=getch();         
  }
  n=i;
  if(n<=0){
       cout<<"\n\n\n\t\t\tPassword not Entered... \n\n Please ";        
  }
  else{
      cout<<"\n\n\n\t\t\tPassword : "<<pass;
      cout<<"\n\t\t\tLenght   : "<<i;
      for(int j=0;j<pswrd.size() && i==pswrd.size();j++){
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
  }
  system("pause");
 }  
 system("pause");
 return 0;
}
