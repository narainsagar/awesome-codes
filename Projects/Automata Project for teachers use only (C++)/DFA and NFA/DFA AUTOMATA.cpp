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
  //   cout<<"\n\t\t\t Section : "; cin>>section;
  //   cout<<"\n\t\t\t Assignment No. : "; cin>>assign;
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
      line();
      cout << "\n\t\t\tINPUTS FILE NOT EXIST\n";
      line();
      system("pause");
      exit(0);
    }
    file.close();
    int j = 0, u = 0, w = 0, found = 0, z = 0, lang = 0;
    bool notexist = false, allInputs = false;
    string input, output;
    output = ("Assignment_" + assign + "+Section_" + section + "+Result.xls");
    static char outputfilename[100];
    for (int i = 0; i < output.size(); i++)
      outputfilename[i] = output[i];
    char var1 = I;
    bool boolean = true;
    ofstream WriteFile;
    WriteFile.open(outputfilename, ios::app);
    string sstr = fname, text = ".txt";
    ifstream inputFile;
    inputFile.open("InputFile.cpp");
    if (inputFile.good())
      while (!inputFile.eof())
      {
        inputFile >> input;
        char check[input.size()];
        for (int e = 0; e <= input.size(); e++)
        {
          lang = 0;
          bool match = false;
          check[w] = var1;
          for (int q = 0; q < a; q++)
            if (input[e] == alpha[q])
              lang++;
          if (lang == 0)
            notexist = true;
          for (int d = 0; d < t && !match; d++)
          {
            string sss = transitions[d];
            if (sss[2] == var1 && input[e] == sss[4])
            {
              var1 = sss[sss.size() - 1];
              match = true;
            }
          }
          w++;
        }
        for (int g = 0; g < f; g++)
          for (int y = 0; y < w; y++)
            if (F[g] == check[y])
            {
              found++;
              z = y;
            }
        if (!found && z != w - 1 && notexist)
          boolean = false;
      } // end while
    else
    {
      cout << "\n\t\t\tFILE NOT EXIST\n";
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
  cout << "\n\t  \4\4\4\4 DETERMINISTIC & NON-DETERMINISTIC FINITE AUTOMATA \4\4\4\4\n\n\t\t\t     \4\4\4\4  DFA and NFA \4\4\4\4";
}
void logo2()
{
  line();
  cout << "\n\t\t   \4\4\4 F A S T - N U C E S   K A R A C H I \4\4\4";
  line();
}
