/*
 * Problem: Minimum Index
 * Topic: Arrays
 * Difficulty: Easy
 * Approach: Linear Search
 *
 * Intuition:
 * Iterate through the capacity array and find the container that fits
 * the item (capacity >= itemSize) with the smallest capacity (best fit).
 *
 * Approach:
 * - Loop through all containers
 * - If container fits the item AND is smaller than current best fit, update
 * - Track the index of the best fit container
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int fit = INT_MAX;
        int n = capacity.size();
        int index = -1; 
        for(int i = 0; i < n; i++){
            if(itemSize <= capacity[i]){
                if(capacity[i] < fit){
                    fit = capacity[i];
                    index = i;
                }
            }
        }
        return index;
    }
};