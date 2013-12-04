#include "stack.h"
#include <stdlib.h>
#include <memory.h>

Stack *createStack(int size,int length){
	Stack *stack = (Stack*)calloc(1, sizeof(Stack));
	stack->starting_address = calloc(size,length);
	stack->each_size = size;
	stack->total_elements = length;
	stack->top = -1;
	return stack;
}
int isStackFull(Stack *stack){
	if(stack->top == stack->total_elements-1){
		return 0; 
	}
	return 1;
}
int isStackEmpty(Stack *stack){
 	if(stack->top == -1)
 		return 0;
 	return 1;
 }

int push(Stack* data, void* element){
	void* topPtr;
	if(isStackFull(data) == 0)
		return 0; 
	data->top = (data->top) + 1;
	topPtr =  (data->starting_address) + ((data->top)*(data->each_size));
	memcpy(topPtr,element,data->each_size);
	return 1;
}	

void *pop(Stack *stack){
	if(isStackEmpty(stack) == 0)
		return 0;
	--stack->top;
	return (stack->starting_address) + ((stack->each_size)*(stack->top+1));
}

void *top(Stack *stack){
	return (stack->starting_address) + ((stack->each_size)*(stack->top));	
}




