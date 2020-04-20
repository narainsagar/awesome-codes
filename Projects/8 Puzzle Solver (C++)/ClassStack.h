/*  
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/
#include "LinkNode.h"
class Stack
{
  LinkNode *head, *tail;

public:
  Stack()
  {
    head = tail = NULL;
  }
  bool isEmpty()
  {
    return ((head == NULL) && (tail == NULL));
  }
  int Size()
  {
    int c = 0;
    if (!isEmpty())
    {
      LinkNode *node = head;
      while (node != tail->Next())
      {
        node = node->Next();
        c++;
      }
    }
    return c;
  }
  void Push(TreeNode *x)
  {
    LinkNode *node = new LinkNode(x);
    if (isEmpty())
    {
      head = node;
      tail = node;
    }
    else
    {
      node->Link(head);
      head = node;
    }
  }
  TreeNode *Pop()
  {
    TreeNode *x = NULL;
    if (!isEmpty())
    {
      LinkNode *node;
      if (head == tail)
      {
        node = head;
        x = node->GetKeyNode();
        head = tail = NULL;
      }
      else
      {
        node = head;
        x = node->GetKeyNode();
        head = head->Next();
      }
      delete node;
    }
    return x;
  }
  void Sort(Stack &fringe)
  {
    TreeNode *node_array[fringe.Size()];
    int m = 0, i = 0;
    while (!fringe.isEmpty())
    {
      node_array[i] = fringe.Pop();
      i++;
    }
    for (int j = 0; j < i; j++)
    {
      for (int k = 0; k < i - 1; k++)
      {
        if (node_array[k]->Get_Heuristic() > node_array[k + 1]->Get_Heuristic())
        {
          TreeNode *temp = node_array[k];
          node_array[k] = node_array[k + 1];
          node_array[k + 1] = temp;
        }
      }
    }
    m = i - 1;
    while (m > -1)
    {
      fringe.Push(node_array[m]);
      m--;
    }
    return;
  }
  void Print()
  {
    if (!isEmpty())
    {
      LinkNode *node = head;
      TreeNode *curr;
      while (node != tail->Next())
      {
        cout << node->GetKeyNode()->H << " ,";
        //   node->GetKeyNode()->Print_NodeState();
        node = node->Next();
      }
      cout << endl;
    }
    else
      cout << "\nStack is Empty.\n";
  }
};
