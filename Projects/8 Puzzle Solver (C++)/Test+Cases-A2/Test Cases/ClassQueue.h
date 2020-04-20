/*  
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
#include "LinkNode.h"
class Queue
{
    LinkNode *head,*tail;
  public:
      Queue(){
         head=tail=NULL;
	  }
      bool isEmpty(){
	     return ((head==NULL)&&(tail==NULL)); 
	  }
      int Size(){
         int c=0;
         if(!isEmpty())
         {
           LinkNode *node=head; 
           while(node!=tail->Next())
           {
            node=node->Next();
            c++;                 
           }     
         }
         return c;
	  }
      void Enqueue(TreeNode* x){
		   LinkNode *node=new LinkNode(x);
		   if(isEmpty())
		   {  
			 head=node;
			 tail=node;
		   }
		   else
		   {
			 LinkNode *curr;
             curr=tail;  
			 curr->Link(node);
			 tail=node;
		   } 
	  }
      TreeNode* Dequeue(){
		  TreeNode* x=NULL;
		  if(!isEmpty())
		  {
			LinkNode *node;
            if(head==tail)
			{
			  node=head;
			  x=node->GetKeyNode();
			  head=tail=NULL;              
			} 
			else
			{ 
			 node=head;
			 x=node->GetKeyNode();
			 head=head->Next();  
			}        
			delete node;
		  }
		  return x;             
      }
};
