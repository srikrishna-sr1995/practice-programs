#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
struct node* del_at_middle(struct node* head);
void main()
{
	struct node *head=NULL;
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,5);
	head=insert_at_begin(head,4);
	head=insert_at_begin(head,18);
	print_list(head);
	head=del_at_middle(head);
	printf("afer deleting in middle\n");
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

struct node* del_at_middle(struct node* head)
{
	if(head==NULL)
	{
		free(head);
		return NULL;
	}
	struct node* prev=NULL;
	struct node* slow=head;
	struct node* fast=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	prev->next=slow->next;
	free(slow);
	return head;

}
