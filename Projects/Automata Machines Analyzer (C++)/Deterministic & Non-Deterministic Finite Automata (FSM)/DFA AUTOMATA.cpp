/*        FINITE AUTOMATA (DFA & NFA) ANALYZER  
Names    :    Narain Sagar (K11-2368), Shamikh Ahmed (K11-2379)
Sec      :     A
Date     :    01-06-2013 (01:09 A.M) 
*/
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
void line();
void logo1();
void logo2();
int main()
{
  while (1)
  { //system("color 4B");
    system("cls");
    char fname[1000], c;
    ifstream file;
    logo2();
    logo1();
    cout << "\n\t\t\tPRESS ESC   - TO EXIT \n\n\t\t\tPRESS ENTER - TO CONTINUE ";
    c = getch();
    if (c == '\e')
      exit(0);
    else
    {
      line();
      cout << "\n\t\tEnter file name like (example.txt)  :  ";
      cin >> fname;
      file.open(fname);
      line();
      system("pause");
      line();
      if (file.good())
      {
        string str, transitions[500], title;
        char I, states[1000], alpha[1000], F[100], ch;
        int s = 0, a = 0, f = 0, i = 0, t = 0, k = 1;
        while (!file.eof())
        {
          getline(file, str);
          cout << str << endl;
          if (k < 5)
          {
            for (int p = 3; p <= str.size(); p += 2)
            {
              if (k == 1)
              {
                states[s] = str[p];
                s++;
              }
              if (k == 2)
              {
                alpha[a] = str[p];
                a++;
              }
              if (k == 3)
              {
                I = str[p - 1];
                i++;
              }
              if (k == 4)
              {
                F[f] = str[p];
                f++;
              }
            }
          }
          else
          {
            transitions[t] = str;
            t++;
          }
          k++;
        } //end while(!file.eof())
        do
        {
          // system("cls");
          int j = 0, u = 0, w = 0, found = 0, z = 0, lang = 0;
          bool notexist = false;
          string input;
          char current = I;
          logo1();
          cout << "( " << fname << " )\n";
          cout << "\n\tALPHABETS ARE : ";
          for (int g = 0; g < a - 1; g++)
            cout << alpha[g] << ",";
          line();
          cout << "\n\t\tInput String : ";
          cin >> input;
          char check[input.size()];
          line();
          for (int e = 0; e <= input.size(); e++) // CODE WORK MAIN
          {
            lang = 0;
            bool match = false;
            check[w] = current;
            for (int q = 0; q < a; q++)
              if (input[e] == alpha[q])
                lang++;
            if (lang == 0)
              notexist = true;
            for (int d = 0; d < t && !match; d++)
            {
              string sss = transitions[d];
              if (sss[2] == current && input[e] == sss[4])
              {
                current = sss[sss.size() - 1];
                match = true;
              }
            }
            w++;
          }
          for (int g = 0; g < f; g++) //  in last am i on final state.?
            for (int y = 0; y < w; y++)
              if (F[g] == check[y])
              {
                found++;
                z = y;
              }
          //     if(notexist) cout<<"\n\t\t\tINVALID ALPHABETS";
          //     else  cout<<"\n\t\t\tVALID ALPHABETS";
          line();
          if (found && z == w - 1 && !notexist)
            cout << "\n\t\t\t... ACCEPTED ...";
          else
            cout << "\n\t\t\t... REJECTED ...";
          line();
          cout << "\n\t\tDo u want to check another String (y/n) ";
          ch = getch();
        } while (ch != 'n');
      }
      else
        cout << "\n\t\t\tNO SUCH FILE EXIST ..";
      line();
      system("pause");
    }
  }
  return 0;
}
void line()
{
  cout << "\n________________________________________________________________________________\n";
}
void logo1()
{
  line();
  cout << "\n\t  \4\4\4\4 DETERMINISTIC & NON-DETERMINISTIC FINITE AUTOMATA \4\4\4\4\n\n\t\t\t     \4\4\4\4  DFA and NFA \4\4\4\4";
  line();
}
void logo2()
{
  line();
  cout << "\n\t\t\t  ...::: Group Members :::...\n\n\t\t\t1. Narain Sagar (K11-2368 SEC-A)\n\n\t\t\t2. Shamikh Ahmed (K11-2371 SEC-A)";
  line();
  cout << "\n\t\t   \4\4\4 F A S T - N U C E S   K A R A C H I \4\4\4";
}
