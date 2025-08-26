// 03. CPU scheduling algorithms: Preemptive Priority

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int pid;            // Process ID
    int at;             // Arrival Time
    int bt;             // Burst Time
    int bt_remaining;   // Remaining Burst Time (for preemption)
    int pr;             // Priority (lower value = higher priority)
    int ct;             // Completion Time
    int tat;            // Turnaround Time (CT - AT)
    int wt;             // Waiting Time (TAT - BT)
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input process details
    cout << "Enter Arrival Time, Burst Time, and Priority for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << " (AT BT PR): ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].bt_remaining = p[i].bt;
        p[i].ct = p[i].tat = p[i].wt = 0;
    }

    int completed = 0;        // Number of completed processes
    int time = 0;             // Current time
    int last_pid = -1;        // Last process in CPU
    vector<int> gantt_start;  // Start times for Gantt slices
    vector<int> gantt_end;    // End times for Gantt slices
    vector<int> gantt_pid;    // Process IDs for Gantt slices

    // Simulation loop
    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        // Select process with highest priority among arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].bt_remaining > 0) {
                if (p[i].pr < highest_priority) {
                    highest_priority = p[i].pr;
                    idx = i;
                } else if (p[i].pr == highest_priority && p[i].at < p[idx].at) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Process change: new slice
            if (last_pid != idx) {
                gantt_start.push_back(time);
                gantt_pid.push_back(idx + 1);
                last_pid = idx;
            }

            p[idx].bt_remaining--;
            time++;

            // Update end time for current slice
            if (gantt_end.size() < gantt_start.size()) {
                gantt_end.push_back(time);
            } else {
                gantt_end.back() = time;
            }

            // Process finished
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

    // Print time markers
    for (int i = 0; i < gantt_start.size(); i++) {
        cout << gantt_start[i] << "    ";
    }
    cout << gantt_end.back() << "\n";

    // Print process table
    float avgWT = 0, avgTAT = 0;
    cout << "\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t"
             << p[i].pr << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n << endl;

    return 0;
}
