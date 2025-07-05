/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// For interviews : avoid this method, this is for CP and Leetcode :
// GFG accepts the storing subsequences in queue (BFS) method
// and that is also enough for interviews.
// But I understand this method better and this is easier to codeo for me

class Solution
{
    // Map to store the minimum steps required to reach each word from the beginWord
    unordered_map<string, int> mpp;
    // To store the final result: all shortest transformation sequences
    vector<vector<string>> ans;
    // To hold the beginWord for use in the DFS base case
    string b;

private:
    void dfs(string word, vector<string> &seq)
    {
        // Base case: if we've reached the beginWord
        if (word == b)
        {
            // Reverse the sequence to get correct order from beginWord to endWord
            reverse(seq.begin(), seq.end());
            // Add the current valid sequence to the answer
            ans.push_back(seq);
            // Re-reverse for backtracking
            reverse(seq.begin(), seq.end());
            return;
        }

        // Get the number of steps it took to reach current word
        int steps = mpp[word];

        // Try changing each character in the word
        for (int i = 0; i < word.size(); ++i)
        {
            char original = word[i]; // Store original character

            // Try replacing with every character from 'a' to 'z'
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                word[i] = ch; // Modify the character

                // Check if the transformed word exists and is one level before current word
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1)
                {
                    seq.push_back(word); // Include word in current path
                    dfs(word, seq);      // Recurse
                    seq.pop_back();      // Backtrack
                }

                word[i] = original; // Restore original character after inner loop
            }
        }
    }

public:
    // Step 1 : Do Word Ladder 1 (but use map for steps) and find out the shortest paths
    // Step 2 : Do dfs from last endWord and try to change and find each word in map
    // and if its one step below the current level :

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        b = beginWord; // Store beginWord for DFS reference

        // Create a set for fast lookup of valid words
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Queue for BFS traversal
        queue<string> q;
        q.push(beginWord);   // Start BFS from beginWord
        mpp[beginWord] = 1;  // Mark beginWord with level 1 (step count)
        st.erase(beginWord); // Remove beginWord from set to avoid revisiting

        int size = beginWord.size(); // Get the word length for character replacement

        while (!q.empty())
        {
            string word = q.front(); // Get the front word
            int steps = mpp[word];   // Get current level
            q.pop();                 // Remove from queue

            // If we've reached the endWord, stop BFS
            if (word == endWord)
                break;

            // Try changing each character in the word
            for (int i = 0; i < size; ++i)
            {
                char original = word[i]; // Store original character

                // Try all characters from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    word[i] = ch; // Change character

                    // If new word exists in the set (i.e., is valid and unvisited)
                    if (st.find(word) != st.end())
                    {
                        q.push(word);          // Add to BFS queue
                        st.erase(word);        // Mark as visited
                        mpp[word] = steps + 1; // Set level of new word
                    }
                }

                word[i] = original; // Restore original character after inner loop
            }
        }

        // If endWord is found (i.e., exists in the map)
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord); // Start path from endWord
            dfs(endWord, seq);      // Backtrack to beginWord using DFS
        }

        return ans;
    }
};