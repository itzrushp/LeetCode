class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long finishing_time = customers[0][0] + customers[0][1]; // when the first customer finishes
        long long total_waiting_time = finishing_time - customers[0][0]; // waiting time for the first customer

        for (int i = 1; i < customers.size(); i++) {
            int arrival_time = customers[i][0];
            if (arrival_time > finishing_time) {
                finishing_time = arrival_time; // if the new customer arrives after the last one has finished
            }
            finishing_time += customers[i][1]; // new finishing time after current customer is served
            total_waiting_time += (finishing_time - arrival_time); // waiting time for current customer
        }

        return (double)total_waiting_time / customers.size();
    }
};
