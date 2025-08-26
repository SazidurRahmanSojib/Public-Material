// 05. Shortest Remaining Time First (SRTF)


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int pid;            // Process ID
    int at;             // Arrival Time
    int bt;             // Burst Time
    int bt_remaining;   // Remaining Burst Time (for preemption)
    int ct;             // Completion Time
    int tat;            // Turnaround Time
    int wt;             // Waiting Time
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << " (AT BT): ";
        cin >> p[i].at >> p[i].bt;
        p[i].bt_remaining = p[i].bt;
        p[i].ct = p[i].tat = p[i].wt = 0;
    }

    int completed = 0;
    int time = 0;
    int last_pid = -1;
    vector<int> gantt_start, gantt_end, gantt_pid;

    while (completed < n) {
        int idx = -1;
        int min_bt = INT_MAX;

        // Find process with shortest remaining time among arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].bt_remaining > 0) {
                if (p[i].bt_remaining < min_bt) {
                    min_bt = p[i].bt_remaining;
                    idx = i;
                } else if (p[i].bt_remaining == min_bt && p[i].at < p[idx].at) {
                    idx = i; // Tie-breaker: earlier arrival
                }
            }
        }

        if (idx != -1) {
            // Process change: new slice in Gantt Chart
            if (last_pid != idx) {
                gantt_start.push_back(time);
                gantt_pid.push_back(p[idx].pid);
                last_pid = idx;
            }

            p[idx].bt_remaining--;
            time++;

            // Update end time of current slice
            if (gantt_end.size() < gantt_start.size()) {
                gantt_end.push_back(time);
            } else {
                gantt_end.back() = time;
            }

            if (p[idx].bt_remaining == 0) {
                completed++;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        } else {
            // CPU idle
            time++;
        }
    }

    // Print Gantt Chart
    cout << "\n--- Gantt Chart ---\n";
    for (int i = 0; i < gantt_pid.size(); i++) {
        cout << "| P" << gantt_pid[i] << " ";
    }
    cout << "|\n";

    // Print exact time markers
    for (int i = 0; i < gantt_start.size(); i++) {
        cout << gantt_start[i] << "    ";
    }
    cout << gantt_end.back() << "\n";

    // Print Process Table
    float avgWT = 0, avgTAT = 0;
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n << endl;

    return 0;
}
