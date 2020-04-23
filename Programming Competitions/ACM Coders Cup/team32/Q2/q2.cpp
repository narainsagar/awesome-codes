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
    read>>T;
    cout<<T<<endl;
    while(c<T){
    read>>ss;
  //  cout<<ss<<endl; 
    for(int i=0;i<=ss.size(); i++){
            ff2=false;
      news="";
      count=1;
      int indi=i;
      int indj=i+1;
       bool ff=false,cf2=false;
       i=0;
       string temp="";
      for(int j=i+1; !ff ;j++){
        if(ss[i]==ss[j]){
          count++;
        }
       else{
          ff=true;
          indj=j;
       }
      }
       if(ff){ 
      for(int k=indi;k<indj;k++)
        temp=temp+ss[i];  
      cout<<"temp="<<temp;
      news+=check(temp);
      cout<<"news="<<news<<endl;        
     }   
    system("pause");
  }
    //cout<<news<<endl;  
 }     
    c++;                   
    }
    
system("pause");
return 0;    
}
