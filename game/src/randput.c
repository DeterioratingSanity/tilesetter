#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL)); // rn seed
	
	int numPairs;
	int bound;
	
	typedef struct tile {
		int attribute;
	} tile;

	printf("How many tile pairs would you like to generate?\n");
	scanf("%d", &numPairs);
	
	printf("What should be the upper bound for each attribute (assuming the lower is 0)?\n");
	scanf("%d", &bound);

	int *tilesAt = malloc((numPairs*2) * sizeof(int)); // allocate dynamic space for our user-defined pairs

	/* Will at some juncture need to replace the allocated area with the aforementioned struct. */

	// Preliminary attribute login (value in bound), whereafter put in indicies of each tile's attribute value, and
	// assigned in pairs to two rands (thus keeping tile parity.
	for (int i = 0; i < numPairs; i++) {
		tilesAt[i] = rand() % bound;
	}

	printf("Printing.\n");

	for (int i = 0; i< numPairs; i++) {
		printf("%d\n", tilesAt[i]);
	}
	
	free(tilesAt);	
}
