#include "testUtils.h"
#include "stack.h"
#include <stdio.h>
#include <memory.h>
#include <string.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef char string[100];


Stack create_ints(int length, int *array){
	int i;
	Stack intData = *createStack(sizeof(int), length);
	for (i = 0; i < intData.total_elements; ++i)
	{
		((int *)intData.starting_address)[i] = array[i];
	}
	return intData;
}

Stack create_chars(int length, char *array){
	int i;
	Stack charData = *createStack(sizeof(char), length);
	for (i = 0; i < charData.total_elements; ++i)
	{
		((char *)charData.starting_address)[i] = array[i];
	}
	return charData;
}

Stack create_strings(int length, string array){
	int i;
	Stack strData = *createStack(sizeof(string), length);
	for (i = 0; i < strData.total_elements; i++)
	{
		(*(string *)strData.starting_address)[i] = *array+i*sizeof(string);
	}
	return strData;
}



int areSizesEqual(Stack u1, Stack u2) {
	return u1.each_size == u2.each_size;
}

int areNumElementsEqual(Stack u1, Stack u2){
	return u1.total_elements == u2.total_elements;
}

int size_of_aryUtil(Stack a) {
	return a.each_size * a.total_elements;
}

int cmpArrays(Stack u1, Stack u2) {
	void *a1 = u1.starting_address;
	void *a2 = u2.starting_address;
	return memcmp(a1,a2,size_of_aryUtil(u1));
}

int areEqual(Stack u1,Stack u2){
	if(!(areSizesEqual(u1,u2) && areNumElementsEqual(u1,u2)))
		return 0;
	return (0 == cmpArrays(u1,u2));
};

int areEqualStrings(Stack u1,Stack u2){
	if(0 == strcmp(u1.starting_address, u2.starting_address)){
		return 1;
	}
	return 0;
}


void test_1_create_a_new_int_type_Stack(){
	Stack* data;
	Stack expected;
	int temp[] = {0,0,0,0,0};
	expected.starting_address = temp;
	expected.each_size = sizeof(int);
	expected.total_elements = 5;
	data = createStack(sizeof(int), 5);
	ASSERT(1 == areEqual(*data, expected));
}


void test_2_create_a_new_char_type_Stack(){
	Stack data , expected ;
	char temp[] = {0,0,0,0,0};
	expected.starting_address = temp;
	expected.each_size = sizeof(char);
	expected.total_elements = 5;
	data = *createStack(sizeof(char), 5);
	ASSERT(1 == areEqual(data, expected));
}

void test_3_create_a_new_string_type_Stack(){
	Stack data , expected ;
	string temp[] = {"","",""};
	expected.starting_address = temp;
	expected.each_size = sizeof(string);
	expected.total_elements = 3;
	data = *createStack(sizeof(string), 3);
	ASSERT(1 == areEqual(data, expected));
}

void test_4_push_element_into_int_type_Stack(){
	int data[] = {1,0,0,0,0};
	int arr[] = {0,0,0,0,0}; 
	int element = 1, result;
	Stack expected = {data,sizeof(int),5,0};
	Stack intData = create_ints(5, arr);
	result = push(&intData, &element);
	ASSERT(areEqual(intData, expected) && result == 1);
}


void test_5_push_element_into_string_type_Stack(){
	string data[] = {"a",0,0,0,0};
	string inputArr[] = {0,0,0,0,0}; 
	string element = "a";
	int result;
	Stack expected = {data,sizeof(string),5,0};
	Stack stringData = create_strings(5, inputArr);
	result = push(&stringData, &element);
	ASSERT(areEqualStrings(stringData, expected) && result == 1);
}

void test_6_push_element_into_char_type_Stack(){
	char data[] = {'a',0,0,0,0};
	char arr[] = {0,0,0,0,0}; 
	char element = 'a';
	Stack expected = {data,sizeof(char),5,0};
	Stack charData = create_chars(5, arr);
	push(&charData, &element);
	ASSERT(areEqual(charData, expected));
}

void test_7_push_element_into_int_type_Stack_when_stack_is_full(){
	int arr[] = {0,0,0,0,0}; 
	int result, element = 1;
	Stack intData = create_ints(5, arr);
	intData.top = 4;
	result = push(&intData, &element);
	ASSERT(0 == result);
}

void test_8_check_isStackFull_when_the_stack_is_full(){
	int arr[] = {0,0,0,0,0}; 
	int result;
	Stack intData = create_ints(5, arr);
	intData.top = 4;
	result = isStackFull(&intData);
	ASSERT(0 == result);	
}

void test_9_check_isStackFull_when_the_stack_is_not_Full(){
	int arr[] = {0,0,0,0,0}; 
	int result;
	Stack intData = create_ints(5, arr);
	intData.top = -1;
	result = isStackFull(&intData);
	ASSERT(1 == result);	
}

void test_10_check_isStackEmpty_when_stack_is_empty(){
	int inputArr[] = {0,0,0,0};
	int result;
	Stack intData = create_ints(4, inputArr);
	result = isStackEmpty(&intData);
	ASSERT(result == 0);
}

void test_11_check_isStackEmpty_when_stack_is_not_empty(){
	int inputArr[] = {0,0,0,0};
	int result;
	Stack intData = create_ints(4, inputArr);
	intData.top = 3;
	result = isStackEmpty(&intData);
	ASSERT(result == 1);
}

void test_12_pop_element_from_int_type_stack(){
	int top = 4;
	void *result;
	int inputArr[] = {1,2,3,4};
	Stack intData = create_ints(4, inputArr);
	intData.top = 3;
	result = pop(&intData);
	ASSERT(*(int*)result == top);
}

void test_13_pop_element_from_char_type_stack(){
	char top = 'a';
	void *result;
	char inputArr[] = {'s','g','d','a'};
	Stack charData = create_chars(4, inputArr);
	charData.top = 3;
	result = pop(&charData);
	ASSERT(*(char*)result == top);
}

void test_14_pop_element_from_STRING_type_stack(){
	string top = "a";
	void *result;
	string inputArr[] = {"s","g","d","a"};
	Stack stringData = create_strings(4, inputArr);
	stringData.top = 3;
	result = pop(&stringData);
	ASSERT(strcmp(top, *(string*)result));
}

void test_15_check_top_in_int_type_stack(){
	int topElement = 1;
	void *result;
	int arr[] = {2,3,1};
	Stack intData = create_ints(3, arr);
	intData.top = 2;
	result = top(&intData);
	ASSERT(*(int*)result == topElement);
}

void test_16_check_top_in_char_type_stack(){
	char topElement = 'a';
	void *result;
	char arr[] = {'d','s','a'};
	Stack charData = create_chars(3, arr);
	charData.top = 2;
	result = top(&charData);
	ASSERT(*(char*)result == topElement);
}


