/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
class TreeNode{
   public:
      int NodeState[9];
      int F;   // Heuristic Hamming priority function value.. i,e.. (F= G+H)
      int G;   // G= Manhattan distance cost = sum of number of moves of all tiles made so to get to the reach goal node..
      int H;   // H=number of tiles that are not in the correct place
      int LoB; // Location of Blank Tile..
      int depth;
      string move; // what move performed on it..
      int variable; // on which value move has performed.. 
      TreeNode *ParentNode;
    
           TreeNode(){
              depth=0;
              move="";
              H=G=0;
              F=G+H;
              variable=LoB=-1;
              ParentNode=NULL;        
           }
           TreeNode(int brd[], TreeNode *p=NULL){
              for(int i=0;i<9;i++){
                  NodeState[i]=brd[i];
                  if(NodeState[i]==0){
                     LoB=i;                    
                  }      
              }
              H=G=0;
              F=G+H;
              ParentNode=p; 
              if (ParentNode == NULL)
                  depth = 0; 
              else
                  depth = ParentNode->depth + 1;        
           } 
           TreeNode(int brd[], TreeNode *p=NULL, TreeNode *goal){
              for(int i=0;i<9;i++){
                  NodeState[i]=brd[i];
                  if(NodeState[i]==0){
                     LoB=i;                    
                  }      
              }
              int misplaced=0;
              for(int i=0;i<9;i++){
                    if(NodeState[i]!=0){
                         if(NodeState[i]!=goal->NodeState[i]){
                              misplaced++;                    
                         }               
                    }      
                }
              H=misplaced;
              G=0;
              F=G+H;
              ParentNode=p; 
              if (ParentNode == NULL)
                   depth = 0; 
              else
                   depth = ParentNode->depth + 1;        
           }
      /*    void set_H_Negative(TreeNode *goal){
                int misplaced=0;
                for(int i=0;i<9;i++){
                    if(NodeState[i]!=0){
                         if(NodeState[i]!=goal->NodeState[i]){
                              misplaced++;                    
                         }               
                    }      
                }
                H=misplaced*-1;
           }  */
           void calculate_and_set_H(TreeNode *goal){
                int misplaced=0;
                for(int i=0;i<9;i++){
                    if(NodeState[i]!=0){
                         if(NodeState[i]!=goal->NodeState[i]){
                              misplaced++;                    
                         }               
                    }      
                }
                G=0;
                H=misplaced;
                F=H;
           }
        /*   void set_G(TreeNode *goal){   // manhattan distance..
                int sum=0;  // sum of all tiles possible moves that reaches to goal..
                for(int i=0;i<9;i++){
                    if(NodeState[i]!=0){
                         int node_var = NodeState[i];
                         int goal_index= Find_Index(goal->NodeState,node_var);
                         sum+= manhattan_moves_cost[i][goal_index];               
                    }      
                }
                G=sum;  
           }
           void set_F(){
                F=G+H; 
           }
           void Calculate_and_Set_Astar_Heuristic(TreeNode *goal){
                set_H(goal);
                set_G(goal);
                set_F();
           } */
           void Calculate_and_Set_Astar_Heuristic(int d,TreeNode *goal){
                calculate_and_set_H(goal);  // misplaced tiles..
                G=d;
                F=G+H;       // F=misplaced + moves done so for = (F = H+depth);
           }
           void set_parameters(string mov,int lob,int var){
                move=mov;
                LoB=lob;
                variable=var;
           }
           int Get_Heuristic(){
               return F;    
           }
           // extra functions..
           void SwapNodeState_Variables(int x, int y){
                int var=NodeState[x];
                NodeState[x]=NodeState[y];
                NodeState[y]=var; 
           }
           void Print_NodeState(){
               for(int i=0;i<9;i++){
                   cout<<NodeState[i]<<", ";    
               }
               cout<<endl; 
           } 
           bool Goal_Test(TreeNode *G){
               bool same=true;
               for(int i=0;i<9;i++)
                   if(this->NodeState[i]!=G->NodeState[i])
                       same=false;       
               return same;   
           }
           bool IsBlank(int x){
                return (NodeState[x]==0);
          }
};
