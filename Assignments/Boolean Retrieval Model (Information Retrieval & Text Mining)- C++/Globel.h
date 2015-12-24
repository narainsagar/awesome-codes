/*
....................... ASSIGNMENT NO # 01 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
*/
#include <windows.h>
#include <string>
#include <cstdlib>
#include<iostream>
#include<conio.h>
#include<fstream>
#include <set>
const int NO_OF_FILES = 10;
const int LIMIT=1000;
using namespace std;

		void printline(){
			cout<<"--------------------------------------------------------------------------------\n";
		}
		void AND(int res[],int arr[]){
           	    for(int i=0;i<NO_OF_FILES;i++){
           	    	res[i]=res[i] & arr[i];
           	    }
           	    return;
       }
       void OR(int res[],int arr[]){
       	    for(int i=0;i<NO_OF_FILES;i++){
       	    	res[i] = res[i] | arr[i];
       	    }
       	    return;
       }
       void NOT(int res[]){
       	    for(int i=0;i<NO_OF_FILES;i++){
       	    	res[i] = !res[i];
       	    }
       	    return;
       }
       void COPY(int res[],int arr[]){
       	    for(int i=0;i<NO_OF_FILES;i++){
       	    	res[i] = arr[i];
       	    }
       	    return;
       }
       string removeSpecials(string strWord){
		        int i=0,len=strWord.size(),j=0;
		        string newStr="";
		        while(i<len){
		              char cc=strWord[i];
		              if( (cc>='0' && cc<='9')||(cc>='a' && cc<='z')){
		                  newStr += strWord[i];
		              } 
		              i++;   
		        }
		        return newStr;  
		}
       
#include "Queue.h"       
#include "Stack.h"
#include "Node.h"
#include "WordList.h"
#include "BooleanModel.h"
