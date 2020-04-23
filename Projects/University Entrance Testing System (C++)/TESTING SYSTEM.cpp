#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void PASSWORD(string pin_code1);

//  section for filling requirement input file stream and out put file stream for each data storing and reading in whole program
ifstream r, rq, r_t, r_r;
ofstream w, wq, w_t, w_r_cs, w_r_ee, w_r;
ifstream r_r_cs("QUALIFIED_IN_CS.txt");
ifstream r_r_ee("QUALIFIED_IN_EE.txt");

//   filling section end

// FOR GENERATE A AUTOMATIC ID FOR STUDENT ( get id from the file student_id and than save by increament and than return id to the student  )
int id, q_choice;

int id_s()
{
  r.open("students_id.txt");
  r >> id;
  r.close();
  id++;
  w.open("students_id.txt");
  w << id;
  w.close();
  return id;
}

//   student class (  sign_up     , sign_in   , testing     ,check student and  save the qualified student   )

class student
{

private:
  // for student info
  string name, password;
  char dpt_choice;
  string check_name, check_password;
  int check_id, id;
  // for test purpose
  float correct_A, wrong_A, total_Q;
  float percentage;
  string Q, Choice_a, Choice_b, Choice_c, Choice_d, A, choice;

public:
  // by default already student registered that is me narain
  student()
  {
    id = 2368;
    name = "NARAIN";
    password = "2368";
    dpt_choice = 1;
  }

  //.............................................................. sign up section

  // taking data for sign up
  void input()
  {
    cout << "\n\n\t\t\t\tNAME       :     ";
    getline(cin >> ws, name);
    cout << "\n\n\t\t\t\tPASSWORD   :     ";
    cin >> password;
    cout << "\n\n\t\t\t\tDEPARTMENT :     \n\n\t\t\t press 1 for CS\n\t\t\t press 2 for EE\n";
    dpt_choice = getch();
  }

  // show sign up data

  void output()
  {

    system("cls");
    id = id_s();
    cout << "\n\n\t\t\t\tYOUR ID    :      K11-" << id;
    cout << "\n\n\t\t\t\tNAME       :     " << name;
    cout << "\n\n\t\t\t\tPASSWORD   :     " << password;
    switch (dpt_choice)
    {
    case '1':
      cout << "\n\n\t\t\t\tDEPARTMENT : CS";
      break;
    case '2':
      cout << "\n\n\t\t\t\tDEPARTMENT : EE";
      break;
    }
    cout << "\n\n\t\t.................REGISTERED.................";
  }

  //.............................................................. sign up section end

  //.............................................................. sign in section

  // taking data for sign in

  void input_for_check()
  {
    cout << "\n\n\t\t\t\tID         :      K11-";
    cin >> check_id;
    cout << "\n\n\t\t\t\tNAME       :     ";
    cin >> check_name;
    cout << "\n\n\t\t\t\tPASSWORD   :     ";
    cin >> check_password;
  }

  // check either student regestered or not if not than repeat
  bool check_user_registration()
  {

    if (check_id == id && check_password == password && check_name == name)
      return true;
    else
      return false;
  }

  //.............................................................. sign up section end

  // ................................................................TESTING SECTION

  // test section taking question from the file of test where acadmic already given the question and test given by regestered student................

  void test(int num_of_question)
  {

    cout << "\n\n\t\t TEST\n\n\n\n";
    cout << "\n\n\t\t\t\tPRESS( x )FOR WITHDRAW FROM ANY QUESTION =  ";
    r_t.open("test.txt");
    correct_A = 0;
    wrong_A = 0;
    for (total_Q = 0; total_Q != num_of_question; total_Q++)
    {
      cout << "\n  Q # " << total_Q + 1 << "\n\n";
      getline(r_t, Q);
      cout << Q << endl;
      getline(r_t, Choice_a);
      cout << Choice_a << endl;
      getline(r_t, Choice_b);
      cout << Choice_b << endl;
      getline(r_t, Choice_c);
      cout << Choice_c << endl;
      getline(r_t, Choice_d);
      cout << Choice_d << endl;
      cout << "\n\tenter your choice ";
      getline(r_t, A);
      // r_t.close();
      cin >> choice;
      if (choice == A)
        correct_A++;
      else if (choice == "x" || choice == "X")
      {
      }
      else
        wrong_A++;
    }
    r_t.close();
    system("cls");
    //  result area
    cout << "\n\n\t\t\t\t\t RESULT  ";
    cout << "\n\n\t\t\t\tNUMBERS OF TOTAL QUESTION =  " << total_Q << endl;
    cout << "\n\n\t\t\t\tNUMBERS OF ATTEMPT QUESTION =  " << correct_A + wrong_A << endl;
    cout << "\n\n\t\t\t\tNUMBERS OF WITHDRAW QUESTION =  " << total_Q - (correct_A + wrong_A) << endl;
    cout << "\n\n\t\t\t\tNUMBERS OF CORRECT ANSWER =  " << correct_A << endl;
    cout << "\n\n\t\t\t\tNUMBERS OF WRONG ANSWER   =  " << wrong_A << endl;
    percentage = ((((correct_A) - (wrong_A / 3)) / total_Q) * 100);
    cout << "\n\n\t\t\t\tPERCENTAGE ( % )          =  " << percentage << " % " << endl;
  }

