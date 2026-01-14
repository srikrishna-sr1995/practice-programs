#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void print_list(struct node *head);
struct node* insert_at_kth_position(struct node *head,int k,int data);
void main()
{
	struct node* head=NULL;
	head=insert_at_kth_position(head,1,12);
	head=insert_at_kth_position(head,2,5);
	head=insert_at_kth_position(head,3,18);
	print_list(head);
}

void print_list(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}
}


struct node* insert_at_kth_position(struct node *head,int k,int data)
{
	struct node* New_node=(struct node *)malloc(sizeof(struct node));
	New_node->data=data;
	New_node->next=NULL;
	struct node* tmp_node=head;
	int i;

	if(k==1)
	{
		New_node->next=head;
		head=New_node;
		return head;
	}
	
	for(i=1;(i<k-1)&&(tmp_node!=NULL);i++)
		tmp_node=tmp_node->next;

	if(tmp_node==NULL)
	{
		printf("k is invalid\n");
		free(New_node);
		return head;
	}

	New_node->next=tmp_node->next;
	tmp_node->next=New_node;
	return head;

}
