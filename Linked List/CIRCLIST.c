/* Program of circular linked list */
#include <stdio.h>
#include <stdlib.h> // For malloc and exit

struct node
{
	int info;
	struct node *link;
} *last = NULL;

void create_list(int num);
void addatbeg(int num);
void addafter(int num, int pos);
void del(int num);
void display();

int main()
{
	int choice, n, m, po, i;
	while (1)
	{
		printf("\n1.Create List\n");
		printf("2.Add at beginning\n");
		printf("3.Add after\n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("How many nodes you want : ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("Enter the element : ");
				scanf("%d", &m);
				create_list(m);
			}
			break;
		case 2:
			printf("Enter the element : ");
			scanf("%d", &m);
			addatbeg(m);
			break;
		case 3:
			printf("Enter the element : ");
			scanf("%d", &m);
			printf("Enter the position after which this element is inserted : ");
			scanf("%d", &po);
			addafter(m, po);
			break;
		case 4:
			if (last == NULL)
			{
				printf("List underflow\n");
				continue;
			}
			printf("Enter the number for deletion : ");
			scanf("%d", &m);
			del(m);
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}

void create_list(int num)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = num;

	if (last == NULL)
	{
		last = tmp;
		tmp->link = last;
	}
	else
	{
		tmp->link = last->link; /* added at the end of list */
		last->link = tmp;
		last = tmp;
	}
}

void addatbeg(int num)
{
	struct node *tmp;
	if (last == NULL)
	{
		create_list(num);
		return;
	}
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = num;
	tmp->link = last->link;
	last->link = tmp;
}

void addafter(int num, int pos)
{
	struct node *tmp, *q;
	int i;
	if (last == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	q = last->link;
	for (i = 0; i < pos - 1; i++)
	{
		q = q->link;
		if (q == last->link)
		{
			printf("There are less than %d elements\n", pos);
			return;
		}
	}
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->link = q->link;
	tmp->info = num;
	q->link = tmp;
	if (q == last) /* Element inserted at the end */
		last = tmp;
}

void del(int num)
{
	struct node *tmp, *q;
	if (last == NULL)
	{
		printf("List is empty\n");
		return;
	}
	if (last->link == last && last->info == num)
	{ /* Only one element */
		tmp = last;
		last = NULL;
		free(tmp);
		return;
	}
	q = last->link;
	if (q->info == num)
	{
		tmp = q;
		last->link = q->link;
		free(tmp);
		return;
	}
	while (q->link != last)
	{
		if (q->link->info == num)
		{ /* Element deleted in between */
			tmp = q->link;
			q->link = tmp->link;
			free(tmp);
			printf("%d deleted\n", num);
			return;
		}
		q = q->link;
	}
	if (q->link->info == num)
	{ /* Last element deleted q->link=last */
		tmp = q->link;
		q->link = last->link;
		free(tmp);
		last = q;
		return;
	}
	printf("Element %d not found\n", num);
}

void display()
{
	struct node *q;
	if (last == NULL)
	{
		printf("List is empty\n");
		return;
	}
	q = last->link;
	printf("List is :\n");
	while (q != last)
	{
		printf("%d ", q->info);
		q = q->link;
	}
	printf("%d\n", last->info);
}