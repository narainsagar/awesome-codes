#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
string check(string s){
  if(s=="-") return "";
  else if(s=="2") return "A";   
  else if(s=="22") return "B";  
  else if(s=="222") return "C";
  
  else if(s=="3") return "D";
  else if(s=="33") return "E";
  else if(s=="333") return "F";
  
  else if(s=="4") return "G";
  else if(s=="44") return "H";
  else if(s=="444") return "I";
  
  else if(s=="5") return "J";
  else if(s=="55") return "K";
  else if(s=="555") return "L";
  
  else if(s=="6") return "M";
  else if(s=="66") return "N";
  else if(s=="666") return "O";
  
  else if(s=="7") return "P";
  else if(s=="77") return "Q";
  else if(s=="777") return "R";
  else if(s=="7777") return "S";
  
  else if(s=="8") return "T";
  else if(s=="88") return "U";
  else if(s=="888") return "V";
  
  else if(s=="9") return "W";
  else if(s=="99") return "X";
  else if(s=="999") return "Y";
  else if(s=="9999") return "Z";
  else return "";
}
int main()
{
    ofstream write;
    ifstream read;
    string ss,news="";
    int T,c=0,count=1;
    bool ff2=false;
    read.open("q2.txt");
    write.open("q2_out.txt",ios::app);
    read>>T;
    cout<<T<<endl;
    while(c<T){
    news="";
    read>>ss;
    bool f=false;
  count=1;
    int i=0;
    news="";
    for(i=0;i<=ss.size() && !f; i++){
      if(ss[i]==ss[i+1])
        count++;
      else{
           string temp;
      for(int d=0;d<count;d++)
         temp+=ss[i];
      news+=check(temp);  
      count=1;   
      }  
   }
   write<<news<<endl;
   c++;
  }
  write.close(); 
  read.close(); 
//system("pause");
return 0;    
}
