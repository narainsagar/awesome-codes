#include <conio.h>
#include <iostream>
#include <stdio.h>
void shape_of_welcome();
int me_n;
int main()
{
  int step[4] = {3, 5, 4, 6}, i, n, comp_n, edit_2 = 1, nine = 0, sum_of_n, e, f, u_2, c_2, u[2], c[2], ch;
  do
  {
    system("cls");
    shape_of_welcome();
    printf("|______________________________________________________________________________|\n");
    printf("1.|\tUSER\t=====>>");
    scanf("%d", &me_n);
    printf("|_________________________________________________|\n");
    comp_n = me_n;
    while (me_n != 0)
    {
      me_n /= 10;
      edit_2 *= 10;
      nine = (edit_2 / 10) * 9 + nine;
    }
    sum_of_n = ((2 * edit_2) + comp_n) - 2;
    printf("\n2.|\tCOMPUTER\t------))( SUM  WILL  BECOME  \t = > %d )\n", sum_of_n);
    printf("|_________________________________________________|\n");
    for (i = 0; i < 2; i++)
    {
      printf("\n%d.|\tUSER\t=====>>", step[i]);
      scanf("%d", &u_2);
      u[i] = u_2;
      printf("|_________________________________________________|\n");
      printf("\n%d.|\tCOMPUTER=====>>", step[i + 2]);
      c_2 = nine - u_2;
      c[i] = c_2;
      printf("%d\n", c_2);
      printf("|_________________________________________________|\n");
    }
    printf("\n|TOTAL SUM ====>>>> %d + %d + %d + %d +%d  =  %d ", comp_n, u[0], c[0], u[1], c[1], comp_n + u[0] + c[0] + u[1] + c[1]);
    printf("\n\n\t\tDO YOU WNAT TO PLAY AGAIN(y/n)");
    printf("\n\n|____________________________________________|\n\n\t\t");
    printf("\n\n\tEnter : ");
    ch = getche();
  } while (ch != 'n');
  getch();
}

//____________________________________________________________shape_of_signin();

void shape_of_welcome()
{
  printf("\t\t ********************************************** \n");
  printf("\t\t **____________________ * ___________________** \n");
  printf("\t\t **______________ *          * ______________** \n");
  printf("\t\t **_____*  WELCOME TO MY 6 STEPS GAME    *___** \n");
  printf("\t\t **______________ *          * ______________** \n");
  printf("\t\t **____________________ * ___________________** \n");
  printf("\t\t **_______>>>>>>ENTER ANY NUMBER<<<<<<_______** \n");
  printf("\t\t ********************************************** \n");
}
//_______________________________________________________________________________________________________
