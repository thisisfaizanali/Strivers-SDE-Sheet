class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // O(n) time complexity
        // while loop n + for loop n = 2n
        //  Get the size of the input vector
        int n = nums.size();

        // Initialize the length of the longest consecutive sequence
        int longest = 1;

        // Create an unordered set to store the elements of the vector
        unordered_set<int> st;

        // Insert all elements of the vector into the set
        for (int i = 0; i < n; ++i)
        {
            st.insert(nums[i]);
        }

        // Iterate through each element in the set
        for (auto it : st)
        {
            // Check if the current element is the start of a sequence
            // (i.e., it - 1 is not in the set)
            if (st.find(it - 1) == st.end())
            {
                int count = 1; // Initialize count for the current sequence
                int x = it;    // Start the sequence from the current element

                // Check for consecutive elements in the sequence
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1; // Move to the next element in the sequence
                    count++;   // Increment the count of the sequence
                }

                // Update the longest sequence length if the current sequence is longer
                longest = max(longest, count);
            }
        }

        // Return the length of the longest consecutive sequence
        return longest;
    }
};
