#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void print_list(struct node *head);
struct node* insert_at_begin(struct node *head,int data);
int Nth_node_from_end(struct node* head, int N);
void main()
{
	struct node *head=NULL;
	head=insert_at_begin(head,12);
	head=insert_at_begin(head,5);
	head=insert_at_begin(head,18);
	print_list(head);
	int N=0;
	printf("enter N\n");
	scanf("%d",&N);
	int Nth_node= Nth_node_from_end(head,N);
	printf("Nth node from end=%d\n",Nth_node);
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

int Nth_node_from_end(struct node* head, int N)
{
	struct node* first=head;
	struct node* second=head;

	for(int i=0;i<N;i++)
	{
		if(first==NULL)
			return -1;//N is greater than number of elements
		first=first->next;
	}

	while(first!=NULL)
	{
		first=first->next;
		second=second->next;
	}

	return second->data;
}
