#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* insert_at_end(struct node *head, int data);
void print_list(struct node *head);
void main()
{
	struct node *head=NULL;
	head=insert_at_end(head,12);
	head=insert_at_end(head,5);
	head=insert_at_end(head,18);
	print_list(head);
}

void print_list(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}

struct node* insert_at_end(struct node *head, int data)
{
	struct node* New_node=(struct node *)malloc(sizeof(struct node));
	New_node->data=data;
	New_node->next=NULL;
	struct node *tmp_node=head;

	if(head==NULL)
	{
		head=New_node;
		return head;
	}
	else
	{
		while(tmp_node->next!=NULL)
			tmp_node=tmp_node->next;

		tmp_node->next=New_node;
		return head;
	}
}
