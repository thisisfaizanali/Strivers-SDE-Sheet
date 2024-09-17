#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // stores current weight of the knapsack
        double currentWeight = static_cast<double>(w);
        // if we want max value in the knapsack
        // we should sort according to
        // descending values of ratios of value/weight
        sort(arr, arr + n, [](Item a, Item b)
             { return (double)a.value / a.weight > (double)b.value / b.weight; });
        // kam weight mein zyaada maal xD hona chahiye na bro
        double maxValue = 0;
        // this will be the ans
        for (int i = 0; i < n; ++i)
        {
            if (currentWeight < arr[i].weight)
            {
                maxValue += ((double)arr[i].value / arr[i].weight) * currentWeight;
                break;
                // since we have reached the end
                // as we are taking fraction, we need to break out
            }
            else
            {
                maxValue += arr[i].value;
                currentWeight -= arr[i].weight;
            }
        }
        return maxValue;
    }
};