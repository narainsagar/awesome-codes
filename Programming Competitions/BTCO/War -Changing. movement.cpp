#include<iostream>
#include<fstream>
using namespace std;
int main()
{
  int n;
  ifstream read;
  read.open("War-Changing.txt");
 // while()
//  {
    read>>n;
    cout<<n;
    for(int k=0;k<=n;k++)
    {string temp;
      getline(read,temp);
      for(int i=0;i<temp.size();i++){
        if(temp[i]>'E' && temp[i]<='Z')        
          temp[i]=temp[i]-5;
         else if(temp[i]=='E')
          temp[i]='Z';
         else if(temp[i]=='D')
          temp[i]='Y';
         else if(temp[i]=='C')
          temp[i]='X';
         else if(temp[i]=='B')
          temp[i]='W';
         else if(temp[i]=='A')
          temp[i]='V';
         else if(temp[i]=='_')
          temp[i]=' ';
         else if(temp[i]>='1' && temp[i]<'5')
          temp[i]+=5;
         else if(temp[i]=='5')
          temp[i]='0';
         else if(temp[i]=='6')
          temp[i]='1';
         else if(temp[i]=='7')
          temp[i]='2';
         else if(temp[i]=='8')
          temp[i]='3';
         else if(temp[i]=='9')
          temp[i]='4';
      }
      cout<<temp<<endl;
  //  }                  
  }
  system("pause");
  return 0;
}
