#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("input.txt");


int main()
{
    int n;
    fin>>n;
    //cout<<n<<endl;
    int x;
    int sum=0;
for(int i=0;i<n;i++)
{
       fin>>x;
      // cout<<x<<endl;
       sum=0;
       x/=6;
 for(int j=1;j<=x;j++)
      {
          // cout<<"j= "<<j<<" x = "<<x<<"sum = "<<sum<<endl;           
           sum+=(6*j);               
        }
cout<<sum<<endl;
}
  system("pause");
  return 0;
}
