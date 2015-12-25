#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int j,votes[100];
int cast_vote();

struct data
    { 
           char name[30];
           char nic[16];
           char fname[20];
           char party[30];
           char nam[20];
           char n_i_c[16];
           int code;
           }e;
int main() 
{
    
    
    /*  FOR  VOTTING CAST*/
        
       
        for(j=0;j<100;j++)
        {
        votes[j]=0;
        }
       
       
    /*
      int n[2];
                       n[0]=0;             
                  n[0]++;     
                  printf("n[o]=%d",n[0]);
      */            
    FILE *fp=NULL,*ft=NULL,*fpt=NULL,*ftp=NULL;
    char another='y';
    
    char num[30];
    char nom[30];
    char nem[30];
    char niic[16];
    int cod,nic_comp,name_comp,a;
    char party[5];
    while(1)
    {
            int ch;
            system("cls");
            printf("\n\t\t=======================================================\n");
            printf("\t\t|        WELLCOME TO ELECTRONIC MAILING SYSTEM        |\n");
            printf("\t\t=======================================================\n\n");
            printf("==>press 1 for new entry of candidate:\n");
            printf("==>press 2 to view list:\n");
            printf("==>press 3 to delete entry:\n");
            printf("==>press 4 to enter voter data:\n");
            printf("==>press 5 to view voter list:\n");
            printf("==>press 6 to delete voter entry:\n");
            printf("==>press 7 for vote casting:\n");
            printf("==>press 8 to exit:\n");
            printf("==>select your choice:\n");
            scanf("%d",&ch);
            switch(ch)
            {
                      case 1:
                           
                           fp=fopen("data.txt","a+");
                           if(fopen==NULL)
                           {
                             printf("error opening!");
                              exit(0);
                           }
                           fseek(fp,0,SEEK_END);
                           another='y';
                           while(another=='y')
                           {
                               printf("enter name,father name,N.I.C and party name of candidate:");
                               scanf("%s\n%s\n%s\n%s",e.name,e.fname,e.nic,e.party);
                               fprintf(fp,"\n%s\n%s\n%s\n%s\n",e.name,e.fname,e.nic,e.party);
                               printf("\nAdd another candidate(y/n)");
                               fflush(stdin);
                               another=getche();
                           }
                           
                               fclose(fp); 
                               fp = NULL;     
                           break;
                      case 2:   
                                                                
                            fp=fopen("data.txt","r");
                            if(fopen==NULL)
                            {
                                       printf("error opening!");
                                       exit(0);
                                       }
                                       int i=0;
                            while(fscanf(fp,"%s%s%s%s",e.name,e.fname,e.nic,e.party)!=EOF)               
                            printf("\n%s\n%s\n%s\n%s\n",e.name,e.fname,e.nic,e.party);
                          
                            
                            break;                          
                                    
                       case 3:
                            another='y';
                            while(another=='y')
                            {
                                              
                                               printf("==>enter the name of candidate to delete:");
                                               scanf("%s",num); 
                                               ft=fopen("temp.txt","r"); 
                                               rewind(fp);
                                               while(fscanf(fp,"%s\n%s\n%s\n%s\n",e.name,e.fname,e.nic,e.party)!=EOF)
                                               {
                                                    if(strcmp(e.name,num)!=0)
                                                    fprintf(ft,"%s\n%s\n%s\n%s\n",e.name,e.fname,e.nic,e.party);
                                               }
                                                    fclose(ft);
                                                    ft = NULL;
                                                    fclose(fp);
                                                    fp = NULL;
                                                    remove("data.txt");
                                                    rename("temp.txt","data.txt");
                                                    
                                                    /*
                                                    fp=fopen("data.txt","r");
                                                    printf("delete another record(y/n)");
                                                    fflush(stdin);
                                                    another=getche();*/
                                                         }
                                                    break;                 
                       case 4:
                             fpt=fopen("vote.txt","a+");
                             if(fopen==NULL)
                             {
                                printf("error opening!");
                                exit(0);
                                }
                             fseek(fpt,0,SEEK_END);
                             another='y';
                             while(another=='y')
                             {
                              printf("enter name,N.I.C and code:");
                              scanf("%s\n%s\n%d",e.nam,e.n_i_c,&e.code);
                              fprintf(fpt,"\n%s\n%s\n%d\n",e.nam,e.n_i_c,e.code);
                              printf("\nAdd another candidate(y/n)");
                              fflush(stdin);
                              another=getche();
                             }
                                
                              fclose(fpt); 
                              fpt = NULL;     
                              break;
                       case 5:
                             fpt=fopen("vote.txt","a+");
                             if(fopen==NULL)
                              {
                                       printf("error opening!");
                                       exit(0);
                              }
                            while(fscanf(fpt,"%s\n%s\n%d\n",e.nam,e.n_i_c,&e.code)!=EOF)                  
                            printf("\n%s\n%s\n%d\n\n",e.nam,e.n_i_c,e.code);
                            break;                          
                       case 6:
                            another='y';
                            while(another=='y')
                            {
                                              
                                               printf("==>enter the name of candidate to delete:");
                                               scanf("%s",nom); 
                                               ftp=fopen("tem.txt","a+"); 
                                               rewind(fpt);
                                               while(fscanf(fpt,"%s\n%s\n%d\n",e.nam,e.n_i_c,&e.code)!=EOF)
                                               {
                                                    if(strcmp(e.nam,nom)!=0)
                                                    fprintf(ftp,"%s\n%s\n%d\n",e.nam,e.n_i_c,e.code);
                                                    }
                                                    fclose(ftp);
                                                    fclose(fpt);
                                                    fpt = NULL;
                                                    ftp=NULL;
                                                    remove("vote.txt");
                                                    rename("tem.txt","vote.txt");
                                                    
                                                    
                                                    fpt=fopen("vote.txt","r");
                                                    printf("delete another record(y/n)");
                                                    fflush(stdin);
                                                    another=getche();
                                                         }
                                                    break;                      
                       case 7:
                            while(1)
                            {
                            int x=0;
                            printf("enter your name:");
                            scanf("%s",nem);
                             
                             printf("please enter your N.I.C:");
                             scanf("%s",niic);    
                             printf("enter your code:");
                             scanf("%d",&cod);  
                             fpt=fopen("vote.txt","a+");
                             rewind(fpt);
                             while(fscanf(fpt,"%s\n%s\n%d\n",e.nam,e.n_i_c,&e.code)!=EOF&&x==0)
                             {
                             
                              /* printf("  niic %s  ,  e.n_i_c ,  %s",niic,e.n_i_c);*/
                                   nic_comp=strcmp(niic,e.n_i_c);
                                   name_comp=strcmp(nem,e.nam);
                                   if(nic_comp==0&&cod==e.code&&name_comp==0)
                                   {
                                                                             
                                    printf("\n\n\t\tyou are eligible to cast vote:\n\n");
                                    cast_vote();
                                    x=1;
                                /*  break;*/
                                    
                                    }
                                    }
                                          fclose(fpt);
                                          fpt = NULL;
                                          
                                          
                                        
                                       if(x==0)           
                                      {
                                                     printf("\n\n\t\tsorry! you are not eligible!\n");
                                      } 
                                      } 
                                      break;
                                              case 8:
                                              if (fpt != NULL)
                                                 fclose(fpt);
                                              if (fp != NULL)
                                                 fclose(fp);
                                              exit(0);
}
}            

getch();
}                                  
  int cast_vote()
{    
     char ch,r,g;
     char cont;
     FILE *fp;
     char autoo=65;
     int j,c;
     int num=0;
      
     printf("following is the list of candidates:");
     fp=fopen("data.txt","a+");
     if(fp==NULL)
     {
        printf("error opening!");
        exit(0);
        }
       int i=0;
       while(fscanf(fp,"%s%s%s%s",e.name,e.fname,e.nic,e.party)!=EOF)
       {   
       printf("\n\n\n\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4( %c )\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4",autoo++);                   
       printf("\n%s\n%s\n%s\n%s\n",e.name,e.fname,e.nic,e.party); 
       num++;
       }
       
     
       printf("\n\n\t\t\t ENTER PARTY NAME   :  ");
        ch=getche(); 
        printf("%d",ch);
       
      
       votes[ch-65]++;
       
       autoo=65;
       
         for(c=0;c<num;c++)
        {
        printf("\n  %c   ==    %d\n",autoo,votes[c]);
        autoo++;
        }
      
      fclose(fp); 
      fp = NULL;
}                          
 
