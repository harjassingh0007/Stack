typedef struct{
	int item[10];
}stack;

int push(stack container,int element);
int pop(stack container);
int top(stack container);
void isStackEmpty(stack container);
void isStackFull(stack container);

