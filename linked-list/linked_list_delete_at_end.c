#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
struct node* delete_at_end(struct node* head);
void main()
{
	struct node *head=NULL;
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,5);
	head=insert_at_begin(head,18);
	print_list(head);
	head=delete_at_end(head);
	print_list(head);
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


struct node* delete_at_end(struct node* head)
{
	struct node* temp=head;
	if(head==NULL)
		return NULL;
	if(head->next==NULL) //delete at head
	{
		free(temp);
		return head;
	}
	while(temp->next->next!=NULL)
		temp=temp->next;

	free(temp->next);
	temp->next=NULL;
	return head;
}
