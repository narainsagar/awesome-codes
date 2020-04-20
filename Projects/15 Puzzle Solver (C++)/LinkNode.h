/*   
     .........  Assignment # 02.........
     Name.........: Narain-Sagar
     ID...........: K11-2368
     SECTION......: C
*/

class LinkNode
{
     TreeNode *key_node;
     LinkNode *next;

public:
     LinkNode(TreeNode *k_n)
     {
          key_node = k_n;
          next = NULL;
     }
     TreeNode *GetKeyNode()
     {
          return (key_node);
     }
     LinkNode *Next()
     {
          return (next);
     }
     void Link(LinkNode *link)
     {
          next = link;
     }
};
