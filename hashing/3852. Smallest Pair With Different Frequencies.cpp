/*
 * Problem: 3852. Smallest Pair With Different Frequencies
 * Topic: Hashing
 * Difficulty: Easy
 * Approach: Frequency Map + Sorting
 *
 * Intuition:
 * Count frequency of each number, then find the two smallest distinct
 * numbers that have different frequencies.
 *
 * Approach:
 * - Build a frequency map of all numbers
 * - Extract unique numbers and sort them
 * - Fix the smallest number (index 0) and scan for the next number
 *   with a different frequency
 * - Return the pair, or {-1, -1} if none exists
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> unique;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto& p : freq) {
            unique.push_back(p.first);
        }

        sort(unique.begin(), unique.end());

        int k = unique.size();
        int i = 0;

        for (int j = i + 1; j < k; j++) {
            int x = unique[i];
            int y = unique[j];
            if (freq[x] != freq[y]) {
                return {x, y};
            }
        }

        return {-1, -1};
    }
};