/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <set>
using namespace std;
/****************************************/
// VARIABLES GLOBEL DECLARATION
/****************************************/
enum ActionType
{
    DOWN,
    UP,
    LEFT,
    RIGHT
};
const string move_list[4] = {"up", "down", "right", "left"};
const int MoveToPos[4][16] = // this tell for specific move from any index where to move (return index for move(i,e.. up,down,left))
    {
        {-1, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},     //DOWN - up
        {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1}, //UP  - down
        {1, 2, 3, -1, 5, 6, 7, -1, 9, 10, 11, -1, 13, 14, 15, -1},  //LEFT  - right
        {-1, 0, 1, 2, -1, 4, 5, 6, -1, 8, 9, 10, -1, 12, 13, 14}    //RIGHT - left
};
/*
const int manhattan_moves_cost[16][16]=
{
     {0,1,2,1,2,3,2,3,4}, //0
     {1,0,1,2,1,2,3,2,3}, //1
     {2,1,0,3,2,1,4,3,2}, //2
     {1,2,3,0,1,2,1,2,3},  //3
     {2,1,2,1,0,1,2,1,2},  //4
     {3,2,1,2,1,0,3,2,1},  //5
     {2,3,4,1,2,3,0,1,2},  //6
     {3,2,3,2,1,2,1,0,1},  //7
     {4,3,2,3,2,1,2,1,0}   //8
};
*/
/****************************************/
/****************************************/
// FUNCTIONS GLOBEL DECLARATION& DEFINITIONS
/****************************************/
bool IsPossible(int indx, ActionType move)
{
    return (MoveToPos[move][indx] != -1);
}
int Move_Index(int pos, ActionType move)
{
    return (MoveToPos[move][pos]);
}
bool OutofBoundMove(int index, ActionType act)
{
    bool flag = false;
    if (index < 0 || index > 15)
        flag = true;
    else if (index >= 0 && index <= 3 && move_list[act] == "up")
        flag = true;
    else if ((index == 0 || index == 4 || index == 8 || index == 12) && move_list[act] == "left")
        flag = true;
    else if ((index == 3 || index == 7 || index == 11 || index == 15) && move_list[act] == "right")
        flag = true;
    else if (index >= 12 && index <= 15 && move_list[act] == "down")
        flag = true;
    return flag;
}
int Find_Index(int arr[], int var)
{
    bool flag = false;
    int Index = -1;
    for (int i = 0; i < 16 && !flag; i++)
        if (arr[i] == var)
        {
            flag = true;
            Index = i;
        }
    return Index;
}
int Find_Variable(int arr[], int index)
{
    if (index < 16)
        return (arr[index]);
}
bool NotVisited(set<__int32> states_set, __int32 number)
{
    return (states_set.count(number) == 0);
}
__int32 Generate_Number(int node_state[16])
{
    __int32 number = 0;
    for (int i = 0; i < 16; i++)
    {
        number = (number * 10) + node_state[i];
    }
    return number;
}
void line()
{
    cout << "\n--------------------------------------------------------------------------------\n";
}
void PuzzleDevelopedBy()
{
    line();
    cout << "\t\t\t ****** 15 PUZZLE ******\n";
    cout << "\n\t\t   ...:: DEVELOPED BY NARAIN SAGAR ::...\n";
    line();
}
/****************************************/
