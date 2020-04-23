#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void PASSWORD(string);

ofstream w_id("id.txt", ios::app);
ifstream r_id("id.txt");
ofstream w_attendence("attendence.txt", ios::app);
ifstream r_attendence("attendence.txt");
ofstream w_class_work("class_work.txt", ios::app);
ifstream r_w_class_work("class_work.txt");
ifstream r_profile("profile.txt");
ofstream w_profile("profile.txt", ios::app);

string id_, date, attendence;

class student
{
private:
   float m1, m2, as1, as2, q1, q2, final, total, gp;
   string course, id;
   string id_, name, pass, g;
   bool check;
   int n;

public:
   void sign_up()
   {
      cout << "\n\n\t  NAME     :   ";
      cin >> name;
      cout << "\n\n\t  ID       :   ";
      cin >> id_;
      cout << "\n\n\t  password :   ";
      cin >> pass;
      cout << "\n\n\t  gender   :   ";
      cin >> g;

      w_id << id_ << endl;
      w_profile << "\n"
                << id_ << "\n"
                << pass << "\n"
                << name << "\n"
                << g;

      cout << "\n\nYOU RE SIGN UP SUCEESFULLY..";
   }

   void show_profile()
   {

      bool s = false;
      string id_p, p_p;
      cout << "\n\n\t ID  :  ";
      cin >> id_p;
      cout << "\n\n\t password  :  ";
      cin >> p_p;

      while (!r_profile.eof() && s == false)

      {

         getline(r_profile >> ws, id_);

         getline(r_profile >> ws, pass);

         getline(r_profile >> ws, name);

         getline(r_profile >> ws, g);

         if (id_p == id_ && p_p == pass)
         {
            cout << "\n\n\t\t ENTER 1 FOR SHOW PROFILE  ";
            cout << "\n\n\t\t ENTER 2 FOR SHOW SEMESTER WORK  ";
            char x;
            cin >> x;
            switch (x)
            {
            case '1':

               cout << "\n\n\t  NAME     :   " << name;
               cout << "\n\n\t  ID       :   " << id_;
               cout << "\n\n\t  password :   " << pass;
               cout << "\n\n\t  gender   :   " << g;
               s = true;
               break;

            case '2':
               show_semester_work();
               break;
            }
         }
      }
   }

   void show_semester_work()
   {
      string given_id, given_course;
      ;
      check = false;

      while (!r_w_class_work.eof() && check == false)
      {
         r_w_class_work >> ws >> id;
         r_w_class_work >> course;
         r_w_class_work >> m1;
         r_w_class_work >> m2;
         r_w_class_work >> q2;
         r_w_class_work >> q2;
         r_w_class_work >> as1;
         r_w_class_work >> as2;
         r_w_class_work >> final;
         r_w_class_work >> gp;
         cout << "________" << id << "  " << id_;
         cout << "enter id ";
         break;
         //break;

         if (id == id_)
         {
            cout << "\nCourse name                     : " << course;
            cout << "\nMarks of mid 1  (out of 15)     : " << m1;
            cout << "\nMarks of mid 2  (out of 15)     : " << m2;
            cout << "\nMarks of quiz 1 (out of 5       : " << q2;
            cout << "\nMarks of quiz 2 (out of 5)      : " << q2;
            cout << "\nMarks of assignment 1 (out of 5): " << as1;
            cout << "\nMarks of assignment 2 (out of 5): " << as2;
            cout << "\nMarks of final exam  (out of 50): " << final;
            cout << "\n TOTAL GPA  :   " << gp;

            check = true;
            break;
         }
      }

      if (check == false)
      {
         cout << "\n\n\n YOUR SEMESTER WORK NOT UPLOADED";
      }
   }

   /*     void sign_in()
       {
        cout<<"ENTER YOUR ID :";    cin>a;
        cout<<"password      :";   cin>>psd;
        if()
            
        } 
*/
};

class teacher
{
private:
   float m1, m2, as1, as2, q1, q2, final, total, gp;
   string course, id;
   char ch_attendence;

public:
   teacher() : m1(0), m2(0), as1(0), as2(0), q1(0), q2(0), final(0), total(0), gp(0)
   {
   }

   void taking_attendence()
   {
      cout << "\n\n\t\t DATE :  ";
      cin >> date;
      cout << "ROLL NUM "
           << " \t\t\t\tDATE :  " << date << endl;
      cout << "\n \t\t (  1- PRESENCE   2-  ABSENCE  3- LATE   )\n\n";
      w_attendence << date << endl;
      r_id >> ws;
      while (!r_id.eof())
      {
         r_id >> id;
      re:
         cout << "\n"
              << id << "\t : ";
         ch_attendence = getch();
         switch (ch_attendence)
         {
         case '1':
            attendence = "P";
            break;
         case '2':
            attendence = "A";
            break;
         case '3':
            attendence = "L";
            break;
         default:
            cout << "(  you enter wrong choice )\n";
            goto re;
         }
         cout << attendence;
         w_attendence << id << "\t" << attendence << endl;
      }

      w_attendence << "*";
   }

