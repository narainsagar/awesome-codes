/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
#include "GlobelDeclarations.h"
#include "TreeNode.h"
#include "ClassQueue.h"

class EightPuzzleTree
{
     TreeNode *Initial, *Goal;

public:
     EightPuzzleTree()
     {
          Initial = Goal = NULL;
     }
     void Uninformed_BFS()
     {
          ifstream read;
          read.open("A2P1in1.txt");
          if (!read)
          {
               cout << "\nFile doesn't exist.\n";
          }
          else
          {
               ofstream write;
               write.open("A2P1out1.txt");
               int init[9], final[9];
               bool GoalFound = false;
               std::set<__int16> Visited_States; // close_set
               Queue Fringe;
               TreeNode *backTrack; // node for back-tracking path
               int count = 0;

               while (!read.eof())
               { // Reading from file..
                    for (int i = 0; i < 9; i++)
                         read >> init[i];
                    for (int i = 0; i < 9; i++)
                         read >> final[i];
               } // reading file finish..

               Initial = new TreeNode(init, NULL);
               Initial->set_parameters("", Find_Index(init, 0), -1);
               Goal = new TreeNode(final);
               Fringe.Enqueue(Initial);

               while (!Fringe.isEmpty() && !GoalFound)
               {
                    TreeNode *parent;
                    parent = Fringe.Dequeue();
                    if (!parent->Goal_Test(Goal))
                    {
                         if (NotVisited(Visited_States, Generate_Number(parent->NodeState)))
                         {
                              Visited_States.insert(Generate_Number(parent->NodeState));
                              int pos = Find_Index(parent->NodeState, 0);
                              ++count;
                              //    cout<<count<<" : "; parent->Print_NodeState();
                              //  system("pause");
                              if (IsPossible(pos, UP) && Move_Index(pos, UP) != -1 && !parent->IsBlank(Move_Index(pos, UP)) && !OutofBoundMove(pos, UP))
                              {
                                   TreeNode *child_up = new TreeNode(parent->NodeState, parent);
                                   child_up->SwapNodeState_Variables(pos, Move_Index(pos, UP));
                                   child_up->set_parameters("up", Find_Index(child_up->NodeState, 0), parent->NodeState[Move_Index(pos, UP)]);
                                   if (NotVisited(Visited_States, Generate_Number(child_up->NodeState)))
                                        Fringe.Enqueue(child_up);
                                   else
                                        delete child_up;
                              }
                              if (IsPossible(pos, DOWN) && Move_Index(pos, DOWN) != -1 && !parent->IsBlank(Move_Index(pos, DOWN)) && !OutofBoundMove(pos, DOWN))
                              {
                                   TreeNode *child_down = new TreeNode(parent->NodeState, parent);
                                   child_down->SwapNodeState_Variables(pos, Move_Index(pos, DOWN));
                                   child_down->set_parameters("down", Find_Index(child_down->NodeState, 0), parent->NodeState[Move_Index(pos, DOWN)]);
                                   if (NotVisited(Visited_States, Generate_Number(child_down->NodeState)))
                                        Fringe.Enqueue(child_down);
                                   else
                                        delete child_down;
                              }
                              if (IsPossible(pos, RIGHT) && Move_Index(pos, RIGHT) != -1 && !parent->IsBlank(Move_Index(pos, RIGHT)) && !OutofBoundMove(pos, RIGHT))
                              {
                                   TreeNode *child_right = new TreeNode(parent->NodeState, parent);
                                   child_right->SwapNodeState_Variables(pos, Move_Index(pos, RIGHT));
                                   child_right->set_parameters("right", Find_Index(child_right->NodeState, 0), parent->NodeState[Move_Index(pos, RIGHT)]);
                                   if (NotVisited(Visited_States, Generate_Number(child_right->NodeState)))
                                        Fringe.Enqueue(child_right);
                                   else
                                        delete child_right;
                              }
                              if (IsPossible(pos, LEFT) && Move_Index(pos, LEFT) != -1 && !parent->IsBlank(Move_Index(pos, LEFT)) && !OutofBoundMove(pos, LEFT))
                              {
                                   TreeNode *child_left = new TreeNode(parent->NodeState, parent);
                                   child_left->SwapNodeState_Variables(pos, Move_Index(pos, LEFT));
                                   child_left->set_parameters("left", Find_Index(child_left->NodeState, 0), parent->NodeState[Move_Index(pos, LEFT)]);
                                   if (NotVisited(Visited_States, Generate_Number(child_left->NodeState)))
                                        Fringe.Enqueue(child_left);
                                   else
                                        delete child_left;
                              }
                         }
                    }
                    else
                    {
                         //   cout<<"Goal State Found..\n";
                         backTrack = parent;
                         GoalFound = true;
                    }
               }

               if (GoalFound)
               {
                    //finding path..
                    string path[backTrack->depth + 1];
                    int values[backTrack->depth + 1];
                    int t = 0, k = 0;
                    //	 cout<<"\nTotal # of Moves : "<<backTrack->depth<<endl;
                    while (backTrack->ParentNode)
                    {
                         path[t] = backTrack->move;
                         values[t] = backTrack->variable;
                         t++;
                         backTrack = backTrack->ParentNode;
                    }
                    for (int s = t - 1; s >= 0; s--)
                    {
                         //		cout<<"\nMove # "<<++k<<":   ";
                         //       cout<<values[s]<<"  "<<path[s]<<endl;
                         write << values[s] << "  " << path[s] << endl;
                    }
                    cout << "Goal State Found..\n";
                    write << "Goal State Found..\n";
               }
               else
               {
                    // if(Fringe.isEmpty())
                    cout << "Goal State Not Found..\n";
                    write << "Goal State Not Found..\n";
               }
               write.close();
          }
          read.close();
     }
};

int main()
{
     EightPuzzleTree *object = new EightPuzzleTree();
     object->Uninformed_BFS();
     system("pause");
     return 0;
}
