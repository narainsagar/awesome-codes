#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;
struct ATM
{
   private:
      string account_no,password;
      int balance;
   public:  
      ATM(){
          account_no="";
          password="";
          balance=0;      
      }      
      void Withdrawal(string acc,string pass,int bal){
       int amount,withdraw;
       string account,passwd;
       cout<<"\n\n\t\tHow much Amount : "; cin>>withdraw;
       if(withdraw>bal){
          cout<<"\n\tYou have Less Balance in account..\n";
          cout<<"\n\t\tYOUR CURRENT BALANCE IS : "<<bal;
          system("pause"); 
          exit(0);              
       } 
       else{
           ifstream read1;
           ofstream write1;
           read1.open("ATM.txt");
           string ac[100], pas[100];
           int baln[100],count=0;
           if(read1.good())
           while(!read1.eof()){
                read1>>account;
                read1>>passwd;
                read1>>amount;
                if(acc==account && pass==passwd){
                     //    do nothing...       
                }
                else{
                  ac[count]=account;
                  pas[count]=passwd;
                  baln[count]=amount;
                  count++;
                }
           }
           read1.close();
           write1.open("ATM.txt");
           for(int i=0;i<count;i++){
                  write1<<endl;
                  write1<<ac[i]<<"\t";
                  write1<<pas[i]<<"\t";
                  write1<<baln[i];      
           }
           write1<<endl;
           write1<<acc<<"\t";
           write1<<pass<<"\t";
           write1<<(bal-withdraw);
           write1.close();  
           cout<<"\n\n\t\tTransaction Successfull..\n\n";
       }    
     }
     void Deposit(string acc,string pass,int bal){
       int amount,deposit;
       string account,passwd;
       cout<<"\n\n\t\tHow much Amount : "; cin>>deposit;  
       ifstream read1;
       ofstream write1;
       string ac[100], pas[100];
       int baln[100],count=0;
       read1.open("ATM.txt");
       if(read1.good())
       while(!read1.eof()){
                read1>>account;
                read1>>passwd;
                read1>>amount;
                if(acc==account && pass==passwd){
                     //    do nothing...       
                }
                else{
                  ac[count]=account;
                  pas[count]=passwd;
                  baln[count]=amount;
                  count++;
                }
           }
           read1.close();
           write1.open("ATM.txt");
           for(int i=0;i<count;i++){
                  write1<<endl;
                  write1<<ac[i]<<"\t";
                  write1<<pas[i]<<"\t";
                  write1<<baln[i];      
           }
           write1<<endl;
           write1<<acc<<"\t";
           write1<<pass<<"\t";
           write1<<(bal+deposit);
           write1.close();  
           cout<<"\n\n\t\tTransaction Successfull..\n\n";
     }
     void Balance_Inquiry(int bal){
        cout<<"\n\n\t\tYOUR CURRENT BALANCE IS : "<<bal<<"\n\n\t\t\tTHANKS!!\n";     
     }
     void Mini_Statement(string acc,string pass,int bal){
        cout<<"\n\n\tUser Mini Staement\n";
        cout<<"\n\t\tYour Account No.     : "<<account_no;
        cout<<"\n\t\tPassword        : "<<password;  
        cout<<"\n\t\tYour Current Balance : "<<bal;  
     }
     void Welcome(){
      Go_Back:    
          system("cls");
          cout<<"\n\n\n\t\t\tWELCOME TO THE MCB BANK LIMITED ONLINE\n";
          cout<<"\n\t\t\t\tA.T.M COUNTER\n";
          cout<<"\n\n\n\tPRESS:\n\n\t\t1. Already Registered User\n\n\t\t2. To Open a New Account\n\n\t\t3. Close Program ";
          char choice;
          choice=getch();
          if(choice=='1') SignIn();
          else if(choice=='2') SignUp();
          else if(choice=='3') exit(0);
          else{
             cout<<"\n\tYou Press Wrong Option..Please try again.. Thank You :)\n";
             system("pause");
             goto Go_Back;
          }                   
      }
      void SignIn(){
         char c;
 GoBack_login:        
         system("cls");
         cout<<"\n\n\tPlease Provide Following Information\n";
         cout<<"\n\t\tAccount No. : "; cin>>account_no;
         cout<<"\n\t\tPassword    : "; cin>>password;
       do{  
     options:    
         string acc,pass;
         int bal;
         ifstream read;
         bool boolean=false;
         read.open("ATM.txt");
         system("cls");
         if(read.good()){
         while(!read.eof()){
            read>>acc;
            read>>pass;
            read>>bal;
            if(acc==account_no && pass==password){
               boolean=true;
               cout<<"\n\n\tPRESS:\n\n\t\t1. Withdrawals\n\n\t\t2. Deposits\n\n\t\t3. Balance Inquiry\n\n\t\t4. Mini Statement ";
               char choice;
               choice=getch();
               if(choice=='1') Withdrawal(acc,pass,bal);
               else if(choice=='2') Deposit(acc,pass,bal);
               else if(choice=='3') Balance_Inquiry(bal);
               else if(choice=='4') Mini_Statement(acc,pass,bal); 
               else{
                  cout<<"\n\tYou Press Wrong Option..Please try again.. Thank You :)\n\n";
                  system("pause");
                  goto options;     
               }
               break;                   
            }                
           }
         }
         else
         {
              cout<<"\n\n\t\tATM File not exist\n\n";
              system("pause"); 
              exit(0);           
         }
         read.close();
         if(!boolean){
             cout<<"\n\n\t\tYou are not Registered.Please Register yourself First..\n\n";
             system("pause");         
             exit(0);
         }
        cout<<"\n\tDo you want to Continue (y/n) "; c=getch(); 
       }while(c!='n');
      }
      void SignUp(){  
register_:
         system("cls");
         string acc,pass;
         int bal;
         bool boolean=false;   
         cout<<"\n\n\tPlease Provide Following Information\n";
         cout<<"\n\t\tAccount No.     : "; cin>>account_no;
         cout<<"\n\t\tPassword        : "; cin>>password;  
back:    cout<<"\n\t\tOpening Balance : "; cin>>balance; 
         if(balance<500){
           cout<<"\n\tThe minimum opening balance must be 500 or more\n\n";
           system("pause");
           goto back;               
         }
         else{
          ifstream read;
          read.open("ATM.txt");
          int cnt=0;
          string ac[100],pas[100];
          int baln[100];
          if(read.good())
          while(!read.eof()){
            read>>acc;
            read>>pass;
            read>>bal;
            if(acc==account_no){
             cout<<"\n\n\t\tThis Account No. is already Registered.. Please try another.\n\n";
             boolean=true;
             system("pause");
             break;
            }
            else{
              ac[cnt]=acc;
              pas[cnt]=pass;
              baln[cnt]=bal;
              cnt++;       
            }
          } 
          read.close();
          if(boolean) goto register_;
          else{
           ofstream write;
           write.open("ATM.txt");
           for(int i=0;i<cnt;i++){
              write<<endl;
              write<<ac[i]<<"\t";
              write<<pas[i]<<"\t";
              write<<baln[i];      
           }
           write<<endl;
           write<<account_no<<"\t";
           write<<password<<"\t";
           write<<balance; 
           cout<<"\n\n\t\t\tRegistered Sucessfully...\n";
           write.close(); 
         }
       } 
   }
};



int main()
{
    ATM counter;
    while(1){
       system("cls");
       counter.Welcome();
       system("pause");
    }
    system("PAUSE");
    return 0;
}
