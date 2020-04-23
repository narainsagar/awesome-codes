#include<iostream>
using namespace std;

int birth(int ,int ,int , int);
int main()
{

birth(9,9,7,11);
  system("pause");
  return 0;
}
int birth(int c_m ,int c_d,int b_m , int b_d)
{
    int day=0;
    if(c_m==b_m&&c_d==b_d)
    cout<<"HAPPY BIRTHDAY"<<endl;
    else
    {
    cout<<"NOT"<<endl;
    
    int x;   
    if(c_m-b_m>=0)
    {
   for(int i=c_m;i<=b_m;i++)
   {
       if(c_m%2==0)
       {
          x=30;         
                   }
       else
         x=31;                
      if(c_m==2)
        x=28;     
          
      if(i==c_m)
         {
            day+=x-c_d;    
                }    
      if(i==b_m)
      {
            day+=b_d;    
                }  
       else
           day+=x;        
          
           }
      
  
     }
   
   
    } 
    cout<<"days = "<<day<<endl;
    }
