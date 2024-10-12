# Line Sweeping Algorithms on Intervals in C++

Line sweeping algorithms are powerful techniques for solving various problems related to intervals efficiently. This document covers five common applications of line sweeping algorithms on intervals, along with C++ implementations and explanations.

## Table of Contents

1. [Interval Overlap Detection](#1-interval-overlap-detection)
2. [Merge Overlapping Intervals](#2-merge-overlapping-intervals)
3. [Calculate Total Covered Length](#3-calculate-total-covered-length)
4. [Find Maximum Overlap Point](#4-find-maximum-overlap-point)
5. [Interval Scheduling](#5-interval-scheduling)

## 1. Interval Overlap Detection

This algorithm determines if there's any overlap among a set of intervals.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int time;
    bool isStart;

    Event(int t, bool start) : time(t), isStart(start) {}
};

bool hasOverlap(const std::vector<std::pair<int, int>>& intervals) {
    std::vector<Event> events;
    for (const auto& interval : intervals) {
        events.emplace_back(interval.first, true);
        events.emplace_back(interval.second, false);
    }

    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.time < b.time || (a.time == b.time && a.isStart > b.isStart);
    });

    int count = 0;
    for (const auto& event : events) {
        if (event.isStart) {
            count++;
            if (count > 1) return true;
        } else {
            count--;
        }
    }
    return false;
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 4}, {5, 7}};
    std::cout << "Has overlap: " << (hasOverlap(intervals) ? "Yes" : "No") << std::endl;
    return 0;
}
```

### Explanation:

1. We define an `Event` struct to represent the start and end points of intervals.
2. The `hasOverlap` function takes a vector of intervals and returns true if there's any overlap.
3. We create a vector of events, sorting them by time (and prioritizing start events over end events when times are equal).
4. We then sweep through the events, incrementing a counter for start events and decrementing for end events.
5. If the counter ever exceeds 1, we've found an overlap and return true.

## 2. Merge Overlapping Intervals

This algorithm merges all overlapping intervals in a given set.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> mergeIntervals(std::vector<std::pair<int, int>>& intervals) {
    if (intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end());

    std::vector<std::pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= merged.back().second) {
            merged.back().second = std::max(merged.back().second, intervals[i].second);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto result = mergeIntervals(intervals);

    std::cout << "Merged intervals: ";
    for (const auto& interval : result) {
        std::cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation:

1. We sort the intervals based on their start times.
2. We iterate through the sorted intervals, merging overlapping ones.
3. If the current interval's start time is less than or equal to the end time of the last merged interval, we update the end time of the last merged interval.
4. Otherwise, we add the current interval to the merged list.

## 3. Calculate Total Covered Length

This algorithm calculates the total length covered by a set of intervals, taking overlaps into account.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int totalCoveredLength(const std::vector<std::pair<int, int>>& intervals) {
    std::vector<std::pair<int, bool>> events;
    for (const auto& interval : intervals) {
        events.emplace_back(interval.first, true);
        events.emplace_back(interval.second, false);
    }

    std::sort(events.begin(), events.end());

    int totalLength = 0;
    int count = 0;
    int lastTime = events[0].first;

    for (const auto& event : events) {
        if (count > 0) {
            totalLength += event.first - lastTime;
        }

        if (event.second) { // Start event
            count++;
        } else { // End event
            count--;
        }

        lastTime = event.first;
    }

    return totalLength;
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}};
    std::cout << "Total covered length: " << totalCoveredLength(intervals) << std::endl;
    return 0;
}
```

### Explanation:

1. We create a vector of events, marking the start and end points of each interval.
2. We sort these events by their time.
3. We sweep through the events, keeping track of the number of active intervals (count).
4. When count > 0, we add the difference between the current event time and the last event time to the total length.
5. We update the count and lastTime for each event.

## 4. Find Maximum Overlap Point

This algorithm finds the point where the maximum number of intervals overlap.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> findMaxOverlapPoint(const std::vector<std::pair<int, int>>& intervals) {
    std::vector<std::pair<int, int>> events;
    for (const auto& interval : intervals) {
        events.emplace_back(interval.first, 1);
        events.emplace_back(interval.second, -1);
    }

    std::sort(events.begin(), events.end());

    int maxOverlap = 0;
    int currentOverlap = 0;
    int maxOverlapPoint = -1;

    for (const auto& event : events) {
        currentOverlap += event.second;
        if (currentOverlap > maxOverlap) {
            maxOverlap = currentOverlap;
            maxOverlapPoint = event.first;
        }
    }

    return {maxOverlapPoint, maxOverlap};
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 4}, {3, 6}, {5, 7}};
    auto result = findMaxOverlapPoint(intervals);
    std::cout << "Maximum overlap point: " << result.first << " with " << result.second << " overlaps" << std::endl;
    return 0;
}
```

### Explanation:

1. We create a vector of events, using 1 for start events and -1 for end events.
2. We sort these events by their time.
3. We sweep through the events, updating the current overlap count.
4. We keep track of the maximum overlap and the point at which it occurs.
5. We return the point of maximum overlap and the number of overlaps at that point.

## 5. Interval Scheduling

This algorithm finds the maximum number of non-overlapping intervals.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> intervalScheduling(std::vector<std::pair<int, int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::vector<std::pair<int, int>> schedule;
    if (intervals.empty()) return schedule;

    schedule.push_back(intervals[0]);
    int lastEnd = intervals[0].second;

    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].first >= lastEnd) {
            schedule.push_back(intervals[i]);
            lastEnd = intervals[i].second;
        }
    }

    return schedule;
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}};
    auto schedule = intervalScheduling(intervals);

    std::cout << "Optimal schedule: ";
    for (const auto& interval : schedule) {
        std::cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation:

1. We sort the intervals based on their end times.
2. We start with the interval that ends earliest.
3. We iterate through the sorted intervals, adding an interval to the schedule if its start time is after or equal to the end time of the last scheduled interval.
4. This greedy approach gives us the maximum number of non-overlapping intervals.

These implementations demonstrate the power and versatility of line sweeping algorithms for interval-related problems. They efficiently handle various scenarios by sorting events and processing them in order, allowing for optimal solutions to complex problems.
