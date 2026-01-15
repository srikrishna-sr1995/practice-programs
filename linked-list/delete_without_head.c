#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* Node_create(int data);
void delete_without_head(struct node* Node);
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
	n5->next=NULL;

	print_list(head);
	delete_without_head(head->next->next);
	printf("After removal of node\n");
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


struct node* Node_create(int data)
{
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->data=data;
	head->next=NULL;
	return head;
}


void delete_without_head(struct node* node)
{
	struct node* tmp=node->next;
	node->data=tmp->data;
	node->next=tmp->next;
	free(tmp);
}
