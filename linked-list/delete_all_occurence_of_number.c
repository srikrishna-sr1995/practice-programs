#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
struct node* delete_all_occurence(struct node* head,int digit);
void main()
{
	struct node *head=NULL;
	head=insert_at_begin(head,1);
	head=insert_at_begin(head,2);
	head=insert_at_begin(head,2);
	head=insert_at_begin(head,1);
	head=insert_at_begin(head,2);
	print_list(head);
	head=delete_all_occurence(head,2);
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

struct node* delete_all_occurence(struct node* head,int digit)
{
	while(head!=NULL && head->data==digit)
	{
		struct node* tmp=head;
		head=head->next;
		free(tmp);
	}

	struct node* curr=head;
	while(curr!=NULL && curr->next!=NULL)
	{
		if(curr->next->data==digit)
		{
			struct node* tmp2;
			tmp2=curr->next;
			curr->next=tmp2->next;
			free(tmp2);
		}
		else
			curr=curr->next;
	}
	return head;
}
