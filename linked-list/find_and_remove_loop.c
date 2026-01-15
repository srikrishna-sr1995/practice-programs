#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* Node_create(int data);
struct node* delete_loop(struct node* head);
void main()
{
	struct node* head=Node_create(1);
	struct node* n2=Node_create(2);
	struct node* n3=Node_create(3);
	struct node* n4=Node_create(4);
	struct node* n5=Node_create(5);

	head->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n3;

	head=delete_loop(head);
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


struct node* delete_loop(struct node* head)
{
	struct node* slow=head;
	struct node* fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			slow=head;
			while(slow!=fast)
			{
				slow=slow->next;
				fast=fast->next;
			}

			struct node* tmp=slow;
			int ctr=1;
			while(tmp->next!=slow)
			{
				tmp=tmp->next;
				ctr++;
			}
			tmp->next=NULL;
			printf("length of loop=%d\n",ctr);
		}
	}
	return head;
}


struct node* Node_create(int data)
{
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->data=data;
	head->next=NULL;
	return head;
}