  // ................................................................TESTING SECTION END

  // ................................................................CHECKING QUALIFIED STUDENT SECTION

  // cheking test percentage if student get percentage  greater than or equal to 50 mean qualified and save data into according to department choice txt
  void save_data_of_student()
  {
    cout << "\n\n percentag  =";
    if (percentage >= 50)
    {
      switch (dpt_choice)
      {
      case '1':
        w_r_cs.open("QUALIFIED_IN_CS.txt", ios::app);
        w_r_cs << "\n"
               << "K11-" << id << endl;
        w_r_cs << name << endl;
        w_r_cs << password << endl;
        w_r_cs << percentage;
        w_r_cs.close();
        break;
      case '2':
        w_r_ee.open("QUALIFIED_IN_EE.txt", ios::app);
        w_r_ee << "\n"
               << "K11-" << id << endl;
        w_r_ee << name << endl;
        w_r_ee << password << endl;
        w_r_ee << percentage;
        w_r_ee.close();
        break;
      }
    }
  }

  // ................................................................CHECKING QUALIFIED STUDENT SECTION END
};

//  IN ACADMIC    (   PASSWORD FOR TEST IS YOUR ARE ACADMIC OR NOT    ,    TEST QUESTION ADDING SECTION  AND  LIST SHOWING SECTION OF BOTH DEPARTMENT QUALIFIED STUDENT LIST  )
class acadmic_manager
{
private:
  string Q, Choice_a, Choice_b, Choice_c, Choice_d;
  char A, c, dpt_choice;
  // variable for cs student qualified list
  string cs_id, cs_name, cs_pass, cs_percentage;
  // variable for ee student qualified list
  string ee_id, ee_name, ee_pass, ee_percentage;

public:
  // password in ********* of acadmic
  //  void PASSWORD(string pin_code1);

  // test question by acadmic
  void adding_test_question();

  // list show  ( read ) from cs-qualified file  &  ee-qualified file
  void qualified_list();
};

int main()
{
  student s;
  acadmic_manager a;
  char choice, ch, chh;
  system("cls");
start:

  cout << "\n\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\n";
  cout << "\n\t\4 FAST NATIONAL UNIVERSITY OF COMPUTER AND EMERGING SCIENCES \4\n\t\t\t\t\4 NUCES \4\n";
  cout << "\n\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\n";

  cout << "\t\t\t________________________________________";
  cout << "\n\n\t\t\t 1.. STUDENT";
  cout << "\n\t\t\t2.. ACADMIC MANAGER";
  cout << "\n\t\t\t3.. EXIT";
  cout << "\n\t\t\t________________________________________\n";
  chh = getch();
  system("cls");
  switch (chh)
  {
  case '1':
    do
    {
      cout << "\n\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
      cout << "\n\t\tpress 1 for sign in  ( if you are already registered )\n";
      cout << "\n\t\tpress 2 for sign up  ( if you are not already registered )\n";
      cout << "\n\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
      choice = getch();
      switch (choice)
      {

      case '1':
        s.input_for_check();
        if (s.check_user_registration())
        {
          s.test(7);
          s.save_data_of_student();
        }
        else
          cout << "\n\n\t\t\tNOT REGISTERED";
        break;

      case '2':
        s.input();
        s.output();
        break;
      }
      cout << "\n\n\t\t\tPRESS 1 FOR CONTINUE\n\t\t\tPRESS 2 FOR MAIN MENUE\n\t\t\tPRESS 3 FOR EXIT";
      ch = getch();
      if (ch == '3')
        exit(0);
      else if (ch == '2')
      {
        goto start;
        system("cls");
      }
      else
        system("cls");
    } while (ch == '1');
    break;

  case '2':
    cout << "\n\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\n";
    cout << "\n\t\t\t\t ACADEMIC BLOCK \n";
    cout << "\n\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\222\n";
    PASSWORD("sagar");
    cout << "\n\t\t\t_________________________________________________\n";
    cout << "\n\t\t\tPRESS 1 FOR ADDING TEST QUESTION ";
    cout << "\n\t\t\tPRESS 2 FOR SHOWING QUALIFIED STUDENT LIST ";
    cout << "\n\t\t\tPRESS 3 FOR MAIN MANUE ";
    cout << "\n\t\t\t__________________________________________________\n";
    char m;
    m = getch();

    if (m == '1')
    {
      system("cls");
      cout << "\n\n\t\t\tENTER TEST ( QUESTION ,4)CHOICE,ANSWER)\n\n\n";
      a.adding_test_question();
    }

    else if (m == '2')
    {
      system("cls");
      a.qualified_list();
    }

    else if (m == '3')
    {
      system("cls");
      goto start;
    }

    break;
  case '3':
    exit(0);
    break;
  }
  system("pause");
  return 0;
}

