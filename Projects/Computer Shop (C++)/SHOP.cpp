#include <iostream>
#include <fstream>
using namespace std;

struct comp_data
{
  string mother_board, ram, processor, hard_disk, rate;
} s[100];

class comp_selling_shop
{
private:
  string mother_board, ram, processor, hard_disk, rate;
  int i;

  string s;

public:
  void show_list_sell()
  {
    ifstream r("comp.txt");
    int n;
    i = 0;
    comp_data s[100];
    while (!r.eof())
    {
      getline(r >> ws, s[i].mother_board);

      getline(r, s[i].ram);

      getline(r, s[i].processor);

      getline(r, s[i].hard_disk);

      getline(r, s[i].rate);

      cout << "\n\n********   " << i + 1 << " *********************************************************";
      cout << "\n\n\t\t  MOTHERBOARD CONF   : " << s[i].mother_board;
      cout << "\n\n\t\t  RAM CONF           : " << s[i].ram;
      cout << "\n\n\t\t  PROCESSOR CONF     : " << s[i].processor;
      cout << "\n\n\t\t  HARD DISK CONF     : " << s[i].hard_disk;
      cout << "\n\n\t\t  RATE OF  COMP      : " << s[i].rate;

      i++;
    }

    r.close();
    cout << "\n\n\t\t\t ENTER NUM OF COMP THAT YOU WANT TO BUY\n\n\t\t===>  ";
    cin >> n;
    cout << "\n\n\t\t\t  ENTER THE AMOUNT : ";
    cin >> rate;
    if (rate == s[n - 1].rate)
    {
      cout << "\n\n\t\t\t YOUR COMPUTER WAS SELLED\n\n\t\t===>  ";
      system("pause");
      ofstream wt("comp.txt");
      cout << "total num" << i;
      system("cls");
      for (int k = 0; k < i; k++)
      {
        if ((k + 1) != n)
        {
          wt << "\n"
             << s[k].mother_board << "\n"
             << s[k].ram << "\n"
             << s[k].processor << "\n"
             << s[k].hard_disk << "\n"
             << s[k].rate;
        }
      }
    }
    else
      cout << "invalid amount";
  }
};

class comp_making : public comp_selling_shop
{
private:
  string mother_board, ram, processor, hard_disk, rate;
  int i;

public:
  void add_comp()
  {
    ofstream w("comp.txt", ios::app);

    cout << "\n\n\t\t ENTER MOTHERBOARD CONF   : ";
    getline(cin >> ws, mother_board);
    cout << "\n\n\t\t ENTER RAM CONF           : ";
    getline(cin >> ws, ram);
    cout << "\n\n\t\t ENTER PROCESSOR CONF     : ";
    getline(cin >> ws, processor);
    cout << "\n\n\t\t ENTER HARD DISK CONF     : ";
    getline(cin >> ws, hard_disk);
    cout << "\n\n\t\t ENTER TOTAL RATE OF YOUR COMP : ";
    cin >> rate;
    w << "\n"
      << mother_board << "\n"
      << ram << "\n"
      << processor << "\n"
      << hard_disk << "\n"
      << rate;
    w.close();
  }
};

int main()
{

  comp_selling_shop comp;
  comp_making cmp_make;
  int choice;
  char ch;

  do
  {
    cout << "\n\n\t\t\t\tWELCOME TO MY COMPUTER SHOP\n\n";
    cout << "\n\n\n\t\t\t 1 :  COMPUTER SELLING";
    cout << "\n\t\t\t 2 :  COMPUTER MAKING";
    cout << "\n\t\t\t 3 :  EXIT\n\t\t\t\t===>  ";
    cin >> choice;
    switch (choice)
    {

    case 1:
      comp.show_list_sell();
      break;
    case 2:
      cmp_make.add_comp();
      break;
    case 3:
      exit(0);
      break;
    default:
      cout << "\n\n\t\t YOU ENTER INVALID CHOICE\n\n";
    }

    cout << "\n\n\t\tdo you want to continue  ( y  / n )";
    cin >> ch;
    system("cls");

  } while (ch != 'n');

  system("pause");
  return 0;
}
