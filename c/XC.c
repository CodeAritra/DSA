#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *create(int val)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

void insert(struct node **head, int val)
{
	struct node *newnode = create(val);
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		struct node *temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void display(struct node *link)
{
	struct node *temp = link;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void posNeg(struct node *main)
{
	struct node *pos = NULL, *neg = NULL, *temp = main;
	while (temp != NULL)
	{
		if (temp->data >= 0)
		{
			insert(&pos, temp->data);
			temp = temp->next;
		}
		else
		{
			insert(&neg, temp->data);
			temp = temp->next;
		}
	}
	printf("POS = ");
	display(pos);
	printf("NEG = ");
	display(neg);
}

int main()
{
	struct node *main = NULL;

	int n, val, i;
	printf("enter the num ele :");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		printf("enter the element :");
		scanf("%d", &val);
		insert(&main, val);
	}

	display(main);
	posNeg(main);

	return 0;
}