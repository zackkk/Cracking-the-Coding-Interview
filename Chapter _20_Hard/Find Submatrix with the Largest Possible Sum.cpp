/* Given an NxN matrix of positive and negative integers, 
   write code to find the sub-matrix with the largest possible sum. */

/* brute-force O(n^6): 
		find left-top corner: O(n^2)
		find right-bottom corner: O(n^2)
		compute area: O(n^2) */

// improve: precompute the area matrix -> O(n^4)
// sumMatrix[i][j] = sumMatrix[i - 1][j] + sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1] + matrix[i][j];