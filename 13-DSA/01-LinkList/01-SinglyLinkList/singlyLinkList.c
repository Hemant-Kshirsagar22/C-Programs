#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *pNext;
};

struct SinglyLinkList
{
	int length;
	struct Node * head;
};

struct SinglyLinkList *createSinglyLinkList(void);
struct Node *createNode(void);
void insertNode(struct SinglyLinkList *, struct Node *);
void display(struct SinglyLinkList *);
void destroySinglyLinkList(struct SinglyLinkList *);

int main(void)
{
	int numberOfNodes = 0;
	struct SinglyLinkList *list = createSinglyLinkList();

	printf("Enter size of list : ");
	scanf("%d", &numberOfNodes);

	for (int i = 0; i < numberOfNodes; i++)
	{
		struct Node *node = createNode();
		printf("Enter The Data For %d : ", i);
		scanf("%d", &node->data);

		insertNode(list, node);
	}

	display(list);

	destroySinglyLinkList(list);
	
	return(0);
}

struct SinglyLinkList *createSinglyLinkList(void)
{
	struct SinglyLinkList *list = (struct SinglyLinkList *)malloc(sizeof(struct SinglyLinkList));

	if (list == NULL)
	{
		printf("malloc() failed for creating singly link list !!!\n\n");
		exit(EXIT_FAILURE);
	}

	list->head = NULL;
	list->length = 0;

	return(list);
}

struct Node *createNode(void)
{
	struct Node *node = NULL;
	node = (struct Node *)malloc(sizeof(struct Node));

	if (node == NULL)
	{
		printf("malloc() failed for creating node !!!\n\n");
		exit(EXIT_FAILURE);
	}

	node->data = 0;
	node->pNext = NULL;

	return(node);
}

void insertNode(struct SinglyLinkList *list, struct Node *node)
{

	if (list->head == NULL)
	{
		list->head = node;
		list->length = list->length + 1;
	}
	else
	{
		struct Node *temp = list->head;

		while (temp->pNext != NULL)
		{
			temp = temp->pNext;
		}

		temp->pNext = node;
		list->length = list->length + 1;
	}
}

void display(struct SinglyLinkList *list)
{
	struct Node *head = list->head;

	printf("\n\nSize of List : %d\n\n", list->length);

	for (int i = 0; i < list->length; i++)
	{
		if (i == list->length - 1)
		{
			printf("%d", head->data);
		}
		else
		{
			printf("%d -> ", head->data);
		}
		head = head->pNext;
	}

	printf("\n\n");
}

void destroySinglyLinkList(struct SinglyLinkList *list)
{
	if (list)
	{
		if (list->head)
		{
			struct Node *current = list->head;
			struct Node *next = NULL;

			while (current != NULL)
			{
				next = current->pNext;
				free(current);
				current = next;
				
			}
		}

		free(list);
		list = NULL;
	}
}
