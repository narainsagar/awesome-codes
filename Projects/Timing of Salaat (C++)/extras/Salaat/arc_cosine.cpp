#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float x;
    int y;
 
    cout<<"\n\t\t\t...* Cosine inverse Function cos^-1(x) *...\n\n";
    cout<<"\n\t\tEnter value in radians : ";cin>>x;
    y=static_cast<int>(acos(x)*57.3);
    cout<<"\n\n\t\tcos^-1("<<x<<") ===>> "<<y;
  cout<<"\n\n";
  system("pause");
  return 0;
}
