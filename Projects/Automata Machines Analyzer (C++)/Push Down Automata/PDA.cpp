/*   PUSH DOWN AUTOMATA ANALYZER  
Names    :   Narain Sagar (K11-2368), Shamikh Ahmed (K11-2379)
Sec     :    A
Date    :   01-06-2013 (01:09 A.M) 
*/
#include<iostream>
#include<conio.h>
#include<fstream>
#include "Stack.h"
using namespace std;
void line();
void logo1();
void logo2();
int main()
{
     while(1)
     {// system("color 4B");
          system("cls");
          char fname[1000],c;
          //ofstream write;
          //write.open("output.txt",ios::app);  // for saving correct accepted string
          ifstream file;
          logo2();
          logo1();
          cout<<"\n\t\t\tPRESS ESC   - TO EXIT \n\n\t\t\tPRESS ENTER - TO CONTINUE ";
          c=getch();
          if(c=='\e') exit(0);
          else{
              line();
              cout<<"\n\t\tEnter file name like (example.txt)  :  ";
              cin>>fname;
              file.open(fname); 
              line();
              system("pause");
              line();
              if(file.good())
              {
                  string str,transitions[500],title;
                  char I,states[1000],alpha[1000],F[100],ch;
                  int s=0,a=0,f=0,i=0,t=0,k=1;
                  while(!file.eof())
                  { getline(file,str);
                    cout<<str<<endl;
                    if(k<5){
                        for(int p=3;p<=str.size();p+=2){   
                           if(k==1){ states[s]=str[p]; s++; }
                           if(k==2){ alpha[a]=str[p];  a++; }
                           if(k==3){ I=str[p-1];       i++; }
                           if(k==4){ F[f]=str[p];      f++; }
                        }
                    }
                    else { transitions[t]=str; t++;  }  
                    k++;
                 }  //end while(!file.eof())
                 do{ 
                     //system("cls");
                     Stack st;
                     st.Push('$');
                     int j=0,u=0,v=0,w=0,found=0,z=0,lang=0,e=0;
                     bool notexist=false,stackFalse=false,dollorFound=false,notmatch=false;
                     string input;
                     char push='$',pop='^',x,current=I;
                     logo1();
                     cout<<"( "<<fname<<" )\n";
                     cout<<"\n\tALPHABETS ARE : ";
                     for(int g=0;g<a-1;g++) cout<<alpha[g]<<",";
                     line();
                     cout<<"\n\t\tInput String : ";
                     cin>>input;
                     char check[input.size()];
                     line();
                     while(!(dollorFound ||notexist ||stackFalse || notmatch))  // MAIN CODE START HERE
                     {    lang=0;
                          check[w]=current;
                          bool match=false;
                          for(int q=0;q<a;q++)    //FOR ALPHABETS
                             if(input[e]==alpha[q]) lang++;        
                          if(lang==0) notexist=true;
                          for(int d=0;d<t && !match;d++)
                          {
                             string ss=transitions[d];
                             if(current==ss[2] && input[e]==ss[4] && e<=input.size()){
                                pop=ss[6];
                                push=ss[8]; 
                                current=ss[11]; 
                                e++;                
                                match=true;
                             }
                             else if(current==ss[2] && ss[4]=='^' && ss[6]=='$' && ss[8]=='$' && st.StackTopValue()==1 ){
                                pop=ss[6];
                                push=ss[8]; 
                                current=ss[11]; 
                                match=true;     
                             }
                             else if(current==ss[2] && ss[4]=='^' && st.StackTopValue()>1){
                                pop=ss[6];
                                push=ss[8]; 
                                current=ss[11];                 
                                match=true;     
                             }  
                           }
                           if(match){
                               if(pop!='^'){
                                  x=st.Pop();
                                  if(pop!=x) stackFalse=true;           
                               }
                              if(push!='^') st.Push(push);  
                              if(push==pop){ if(push=='$')dollorFound=true; }                    
                           }
                           else notmatch=true;
                     }
                     if(dollorFound){ 
                        for(int g=0;g<f;g++)
                           if(F[g]==current)  found++;
                     }
                  //   if(notexist)  cout<<"\n\t\t\tINVALID ALPHABETS";
                 //    if(stackFalse)cout<<"\n\t\t\tSTACK PROBLEM";
                  //   line();
                     x=st.Pop();
                     if(dollorFound && e==input.size() && found && !stackFalse && !notexist && x=='$' && !notmatch)
                          cout<<"\n\t\t\t... ACCEPTED ...";
                     else cout<<"\n\t\t\t... REJECTED ...";
                    line();
                    cout<<"\n\t\tDo u want to check another String (y/n) ";
                    ch=getch();
              }while(ch!='n');
          }
          else  cout<<"\n\t\t\tNO SUCH FILE EXIST ..";
          line(); 
          file.close();
          system("pause");
       }
    }
    return 0;
}

void line(){
  cout<<"\n________________________________________________________________________________\n";     
}
void logo1(){
  line();
  cout<<"\n\t\t\t  \4\4\4\4 PUSH DOWN AUTOMATA \4\4\4\4\n\n\t\t\t    \t \4\4\4\4 PDA  \4\4\4\4";    
  line();
}
void logo2(){
  line();
  cout<<"\n\t\t\t  ...::: Group Members :::...\n\n\t\t\t1. Narain Sagar (K11-2368 SEC-A)\n\n\t\t\t2. Shamikh Ahmed (K11-2371 SEC-A)";
  line();
  cout<<"\n\t\t   \4\4\4 F A S T - N U C E S   K A R A C H I \4\4\4";    
}
