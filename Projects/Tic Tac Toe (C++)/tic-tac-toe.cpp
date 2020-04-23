#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

void mul();
void single();
int check();
void shape2();
int win_c();
char xo[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char n[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
ofstream w("ttt.txt", ios::app);

int main()
{
  system("color 0D");
  char ch;
  cout << "\n\n\t\t\tm FOR MULTI PLAYER";
  cout << "\n\n\t\t\ts FOR SINGLE PLAYER\n\n\t\t>>  ";
  cin >> ch;
  w << "\n\n\t\t\tm FOR MULTI PLAYER";
  w << "\n\n\t\t\ts FOR SINGLE PLAYER\n\n\t\t>>  " << ch;
  switch (ch)
  {
  case 'm':
    system("cls");
    mul();
    break;
  case 's':
    system("cls");
    single();
    break;
  default:
    cout << "\n\n YOU ENTER WRONG CHOICE ";
    w << "\n\n YOU ENTER WRONG CHOICE ";
  }
  cout << "\n\n\t\tPRESS ENTER";
  w << "\n\n\t\tPRESS ENTER";
  getch();

  system("pause");
  return 0;
}

void mul()
{
  int p = 1, num, result;
  char p1m = 431, p2m = 432, mark;
  string pn, p1 = "PLAYER 1", p2 = "PLAYER 2";
  cout << "\n\n\t PLAYER 1 NAME  :    ";
  cin >> p1;
  // cout<<"\n\n\t SELECT YOUR SHAPE (LIKE X,O,ETC)   ";  cin>>p1m;
  cout << "\n\n\t PLAYER 2 NAME :     ";
  cin >> p2;
  // cout<<"\n\n\t SELECT YOUR SHAPE(LIKE X,O,ETC)    ";  cin>>p2m;
  w << "\n\n\t PLAYER 1 NAME  :    ";
  w << p1;
  //w<<"\n\n\t SELECT YOUR SHAPE (LIKE X,O,ETC)   ";  w<<p1m;
  w << "\n\n\t PLAYER 2 NAME :     ";
  w << p2;
  //w<<"\n\n\t SELECT YOUR SHAPE(LIKE X,O,ETC)    ";  w<<p2m;
  cout << "\n\n\t\t\t\tSYMBOL FOR   " << p1 << " is  " << p1m << "\n\n\t\t\t\tSYMBOL FOR   " << p2 << " is  " << p2m << "\n\t\t  PRESS ENTER TO START THE GAME  :";
  getch();

  do
  {
    system("cls");
    p = (p % 2) ? 1 : 2;
    pn = (p == 1) ? p1 : p2;
    shape2();
    cout << "\t\t>>   " << pn << "    <<\t\t  ======>   ";
    cin >> num;
    w << "\t\t>>   " << pn << "    <<\t\t  ======>   ";
    w << num;
    mark = (p == 1) ? p1m : p2m;
    if (n[num] == xo[num])
    {
      xo[num] = mark;
    }
    else
    {
      if (num == 10)
      {
        cout << "\n\n\t\t\t...:: GAME DRAW ::...";
        w << "\n\n\t\t\t...:: GAME DRAW ::...";
        break;
      }
      cout << "\n    .:: INVALID ::.";
      w << "\n    .:: INVALID ::.";
      p--;
      cout << "\nmark" << mark;
      w << "\nmark" << mark;
      getch();
    }
    result = check();
    p++;
  } while (result - 1);

  shape2();
  char a = 434, b = 434;
  cout << "\n   .:: WINNER IS ::.   "
       << "\n"
       << "   >> " << pn << " <<   " << endl;
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << "\t\t\tWINNEE IS  :  " << pn;
  w.close();
}

void single()
{
  int p = 1, e = 0, num, result;
  char p1m = 431, p2m = 432, mark;
  string pn, p1 = " YOU ", p2 = "COMPUTER ";
  cout << "\n\n\t  ENTER YOUR NAME :    ";
  cin >> p1;
  // cout<<"\n\n\t SELECT YOUR SHAPE (LIKE X,O,ETC)   ";  cin>>p1m;
  // cout<<"\n\n\t SELECT YOUR SHAPE(LIKE X,O,ETC)    ";  cin>>p2m;
  w << "\n\n\t  ENTER YOUR NAME :    " << p1;
  //w<<"\n\n\t SELECT YOUR SHAPE (LIKE X,O,ETC)   ";  w<<p1m;
  //w<<"\n\n\t SELECT YOUR SHAPE(LIKE X,O,ETC)    ";  w<<p2m;
  cout << "\n\n\t\t\t\tSYMBOL FOR   " << p1 << " is  " << p1m << "\n\n\t\t\t\tSYMBOL FOR   " << p2 << " is  " << p2m << "\n\t\t  PRESS ENTER TO START THE GAME  :";
  getch();

  do
  {
    int k, c;
    system("cls");
    p = (p % 2) ? 1 : 2;
    pn = (p == 1) ? p1 : p2;
    shape2();
    if (pn == p2)
    {
      c = win_c();
      // num=(n!=num&&(n<=9))?n:(num+1);
      //num=(num>9)?((num-9)+n):num;
      // num=n;
      if ((xo[c] == p1m) || (xo[c] == p2m))
      {
        for (k = 1; k < 10; k++)
        {
          if ((xo[k] != p1m) && (xo[k] != p2m))
            break;
        }
        num = k;
      }
      else
        num = c;
      // num=((xo[num]==p1m)||(xo[num]==p2m)||num>9)?num-e:num;
      cout << "\t\t>>   " << pn << "    <<\t\t  ======>   " << num << "\n\n";

      w << "\t\t>>   " << pn << "    <<\t\t  ======>   ";
      w << num;
    }
    else
    {
      cout << "\t\t>>   " << pn << "    <<\t\t  ======>   ";
      cin >> num;
      w << "\t\t>>   " << pn << "    <<\t\t  ======>   ";
      w << num;
    }

    mark = (p == 1) ? p1m : p2m;
    if (n[num] == xo[num])
    {
      xo[num] = mark;
      result = check();
    }
    else
    {
      cout << "\n    .:: INVALID ::.";
      p--;
      e++;
      cout << "\nmark" << mark;
      getch();
    }
    p++;
  } while (result - 1);
  if (result == 0)
    cout << "\n\n\t\t\t...:: GAME DRAW ::...";
  else
  {
    shape2();
    char a = 434, b = 434;
    cout << "\n   .:: WINNER IS ::.   "
         << "\n"
         << "   >> " << pn << " <<   " << endl;
    cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  }
  w << "\t\t\tWINNEE IS  :  " << pn;
  w.close();
}

//.............................................shape of tic toc toi

void shape2()
{
  char a = 434, b = 434;
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  cout << " .:: TIC TOC TOI ::. \n";
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  cout << a << a << "  " << xo[1] << "  " << a << "  " << xo[2] << "  " << a << "  " << xo[3] << "  " << a << a << endl;
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  cout << a << a << "  " << xo[4] << "  " << a << "  " << xo[5] << "  " << a << "  " << xo[6] << "  " << a << a << endl;
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  cout << a << a << "  " << xo[7] << "  " << a << "  " << xo[8] << "  " << a << "  " << xo[9] << "  " << a << a << endl;
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  cout << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << " .:: TIC TOC TOI ::. \n";
  w << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << a << a << "  " << xo[1] << "  " << a << "  " << xo[2] << "  " << a << "  " << xo[3] << "  " << a << a << endl;
  w << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << a << a << "  " << xo[4] << "  " << a << "  " << xo[5] << "  " << a << "  " << xo[6] << "  " << a << a << endl;
  w << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << a << a << "  " << xo[7] << "  " << a << "  " << xo[8] << "  " << a << "  " << xo[9] << "  " << a << a << endl;
  w << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
  w << a << a << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << b << a << a << endl;
}

//.......................................................checking winner
int check()
{

  if (((xo[1] == xo[2]) && (xo[2] == xo[3]) && (xo[3] == xo[1])) || ((xo[4] == xo[5]) && (xo[5] == xo[6]) && (xo[6] == xo[4])) || ((xo[7] == xo[8]) && (xo[8] == xo[9]) && (xo[9] == xo[7])) || ((xo[1] == xo[4]) && (xo[4] == xo[7]) && (xo[7] == xo[1])) || ((xo[2] == xo[5]) && (xo[5] == xo[8]) && (xo[8] == xo[2])) || ((xo[3] == xo[6]) && (xo[6] == xo[9]) && (xo[9] == xo[3])) || ((xo[1] == xo[5]) && (xo[5] == xo[9]) && (xo[9] == xo[1])) || ((xo[3] == xo[5]) && (xo[5] == xo[7]) && (xo[7] == xo[3])))
    return 1;
  else
    return 0;
}

int win_c()
{
  int x;
  if (xo[1] == xo[2])
    return 3;
  if (xo[3] == xo[4])
    return 5;
  if (xo[5] == xo[6])
    return 7;
  if (xo[7] == xo[8])
    return 9;
  if (xo[1] == xo[4])
    return 7;
  if (xo[4] == xo[7])
    return 1;
  if (xo[1] == xo[7])
    return 4;
  if (xo[2] == xo[5])
    return 8;
  if (xo[5] == xo[8])
    return 2;
  if (xo[2] == xo[8])
    return 5;
  if (xo[3] == xo[6])
    return 9;
  if (xo[6] == xo[9])
    return 3;
  if (xo[3] == xo[9])
    return 6;
  if (xo[1] == xo[5])
    return 9;
  if (xo[5] == xo[9])
    return 1;
  if (xo[1] == xo[9])
    return 5;
  if (xo[3] == xo[5])
    return 7;
  if (xo[5] == xo[7])
    return 3;
  if (xo[3] == xo[7])
    return 5;
  else
    return 9;
}
