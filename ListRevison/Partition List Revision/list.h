// a concrete linked list
// list is a pointer to a struct - containing the head ptr
 
typedef struct _node *link;    // a link points ot a node
 
typedef struct _node {
    int value;
    link next;
} node;
 
// a list is represented by a pointer to a struct which contains 
// a pointer to the first node of the list called the "head"
typedef struct _list {
    link head;
} *list; 
