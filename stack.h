#include <stdbool.h>
typedef struct{
	void* starting_address;
	int each_size;
	int total_elements;
	int top;
}Stack;

Stack* createStack(int size, int totalElements);
int push(Stack* stack ,void* element);
int isStackFull(Stack *stack);
void *pop(Stack *stack);
int isStackEmpty(Stack *stack);
void *top(Stack *stack);
