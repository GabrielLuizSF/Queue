#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN 


typedef struct node{
	int value;
	struct node *next;
}node;


typedef struct{
	node *head;
	node *tail;
}queue;


void init_queue(queue *q){
	q->head = NULL;
	q->tail = NULL;
}


bool enqueue(queue *q, int value){
	
	node * newnode  = malloc(sizeof(node));
	
	if(newnode ==  NULL)return false;
	
	 newnode->value = value;
	 newnode->next = NULL;
	
	 if(q->tail != NULL){
	 	q->tail->next = newnode;
	 }
	
	 q->tail = newnode;
	
	
	 if(q->head == NULL){
	 	q->head = newnode;
	 }
	 return true;
}
int dequeue(queue *q){
	if(q->head == NULL) return QUEUE_EMPTY;
	node *tmp = q->head;

	int result = tmp->value;
	q->head = q->head->next;
	
	if(q->head == NULL){
		q->tail = NULL;
	}
	free(tmp);
	return result;
}

int main(){
	queue queue1 , queue2 , queue3 ;
	
	init_queue(&queue1);
	init_queue(&queue2);
	init_queue(&queue3);
	
	enqueue(&queue1,57);
	enqueue(&queue2,77);
	enqueue(&queue2,23);
	enqueue(&queue2,150);
	enqueue(&queue3,750);
	
	int t;
	
	while((t = dequeue(&queue1)) != QUEUE_EMPTY){
		printf("t = %d\n",t);
	}
	while((t = dequeue(&queue2)) != QUEUE_EMPTY){
		printf("t = %d\n",t);
	}
	while((t = dequeue(&queue3)) != QUEUE_EMPTY){
		printf("t = %d\n",t);
	}
	
} 