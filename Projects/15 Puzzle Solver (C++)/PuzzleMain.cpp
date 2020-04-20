#include "GlobelDeclarations.h"
#include "TreeNode.h"
#include "ClassStack.h"
#include "FifteenPuzzleTree.h"

int main()
{
back:
    system("cls");
    char key;
    PuzzleDevelopedBy();
    cout << "\tCopyrights: 2015 - Dharam Solutions, All rights reserved.\n";
    cout << "\n\t** Note: Please read the 'readme.txt' file before to use. **\n";
    line();
    cout << "\n PRESS ENTER KEY TO CONTINUE  ";
    key = getch();
    if (key == '\r')
    {
        system("cls");
        PuzzleDevelopedBy();
        FifteenPuzzleTree *object = new FifteenPuzzleTree();
        object->Informed_A_Star_Search();
    }
    else
    {
        line();
        cout << "\n\t\t\t\tWrong Input...!\n";
        system("pause");
        goto back;
    }
    system("pause");
    return 0;
}
