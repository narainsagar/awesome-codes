#include<conio.h> 
#include<iostream> 
#include<fstream>
#include<math.h> 
using namespace std; 
ifstream file;

void intro_1();
void intro_2();
float fround(float); 
string ass_grade(double); 
void PASSWORD(string);
void line(); 
int main() 
{  system("color 0C"); 
   double data[100]; 
   int i=0;
   file.open("input.txt");
   if(file.good()){//cout<<"ok..";
     while(!file.eof())
     {
        file>>data[i];
        i++;               
     }
   }
    else
      cout<<"No Such file exist...."; 
   cout<<i<<endl;
   for(int j=0;j<i;j++)
     cout<<data[j]<<"\t";
   while(1)
   { //  system("cls");
       int n=0,ts=0; 
       intro_1();
       system("pause");
       intro_2();
       cout<<"\tNUMBER OF SEMESTER'S :  ";
       cin>>ts; 
      // file>>ts;
       cout<<"\n\tNUMBER OF COURSES OF CURRENT SEMESTER  :  ";
       cin>>n; 
       file>>n;
       string Grades[n]; 
       double sub[n],cdthr[n],sgpa=0.0,tc=0.0,new_cgpa=0.0,prev_cgpa=0.0,  
          total_sem[ts],c_sgpa=0.0,sum_sem=0.0,crdts[ts],total_crdts=0.0;  
       line();
       cout<<"\tPROVIDE CURRENT SEMESTER'S GRADES"; 
       line(); 
       for(int i=0;i<n;i++) 
       {  
          cout<<"\n gpa of subject "<<i+1<<" :  "; 
          cin>>sub[i];
         // file>>sub[i];          
          Grades[i]=ass_grade(sub[i]);   
          cout<<"\n Credit hour :   ";  
          cin>>cdthr[i]; 
          //file>>cdthr[i]; 
          tc+=cdthr[i]; 
          sgpa+=(sub[i]*cdthr[i]); 
       } 
       c_sgpa=fround(sgpa/tc); 
       line(); 
       cout<<"\t\t\tCurrent Semester SGPA    :  "<<c_sgpa; 
       cout<<"\n\n\t\t\tCurrent Semester Credits :  "<<tc;
       line();
       if(ts!=1){ 
       cout<<"\tPROVIDE PREVIOUS SEMESTER'S GRADES"; 
       line(); 
       for(int i=0;i<ts-1;i++) 
       { 
         cout<<"\n Semester "<<i+1<<" SGPA  =  "; 
         cin>>total_sem[i]; 
         //file>>total_sem[i];
         cout<<"\n Credits Earned  : "; cin>>crdts[i]; 
         sum_sem+=total_sem[i]; 
         total_crdts+=crdts[i]; 
       }} 
       prev_cgpa=fround((sum_sem/(ts-1))); 
       total_sem[ts-1]=c_sgpa; 
       crdts[ts-1]=tc; 
       total_crdts+=tc; 
       new_cgpa=fround((c_sgpa+sum_sem)/ts); 
       system("cls"); 
       intro_2();
       line();
       cout<<"\t\t\tSEMESTER'S POINTS AND CREDITS EARNED";
       line();
       for(int k=0;k<ts;k++)
         cout<<"\tSemester "<<k+1<<" sgpa : "<<total_sem[k]<<"\t\t\tCredts Earned : "<<crdts[k]<<endl; 
       line();
       cout<<"\t\t\t\t**TRANSCRIPT**";
       line(); 
       cout<<"\tOLD CGPA    : "<<prev_cgpa<<"\t\t\t  CURRENT SGPA       : "<<c_sgpa; 
       cout<<"\n\n\tNEW CGPA    : "<<new_cgpa<<"\t\t\t  TOTAL CRDTS EARNED : "<<total_crdts<<endl; 
       line(); 
       cout<<"\tCOURSES\t\t\tPOINTS\t\tCrdt HRS.\t\tGRADES"; 
       line(); 
       for(int i=0;i<n;i++) 
         cout<<"\n\tSubject "<<i+1<<" \t\t "<<sub[i]<<"\t\t  "<<cdthr[i]<<"\t\t\t"<<Grades[i]<<"\n"; 
       line();
       system("pause");
   } 
 system("pause"); 
 return 0;  
} 
  /*     .....FUNCTIONS DECLARATIONS HERE.....  */
float fround(float n) 
{ 
    return floor(n*pow(10,2)+ 0.5)/pow(10,2); 
} 
void line() 
{ 
  cout<<"\n________________________________________________________________________________\n"; 
} 
string ass_grade(double pts) 
{ 
   if(pts==4.00) 
     return "A";  
   else if(pts==3.67) 
     return "A-";   
   else if(pts==3.33) 
     return "B+";   
   else if(pts==3.00) 
     return "B"; 
   else if(pts==2.67) 
     return "B-";  
   else if(pts==2.33) 
     return "C+";  
   else if(pts==2.00) 
     return "C";  
   else if(pts==1.67) 
     return "C-";  
   else if(pts==1.33) 
     return "D+";  
   else if(pts==1.00) 
     return "D";  
   else if(pts==0.00) 
     return "F";   
} 
void PASSWORD(string pin_code1="PASSWORD")
{
    char c,e,x;
    char *ch;  
	ch=new char[100];
    do
	{
     cout<<"\t  ( password is "<<pin_code1<<"   )   \n";
	 cout<<"\n\t\t\tPASSWORD\t:\t";
	for(int k=0;e!='\r';k++)
	{
	ch[k]=getch();
	e=ch[k];
	if(ch[k]=='\b')
	cout<<"\b \b";
    else
    cout<<"*";
    }
    e=' ';
    for(int i=0;i<pin_code1.size();i++)
    if(pin_code1[i]!=ch[i])
       x='n';
	  
    if(x!='n')
      {
      line();
      cout<<"\t\t\t\tCORRECT PASSWORD ";
      e='x';
      }
   else
   {
     system("cls");
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tINCORRECT PASSWORD   \n";
     x=' ';
   }
   if(e!='x')
   {          
     cout<<"\n\t\t\t PRESS 1 TO CONTINUE AND 2 TO EXIT   ";
     c=getch();
     system("cls");
   }
   if(c=='2')
     exit(0);           
  }while(c!='2'&&e!='x');
}
void intro_1()
{
    cout<<"\n\n\n\n\n\n\n\n\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n"; 
    cout<<"\n\t\t\4\4\4\4\t\tPROGRAMMER :  NARAIN SAGAR  \t\t\4\4\4\4\n"; 
    cout<<"\n\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4"; 
    line();
    PASSWORD("sagar");
    line();      
}
void intro_2()
{
     system("cls");
     cout<<"\n\n\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n"; 
     cout<<"\n\t\t\4\4\4\t\t  (  CGPA CALCULATOR   ) \t\t\4\4\4\4\n"; 
     cout<<"\n\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n"; 
     line();      
}
