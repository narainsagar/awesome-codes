#include<iostream>
/*****************************************/
Stack::Stack()
{
    StackTop=0;       
} 
/*****************************************/
int Stack::StackTopValue()
{
   return StackTop;                
}
/*****************************************/
bool Stack::isFull()
{
    if(StackTop==LIMIT)
         return true;
    else
         return false;     
}
/*****************************************/
bool Stack::isEmpty()
{
   if(StackTop==0)
      return true;
   else
      return false;     
}
/*****************************************/
void Stack::Push(char x)
{
    if(!isFull())
    {
      contents[StackTop]=x;
      StackTop++;             
    }     
}
/*****************************************/
char Stack::Pop()
{
    if(!isEmpty())
    {
        StackTop--; 
        return contents[StackTop];            
    }     
}
/*****************************************/
