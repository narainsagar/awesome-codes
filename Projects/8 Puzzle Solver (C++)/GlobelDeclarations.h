/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
#include <iostream>
#include <fstream>
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
const int MoveToPos[4][9] = // this tell for specific move from any index where to move (return index for move(i,e.. up,down,left))
	{
		{-1, -1, -1, 0, 1, 2, 3, 4, 5}, //DOWN
		{3, 4, 5, 6, 7, 8, -1, -1, -1}, //UP
		{1, 2, -1, 4, 5, -1, 7, 8, -1}, //LEFT
		{-1, 0, 1, -1, 3, 4, -1, 6, 7}	//RIGHT
};
/*
const int manhattan_moves_cost[9][9]=
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
	if (index < 0 || index > 8)
		flag = true;
	else if (index >= 0 && index <= 2 && move_list[act] == "up")
		flag = true;
	else if ((index == 0 || index == 3 || index == 6) && move_list[act] == "left")
		flag = true;
	else if ((index == 2 || index == 5 || index == 8) && move_list[act] == "right")
		flag = true;
	else if (index >= 6 && index <= 8 && move_list[act] == "down")
		flag = true;
	return flag;
}
int Find_Index(int arr[], int var)
{
	bool flag = false;
	int Index = -1;
	for (int i = 0; i < 9 && !flag; i++)
		if (arr[i] == var)
		{
			flag = true;
			Index = i;
		}
	return Index;
}
int Find_Variable(int arr[], int index)
{
	if (index < 9)
		return (arr[index]);
}
bool NotVisited(set<__int16> states_set, __int16 number)
{
	return (states_set.count(number) == 0);
}
__int16 Generate_Number(int node_state[9])
{
	__int16 number = 0;
	for (int i = 0; i < 9; i++)
	{
		number = (number * 10) + node_state[i];
	}
	return number;
}
/****************************************/
