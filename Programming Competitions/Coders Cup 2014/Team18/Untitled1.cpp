#include <iostream>
#include<fstream>

using namespace std;


int main ()
{
	ifstream read;
	read.open("input.txt");
	
	if(read){
		ofstream write;
		write.open("input1.txt");
		cout<<"good\n";
		while(!read.eof()){
			string r;
			read>>r;
			write<<r<<endl;
			cout<<r<<endl;
		}
		write.close();
	}
	else{
		cout<<"file not exist..\n";
	}
	read.close();
	
	return 0;
	
}
