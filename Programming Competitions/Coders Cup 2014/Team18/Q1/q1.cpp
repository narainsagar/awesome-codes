#include <iostream>
#include<fstream>

using namespace std;

int main ()
{
	ifstream read;
	read.open("input1.txt");
	
	if(read){
		//cout<<"good\n";
		int m,n;
		read>>n>>m;
		if((n>=1 && n<=1000) && (m>=0 && m<=100000)){
			int array[m][2];
			int output[20];
			int count=0;
			for(int i=0;i<m;i++){
				int a,b;
				read>>a>>b;
				if((a>=1 && a<=n)&&(b>=1 && b<=n)){
					array[i][0] = a;
					array[i][1] = b;
				}
			}
			while(!read.eof()){
				read>>output[count];
				count++;
			}
		//	cout<<count<<endl;
			bool res[count+1];
			int siz=count;
			for(int j=0;j<count;j++){
				int out = output[j];
				for(int k=0;k<m;k++){
					bool flag = false;
					if(out == array[k][0]){
					//	cout<<"T";
						for(int p=j+1;p<count;p++){
							if(array[k][1] == output[p]){
								flag = true;
							}
						}
						if(flag){
						//	cout<<"f\n";
							res[j] = true;	
						}
						else{
							res[j] = false;	
						}
					}
				}
			}
			int counter=0;
			//	cout<<"siz="<<siz<<endl;
		//	cout<<counter<<endl;
			
			for(int h=0;h<siz;h++){
			//	cout<<res[h];
				if(res[h]==0)
				  counter++;
			}
		//	cout<<"siz="<<siz<<endl;
		//	cout<<counter<<endl;
			if(counter==0){
				cout<<"NO\n";
			}
			else{
				cout<<"YES\n";	
			}
			}
		//	cout<<endl;	
	//	}
	}
	else{
		cout<<"file not exist..\n";
	}
	read.close();
	
	return 0;
	
}
