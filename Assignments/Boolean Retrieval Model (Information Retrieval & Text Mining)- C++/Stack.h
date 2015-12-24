/*
....................... ASSIGNMENT NO # 01 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
*/
template<class ST>
class Stack
{
    ST contents[LIMIT];
    int StackTop;
public:
    Stack();
    bool isFull();
    bool isEmpty();
    void Push(ST x);
    ST Pop();     
};

/*****************************************/
template<class ST>
Stack<ST>::Stack()
{
    StackTop=0;       
} 
/*****************************************/
template<class ST>
bool Stack<ST>::isFull()
{
    return (StackTop==LIMIT);     
}
/*****************************************/
template<class ST>
bool Stack<ST>::isEmpty()
{
   return (StackTop==0);     
}
/*****************************************/
template<class ST>
void Stack<ST>::Push(ST x)
{
    if(!isFull())
    {
      contents[StackTop]=x;
      StackTop++;             
    }     
}
/*****************************************/
template<class ST>
ST Stack<ST>::Pop()
{
    if(!isEmpty())
    {
        StackTop--;
        return contents[StackTop];            
    }     
}
/*****************************************/

