#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL)); // seed specifier for random numbers

	int numPairs; // key values
	int bound;
	int width = 0;
	int numAttr;

	typedef struct tile { // define a tile n
		int* attributes;
	} tile;

	printf("How many tile pairs would you like to generate?\n"); // scan inputs
	scanf("%d", &numPairs);
	
	printf("What should be the upper bound for each attribute (assuming the lower is 0)?\n");
	scanf("%d", &bound);

	int boundBy = bound; // calculate the bound width (for subsequent use in form specifying the output)
	do {
		boundBy = boundBy / 10;
		width += 1;
	} while (boundBy != 0);

	printf("How many attributes should each tile have?\n");
	scanf("%d", &numAttr);

	tile* tilesAt = malloc((numPairs*2) * sizeof(tile)); // allocate tile array tilesAt

	for (int i = 0; i < numPairs * 2; i++) {
		tilesAt[i].attributes = calloc(numAttr, sizeof(int)); //allocate at each tile's value attributes an int array
	}

	// note attr x1, x2 tends to give obviouslty and unobviously a great num matches, whereas x3 has may x2 but few x3 (as we expect)
	for (int j = 0; j < numAttr; j++) { // for each attribute
		for (int i = 0; i < numPairs; i++) { // for each pair (num pairs is half num tiles, each chooses two)
		
			// pick two distinct and as-yet unchosen values
			int n = -1;
			int m = -1;
			do {
				n = rand() % (numPairs*2);
			} while (tilesAt[n].attributes[j] != 0);

			do { 
				m = rand() % (numPairs * 2);
			} while ((tilesAt[m].attributes[j] != 0) || (m == n));

			// increase by one to polish validation
			int set = ((rand() % bound) + 1);

			// assign value
			tilesAt[n].attributes[j] = set;
			tilesAt[m].attributes[j] = set;
		}
	}

	for (int i = 0; i<numPairs * 2; i++) { // for every tile
		printf("[");
		for (int j = 0; j < numAttr; j++) { //print each attribute
			printf("%*d", width, tilesAt[i].attributes[j]); //* width to dynamically specify the per-unit width (easier to read) from prior bound calc
			if (j+1 < numAttr) {
				printf(", "); // conditionally comma-separate attributes
			}
		}
		printf("]");

		if (i % 5 == 4) { // five tiles per line
			printf("\n");
		} else {
			printf(", ");
		}
	}
	
	// free each tile's allocated attr space
	for (int i = 0; i < numPairs * 2; i++) {	
		free(tilesAt[i].attributes);
	}

	printf("\n");

	// free tiles array
	free(tilesAt);	
}
