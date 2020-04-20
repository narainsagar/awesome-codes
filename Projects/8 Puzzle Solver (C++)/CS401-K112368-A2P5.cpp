/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
#include "GlobelDeclarations.h"
#include "TreeNode.h"
#include "ClassStack.h"

class EightPuzzleTree
{
       TreeNode *Start, *Goal;

public:
       EightPuzzleTree()
       {
              Start = Goal = NULL;
       }
       void Steepest_Hill_Climbing()
       {
              ifstream read2;
              read2.open("A2P5in1.txt");
              if (read2)
              {
                     ofstream write;
                     write.open("A2P5out1.txt");
                     int init[9], final[9];
                     int count = 0;
                     std::set<__int16> Visited_States;
                     Stack Fringe;
                     int GoalCount = 0;
                     bool GoalFound = false;
                     TreeNode *traverse_node = NULL;

                     while (!read2.eof())
                     { // Reading from file..
                            for (int i = 0; i < 9; i++)
                                   read2 >> init[i];
                            for (int i = 0; i < 9; i++)
                                   read2 >> final[i];
                     } // reading file finish..

                     Goal = new TreeNode(final);
                     Start = new TreeNode(init, NULL);
                     Start->calculate_and_set_H(Goal);
                     Start->set_parameters("", Find_Index(init, 0), -1);
                     Fringe.Push(Start);
                     while (!Fringe.isEmpty() && !GoalFound)
                     {
                            TreeNode *parent = Fringe.Pop();
                            if (!parent->Goal_Test(Goal))
                            {
                                   if (NotVisited(Visited_States, Generate_Number(parent->NodeState)))
                                   {
                                          Stack Child_Fringe; // for choosing best neighbourhood from all possible children.
                                          Visited_States.insert(Generate_Number(parent->NodeState));
                                          int pos = Find_Index(parent->NodeState, 0);
                                          ++count;
                                          //   cout<<count<<"  Node  : "; parent->Print_NodeState();
                                          //  system("pause");
                                          if (IsPossible(pos, UP) && Move_Index(pos, UP) != -1 && !parent->IsBlank(Move_Index(pos, UP)) && !OutofBoundMove(pos, UP))
                                          {
                                                 TreeNode *child_up = new TreeNode(parent->NodeState, parent);
                                                 child_up->SwapNodeState_Variables(pos, Move_Index(pos, UP));
                                                 child_up->set_parameters("up", Find_Index(child_up->NodeState, 0), parent->NodeState[Move_Index(pos, UP)]);
                                                 child_up->calculate_and_set_H(Goal);
                                                 Child_Fringe.Push(child_up);
                                          }
                                          if (IsPossible(pos, DOWN) && Move_Index(pos, DOWN) != -1 && !parent->IsBlank(Move_Index(pos, DOWN)) && !OutofBoundMove(pos, DOWN))
                                          {
                                                 TreeNode *child_down = new TreeNode(parent->NodeState, parent);
                                                 child_down->SwapNodeState_Variables(pos, Move_Index(pos, DOWN));
                                                 child_down->set_parameters("down", Find_Index(child_down->NodeState, 0), parent->NodeState[Move_Index(pos, DOWN)]);
                                                 child_down->calculate_and_set_H(Goal);
                                                 Child_Fringe.Push(child_down);
                                          }
                                          if (IsPossible(pos, RIGHT) && Move_Index(pos, RIGHT) != -1 && !parent->IsBlank(Move_Index(pos, RIGHT)) && !OutofBoundMove(pos, RIGHT))
                                          {
                                                 TreeNode *child_right = new TreeNode(parent->NodeState, parent);
                                                 child_right->SwapNodeState_Variables(pos, Move_Index(pos, RIGHT));
                                                 child_right->set_parameters("right", Find_Index(child_right->NodeState, 0), parent->NodeState[Move_Index(pos, RIGHT)]);
                                                 child_right->calculate_and_set_H(Goal);
                                                 Child_Fringe.Push(child_right);
                                          }
                                          if (IsPossible(pos, LEFT) && Move_Index(pos, LEFT) != -1 && !parent->IsBlank(Move_Index(pos, LEFT)) && !OutofBoundMove(pos, LEFT))
                                          {
                                                 TreeNode *child_left = new TreeNode(parent->NodeState, parent);
                                                 child_left->SwapNodeState_Variables(pos, Move_Index(pos, LEFT));
                                                 child_left->set_parameters("left", Find_Index(child_left->NodeState, 0), parent->NodeState[Move_Index(pos, LEFT)]);
                                                 child_left->calculate_and_set_H(Goal);
                                                 Child_Fringe.Push(child_left);
                                          }
                                          if (!Child_Fringe.isEmpty())
                                          {
                                                 TreeNode *Best = NULL;
                                                 Best = Child_Fringe.Pop();
                                                 while (!Child_Fringe.isEmpty())
                                                 {
                                                        TreeNode *check = Child_Fringe.Pop();
                                                        if (check->H <= Best->H)
                                                        {
                                                               Best = check;
                                                        }
                                                 }
                                                 //   cout<<"best   = "<<Best->H <<"\n";
                                                 //   cout<<"parent = "<<parent->H <<"\n\n";
                                                 if (Best->H < parent->H)
                                                        Fringe.Push(Best); // insert the selected best node to fringe..
                                          }
                                   }
                                   //  else { cout<<"\nAlready a visited state: ";  parent->Print_NodeState(); }
                            }
                            else
                            {
                                   traverse_node = parent;
                                   GoalFound = true;
                            }
                     }
                     if (GoalFound)
                     {
                            //finding path..
                            //   cout<<"\nTotal # of Moves : "<<traverse_node->depth<<endl;
                            string path[traverse_node->depth + 1];
                            int values[traverse_node->depth + 1];
                            int t = 0, k = 0;
                            while (traverse_node->ParentNode)
                            {
                                   path[t] = traverse_node->move;
                                   values[t] = traverse_node->variable;
                                   t++;
                                   traverse_node = traverse_node->ParentNode;
                            }
                            for (int s = t - 1; s >= 0; s--)
                            {
                                   //   cout<<"\nMove # "<<++k<<":   ";
                                   //    cout<<values[s]<<"  "<<path[s]<<endl;
                                   write << values[s] << "  " << path[s] << endl;
                            }
                            cout << "Goal State Found..\n";
                            write << "Goal State Found..\n";
                     }
                     else
                     {
                            cout << "Goal State Not Found..\n";
                            write << "Goal State Not Found..\n";
                     }
                     write.close();
              }
              else
              {
                     cout << "\nFile does not exist.\n";
              }
              read2.close();
       }
};

int main()
{
       EightPuzzleTree *object = new EightPuzzleTree();
       object->Steepest_Hill_Climbing();
       system("pause");
       return 0;
}
