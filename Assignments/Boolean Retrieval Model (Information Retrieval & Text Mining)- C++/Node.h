/*
....................... ASSIGNMENT NO # 01 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
*/
class Node{
    public:
          string word;
          int inDocs[NO_OF_FILES];
          Node *next;
          Node(string w=""){
               word = w;
               next = NULL;
               for(int i=0;i<NO_OF_FILES;i++){
                   inDocs[i]=0;
               }  
          } 
          Node(string w,int inD, Node *p=NULL){
               word = w;
               next = p;
               for(int i=0;i<NO_OF_FILES;i++){
                   inDocs[i]=0;
                   if( inD==i )
                       inDocs[i]=1;
               }  
          } 
          Node(string w,int arr[]){
               word = w;
               next = NULL;
               for(int i=0;i<NO_OF_FILES;i++){
                   inDocs[i]=arr[i];
               }  
          }      
};
