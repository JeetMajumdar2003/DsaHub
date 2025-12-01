#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// Maximize profit by scheduling jobs(Min Heap)
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    // S-1: Create a job list of type {start, end, profit}
    vector<vector<int>> jobs;
    for(int i=0; i<startTime.size(); i++){
        jobs.push_back({startTime[i], endTime[i], profit[i]});
    }

    // S-2: Sort the jobs based on their start time
    sort(jobs.begin(), jobs.end()); // Sort based on start time, [1, 3, 2, 3] -> [1, 2, 3, 3]
    // cout<<"Jobs: "<<endl;
    // for(auto job: jobs){
    //     cout<<job[0]<<" "<<job[1]<<" "<<job[2]<<endl;
    // }

    // S-3: Create a Min Heap to track the jobs based on their endTime and cumulativeProfit
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int maxProfit = 0;
    int start, end, currProfit;
    for(int i=0; i<jobs.size(); i++){
        start = jobs[i][0];
        end = jobs[i][1];
        currProfit = jobs[i][2];

        // Remove the jobs from the heap which are already ended before the current job starts
        while(!pq.empty() && pq.top()[0] <= start){
            maxProfit = max(maxProfit, pq.top()[1]);
            pq.pop();
        }

        // Add the current job to the heap
        pq.push({end, maxProfit + currProfit});
        // cout<<"End: "<<end<<" MaxProfit: "<<maxProfit + currProfit<<endl;
    }

    // S-4: Return the maxProfit
    while(!pq.empty()){
        maxProfit = max(maxProfit, pq.top()[1]);
        pq.pop();
    }

    return maxProfit;
}

int main(){
    vector<int> startTime = {1, 3, 2, 3};
    vector<int> endTime = {3, 5, 4, 6};
    vector<int> profit = {50, 40, 10, 70};

    cout<<jobScheduling(startTime, endTime, profit)<<endl;
    return 0;
}

/*
startTime = [1, 2, 3, 3], 
endTime   = [3, 4, 5, 6],
profit    = [50, 10, 40, 70]
*/