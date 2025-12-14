#ifndef LIST_H
#define LIST_H

    #define TRUE 1
    #define FALSE 0

    typedef struct Node node_t;

    struct Node
    {
        node_t *pNodePrev;
        int data;
        node_t *pNodeNext;
    };

    typedef struct List list_t;
    
    struct List
    {
        node_t *head;
        int length;
    };

    node_t *createNode(void);
    list_t *createList(void);
    
    list_t *createRandomList(int);

    void insert(list_t *, int, int);
    
    void removeNode(list_t *, int);
    
    void displayList(list_t *);
    
    void freeList(list_t **);

#endif