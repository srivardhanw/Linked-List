#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node; // we are using typedef for our convenience
node *head = NULL; // declaring the head node globally
//----------------------------------------------------------------------------------
void InsBeg(int val) // Inserts node at the beginning
{
	node *newNode = malloc(sizeof(node)); // creating new node
	newNode->data = val; // assigning data to new Node
	newNode->next = head;//we store the address of the head node in newNode cuz..
	head = newNode; // we made the newNode as the head node.
}
//----------------------------------------------------------------------------------
void InsEnd(int val)// Inserts Node at the end of the list
{
	node *newNode = malloc(sizeof(node)); // creating new node
	newNode->data = val; // assigning data to new Node
	newNode->next = NULL;
	if(head == NULL)
	{
		head = newNode;
	} // if the list is empty then lastnode is the first node
	else
	{
		node *lastNode = head; // temporary head for traversing the list
		while(lastNode->next!= NULL)
		{
			lastNode = lastNode->next;
		} // for traversing the list till we hit NULL i.e the lastnode
		lastNode->next = newNode; // adding the newNode at the end of the list (or) to the lastnode
	}
}
//----------------------------------------------------------------------------------
void DeleteNode(int key) // deletes a node with the specified key
{
	node *current = head, *temp;
	if(head->data == key) // if head has the key element
	{
		temp = head; // store the head node in temp to free memory 
		head = head->next; // removing the head node from the list
		free(temp); // freeing the memory allocation for headnode
	}
	else
	{
		while(current->next != NULL) // loop for traversing the list
		{
			if(current->next->data == key) // if the node with the key element is found in the list
			{ //(note: remember we need to do operations on the previous node of the node containing the key) 
			
				temp = current->next; // we are storing the node to be deleted in temp to free the memory 
				current->next = current->next->next; // removing the key node from the list
				free(temp); // freeing the memory allocation of key node
				break; // breaking the loop since we deleted the key node
			}
			else
			{
				current = current->next;// if the key is not found then the traversal of the list continues
				// the current variable is replaced by the next node i.e current->next 
			}
		}
	}
}
//----------------------------------------------------------------------------------------------------
void Display()
{
	node *temp = head; // temp head for traversing the list
	while(temp != NULL) // runs the loop till we hit the last node in the list
	{
		printf("%d->",temp->data); // printing the data
		temp = temp->next; // moving the pointer to the next node
	}
	printf("NULL\n");
}
//----------------------------------------------------------------------------------------------------
int main()
{
	int ch, num;
	while(1)
	{
		printf("Choose\n1.InsBeg 2.InsEnd 3.DeleteNode 4.Display 5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter data\n");
			scanf("%d",&num);
			InsBeg(num);
			break;
			
			case 2: printf("Enter data\n");
			scanf("%d",&num);
			InsEnd(num);
			break;
			
			case 3: printf("Enter the key\n");
			scanf("%d",&num);
			DeleteNode(num);
			break;
			
			case 4: Display();break;
			
			case 5: exit(0);break;
		}
	}
	return 0;
}
