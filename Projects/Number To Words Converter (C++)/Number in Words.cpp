#include <iostream>
#include <conio.h>
using namespace std;
string check(unsigned long long);
void line();
int main()
{ // system("color 0D");
    unsigned long long number;
    while (1)
    {
        system("cls");
        line();
        cout << "\t\t......:::: DECIMAL NUMBER INTO WORDS ::::......";
        line();
        cout << "\t\t>>>>> Number Range 0 Upto 9-DIGITS <<<<<";
        line();
        cout << "\n\tEnter  Number\t >>>  ";
        cin >> number;
        line();
        if (number == 0)
            cout << "\t\t\t Number  " << number << " In Words is \n\n\t ZERO";
        else if (number > 0 && number < 1000000000)
        {
            cout << "\t\t\t Number  " << number << " In Words is\n\n\t";
            cout << check(number);
        }
        else
            cout << "\t..... Wrong Number Entered...";
        line();
        cout << "\t\tPress ENTER KEY to Continue  \t ";
        getch();
    }
    line();
    system("pause");
    return 0;
} // ......END OF MAIN FUNCTION....
//..............................function definition start from here...............................
void line() { cout << "\n________________________________________________________________________________\n"; }
string check(unsigned long long n)
{
    if (n == 1)
        return "One ";
    else if (n == 2)
        return "Two ";
    else if (n == 3)
        return "Three ";
    else if (n == 4)
        return "Four ";
    else if (n == 5)
        return "Five ";
    else if (n == 6)
        return "Six ";
    else if (n == 7)
        return "Seven ";
    else if (n == 8)
        return "Eight ";
    else if (n == 9)
        return "Nine ";
    else if (n == 10)
        return "Ten ";
    else if (n == 11)
        return "Eleven ";
    else if (n == 12)
        return "Tweleve ";
    else if (n == 13)
        return "Thirteen ";
    else if (n == 14)
        return "Fourteen ";
    else if (n == 15)
        return "Fifteen ";
    else if (n == 16)
        return "Sixteen ";
    else if (n == 17)
        return "Seventeen ";
    else if (n == 18)
        return "Eighteen ";
    else if (n == 19)
        return "Nineteen ";
    else if (n >= 20 && n < 30)
        return "Twenty " + check(n % 10);
    else if (n >= 30 && n < 40)
        return "Thirty " + check(n % 10);
    else if (n >= 40 && n < 50)
        return "Fourty " + check(n % 10);
    else if (n >= 50 && n < 60)
        return "Fifty " + check(n % 10);
    else if (n >= 60 && n < 70)
        return "Sixty " + check(n % 10);
    else if (n >= 70 && n < 80)
        return "Seventy " + check(n % 10);
    else if (n >= 80 && n < 90)
        return "Eighty " + check(n % 10);
    else if (n >= 90 && n < 100)
        return "Ninety " + check(n % 10);
    else if (n >= 100 && n < 1000)
        return check(n / 100) + "Hundred(s) And " + check(n % 100);
    else if (n >= 1000 && n < 100000)
        return check(n / 1000) + "Thousand(s) " + check(n % 1000);
    else if (n >= 100000 && n < 10000000)
        return check(n / 100000) + "Lac(s) " + check(n % 100000);
    else if (n >= 10000000 && n < 1000000000)
        return check(n / 10000000) + "Crore(s) " + check(n % 10000000);
    /*  else if(n>=1000000000 && n<100000000000)     return check(n/1000000000)+"Arab "+check(n%1000000000);
    else if(n>=100000000000 && n<10000000000000)      return check(n/100000000000)+"Kharab "+check(n%100000000000);
    else if(n>=10000000000000 && n<1000000000000000)    return check(n/10000000000000)+"Padum "+check(n%10000000000000);  */
    else
        return " ";
}
