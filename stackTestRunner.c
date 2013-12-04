#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_create_a_new_int_type_Stack");
	setup();
		test_1_create_a_new_int_type_Stack();
	tearDown();
	testEnded();
	testStarted("test_2_create_a_new_char_type_Stack");
	setup();
		test_2_create_a_new_char_type_Stack();
	tearDown();
	testEnded();
	testStarted("test_3_create_a_new_string_type_Stack");
	setup();
		test_3_create_a_new_string_type_Stack();
	tearDown();
	testEnded();
	testStarted("test_4_push_element_into_int_type_Stack");
	setup();
		test_4_push_element_into_int_type_Stack();
	tearDown();
	testEnded();
	testStarted("test_5_push_element_into_string_type_Stack");
	setup();
		test_5_push_element_into_string_type_Stack();
	tearDown();
	testEnded();
	testStarted("test_6_push_element_into_char_type_Stack");
	setup();
		test_6_push_element_into_char_type_Stack();
	tearDown();
	testEnded();
	testStarted("test_7_push_element_into_int_type_Stack_when_stack_is_full");
	setup();
		test_7_push_element_into_int_type_Stack_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_8_check_isStackFull_when_the_stack_is_full");
	setup();
		test_8_check_isStackFull_when_the_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_9_check_isStackFull_when_the_stack_is_not_Full");
	setup();
		test_9_check_isStackFull_when_the_stack_is_not_Full();
	tearDown();
	testEnded();
	testStarted("test_10_check_isStackEmpty_when_stack_is_empty");
	setup();
		test_10_check_isStackEmpty_when_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_11_check_isStackEmpty_when_stack_is_not_empty");
	setup();
		test_11_check_isStackEmpty_when_stack_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_12_pop_element_from_int_type_stack");
	setup();
		test_12_pop_element_from_int_type_stack();
	tearDown();
	testEnded();
	testStarted("test_13_pop_element_from_char_type_stack");
	setup();
		test_13_pop_element_from_char_type_stack();
	tearDown();
	testEnded();
	testStarted("test_14_pop_element_from_STRING_type_stack");
	setup();
		test_14_pop_element_from_STRING_type_stack();
	tearDown();
	testEnded();
	testStarted("test_15_check_top_in_int_type_stack");
	setup();
		test_15_check_top_in_int_type_stack();
	tearDown();
	testEnded();
	testStarted("test_16_check_top_in_char_type_stack");
	setup();
		test_16_check_top_in_char_type_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
