#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
	struct Node *pPrev;
} Node;

typedef struct
{
	int length;
	Node *head;
	Node *last;
} DoublyLinkList;


DoublyLinkList *createDoublyLinkList(void);
Node *createNode(void);
void insertNode(DoublyLinkList *, Node *);
void display(DoublyLinkList *);
void freeDoublyLinkList(DoublyLinkList *);

int main(void)
{
	int numberOfNodes = 0;
	DoublyLinkList * const list = createDoublyLinkList();

	printf("Enter The Number Of Nodes : ");
	scanf("%d", &numberOfNodes);

	for (int i = 0; i < numberOfNodes; i++)
	{
		Node *node = createNode();
		
		printf("Enter Data for %d : ", i);
		scanf("%d", &node->data);

		insertNode(list, node);
	}

	display(list);

	freeDoublyLinkList(list);

	printf("End Of Program");
	return(0);
}

DoublyLinkList *createDoublyLinkList(void)
{
	DoublyLinkList * const list = (DoublyLinkList *)malloc(sizeof(DoublyLinkList));

	if (list == NULL)
	{
		printf("malloc() failed While Creating List !!!\n\n");
		exit(EXIT_FAILURE);
	}

	list->head = NULL;
	list->length = 0;
	return(list);
}

Node *createNode(void)
{
	Node *node = (Node *)malloc(sizeof(Node));

	if (node == NULL)
	{
		printf("malloc() failed while creating Node !!!\n\n");
		exit(EXIT_FAILURE);
	}

	node->data = 0;
	node->pNext = NULL;
	node->pPrev = NULL;

	return(node);
}

void insertNode(DoublyLinkList *list, Node *node)
{
	if(list)
	{
		if (list->head == NULL)
		{
			list->head = node;
			list->last = node;

			list->length = list->length + 1;
		}
		else
		{
			list->last->pNext = node;
			node->pPrev = list->last;
			list->last = node;

			list->length = list->length + 1;
		}
	}
	else
	{
		printf("Given List is NULL !!!\n\n");
		exit(EXIT_FAILURE);
	}
}

void display(DoublyLinkList *list)
{
	printf("\n\nLength Of List : %d\n\n", list->length);

	for (Node *i = list->head; i != NULL; i = i->pNext)
	{
		printf("%d <-> ", i->data);
	}

	printf("\n\n");
}

void freeDoublyLinkList(DoublyLinkList *list)
{
	
	if (list)
	{
		if (list->head)
		{
			Node *j = list->head;
			for (Node *i = list->head; i != NULL; i = j)
			{
				j = i->pNext;
				free(i);
			}
		}

		free(list);
		list = NULL;
	}

}