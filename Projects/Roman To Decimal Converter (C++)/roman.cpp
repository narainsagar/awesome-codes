#include <iostream>
using namespace std;

class Roman
{

public:
  int fix(char s)
  {
    if (s == 'I')
      return 1;
    if (s == 'V')
      return 5;
    if (s == 'X')
      return 10;
    if (s == 'L')
      return 50;
    if (s == 'C')
      return 100;
    if (s == 'D')
      return 500;
    if (s == 'M')
      return 1000;
  }
};

int main()
{

  Roman roma;
  string str;
  int c[100];
  int k;
  int num = 0;
  while (1)
  {
    cout << "\n\t\t Enter number in roman form  ( like  XV    note( CAPSLOCK ON BEFORE WRITE )) " << endl;
    cin >> str;
    for (int i = 0; i <= str.size(); i++)
    {
      // k=0;
      cout << roma.fix(str[i]);
      c[i] = roma.fix(str[i]);

      if (i != 0)
      {
        if (c[i - 1] >= c[i])
          num += c[i - 1];
        if (c[i - 1] < c[i])
          num -= c[i - 1];
      }
    }
    cout << "NUM =====*************=========\n\n\n\t" << num << endl
         << endl
         << endl;
    num = 0;
  }
  system("pause");
  return 0;
}
