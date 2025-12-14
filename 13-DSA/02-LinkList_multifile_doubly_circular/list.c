#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *createList(void)
{
    list_t *pList = NULL;

    pList = (list_t *)malloc(sizeof(list_t));

    pList->head   = NULL;
    pList->length = 0;

    return(pList);
}

node_t *createNode(void)
{
    node_t *pNode = NULL;

    pNode = (node_t *)malloc(sizeof(node_t));

    pNode->pNodePrev = NULL;
    pNode->data      = 0;
    pNode->pNodeNext = NULL;
}

list_t *createRandomList(int listSize)
{
    list_t *pList = createList();

    for(int i = 0; i < listSize; i++)
    {
        insert(pList, pList->length + 1, rand() % 100);
    }

    return(pList);
}

void insert(list_t *pList, int position, int element)
{
    if(pList == NULL)
    {
        printf("Give valid list_t * !!!\n\n");
        return;
    }

    if(position <= 0)
    {
        if(pList->head == NULL)
        {
            // insert first when head is null
            pList->head = createNode();
            
            pList->head->data      = element;
            pList->head->pNodeNext = pList->head;
            pList->head->pNodePrev = pList->head;
        }
        else
        {
            // insert first when head is not null
            node_t *pNode = createNode();

            pNode->data = element;

            pNode->pNodeNext                  = pList->head;
            pNode->pNodePrev                  = pList->head->pNodePrev;
            pList->head->pNodePrev->pNodeNext = pNode;
            pList->head->pNodePrev            = pNode;

            pList->head = pNode; // setting new head
        }

        pList->length = pList->length + 1;
    }
    else if(position < pList->length)
    {
        // insert middle node
        node_t *pTemp = NULL;
        int i = 0;

        node_t *pNode = createNode();

        pNode->data = element;

        for(pTemp = pList->head,i = 1; i <= position; pTemp = pTemp->pNodeNext, i++);

        pNode->pNodeNext            = pTemp;
        pNode->pNodePrev            = pTemp->pNodePrev;
        pTemp->pNodePrev->pNodeNext = pNode;
        pTemp->pNodePrev            = pNode; 

        pList->length = pList->length + 1;
    }
    else if(position >= pList->length)
    {
        // insert end
         if(pList->head == NULL)
        {
            // insert end when head is null
            pList->head = createNode();
            
            pList->head->data      = element;
            pList->head->pNodeNext = pList->head;
            pList->head->pNodePrev = pList->head;
        }
        else
        {
            // insert end when head is not null
            node_t *pNode = createNode();

            node_t *pEnd = pList->head->pNodePrev;


            pNode->data = element;

            pNode->pNodePrev           = pEnd;
            pNode->pNodeNext           = pEnd->pNodeNext;
            pEnd->pNodeNext->pNodePrev = pNode;
            pEnd->pNodeNext            = pNode;
        }
        pList->length = pList->length + 1;
    }
    else
    {
        printf("please give valid position !!!\n\n");
    }
}

void removeNode(list_t *pList, int position)
{
    if(pList == NULL || pList->head == NULL)
    {
        printf("List Is Empty !!!\n\n");
        return;
    }

    if(position <= 0)
    {
        // delete first 
        if(pList->head->pNodeNext == pList->head || pList->head->pNodePrev == pList->head)
        {
            // if there is only one node
            pList->head->pNodePrev = NULL;
            pList->head->pNodeNext = NULL;
            pList->head->data = 0;

            free(pList->head);
            pList->head = NULL;
        }
        else
        {
            // if there are multiple nodes
            node_t *pNodeToFree = pList->head;

            pList->head = pNodeToFree->pNodeNext;

            pNodeToFree->pNodePrev->pNodeNext = pNodeToFree->pNodeNext;
            pNodeToFree->pNodeNext->pNodePrev = pNodeToFree->pNodePrev;


            pNodeToFree->pNodeNext = NULL;
            pNodeToFree->pNodePrev = NULL;
            pNodeToFree->data = 0;

            free(pNodeToFree);
            pNodeToFree = NULL;
        }
        pList->length = pList->length - 1;
    }
    else if(position < pList-> length)
    {
        // remove middle node
        int i = 0;
        node_t *pNodeToFree = NULL;
        
        for(i = 0, pNodeToFree = pList->head; i < position; pNodeToFree = pNodeToFree->pNodeNext, i++);

        pNodeToFree->pNodePrev->pNodeNext = pNodeToFree->pNodeNext;
        pNodeToFree->pNodeNext->pNodePrev = pNodeToFree->pNodePrev;

        // free node
        pNodeToFree->pNodeNext = NULL;
        pNodeToFree->pNodePrev = NULL;
        pNodeToFree->data = 0;

        free(pNodeToFree);
        pNodeToFree = NULL;

        pList->length = pList->length - 1;
      
    }
    else if(position >= pList->length)
    {
        if(pList->head->pNodeNext == pList->head || pList->head->pNodePrev == pList->head)
        {
            // if there is only one node
            pList->head->pNodePrev = NULL;
            pList->head->pNodeNext = NULL;
            pList->head->data = 0;

            free(pList->head);
            pList->head = NULL;

        }
        else
        {
            // if there are multiple nodes
            node_t *pNodeToFree = pList->head->pNodePrev;

            pNodeToFree->pNodePrev->pNodeNext = pNodeToFree->pNodeNext;
            pNodeToFree->pNodeNext->pNodePrev = pNodeToFree->pNodePrev;

            // free node
            pNodeToFree->pNodeNext = NULL;
            pNodeToFree->pNodePrev = NULL;
            pNodeToFree->data = 0;

            free(pNodeToFree);
            pNodeToFree = NULL;

        }

        pList->length = pList->length - 1;

    }
    else
    {
        printf("Please Enter Valid Position !!!\n\n");
    }
}

void displayList(list_t *pList)
{
    if(pList == NULL || pList->head == NULL)
    {
        printf("\n\nList Is Empty !!!\n\n");
        return;
    }

    printf("\n\nLENGTH : %d\n",pList->length);

    printf("\n\n[START]->%2d ->",pList->head->data);

    for(node_t *pNode = pList->head->pNodeNext; pNode != pList->head; pNode = pNode->pNodeNext)
    {
        printf("%2d ->",pNode->data);
    }

    printf("[END]\n\n");
}

void freeList(list_t **ppList)
{
    if(*ppList)
    {
        if((*ppList)->head)
        {
            node_t *pTemp = NULL;

            for(node_t *pNode = (*ppList)->head->pNodeNext; pNode != (*ppList)->head; pNode = pTemp)
            {
                pTemp = pNode->pNodeNext;
                
                pNode->pNodePrev = NULL;
                pNode->data      = 0;
                pNode->pNodeNext = NULL;

                free(pNode);
                pNode = NULL;
            }

            (*ppList)->head->pNodePrev = NULL;
            (*ppList)->head->data      = 0;
            (*ppList)->head->pNodeNext = NULL;

            free((*ppList)->head);
            (*ppList)->head = NULL;
        }

        (*ppList)->length = 0;
        free(*ppList);
        *ppList = NULL;
    }
}
