#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"\n\n\t\tEnter Size  >> "; cin>>n;
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=(n*2);j++)
      {     if((j==n+i) || (j<=n-i) ||(i==n && j%2==0))         
              cout<<"*";
            else 
              cout<<" ";           
      }cout<<endl;       
    }      
system("pause");
return 0;      
}
