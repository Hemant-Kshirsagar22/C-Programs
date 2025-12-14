#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *pNodePrev;
    int data;
    struct Node *pNodeNext;
};

struct Node *createNode(void);
struct Node *createLinkList(int data);
void insertNode(struct Node *pNode, int data);
void displayLinkList(struct Node *pNode);
struct Node *createList(int numberOfNodes);
void freeLinkList(struct Node *pNode);

int main(void)
{
    struct Node *pNode = NULL;
    int numberOfNodes = 0;
    /*pNode = createLinkList(10);
    insertNode(pNode, 20);
    insertNode(pNode, 30);
    insertNode(pNode, 40);
    insertNode(pNode, 50);*/

    printf("Enter The Number Of Nodes Do You Want To Create : ");
    scanf("%d", &numberOfNodes);
    pNode = createList(numberOfNodes);
    displayLinkList(pNode);

    freeLinkList(pNode);
    free(pNode);
    pNode = NULL;
    printf("End of program\n");
    return(0);
}

struct Node *createNode(void)
{
    struct Node *node = NULL;
    node = (struct Node *)malloc(sizeof(struct Node));

    if(node == NULL)
    {
        printf("Error while Allocating memory for node !!!\n\n");
        exit(0);
    }

    node->data = 0;
    node->pNodeNext = NULL;
    node->pNodePrev = NULL;
    
    return(node);
}

struct Node *createLinkList(int data)
{
    struct Node *pNode = NULL;

    pNode = createNode();

    pNode->data = data;
    pNode->pNodeNext = pNode;
    pNode->pNodePrev = pNode;

    return(pNode);
}

void insertNode(struct Node *pNode, int data)
{
    struct Node *pNewNode = NULL;

    pNewNode = createNode();

    pNewNode->data = data;

    pNewNode->pNodePrev            = pNode->pNodePrev;
    pNewNode->pNodeNext            = pNode;
    pNode->pNodePrev->pNodeNext    = pNewNode;
    pNode->pNodePrev               = pNewNode;
}

void displayLinkList(struct Node *pNode)
{
    struct Node *iPNode = NULL;

    printf("LIST IS : \n\n");
    printf("[START]->%d->", pNode->data);

    for(iPNode = pNode->pNodeNext; iPNode != pNode; iPNode = iPNode->pNodeNext)
    {
        printf("%d->", iPNode->data);
    }

    printf("[END]\n\n\n");
}

struct Node *createList(int numberOfNodes)
{
    struct Node *pNode = NULL;
    
    pNode = createNode();

    pNode->data = rand() % 100;

    pNode->pNodeNext = pNode;
    pNode->pNodePrev = pNode;

    for(int i = 2; i <= numberOfNodes; i++)
    {
        insertNode(pNode, rand() % 100);
    }

    return(pNode);
}

void freeLinkList(struct Node *pNode)
{
    struct Node *pTemp = NULL;
    struct Node *iPNode = NULL;
    for (iPNode = pNode->pNodePrev; iPNode != pNode; iPNode = pTemp)
    {
        pTemp = iPNode->pNodePrev;
        iPNode->pNodePrev = NULL;
        iPNode->pNodeNext = NULL;
        free(iPNode);
    }
    pNode->pNodePrev = NULL;
    pNode->pNodeNext = NULL;
    free(pNode);
    printf("\nFreed the Link List...\n");
}
