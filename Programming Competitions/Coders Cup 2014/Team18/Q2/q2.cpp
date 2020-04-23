#include <iostream>
#include<fstream>

using namespace std;


int main ()
{
	ifstream read;
	read.open("input2.txt");
	
	if(read){
		int T=0,pre=0,post=0;
		int case1=1;
		int array1[4][4],array2[4][4];
		read>>T;
		if(T>=1 && T<=100){
			for(int i=0;i<T;i++){
				read>>pre;
				if(pre>=1 && pre<=4){
					for(int j=0;j<4;j++){
						for(int k=0;k<4;k++){
							read>>array1[j][k];
						}
					}
					read>>post;
					if(post>=1 && post<=4){
						for(int j=0;j<4;j++){
							for(int k=0;k<4;k++){
								read>>array2[j][k];
							}
						}
						int found=0, counter =0;
						for(int p=0;p<4;p++){
							for(int q=0;q<4;q++){
								if(array1[pre][q] == array2[post][q]){
									found = array1[pre][q];
									counter++;
								}
							}
						}
						if(counter == 1){
							cout<<"Case #"<<case1<<":"<< found<<endl;
							
			         	}
			         	else if(counter > 0){
			         		cout<<"Case #"<<case1<<":"<< "Bad magician!\n";
			         	}
			         	else {
			         		cout<<"Case #"<<case1<<":"<< "Volunteer cheated!\n";
			         	}
			         	case1++;
					}
				}
				
			}	
		}
		
		
	}
	else{
		cout<<"file not exist..\n";
	}
	read.close();
	
	return 0;
	
}
