#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void main()
{
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	struct node* last=head;

	for(int i=2;i<=6;i++)
	{
		last->next=(struct node*)malloc(sizeof(struct node));
		last=last->next;
		last->data=i;
	}

	last->next=head;

	struct node* curr=head;
	do
	{
		printf("%d\n",curr->data);
		curr=curr->next;
	}
	while(curr!=head);
}