void acadmic_manager::adding_test_question()
{
  ofstream w_t("test.txt", ios::app);
  for (int i = 0; !(c == 'n' || c == 'N'); i++)
  {
    cout << "\n\n\t\t\t\t QUESTION:  ";
    getline(cin, Q);
    w_t << Q << endl;
    cout << "choice a)";
    getline(cin, Choice_a);
    w_t << " a) " << Choice_a << endl;
    cout << "choice b)";
    getline(cin, Choice_b);
    w_t << " b) " << Choice_b << endl;
    cout << "choice c)";
    getline(cin, Choice_c);
    w_t << " c) " << Choice_c << endl;
    cout << "choice d)";
    getline(cin, Choice_d);
    w_t << " d) " << Choice_d << endl;
    cout << "correct choice ";
    A = getche();
    w_t << A << endl;
    cout << "\n do you want to add another question (y/n)";
    c = getche();
  }
}

void PASSWORD(string pin_code1 = "PASSWORD")
{
  char c, e, x;
  char *ch;
  ch = new char[100];
  do
  {
    cout << " \t  ( password is " << pin_code1 << "   )   \n";
    cout << "\n\t\t\tPASSWORD\t:\t";
    for (int k = 0; e != '\r'; k++)
    {
      ch[k] = getch();
      e = ch[k];
      if (ch[k] == '\b')
        cout << "\b \b";
      else
        cout << "*";
    }
    e = ' ';

    for (int i = 0; i < pin_code1.size(); i++)
      if (pin_code1[i] != ch[i])
        x = 'n';

    if (x != 'n')
    {
      cout << "\n\n\t\t\t\tCORRECT PASSWORD \n";
      e = 'x';
    }
    else
    {
      system("cls");
      cout << "\n\t\t\t\tINCORRECT PASSWORD \n";
      x = ' ';
    }
    if (e != 'x')
    {
      cout << "\n\t\t\t PRESS 1 TO CONTINUE AND 2 TO EXIT \n";
      c = getch();
      system("cls");
    }
    if (c == '2')
    {
      exit(0);
    }

  } while (c != '2' && e != 'x');
}

void acadmic_manager::qualified_list()
{

  cout << "\n\n\t\t\t\tDEPARTMENT :     \n\n\t\t\t press 1 for CS QUALIFIED LIST\n\t\t\t press 2 for EE QUALIFIED LIST\n";
  dpt_choice = getch();
  switch (dpt_choice)
  {
  case '1':
    cout << "\n\n\t\t\t\( QUALIFIED LIST ) DEPARTMENT : CS\n";
    while (!r_r_cs.eof())
    {
      getline(r_r_cs >> ws, cs_id);
      getline(r_r_cs, cs_name);
      getline(r_r_cs, cs_pass);
      getline(r_r_cs, cs_percentage);
      cout << "\n\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
      cout << "\n\t\t\t\t\tID               :   " << cs_id << endl;
      cout << "\n\t\t\t\t\tNAME             :   " << cs_name << endl;
      cout << "\n\t\t\t\t\tPASSWORD         :   " << cs_pass << endl;
      cout << "\n\t\t\t\t\tTEST PERCENTAGE  :   " << cs_percentage << endl;
    }

    break;
  case '2':
    cout << "\n\n\t\t\t\t( QUALIFIED LIST ) DEPARTMENT : EE\n";
    while (!r_r_ee.eof())
    {
      getline(r_r_ee >> ws, ee_id);
      getline(r_r_ee, ee_name);
      getline(r_r_ee, ee_pass);
      getline(r_r_ee, ee_percentage);
      cout << "\n\t\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
      cout << "\n\t\t\t\t\tID               :   " << ee_id << endl;
      cout << "\n\t\t\t\t\tNAME             :   " << ee_name << endl;
      cout << "\n\t\t\t\t\tPASSWORD         :   " << ee_pass << endl;
      cout << "\n\t\t\t\t\tTEST PERCENTAGE  :   " << ee_percentage << endl;
    }

    break;
  }
}
