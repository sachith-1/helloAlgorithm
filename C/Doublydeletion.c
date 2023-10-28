#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insert (struct Node **head, int data)
{

  struct Node *freshNode = (struct Node *) malloc (sizeof (struct Node));

  freshNode->data = data;
  freshNode->next = *head;
  freshNode->prev = NULL;

  // If the linked list already had atleast 1 node
  if (*head != NULL)
    (*head)->prev = freshNode;

  // freshNode will become head
  *head = freshNode;
}

void deleteEnd (struct Node **head)
{
  struct Node *tempNode = *head;

  // if DLL is empty
  if (*head == NULL)
    {
      printf ("Linked List Empty, nothing to delete\n\n");
      return;
    }

  // if Linked List has only 1 node
  if (tempNode->next == NULL)
    {
      printf ("%d deleted\n\n", tempNode->data);
      *head = NULL;
      return;
    }

  // else traverse to the last node
  while (tempNode->next != NULL)
    tempNode = tempNode->next;

  struct Node *secondLast = tempNode->prev;

  // Curr assign 2nd last node's next to Null
  secondLast->next = NULL;

  printf ("%d deleted\n\n", tempNode->data);
  free (tempNode);
}

//function to print the doubly linked list
void display (struct Node *node)
{
  struct Node *end = NULL;

 
  while (node != NULL)
    {
      printf (" %d ", node->data);
      end = node;
      node = node->next;
    }

  printf ("\n\n");
}

int main ()
{
  struct Node *head = NULL;

  insert (&head, 7);
  insert (&head, 8);
  insert (&head, 9);
  insert (&head, 10);
  insert (&head, 11);
  insert (&head, 12);

  printf("Linked List Before Deletion");
  display (head);

  deleteEnd (&head);
  printf("Linked List After Deletion");
  display (head);

  return 0;
}
