#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
struct node* delete_last_occurance(struct node* head, int k);
void main()
{
	struct node *head=NULL;
	head=insert_at_begin(head,1);
	head=insert_at_begin(head,1);
	head=insert_at_begin(head,1);
	head=insert_at_begin(head,1);
	head=insert_at_begin(head,1);
	print_list(head);
	int k=0;
	printf("enter value whose last occurance\n");
	scanf("%d",&k);
	head=delete_last_occurance(head, k);
	printf("list after removal\n");
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


struct node* delete_last_occurance(struct node* head, int k)
{
	struct node* last=NULL;
	struct node* curr=head;
	struct node* last_prev =NULL;
	struct node* prev =NULL;

	while(curr!=NULL)
	{
		if(curr->data==k)
		{
			last_prev=prev;
			last=curr;
		}
		prev=curr;
		curr=curr->next;
	}

	if(last==NULL)
		return head;
	else if(last_prev==NULL)
		head=head->next;
	else
		last_prev->next= last->next;

	free(last);
	return head;
}
