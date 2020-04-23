/*           TURING MACHINE ANALYZER  
Names    :   Narain Sagar (K11-2368), Shamikh Ahmed (K11-2379)
Sec     :    A
Date    :    02-06-2013 (03:34 A.M) 
*/
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void line();
void logo1();
void logo2();
int main()
{
 while(1)
 { //system("color 4B");
      system("cls");
      char fname[1000],c;
      ifstream file;
      logo2();
      logo1();
      cout<<"\n\t\t\tPRESS ESC   - TO EXIT \n\n\t\t\tPRESS ENTER - TO CONTINUE ";
      c=getch();
     if(c=='\e')
        exit(0);
     else
     {
      line();
      cout<<"\n\t\tEnter file name like (example.txt)  :  ";
      cin>>fname;
      file.open(fname); 
      line();
     if(file.good())
     {
          string str,transitions[500],title;
          char I,states[1000],alpha[1000],F[100],ch;
          int s=0,a=0,f=0,i=0,t=0,k=1;
          while(!file.eof())
          {
           // file>>str;
            getline(file,str);
            cout<<str<<endl;
          //  if(k==0)
          //     title=str;
            if(k<5)
            {
                  for(int p=3;p<=str.size();p+=2){   
                    if(k==1){
                      states[s]=str[p];
                      s++;       
                    }
                    else if(k==2){
                      alpha[a]=str[p];
                      a++;       
                   }
                   else if(k==3){  
                     I=str[p-1];
                     i++;       
                   }
                  else if(k==4){
                    F[f]=str[p];
                    f++;       
                  }
                }
          }
          else
          {
              transitions[t]=str;
              t++;     
          }  k++;
         }  //end while(!file.eof())
         line();
         system("pause");
     do{
         system("cls");
         char tape[1000];
         char cc,current=I,reachedFinal=false,notexist=false,notFound=false;
         int x,start,pointer,limit=99,end;  x=start=pointer=30;
         for(int g=0;g<limit;g++)
             tape[g]='\4';
         string input;
         logo1();
         cout<<"\n\t\t\t\tTAPE";
         line(); 
         for(int g=0;g<limit;g++){
          cout<<tape[g];
          if(pointer<=limit && g==pointer-1) cout<<">";
          else if(g==pointer-1 && pointer>limit)  cout<<"<";
         }
         line();
         cout<<"\n ( "<<fname<<" )\n";
         cout<<"\n\tSTATES ARE : ";
         for(int g=0;g<s-1;g++)
           cout<<states[g]<<",";
      //   line();
         cout<<"\n\n\tFINAL STATES ARE : ";
         for(int g=0;g<f-1;g++)
           cout<<F[g]<<",";
      //   line();
         cout<<"\n\n\tALPHABETS ARE : ";
         for(int g=0;g<a-1;g++)
           cout<<alpha[g]<<",";
         line();
         cout<<"\n\t\tInput String : ";
         cin>>input;
         for(int g=0;g<input.size();g++,x++)
            tape[x]=input[g];        
         line();
         cout<<"\n\t\t\t\tTAPE";
         line(); 
         for(int g=0;g<limit;g++){
          cout<<tape[g];
          if(pointer<=limit && g==pointer-1) cout<<">";
          else if(g==pointer-1 && pointer>limit)  cout<<"<";
         }
         line();  
         for(int w=pointer;w<start+input.size() && !notexist;w++){
             int lang=0;
             for(int q=0;q<a;q++)
                if(tape[w]==alpha[q])
                    lang++;        
              if(lang==0)
                notexist=true; 
         }
         int step=0;
 //       if(notexist==false) 
         while(!(reachedFinal || notFound))
         {  bool found=false; step++;
            int d=0;
             for(d;d<t && !found;d++)
             {
                string ss=transitions[d];    
                if(current==ss[2] && tape[pointer]==ss[4])
                {
                   current=ss[11];    // for state change
                   tape[pointer]=ss[6];  // for replacing
                                         //for movement
                   if(ss[8]=='L') pointer--;
                   if(ss[8]=='R') pointer++;
                   if(ss[8]=='S'){  /*do nothing; */  }   
                   found=true;                
                } 
             }
             if(d==t && found==false)  notFound=true; 
             if(found){
                 for(int h=0;h<f-1;h++)
                    if(current==F[h])
                       reachedFinal=true;
             }
         }
         system("pause");
         system("cls");
         cout<<"\n\t\t\t\tFINAL OUTPUT TAPE";
         line(); 
         for(int g=0;g<limit;g++){
          cout<<tape[g];
          if(pointer<=limit && g==pointer-1) cout<<">";
          else if(g==pointer-1 && pointer>limit)  cout<<"<";
         }
         line();
     //  else
     //    cout<<"\n\t\t Not exist\n";
        if(reachedFinal && !notFound&& !notexist)     cout<<"\n\t\t\t... SUCCESSFUL ...";
        else     cout<<"\n\t\t\t... UN SUCESSFULL ...";  
     line();
     cout<<"\n\t\tDo u want to check another String (y/n) ";
     ch=getch();
     }while(ch!='n');
    }
    else{
      line();
      cout<<"\n\t\t\tNO SUCH FILE EXIST ..";
    }
    line(); 
    file.close();
    system("pause");
    }
  }
  return 0;
}

void line()
{
  cout<<"\n________________________________________________________________________________\n";     
}
void logo1()
{
  line();
  cout<<"\n\t\t\t  \4\4\4\4 TURING MACHINE \4\4\4\4\n\n\t\t\t    \t \4\4\4\4 TM  \4\4\4\4";    
  line();
}
void logo2()
{
  line();
  cout<<"\n\t\t\t  ...::: Group Members :::...\n\n\t\t\t1. Narain Sagar (K11-2368 SEC-A)\n\n\t\t\t2. Shamikh Ahmed (K11-2371 SEC-A)";
  line();
  cout<<"\n\t\t   \4\4\4 F A S T - N U C E S   K A R A C H I \4\4\4";    
}