   void add_semester_work()
   {
      cout << "\nEnter ID                         : ";
      getline(cin >> ws, id);
      cout << "\nEnter course name                : ";
      getline(cin >> ws, course);
      cout << "\nEnter marks of mid 1  (out of 15): ";
      cin >> m1;
      cout << "\nEnter marks of mid 2  (out of 15): ";
      cin >> m2;
      cout << "\nEnter marks of quiz 1 (out of 5) : ";
      cin >> q2;
      cout << "\nEnter marks of quiz 2 (out of 5) : ";
      cin >> q2;
      cout << "\nEnter marks of assignment 1 (out of 5): ";
      cin >> as1;
      cout << "\nEnter marks of assignment 2 (out of 5): ";
      cin >> as2;
      cout << "\nEnter marks of final exam  (out of 50): ";
      cin >> final;
   }

   void cal_semester_work()
   {
      cout << "\nCourse name                     : " << course;
      cout << "\nMarks of mid 1  (out of 15)     : " << m1;
      cout << "\nMarks of mid 2  (out of 15)     : " << m2;
      cout << "\nMarks of quiz 1 (out of 5       : " << q2;
      cout << "\nMarks of quiz 2 (out of 5)      : " << q2;
      cout << "\nMarks of assignment 1 (out of 5): " << as1;
      cout << "\nMarks of assignment 2 (out of 5): " << as2;
      cout << "\nMarks of final exam  (out of 50): " << final;
      total = m1 + m2 + q1 + q2 + as1 + as2 + final;
      cout << "\nTotal persentage                : " << total << "%";

      cout << "\nGPA is: ";
      if (total > 86)
      {
         cout << "4";
         gp = 4;
      }
      else if (total > 76)
      {
         cout << "3.5";
         gp = 3.5;
      }
      else if (total > 70)
      {
         cout << "3";
         gp = 3;
      }
      else if (total > 60)
      {
         cout << "2.5";
         gp = 2.5;
      }
      else if (total > 50)
      {
         cout << "2";
         gp = 2;
      }
      else
      {
         cout << "fail !!";
         gp = 0;
      }

      w_class_work << "\n"
                   << id << "\n"
                   << course << "\n"
                   << m1 << "\n"
                   << m2 << "\n"
                   << as1 << "\n"
                   << as2 << "\n"
                   << q1 << "\n"
                   << q2 << "\n"
                   << final << "\n"
                   << total << "\n"
                   << gp;
   }

   void show_attendence()
   {
      string s;
      while (!r_attendence.eof())
      {
         getline(r_attendence, s);
         cout << "\t" << s << endl;
      }
   }

   void signin_teacher()
   {
      string t_name;
      cout << "\n\n\t\t   ENTER NAME   :   ";
      cin >> t_name;
      PASSWORD("teacher");
   }
};

int main()
{
label:
   student s;
   teacher t;
   char chhh, chhhh, at;
   char ch;
   cout << "\n\n\n\n\n\n\n\n\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
   cout << "\n\t\t\4\4\4\t\tPROGRAMMER :  NARAIN SAGAR  ( Nine )\t\4\4\4\4\n";
   cout << "\n\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n";
   cout << "_______________________________________________________________________________________________\n";
   PASSWORD("sagar");
   cout << "_______________________________________________________________________________________________\n";
   system("pause");
   system("cls");
   cout << "__________________________________________________________________________________\n";
   cout << "__________________________________________________________________________________";
   cout << "\n\n \t\t\t   1   STUDENT \n\n\t\t\t   2   TEACHER\n\t\t\t\n";
   cout << "__________________________________________________________________________________\n";
   chhh = getch();
   system("CLS");
   switch (chhh)
   {

   student:
   case '1':
      cout << "\n\n\t\t 1- FOR SIGN UP\n\t\t 2- FOR SIGN IN\n\t\t \n\n";
      chhhh = getch();
      switch (chhhh)
      {
      case '1':
         s.sign_up();
         cout << "\n\n (3) FOR GOING MAIN MENU..\n\n\t\t\t";
         ch = getch();
         if (ch == '3')
         {
            system("CLS");
            goto label;
         }
         else
            //system("pause"):
            exit(0);
         break;

      case '2':
         s.show_profile();

         break;
      }

      break;

   case '2':
   teacher:
      t.signin_teacher();
      cout << "\n\n\t\t 1- ATTENDENCE SYSTEM \n\t\t 2-SEMESTER WORK ADDING \n\t\t 3-SEE SEMESTER WORK\n\t\t  4-show attendence\n\n";
      at = getch();
      switch (at)
      {
      case '1':
         t.taking_attendence();
         break;
      case '2':
         t.add_semester_work();
         t.cal_semester_work();
         break;
      case '3':
         t.cal_semester_work();
         break;
      case '4':
         t.show_attendence();
         break;
      }
      break;
   }

   system("pause");
   return 0;
}

void PASSWORD(string pin_code1 = "sagar")
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
         cout << "\n\t\t PRESS 1 TO CONTINUE AND 2 TO EXIT \n";
         c = getch();
         system("cls");
      }
      if (c == '2')
      {
         exit(0);
      }

   } while (c != '2' && e != 'x');
}
