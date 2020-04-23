#include<iostream>
#include<fstream.h>
using namespace std;
int main()
{
    ofstream write;
    ifstream read;
    write.open("q1.txt");
    
    
    while(!write.eof()){
    write>>ss;
    cout<<ss<<endl;                    
    }
    
    
    
system("pause");
return 0;    
}
