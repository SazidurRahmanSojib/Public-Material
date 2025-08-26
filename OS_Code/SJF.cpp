// 04. CPU scheduling algorithms: SJF 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int ct;    // Completion Time
    int tat;   // Turnaround Time (CT - AT)
    int wt;    // Waiting Time (TAT - BT)
    bool done; // Flag to check if process is finished
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
        p[i].done = false;
    }

    int completed = 0;
    int time = 0;
    vector<int> gantt_pid;
    vector<int> gantt_start, gantt_end;

    while (completed < n) {
        int idx = -1;
        int min_bt = 1e9;

        // Find the shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time) {
                if (p[i].bt < min_bt) {
                    min_bt = p[i].bt;
                    idx = i;
                } else if (p[i].bt == min_bt && p[i].at < p[idx].at) {
                    idx = i; // Tie-breaker: earlier arrival
                }
            }
        }

        if (idx != -1) {
            // Record Gantt slice
            gantt_start.push_back(time);
            gantt_pid.push_back(p[idx].pid);

            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].done = true;
            completed++;

            gantt_end.push_back(time);
        } else {
            time++; // CPU idle if no process arrived
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
