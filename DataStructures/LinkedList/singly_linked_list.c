//// Basic Operations in Linkedlist 
// 	1.insertion  
//	2.deletion 
//	3.searching the node
	
#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

struct Linkedlist
{
	int data;
	struct Linkedlist *next; 	// pointer to the next node 
};

void print_the_list(struct Linkedlist*);
void insert_in_front(struct Linkedlist**,int);
void insert_after_given_node(struct Linkedlist*,int);



//This func just prints the entire list 
void print_the_list(struct Linkedlist *ptr)
{
	printf("\n/*******Linked List *******/");
	while(ptr!=NULL)
	{
		printf("\n%d ",ptr->data);
		ptr=ptr->next;
	}
}
//creates a new node and returns the node
struct Linkedlist* create_node(int data)
{
	struct Linkedlist* new_node=(struct Linkedlist*)malloc(sizeof(struct Linkedlist));
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}

//Inserts a node in the front 
void insert_in_front(struct Linkedlist **ptr_ref,int data)
{
	struct Linkedlist *new_node= create_node(data);
	if(*ptr_ref==NULL)	//if the list is empty 
		new_node->next=NULL;
	
	new_node->next =*ptr_ref;
 	*ptr_ref = new_node;	//point the header pointer to point to the new node
}

void insert_after_given_node(struct Linkedlist *ptr,int data)
{
	struct Linkedlist *insert_node=create_node(data);
	insert_node->next=ptr->next;
	ptr->next=insert_node;
}

void insert_in_end(struct Linkedlist **ptr,int data)
{
	struct Linkedlist *new_node=create_node(data);
	struct Linkedlist *head_ref=*ptr;	//holds the copy of header pointer
	while(head_ref->next!=NULL)	//move the pointer until it reaches the last node
		head_ref=head_ref->next;
		
	head_ref->next=new_node;
}
	
void delete_last_node(struct Linkedlist **ptr)
{
	struct Linkedlist *head_ref=*ptr;
	while(head_ref->next->next!=NULL)
		head_ref=head_ref->next;

		head_ref->next=NULL;
}

//This function deletes a a specified node
void delete_specific_node(struct Linkedlist **ptr, int key)
{
	struct Linkedlist* head_ref=*ptr,*prev;
	// if header contains the key to be deleted 
	if(head_ref!=NULL && head_ref->data == key)
	{
		*ptr=head_ref->next;	//point the head_ref pointer to point to the next node of head
		free(head_ref);
		return;
	}
	while(head_ref!=NULL && head_ref->data !=key)
	{
		prev=head_ref;
		head_ref=head_ref->next;
	}
	
	prev->next=head_ref->next;
	if(head_ref == NULL) 
	 printf("Key not found\n");
	
}

//This function deletes the entire list
void delete_entire_list(struct Linkedlist **ptr)
{
	struct Linkedlist *head_ref=*ptr,*next_node;	
	while(head_ref!=NULL)
	{
		next_node=head_ref->next;	// store the address of the next node before deleting the node
		free(head_ref);
		head_ref=next_node;
	}
	*ptr=NULL;
	printf("\nEntire list deleted"); 
}

// finds the length of the list 
int find_length(struct Linkedlist *head)
{
	int length=0;
	while(head!=NULL)
	{
		length++;
		head=head->next;
	}
	return length;

}

int recursive_search(struct Linkedlist* head, int key)
{
	if(head==NULL)
		return false;
	
	if (head->data == key)
  		 return true;
	
       return recursive_search(head->next, key); 
}

int main()
{
	struct Linkedlist *head=NULL;
	int choice;
	int value;
   	while(1)
   	{
		int position=0;
        	printf("\n1.Add node at first ");
		printf("\n2.Insert after the specific node");
       		printf("\n3.Delete the last node");
		printf("\n4.Enter the value of the node to be deleted");
		printf("\n5.Delete the entire list");
		printf("\n6.Check whether the node is present in the list");
		printf("\n7.Find the length of the list");
        	printf("\n8.Print the Entire List");
        	printf("\nEnter your choice: ");
        	scanf("%d",&choice);
        	switch(choice)
        	{
        		case 1:
			{
				printf("Enter the value of data to be inserted\n");
				scanf("%d",&value);
            			insert_in_front(&head,value);
            		}break;
			case 2:
			{	
							printf("Enter the position to enter the node\n");
				scanf("%d",&position);
				printf("Enter the value of data to be inserted\n");
				scanf("%d",&value);
				if(position==1)	
				{
					insert_after_given_node(head,value);
				}else
				{	
					struct Linkedlist *temp=head;
					for(int i=1;i<position;i++)
						temp=temp->next;
					
					insert_after_given_node(temp,value);						
				}
			}break;
        		case 3:
            			delete_last_node(&head);
            			break;
        	
			case 4: 
			{
 				printf("\n Enter the position of the node to delete ");
				scanf("%d",&position);
				delete_specific_node(&head,position);

			}break;
			case 5:
				delete_entire_list(&head);
				break;
			case 6:
				printf("\n Enter the value to be searched");
				scanf("%d",&value);
				if(!recursive_search(head,value))
					printf("\n Value not found");
				else
					printf("\n Value found in the list");
			        break;
			case 7: 
				printf("\n Length of the list :: %d",find_length(head));
				break;	
			case 8:
            			print_the_list(head);
            			break;
        		default:
            		printf("\ninvalid choice");
        	}
    	}
	return(0);

}

