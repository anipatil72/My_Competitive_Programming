#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Service
{
    int time;  // Time when the service will be free
    int index; // Service index
};

// Comparator to prioritize the earlier available service
struct Compare
{
    bool operator()(Service const &s1, Service const &s2)
    {
        return s1.time > s2.time;
    }
};

int getMinTime(int n, vector<int> &cache)
{
    // Priority queue to manage services based on their availability time
    priority_queue<Service, vector<Service>, Compare> pq;

    // Initialize the priority queue with all services starting at time 0
    for (int i = 1; i <= n; ++i)
    {
        pq.push({0, i});
    }

    int currentTime = 0;

    for (int req : cache)
    {
        Service currService = pq.top();
        pq.pop();

        // If the service processing the request is the same as the cached service
        if (currService.index == req)
        {
            // Cache hit, process in 1 unit time
            currService.time += 1;
        }
        else
        {
            // Cache miss, process in 2 units time
            currService.time += 2;
        }

        // Update the current time to the maximum of itself or the service's time
        currentTime = max(currentTime, currService.time);

        // Push the updated service back into the priority queue
        pq.push(currService);
    }

    return currentTime;
}

int main()
{
    // Example test cases
    int n1 = 4;
    vector<int> cache1 = {1, 2, 3, 4};
    cout << "Minimum time to process all requests: " << getMinTime(n1, cache1) << endl;

    int n2 = 3;
    vector<int> cache2 = {1, 1, 3, 1, 1};
    cout << "Minimum time to process all requests: " << getMinTime(n2, cache2) << endl;

    return 0;
}
