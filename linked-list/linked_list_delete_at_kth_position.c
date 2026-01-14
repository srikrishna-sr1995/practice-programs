#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
struct node* delete_at_kth_position(struct node* head, int pos);
void main()
{
	struct node *head=NULL;
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,5);
	head=insert_at_begin(head,18);
	print_list(head);
	head=delete_at_kth_position(head,4);
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

struct node* delete_at_kth_position(struct node* head, int k)
{
	if(head==NULL)
		return NULL;
	if(k==1)
	{
		struct node* temp=head;
		head=head->next;
		free(temp);
		return head;
	}
	struct node* temp2=head;
	for(int i=1;(i<k-1)&&(temp2!=NULL);i++)
		temp2=temp2->next;

	if(temp2==NULL || temp2->next==NULL)
		return head; //k is invalid

	struct node* del=temp2->next;
	temp2->next=del->next;
	free(del);
	return head;

}
