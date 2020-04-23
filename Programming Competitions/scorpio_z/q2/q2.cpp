#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("input.txt");


long prime(int n)
{
     int x=0;
     long z=1;
     bool s;
     for(int i=2;x<n;i++)
     {
            s=true;
         for(int j=2;j<=i/2;j++)
         {
                //cout<<"  "<<j;
                 if(i%j==0)
                   {
                      s=false;    
                       break;     
                           }
                 }
                // cout<<s;
                // system("pause");
                if(s)
                {
                    // cout<<i<<endl;
                     z*=i;
                     x++;
                    
                      
                   }     
                
                 
                 }
             
             z++;
        return z;
     
     
     
     }


int main()
{
    long R,p;
    
   // cout<<prime(3)<<endl;
    
   int n;
   fin>>n;
   for(int i=0;i<n;i++)
   {
         fin>>R;
        cout<<prime(R)<<endl;
           
           }    
    


  system("pause");
  return 0;
}
