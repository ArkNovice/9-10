#include<stdio.h>
#include<stdlib.h>
struct Link *AppendNode(struct Link *head);
void DispLink(struct Link *head);
void DeleteMemory(struct Link *head);
struct Link
{
	int data;
	struct Link *next;
};
int main()
{
	int i=0;
	char c;
	struct Link *head=NULL;
	printf("Do you want to append a new node(Y/N)?");
	scanf(" %c", &c);
	while(c=='Y'||c=='y')
	{
		head=AppendNode(head);
		DispLink(head);
		printf("Do you want to append a new node(Y/N)?");
		scanf(" %c", &c);
		 i++;
	}
	printf("%d new nodes have been appended!\n", i);
	DeleteMemory(head);
	return 0;
}
struct Link *AppendNode(struct Link *head)
{
	struct Link *p=NULL;
	struct Link *pr=head;
	int data;
	p=(struct Link*)malloc(sizeof(struct Link));
	if(p==NULL)
	{
		printf("No enough memory to alloc");
		exit(0);
	}
	if(head==NULL)
	{
		head = p;
	}
	else
	{
		while(pr->next != NULL)
		{
			pr=pr->next;
		}
		pr->next=p;
	}
	pr=p;
	printf("Input node data:");
	scanf("%d", &data);
	pr->data=data;
	pr->next=NULL;
	return head;
}
void DispLink(struct Link *head)
{
	struct Link *p=head;
	int j=1;
	while(p!=NULL)
	{
		printf("%5d%10d\n", j, p->data);
		p=p->next;
		j++;
	}
}
void DeleteMemory(struct Link *head)
{
	struct Link*p=head, *pr=NULL;
	while(p!=NULL)
	{
		pr=p;
		p=p->next;
		free(pr);
	}
}
