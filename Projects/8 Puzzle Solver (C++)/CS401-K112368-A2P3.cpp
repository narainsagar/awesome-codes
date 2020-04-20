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

       void Greedy_Best_First_Search()
       {
              ifstream read2;
              read2.open("A2P3in1.txt");
              if (read2)
              {
                     ofstream write;
                     write.open("A2P3out1.txt");
                     int init[9], final[9];
                     int count = 0;
                     std::set<__int16> Visited_States; // close_set
                     Stack Fringe;
                     int GoalCount = -1;
                     bool GoalFound = false;
                     TreeNode *backTrack = NULL;

                     while (!read2.eof())
                     { // Reading from file..
                            for (int i = 0; i < 9; i++)
                                   read2 >> init[i];
                            for (int i = 0; i < 9; i++)
                                   read2 >> final[i];
                     } // reading file finish..

                     Goal = new TreeNode(final, NULL);
                     Start = new TreeNode(init, NULL);
                     Start->calculate_and_set_H(Goal);
                     Goal->calculate_and_set_H(Goal);
                     Start->set_parameters("", Find_Index(init, 0), -1);
                     Fringe.Push(Start);

                     while (!Fringe.isEmpty() && !GoalFound)
                     {
                            Fringe.Sort(Fringe); // sort-it for priority approach..
                                                 //  Fringe.Print();
                                                 //  system("pause");
                            TreeNode *parent = Fringe.Pop();
                            if (!parent->Goal_Test(Goal))
                            {
                                   if (NotVisited(Visited_States, Generate_Number(parent->NodeState)))
                                   {
                                          Visited_States.insert(Generate_Number(parent->NodeState));
                                          int pos = Find_Index(parent->NodeState, 0);
                                          ++count;
                                          //      cout<<count<<"  Node  : "<<parent->H<<" :: "; parent->Print_NodeState();
                                          //  system("pause");
                                          if (IsPossible(pos, UP) && Move_Index(pos, UP) != -1 && !parent->IsBlank(Move_Index(pos, UP)) && !OutofBoundMove(pos, UP))
                                          {
                                                 TreeNode *child_up = new TreeNode(parent->NodeState, parent);
                                                 child_up->SwapNodeState_Variables(pos, Move_Index(pos, UP));
                                                 child_up->set_parameters("up", Find_Index(child_up->NodeState, 0), parent->NodeState[Move_Index(pos, UP)]);
                                                 child_up->calculate_and_set_H(Goal);
                                                 Fringe.Push(child_up);
                                          }
                                          if (IsPossible(pos, DOWN) && Move_Index(pos, DOWN) != -1 && !parent->IsBlank(Move_Index(pos, DOWN)) && !OutofBoundMove(pos, DOWN))
                                          {
                                                 TreeNode *child_down = new TreeNode(parent->NodeState, parent);
                                                 child_down->SwapNodeState_Variables(pos, Move_Index(pos, DOWN));
                                                 child_down->set_parameters("down", Find_Index(child_down->NodeState, 0), parent->NodeState[Move_Index(pos, DOWN)]);
                                                 child_down->calculate_and_set_H(Goal);
                                                 Fringe.Push(child_down);
                                          }
                                          if (IsPossible(pos, RIGHT) && Move_Index(pos, RIGHT) != -1 && !parent->IsBlank(Move_Index(pos, RIGHT)) && !OutofBoundMove(pos, RIGHT))
                                          {
                                                 TreeNode *child_right = new TreeNode(parent->NodeState, parent);
                                                 child_right->SwapNodeState_Variables(pos, Move_Index(pos, RIGHT));
                                                 child_right->set_parameters("right", Find_Index(child_right->NodeState, 0), parent->NodeState[Move_Index(pos, RIGHT)]);
                                                 child_right->calculate_and_set_H(Goal);
                                                 Fringe.Push(child_right);
                                          }
                                          if (IsPossible(pos, LEFT) && Move_Index(pos, LEFT) != -1 && !parent->IsBlank(Move_Index(pos, LEFT)) && !OutofBoundMove(pos, LEFT))
                                          {
                                                 TreeNode *child_left = new TreeNode(parent->NodeState, parent);
                                                 child_left->SwapNodeState_Variables(pos, Move_Index(pos, LEFT));
                                                 child_left->set_parameters("left", Find_Index(child_left->NodeState, 0), parent->NodeState[Move_Index(pos, LEFT)]);
                                                 child_left->calculate_and_set_H(Goal);
                                                 Fringe.Push(child_left);
                                          }
                                   }
                                   //  else { cout<<"\nAlready a visited state: ";  parent->Print_NodeState(); }
                            }
                            else
                            {
                                   GoalCount++;
                                   backTrack = parent;
                                   GoalFound = true;
                            }
                     }
                     if (GoalFound)
                     {
                            //finding path..
                            //     cout<<"\nTotal # of Moves : "<<backTrack->depth<<endl;
                            string path[backTrack->depth + 1];
                            int values[backTrack->depth + 1];
                            int t = 0, k = 0;
                            while (backTrack->ParentNode)
                            {
                                   path[t] = backTrack->move;
                                   values[t] = backTrack->variable;
                                   t++;
                                   backTrack = backTrack->ParentNode;
                            }
                            for (int s = t - 1; s >= 0; s--)
                            {
                                   //       cout<<"\nMove # "<<++k<<":   ";
                                   //       cout<<values[s]<<"  "<<path[s]<<endl;
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
       object->Greedy_Best_First_Search();
       system("pause");
       return 0;
}
