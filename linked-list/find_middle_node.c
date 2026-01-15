#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
struct node* middle_node(struct node* head);
void main()
{
	struct node *head=NULL;
	struct node *middle=NULL;
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,5);
	head=insert_at_begin(head,6);
	head=insert_at_begin(head,18);
	print_list(head);
	middle=middle_node(head);
	printf("middle node =%d\n",middle->data);
}

void print_list(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d\n", head->data);
		head=head->next;
	}
}


struct node* insert_at_begin(struct node *head,int data)
{
	struct node* New_node=(struct  node *)malloc(sizeof(struct node));
	New_node->data=data;
	New_node->next=NULL;
	New_node->next=head;
	head=New_node;
	return head;
}

struct node* middle_node(struct node* head)
{
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
