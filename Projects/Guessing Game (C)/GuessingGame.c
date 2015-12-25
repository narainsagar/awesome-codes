#include<stdio.h>
#include<conio.h>
void looser_shape();
void winner_shape();
void shape_of_welcome();
void fun_line();

FILE *w;
FILE *l;

int main()
{
    char name[100];
    w=fopen("winner.txt","a+");
    l=fopen("looser.txt","a+");
    int num, diff, guess;
    float per;
    char a=37;
    int count=1;
    char ch,chose,chh;
start:
    system("cls"); 
    shape_of_welcome();
    printf("\n\n\t\t 1    -   for play game\n\t\t 2    -   for owner of game ( see list of winner or runner )\n\n");
    chose=getch();
    switch(chose)
    {

case '1':
      
 do
 {   system("cls");
     shape_of_welcome();
     printf("\n\n\t\t NAME   :    ");
     scanf("%s",name); 
     srand(time(0));
     num=rand()%100;
     system("cls");
     shape_of_welcome();
     fun_line();
     fun_line();
     printf("\t\t\t\t     NUMBER GUESSING GAME\n");
     fun_line();
     fun_line();
     printf("\n\n\t\t\t YOU CAN GUESS ONLY FIVE TIMES\n\n");
     printf("\n\t\t**********************************************\n\n");
 do
 {  // printf("%d",num);
     printf( "\t\tEnter the number :\t");
     scanf("%d",&guess);
     diff=abs(num-guess);
    // printf("%d\t",diff);
     if (diff==0)
     {
     system("CLS");
     fun_line();
     fun_line();
     printf( "\n\n\t\t\t\tCONGRATES...! \n\n\t\t\tYOU HAVE GUESSED CORRECT..\n");
     printf("\n \t\t\tYOU WON THE GAME!!!!!!\n\n\n");
     fprintf(w,"\n %s",name);
     fun_line();
     fun_line();
     break;
     }   
     else 
     {
          per=diff*100/num;
      printf( "\t\tYour are %.2f %c far from Answer\n\n",per,a);
     }
     count++;
  }
 while (count<=5);
   if(count==6)
   {
    fun_line();
    fun_line();
    printf("\n\t\t\tYOU LOSE THE GAME !\n");
    fprintf(l,"\n %s",name);
    fun_line();
    printf("\t\t\tThe actual number was %d \n",num);
    fun_line();
    fun_line();
   }
   printf("\n\n\t\tDO U WANT TO PLAY AGAIN(y/n) : ");
   ch=getche();
   count=1;
   per=0;
 }
   while (ch!='n');
   break;
   
   case '2':
           system("cls");
           printf("\n\n\t\t 1    -   WINNERS LIST \n\t\t 2    -   LOOSERS LIST \n\t\t\t");
           char c;
           int x=0;
           c=getch();
        if(c=='1')
        {
             winner_shape();      
             while(fscanf(w,"%s",name)!=EOF)
             {
             printf("\t\t\t\t>>>>> %s\n",name);
             x++;
             }
             if(x==0)
             printf("\t\t\t THERE IS NO DATA IN THE FILE  \n"); 
             printf("\n\n\t\t\tDO U WANT TO GO ON START (y/n):\t");
             scanf("%c",&chh);
             if(chh=='y')
               goto start;
             else 
               exit(0);
             }
          else if(c=='2')
          {

             looser_shape();    
             while(fscanf(l,"%s",name)!=EOF)
             {
             printf("\t\t\t\t>>>>> %s\n",name);
             x++;
             }
              if(x==0)
             printf("\t\t\t THERE IS NO DATA IN THE FILE\n");             
             printf("\n\n\t\t\tDO U WANT TO GO ON START (y/n):\t");
             scanf("%c",&chh);
             if(chh=='y')
                 goto start;
             else
                 exit(0);  
             }
         else
         {
             printf("\n\n\t\t\t YOU ENTER WRONG\n\n"); 
         }                      
         break;
  }
     printf("\n\n\n");
     getch();
     return 0;
               
}                   // END OF MAIN





//******************************************************************************

//*******************************  FUNCTIONS DEFINITIONS  ***********************

//*********************************************************************************


void fun_line()            // DEFINTION OF FUN_LINE();
{
     printf("_______________________________________________________________________________");
}// end function.....



//_________________________shape_of_signin();

void shape_of_welcome()
{ 
    printf("\n\t\t ********************************************** \n");
    printf("\t\t **____________________ * ___________________** \n");
    printf("\t\t **______________ *          * ______________** \n");
    printf("\t\t **_____***  WELCOME TO  GUESS GAME    ***___** \n");
    printf("\t\t **______________ *          * ______________** \n");
    printf("\t\t **____________________ * ___________________** \n");
    printf("\t\t **_______>>>>>> GUESS A NUMBER <<<<<<_______** \n");
    printf("\t\t ********************************************** \n\n");   
}
//__________________________________________________________________________________




//_________________________winner_shape();
void winner_shape() 
{
          
    printf("\n\t\t ********************************************** \n");
    printf("\t\t **__________________________________________** \n");
    printf("\t\t **____________________ * ___________________** \n");
    printf("\t\t **______________ *          * ______________** \n");
    printf("\t\t **___________ *     WINNERS    * ___________** \n");
    printf("\t\t **______________ *          * ______________** \n");
    printf("\t\t **____________________ * ___________________** \n");
    printf("\t\t **__________________________________________** \n");
    printf("\t\t ********************************************** \n\n\n");
       
}  // end function......
     


//_________________________winner_shape();
void looser_shape()
{   
         
    printf("\n\t\t ********************************************** \n");
    printf("\t\t **__________________________________________** \n");
    printf("\t\t **____________________ * ___________________** \n");
    printf("\t\t **______________ *          * ______________** \n");
    printf("\t\t **___________ *     LOOSERS    * ___________** \n");
    printf("\t\t **______________ *          * ______________** \n");
    printf("\t\t **____________________ * ___________________** \n");
    printf("\t\t **__________________________________________** \n");
    printf("\t\t ********************************************** \n\n\n");
    
   
}// end function........
