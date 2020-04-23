#include <windows.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
void line();
void logo1();
void logo2();
int main()
{
  logo1();
  logo2();
  string section, assign;
  cout << "\n\t\t\t Section : ";
  cin >> section;
  cout << "\n\t\t\t Assignment No. : ";
  cin >> assign;
  int No = 0;
  HANDLE hFind;
  WIN32_FIND_DATA FindData;
  hFind = FindFirstFile("*.txt", &FindData);
  do
  {
    ifstream file;
    string str, transitions[500];
    char I, states[1000], alpha[1000], F[100], ch;
    int s = 0, a = 0, f = 0, i = 0, t = 0, k = 1;
    char *fname = new char[100];
    No++;
    fname = FindData.cFileName;
    file.open(fname);
    if (file.good())
      while (!file.eof())
      {
        getline(file, str);
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
    else
    {
      cout << "\n\t\t\tFILE NOT EXIST\n";
      system("pause");
      exit(0);
    }
    file.close();
    char tape[1000];
    char cc, current = I;
    bool boolean = true, reachedFinal = false, notexist = false, notFound = false;
    int x, start, pointer, limit = 99, end;
    x = start = pointer = 30;
    for (int g = 0; g < limit; g++)
      tape[g] = '\4';
    string input, output;
    output = ("Assignment_" + assign + "+Section_" + section + "+Result.xls");
    static char outputfilename[100];
    for (int i = 0; i < output.size(); i++)
      outputfilename[i] = output[i];
    ofstream WriteFile;
    WriteFile.open(outputfilename, ios::app);
    string sstr = fname, text = ".txt";
    ifstream inputFile;
    inputFile.open("InputFile.cpp");
    if (inputFile.good())
      while (!inputFile.eof())
      {
        inputFile >> input;
        for (int g = 0; g < input.size(); g++, x++)
          tape[x] = input[g];
        for (int w = pointer; w < start + input.size() && !notexist; w++)
        {
          int lang = 0;
          for (int q = 0; q < a; q++)
            if (tape[w] == alpha[q])
              lang++;
          if (lang == 0)
            notexist = true;
        }
        if (notexist == false)
          while (!(reachedFinal || notFound))
          {
            bool found = false;
            char next, move, replace;
            int d = 0;
            for (d; d < t && !found; d++)
            {
              string ss = transitions[d];
              if (current == ss[2] && tape[pointer] == ss[4])
              {
                replace = ss[6];
                move = ss[8];
                next = ss[11];
                found = true;
              }
            }
            if (d == t && found == false)
              notFound = true;
            if (found)
            {
              current = next;
              tape[pointer] = replace;
              if (move == 'L')
                pointer--;
              if (move == 'R')
                pointer++;
              if (move == 'S')
              { /*do nothing; */
              }
            }
            if (found)
              for (int h = 0; h < f - 1; h++)
                if (current == F[h])
                  reachedFinal = true;
          }
        if (!reachedFinal && notFound && notexist)
          boolean = false;
      }
    else
    {
      line();
      cout << "\n\t\t\t INPUTS FILE NOT EXIST\n";
      line();
      system("pause");
      exit(0);
    }
    if (boolean)
    {
      WriteFile << (sstr.erase(sstr.find(".txt"), text.size()))
                << "\t\t"
                << "ACCEPTED" << endl;
    }
    else
    {
      WriteFile << (sstr.erase(sstr.find(".txt"), text.size()))
                << "\t\t"
                << "REJECTED" << endl;
    }
    WriteFile.close();
    inputFile.close();
    fname = FindData.cFileName;
  } while (FindNextFile(hFind, &FindData));
  line();
  system("pause");
  return 0;
}

void line()
{
  cout << "\n________________________________________________________________________________\n";
}
void logo1()
{
  line();
  cout << "\n\t\t\t  \4\4\4\4 TURING MACHINE \4\4\4\4\n\n\t\t\t    \t \4\4\4\4 TM  \4\4\4\4";
}
void logo2()
{
  line();
  cout << "\n\t\t   \4\4\4 F A S T - N U C E S   K A R A C H I \4\4\4";
  line();
}
