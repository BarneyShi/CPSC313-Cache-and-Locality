#include <stdio.h>
#include "life.h"

// You are only allowed to change the contents of this file with respect 
// to improving the performance of this program



// If you need to initialize some data structures for your implementation
// of life then make changes to the following function, otherwise 
// do not change this function.

void initLife() {
}



// When completed this file will contain several versions of the life() function. Each 
// version will be surrounded with  and ifdef, undef, and endif as illustrated below. Put 
// a #define USE immediately infront of the version of the life() function you want to use.
// Your version of life() must produce a correct result. 

// You are required to document the changes you make in the README.txt file. For each entry
// in the README.txt file there is to be a version of the matching  life() function here such
// that the markers can see, and run if needed,  the actual code that you used 
// to produce your results for the logged change to the life function.  


#ifdef USE
int life(long oldWorld[N][N], long newWorld[N][N]) {
  return 0;
}
#undef USE
#endif


#ifdef USE

#define this is the starting point

int life(long oldWorld[N][N], long newWorld[N][N]) {

  int i, j, k, l;
  
  //clear the new world
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] =  0;
    }

  int col, row;
  int q = -1;


  // Count the cells to the top left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }
  
  // Count the cells immediately above
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j - 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the top right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j - 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

 // Count the cells to the immediate left
  for (i = 0; i < N; i++) {
    col = (i -1 + N) % N;
    for (j = 0; j < N; j++) {
       newWorld[j][i] += oldWorld[j][col];
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      newWorld[j][i] += oldWorld[j][col];
    }
  }

// Count the cells to the bottom left
  for (i = 0; i < N; i++) {
    col = (i - 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1 + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Count the cells immediately below
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][i];
    }
  }

  // Count the cells to the bottom right
  for (i = 0; i < N; i++) {
    col = (i + 1 + N) % N;
    for (j = 0; j < N; j++) {
      row = (j + 1  + N ) % N;
      newWorld[j][i] += oldWorld[row][col];
    }
  }

  // Check each cell to see if it should come to life, continue to live, or die
  int alive = 0;
  
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      newWorld[j][i] = checkHealth(newWorld[j][i], oldWorld[j][i]);
      alive += newWorld[j][i] ? 1:0;
    }

  return alive;
}
#undef USE
#endif


#define USE
#ifdef USE

#define this is final change

int life(long oldWorld[N][N], long newWorld[N][N]) {
	
	int F = N;
	int j;
	int i = 0;

	

	//clear the new world
	for (i; i < F; ++i)
		for (j = 0; j < F; ++j) {
			newWorld[i][j] = 0;
		}

		int col, row, colplus, rowplus;
		
		i = 0;
		row = F - 1;
		
		for (j = 0; j < F; ++j) {	
			col = (j - 1 + F) % F;
			newWorld[i][j] += oldWorld[row][col] + oldWorld[row][j] + oldWorld[1][col] + oldWorld[1][j] + oldWorld[i][col];
		// commented out, put all on one line
		// newWorld[i][j] += oldWorld[row][j];
		// newWorld[i][j] += oldWorld[1][col];			
		// newWorld[i][j] += oldWorld[1][j];
		// newWorld[i][j] += oldWorld[i][col];
		}
		
		// Count the cells to the top left
		for (i = 1; i < F; ++i) {
			row = i-1;
			col = F-1;
			rowplus = (i + 1 + F) % F;
			newWorld[i][0] += oldWorld[row][col] + oldWorld[row][0] + oldWorld[rowplus][col] + oldWorld[rowplus][0] + oldWorld[i][col];
		// same applies here
		// newWorld[i][0] += oldWorld[row][0];
		// newWorld[i][0] += oldWorld[rowplus][col];
		// newWorld[i][0] += oldWorld[rowplus][0];
		// newWorld[i][0] += oldWorld[i][col];
		
		for (j = 1; j < F; ++j) {
			col = j-1;
			newWorld[i][j] += oldWorld[row][col] + oldWorld[row][j] + oldWorld[rowplus][col] + oldWorld[rowplus][j] + oldWorld[i][col];
			// newWorld[i][j] += oldWorld[row][j];
			// newWorld[i][j] += oldWorld[rowplus][col];
			// newWorld[i][j] += oldWorld[rowplus][j];
			// newWorld[i][j] += oldWorld[i][col];	
		}
	}

		for (i = 0; i < F; ++i) {
			row = (i - 1 + F) % F;
			rowplus = (i + 1 + F) % F;
			colplus = (0 + 1 + F) % F;
			newWorld[i][0] += oldWorld[row][colplus] + oldWorld[i][colplus] + oldWorld[rowplus][colplus];
    	// newWorld[i][0] += oldWorld[i][colplus];
    	// newWorld[i][0] += oldWorld[rowplus][colplus];
		
		for (j = 1; j < F-1; j++) {
			colplus = j+1;
			newWorld[i][j] += oldWorld[row][colplus] + oldWorld[i][colplus] + oldWorld[rowplus][colplus];
			// newWorld[i][j] += oldWorld[i][colplus];
			// newWorld[i][j] += oldWorld[rowplus][colplus];
		}
		
        newWorld[i][F-1] += oldWorld[row][0] + oldWorld[i][0] + oldWorld[rowplus][0];
        // newWorld[i][F-1] += oldWorld[i][0];
        // newWorld[i][F-1] += oldWorld[rowplus][0];
	}

	// Check each cell to see if it should come to life, continue to live, or die
	int alive = 0;
	for (i = 0; i < F; ++i) {
		for (j = 0; j < F; ++j) {
			newWorld[i][j] = checkHealth(newWorld[i][j], oldWorld[i][j]);
			alive += newWorld[i][j] ? 1 : 0;
		}
	}

	return alive;
}
#undef USE
#endif

