#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL)); // rn seed
	
	int numPairs;
	int bound;
	int numAttr;
	
	typedef struct tile {
		int* attributes;
	} tile;

	printf("How many tile pairs would you like to generate?\n");
	scanf("%d", &numPairs);
	
	printf("What should be the upper bound for each attribute (assuming the lower is 0)?\n");
	scanf("%d", &bound);

	printf("How many attributes should each tile have?\n");
	scanf("%d", &numAttr);

	tile* tilesAt = malloc((numPairs*2) * sizeof(tile)); // allocate dynamic space for our user-defined pairs

	/* Will at some juncture need to replace the allocated area with the aforementioned struct. */

	// Preliminary attribute login (value in bound), whereafter put in indicies of each tile's attribute value, and
	// assigned in pairs to two rands (thus keeping tile parity.
	for (int i = 0; i < numPairs * 2; i++) {
		//tilesAt[i] = rand() % bound;
		//tilesAt[i] = malloc(numAttr * sizeof(int));
		
		//tilesAt[i] = malloc(sizeof(tile));
		tilesAt[i].attributes = calloc(numAttr, sizeof(int));

		//printf("woop\n");
	
	}

	// note attr x1, x2 tends to give obviouslty and unobviously a great num matches, whereas x3 has may x2 but few x3 (as we expect)
	for (int j = 0; j < numAttr; j++) {
		
	
		for (int i = 0; i < numPairs; i++) {
			//printf("inner woopalogue\n");
			//tilesAt[i].attributes[j] = rand() % bound;
			//printf("sucessful woopment\n");
			
			int n = -1;
			int m = -1;
			do {
				n = rand() % (numPairs*2);
			} while (tilesAt[n].attributes[j] != 0);

			do { 
				m = rand() % (numPairs * 2);
			} while ((tilesAt[m].attributes[j] != 0) || (m == n));

			//printf("woop %d %d\n", n, m);

			int set = ((rand() % bound) + 1);

			tilesAt[n].attributes[j] = set;
			tilesAt[m].attributes[j] = set;
		}
		//printf("bump\n");
	}

	//printf("Printing.\n");

	for (int i = 0; i<numPairs * 2; i++) {
		printf("[");
		for (int j = 0; j < numAttr; j++) {
			printf("%d, ", tilesAt[i].attributes[j]);
		}
		printf("]");
		if (i % 5 == 4) {
			printf("\n");
		} else {
			printf(", ");
		}
	}

	//printf("woop out\n");

	for (int i = 0; i < numPairs * 2; i++) {
		//printf("%d\n", tilesAt[i]);
		
		free(tilesAt[i].attributes);
		//printf("attriwoop\n");
		//free(tilesAt[i]);
		//printf("tiliwoop\n");
	}

	//printf("deallowoop\n");
	printf("\n");
	free(tilesAt);	
}
