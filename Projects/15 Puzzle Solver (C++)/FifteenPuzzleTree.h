/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/

class FifteenPuzzleTree
{
   TreeNode *Start, *Goal;

public:
   FifteenPuzzleTree()
   {
      Start = Goal = NULL;
   }
   void Informed_A_Star_Search()
   {
      ifstream read2;
      char *inputFileName = new char[50];
      cout << "Enter FileName (i.e '*.txt'): ";
      cin >> inputFileName;
      read2.open(inputFileName);
      if (read2)
      {
         //   ofstream write;
         //  write.open(inputFileName);
         int init[16], final[16];
         int count = 0;
         std::set<__int32> Visited_States;
         Stack Fringe;
         int GoalCount = -1;
         bool GoalFound = false;
         TreeNode *backTrack = NULL;

         while (!read2.eof())
         { // Reading from file..
            for (int i = 0; i < 16; i++)
               read2 >> init[i];
            for (int i = 0; i < 16; i++)
               read2 >> final[i];
         } // reading file finish..

         Goal = new TreeNode(final, NULL);
         Start = new TreeNode(init, NULL);
         //  Start->Calculate_and_Set_Astar_Heuristic(Goal);
         //  Goal->Calculate_and_Set_Astar_Heuristic(Goal);
         Start->Calculate_and_Set_Astar_Heuristic(Start->depth, Goal);
         Goal->Calculate_and_Set_Astar_Heuristic(Goal->depth, Goal);
         Start->set_parameters("", Find_Index(init, 0), -1);
         Fringe.Push(Start);
         while (!Fringe.isEmpty() && !GoalFound)
         {
            Fringe.Sort(Fringe); // sort-it for priority approach..
                                 //   Fringe.Print();
                                 //   system("pause");
            TreeNode *parent = Fringe.Pop();
            if (!parent->Goal_Test(Goal))
            {
               if (NotVisited(Visited_States, Generate_Number(parent->NodeState)))
               {
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
                     child_up->Calculate_and_Set_Astar_Heuristic(child_up->depth, Goal);
                     Fringe.Push(child_up);
                  }
                  if (IsPossible(pos, DOWN) && Move_Index(pos, DOWN) != -1 && !parent->IsBlank(Move_Index(pos, DOWN)) && !OutofBoundMove(pos, DOWN))
                  {
                     TreeNode *child_down = new TreeNode(parent->NodeState, parent);
                     child_down->SwapNodeState_Variables(pos, Move_Index(pos, DOWN));
                     child_down->set_parameters("down", Find_Index(child_down->NodeState, 0), parent->NodeState[Move_Index(pos, DOWN)]);
                     child_down->Calculate_and_Set_Astar_Heuristic(child_down->depth, Goal);
                     Fringe.Push(child_down);
                  }
                  if (IsPossible(pos, RIGHT) && Move_Index(pos, RIGHT) != -1 && !parent->IsBlank(Move_Index(pos, RIGHT)) && !OutofBoundMove(pos, RIGHT))
                  {
                     TreeNode *child_right = new TreeNode(parent->NodeState, parent);
                     child_right->SwapNodeState_Variables(pos, Move_Index(pos, RIGHT));
                     child_right->set_parameters("right", Find_Index(child_right->NodeState, 0), parent->NodeState[Move_Index(pos, RIGHT)]);
                     child_right->Calculate_and_Set_Astar_Heuristic(child_right->depth, Goal);
                     Fringe.Push(child_right);
                  }
                  if (IsPossible(pos, LEFT) && Move_Index(pos, LEFT) != -1 && !parent->IsBlank(Move_Index(pos, LEFT)) && !OutofBoundMove(pos, LEFT))
                  {
                     TreeNode *child_left = new TreeNode(parent->NodeState, parent);
                     child_left->SwapNodeState_Variables(pos, Move_Index(pos, LEFT));
                     child_left->set_parameters("left", Find_Index(child_left->NodeState, 0), parent->NodeState[Move_Index(pos, LEFT)]);
                     child_left->Calculate_and_Set_Astar_Heuristic(child_left->depth, Goal);
                     Fringe.Push(child_left);
                  }
               }
               //  else { cout<<"\nAlready a visited state: ";  parent->Print_NodeState(); }
            }
            else
            {
               GoalCount++;
               //    cout<<"Goal\n";
               backTrack = parent;
               GoalFound = true;
            }
         }
         if (GoalFound)
         {
            //finding path..
            line();
            cout << "\nTotal # of Moves : " << backTrack->depth << endl;
            line();
            cout << endl;
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
               cout << "\nMove # " << ++k << ":   ";
               cout << values[s] << "  " << path[s] << endl;
               //   write<<values[s]<<"  "<<path[s]<<endl;
            }
            line();
            cout << "\nPuzzle Solved: Goal State Found..\n";
            //  write<<"Goal State Found..\n";
         }
         else
         {
            line();
            cout << "\nPuzzle UnSolvable: Goal State Not Found..\n";
            //  write<<"Goal State Not Found..\n";
         }
         //   write.close();
      }
      else
      {
         line();
         cout << "\nFile does not exist.\n";
      }
      read2.close();
      line();
   }
};
