/*++++++++++++++++++++++++++++++++++++++++++++++++++++++ Bismillah +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// leetcode version :
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // queue for BFS : {word, steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start with the beginWord at level 1

        // Use an unordered_set for fast lookup of words in the wordList and for marking visit :
        unordered_set<string> st(wordList.begin(), wordList.end());
        // When we encounter a word during BFS and push it into the queue, we immediately erase it from the set.
        // This acts as marking it "visited" — it ensures we don’t revisit the same word again from another path,
        st.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we reach the endWord, return the number of steps
            if (word == endWord)
                return steps;

            // Try changing each character of the current word to all letters 'a' to 'z'
            for (int i = 0; i < word.size(); ++i)
            {
                // Store the original character so we can restore it later
                char original = word[i];

                // Replace the character with all possible lowercase letters
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    word[i] = ch;

                    // If the new word exists in the set, it's a valid transformation
                    if (st.find(word) != st.end())
                    {
                        // Remove it from the set to mark it as visited
                        st.erase(word);
                        // Push the new word along with incremented steps into the queue
                        q.push({word, steps + 1});
                    }
                }

                // Restore the original character before moving to the next position
                word[i] = original;
            }
        }

        // If we exhaust the queue and never find the endWord, return 0
        return 0;
    }
};

// GFG version :
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
        // queue for BFS : {word, steps}
        queue<pair<string, int>> q;
        q.push({startWord, 1}); // Start with the startWord at level 1

        // Use an unordered_set for fast lookup of words in the wordList and for  marking visit :
        unordered_set<string> st(wordList.begin(), wordList.end());
        // When we encounter a word during BFS and push it into the queue, we immediately erase it from the set.
        // This acts as marking it "visited" — it ensures we don’t revisit the same word again from another path,
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we reach the target word, return the number of steps
            if (word == targetWord)
                return steps;

            // Try changing each character of the current word to all letters 'a' to 'z'
            for (int i = 0; i < word.size(); ++i)
            {
                // Store the original character so we can restore it later
                char original = word[i];

                // Replace the character with all possible lowercase letters
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    word[i] = ch;

                    // If the new word exists in the set, it's a valid transformation
                    if (st.find(word) != st.end())
                    {
                        // Remove it from the set to mark it as visited
                        st.erase(word);
                        // Push the new word along with incremented steps into the queue
                        q.push({word, steps + 1});
                    }
                }

                // Restore the original character before moving to the next position
                word[i] = original;
            }
        }

        // If we exhaust the queue and never find the target word, return 0
        return 0;
    }
};