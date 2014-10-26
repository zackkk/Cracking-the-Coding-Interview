/* You have a large text file containing words. 
   Given any two words, find the shortest distance (in terms of number of words) between them in the file. 
   Can you make the searching operation in O(1) time? What about the space complexity for your solution? */

// adjacency matrix stores all its locations
// for each location of word 1, use binary search to find the min diff in word 2