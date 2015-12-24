/*
....................... ASSIGNMENT NO # 01 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
*/
class WordList{
      private:
             Node *head;
      public:
             WordList(){
                head = NULL;           
             }
             bool isEmpty(){
                return (head==NULL);     
             }
             Node* Get(string wrd){
                   if(!isEmpty()){
                       Node *curr=head,*ret=NULL;
                       bool found=false;
                       while(curr!=NULL && !found){
                             if(curr->word ==wrd){
                                  found=true;
                             }
                             else
                                 curr=curr->next;  
                       }  
                       if(found){
                           ret=curr;
                           ret->next=NULL;                                
                       } 
                       return ret;        
                   }
             }
             void InsertSorted(string wrd, int doc){
                 Node *newnode = new Node(wrd,doc);
                 if(isEmpty()){
                     head = newnode;              
                 }
                 else{
                     Node *curr = head,*prev=NULL;
                     bool found=false;
                     while(curr!=NULL && !found){
                           if(curr->word == wrd){ // found
                               found = true;          
                           }
                           else{
                               curr = curr->next;     
                           }            
                     } 
                     if(!found){
                         curr = head;
                         bool inserted=false;
                         while(curr!=NULL && !inserted){
                               if(wrd>=curr->word){
                                  prev = curr;
                                  curr = curr->next;                   
                               }
                               else
                                  inserted = true;  
                         }
                         if(inserted){
                             newnode->next = curr;
                             if(prev==NULL) // insert in begin
                                  head = newnode;
                             else  // in middle
                                  prev->next = newnode;          
                         }
                         else{
                             prev->next = newnode;
                         }           
                     }
                     else{
                         curr->inDocs[doc]=1;    
                     }    
                 }  
             }
};         
