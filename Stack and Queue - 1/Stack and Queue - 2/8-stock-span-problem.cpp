/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class StockSpanner
{
    stack<pair<int, int>> st;
    // push value of element and span value
public:
    StockSpanner()
    {
    }
    int next(int price)
    {
        // read the question many times : pge concept
        int span = 1; // for including the current element
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second; //(add the spans)
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */