#include <stdio.h>
#include "10_.h"

int main(){
	struct Vector* vector1=init(10);
	printf(
		"size = %d, "
		"capactiy = %d, "
		"empty = %d\n"
		, size(vector1), capacity (vector1), empty(vector1));

	for (int i=1; i<11; i++) //filing array
		push_back(vector1, i);
	printf("6th element: %d\n", at(vector1, 5));
	
	print(vector1);
	reverse(vector1); // reverse vector of even length
	print(vector1);

	insert(vector1, 5, 1337); //should throw errors
	insert(vector1, 1337, 5); 

	reallocate(vector1, 100); // increase capcacity to 100
	printf("New capacity = %d\n", capacity(vector1));

	insert(vector1, 5, 1337); //error

	insert(vector1, 1337, 5);
	print(vector1);
	reverse(vector1); //reverse odd length
	print(vector1);

	int array2[] = {1, 2, 3, 4, 5}; // testing reserve()
	struct Vector *vector2 = reserve(10, 5, array2);
	print (vector2);

	printf(
		"size = %d, "
		"capactiy = %d, "
		"empty = %d\n"
		, size(vector2), capacity (vector2), empty(vector2));

	fremove (vector2, 7); //should not work
	fremove (vector2, 11); //should not work
	fremove (vector2, 3); 
	
	print (vector2);
	reallocate(vector2, 3); //should throw warning but work;
	printf("%d\n", at(vector2, 4)); // out of range;
	print (vector2);

	return 0;
}

