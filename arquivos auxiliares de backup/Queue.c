#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Queue {
  int size;
  int begin;
  int end;
  void **elements;
};

Queue *Queue_alloc(int size) {
  Queue *q = malloc(sizeof(Queue));
  
  if (q) {
    q->size = size;
    q->begin = -1;
    q->end = -1;
    
    q->elements = calloc(size, sizeof(void*));
    if (q->elements == NULL) {
      free(q);
      q = NULL;
    }
  }
  
  return q;
}

void Queue_free(Queue *q) {
	if (q) {
		free(q->elements);
		free(q);
	}
}

int Queue_isEmpty(Queue *q) {
	if (q)
		return q->begin == -1 && q->end == -1;
	
	return 1;
}

int Queue_next(Queue *q, int index) {
	if (q != NULL && index >= 0)
		return (index + 1) % q->size;
	
	return 0;
}

int Queue_isFull(Queue *q) {
	if (q) 
		return Queue_next(q, q->end) == q->begin;
	
	return 0;
}

void Queue_push(Queue *q, void *
item) {
	if (q) {
		if (!Queue_isFull(q)) {
			if (Queue_isEmpty(q)) {
				q->begin = 0;
				q->end = 0;
			}
			else {
				q->end = Queue_next(q, q->end);
			}
			
			q->elements[q->end] = item;
		}
		else {
			printf("ERROR: Queue is full.\n");
		}
	}
}

void Queue_print(Queue *q, void (*print)(void*)) {
	int i;
	
	if (q && !Queue_isEmpty(q)) {
		
		for (i = q->begin; q->elements[i] 
                      && Queue_next(q, i) != q->begin; 
                                    i = Queue_next(q, i)) {
			print(q->elements[i]);
		}
		
		if (q->elements[i])
			print(q->elements[i]);
			
		printf("\n");
	}
}

void *Queue_pop(Queue *q) {
	void *aux;
	
	if (q) {
		if (!Queue_isEmpty(q)) {
			aux = q->elements[q->begin];
			q->elements[q->begin] = NULL;
			
			if (q->begin == q->end) {
				q->begin = -1;
				q->end = -1;
			}
			else {
				q->begin = Queue_next(q, q->begin);
			}
			
			return aux;
		}
		else {
			printf("ERROR: Queue is empty.\n");
		}
	}
	
	return NULL;
}

void *Queue_begin(Queue *q) {
	if (q && !Queue_isEmpty(q))
		return q->elements[q->begin];
	
	return NULL;
}

void *Queue_end(Queue *q) {
	if (q && !Queue_isEmpty(q))
		return q->elements[q->end];
	
	return NULL;
}
