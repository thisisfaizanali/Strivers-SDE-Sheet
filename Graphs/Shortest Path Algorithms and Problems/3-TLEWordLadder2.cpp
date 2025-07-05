/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// GFG version will accept this method but not Leetcode : (TLE) :
// In interviews use this method : most apt
// BFS + DFS (optimal) is for CP so avoid that in interviews
// And I don't like coding this :

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        // Convert the word list into a set for O(1) lookups
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Queue to store the paths (each path is a sequence from beginWord to current word)
        queue<vector<string>> q;
        q.push({beginWord}); // Initialize with path containing only the beginWord

        // Final result storing all shortest transformation sequences
        vector<vector<string>> ans;

        // To store words used at the current level (to remove from word list after the level ends)
        unordered_set<string> usedOnLevel;

        int level = 1;          // Current BFS level (depth)
        int minLevel = INT_MAX; // Minimum level at which endWord is found

        while (!q.empty())
        {
            vector<string> path = q.front(); // Get current path
            q.pop();

            // If we reach a new level, remove all words used in the previous level from the word set
            if (path.size() > level)
            {
                for (auto &word : usedOnLevel)
                    st.erase(word); // Avoid revisiting words in future levels

                usedOnLevel.clear(); // Reset for new level
                level = path.size();

                // Early stopping: if we already found the shortest path, no need to go deeper
                if (level > minLevel)
                    break;
            }

            // Get the last word of the current path
            string lastWord = path.back();

            // If we've reached the endWord
            if (lastWord == endWord)
            {
                minLevel = level;    // Record the level
                ans.push_back(path); // Store the current path as a valid answer
            }

            // Try changing each character in the lastWord
            for (int i = 0; i < lastWord.size(); ++i)
            {
                string temp = lastWord;

                // Replace character with 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    temp[i] = ch;

                    // If transformed word exists in the set (unvisited and valid)
                    if (st.find(temp) != st.end())
                    {
                        // Create a new path including this transformed word
                        vector<string> newPath = path;
                        newPath.push_back(temp);

                        q.push(newPath);          // Push the new path into the queue
                        usedOnLevel.insert(temp); // Mark this word as used on this level
                    }
                }
            }
        }

        return ans; // Return all shortest transformation sequences
    }
};
