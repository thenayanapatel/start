
#include <bits/stdc++.h> 

using namespace std; 


struct Node { 
	int data; 
	struct Node* next; 
	struct Node* prev; 
}; 


void reverse(struct Node** head_ref) 
{ 
	struct Node* temp = NULL; 
	struct Node* current = *head_ref; 

	
	
	while (current != NULL) { 
		temp = current->prev; 
		current->prev = current->next; 
		current->next = temp; 
		current = current->prev; 
	} 

	
	
	if (temp != NULL) 
		*head_ref = temp->prev; 
} 


struct Node* merge(struct Node* first, struct Node* second) 
{ 
	
	if (!first) 
		return second; 

	
	if (!second) 
		return first; 

	
	if (first->data < second->data) { 
		first->next = merge(first->next, second); 
		first->next->prev = first; 
		first->prev = NULL; 
		return first; 
	} else { 
		second->next = merge(first, second->next); 
		second->next->prev = second; 
		second->prev = NULL; 
		return second; 
	} 
} 


struct Node* sort(struct Node* head) 
{ 
	
	
	if (head == NULL || head->next == NULL) 
		return head; 

	struct Node* current = head->next; 

	while (current != NULL) { 

		
		
		if (current->data < current->prev->data) 
			break; 

		
		current = current->next; 
	} 

	
	if (current == NULL) 
		return head; 

	
	
	current->prev->next = NULL; 
	current->prev = NULL; 

	
	reverse(¤t); 

	
	
	return merge(head, current); 
} 



void push(struct Node** head_ref, int new_data) 
{ 
	
	struct Node* new_node = 
		(struct Node*)malloc(sizeof(struct Node)); 

	
	new_node->data = new_data; 

	
	
	new_node->prev = NULL; 

	
	new_node->next = (*head_ref); 

	
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	
	(*head_ref) = new_node; 
} 



void printList(struct Node* head) 
{ 
	
	if (head == NULL) 
		cout << "Doubly Linked list empty"; 

	while (head != NULL) { 
		cout << head->data << " "; 
		head = head->next; 
	} 
} 


int main() 
{ 
	struct Node* head = NULL; 

	
	
	push(&head, 1); 
	push(&head, 4); 
	push(&head, 6); 
	push(&head, 10); 
	push(&head, 12); 
	push(&head, 7); 
	push(&head, 5); 
	push(&head, 2); 

	cout << "Original Doubly linked list:n"; 
	printList(head); 

	
	head = sort(head); 

	cout << "\nDoubly linked list after sorting:n"; 
	printList(head); 

	return 0; 
} 
