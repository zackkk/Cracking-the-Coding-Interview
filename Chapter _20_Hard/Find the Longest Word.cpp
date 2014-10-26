/* Write a program to find the longest word made of other words. */

/*
The solution below does the following:
1. Sort the array by size, putting the longest word at the front
2. For each word, split it in all possible ways. That is, for “test”, split it into {“t”, “est”}, {“te”, “st”} and {“tes”, “t”}.
3. Then, for each pairing, check if the first half and the second both exist elsewhere in the array.
4. “Short circuit” by returning the first string we find that fits condition #3.
*/

// it assumed that we can only split the word into two parts.