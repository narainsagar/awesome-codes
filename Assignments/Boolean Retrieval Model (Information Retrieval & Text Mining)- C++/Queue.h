/*
....................... ASSIGNMENT NO # 01 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
*/
template<class ST>
class Queue
{
     ST contents[LIMIT];
     int head,tail;
 public:
     Queue();
     bool isFull();
     bool isEmpty();
     void Enqueue(ST x);    // Insert data...  
     ST Dequeue();          // delete/remove data...
};


/*****************************************/
template<class ST>
Queue<ST>::Queue()
{
    head=0;
    tail=0;        
}
/*****************************************/
template<class ST>
bool Queue<ST>::isFull()
{
    return (tail==LIMIT);         
}
/*****************************************/
template<class ST>
bool Queue<ST>::isEmpty()
{
    return (head==tail);
                 
}
/*****************************************/
template<class ST>
void Queue<ST>::Enqueue(ST x)
{
    if(!isFull())
    {
       contents[tail]=x;
       tail++;          
    }            
}
/*****************************************/
template<class ST>
ST Queue<ST>::Dequeue()
{
   if(!isEmpty())
   {
       ST x=contents[head];
       head++;
       return x;             
   }             
}
/*****************************************/
/*****************************************/

