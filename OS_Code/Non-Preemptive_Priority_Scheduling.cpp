#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int pr;    // Priority (smaller number = higher priority)
    int ct;    // Completion Time
    int tat;   // Turnaround Time
    int wt;    // Waiting Time
    bool done; // Finished or not
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    cout << "Enter Arrival Time, Burst Time, and Priority for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << " (AT BT PR): ";
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        p[i].done = false;
    }

    int time = 0, completed = 0;
    vector<pair<int,int>> gantt; // (completion time, pid)

    while (completed < n) {
        int idx = -1;
        int bestPr = 1e9;

        // Find process with highest priority (lowest PR value) that has arrived
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time) {
                if (p[i].pr < bestPr) {
                    bestPr = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == bestPr) {
                    // If same priority, pick lower arrival time
                    if (p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1) {
            time++; // No process has arrived yet
        } else {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].done = true;
            completed++;
            gantt.push_back({time, p[idx].pid});
        }
    }

    // Print Gantt Chart
    cout << "\n--- Gantt Chart ---\n";
    for (auto &g : gantt) {
        cout << "| P" << g.second << " ";
    }
    cout << "|\n";

    cout << "0";
    for (auto &g : gantt) {
        cout << "    " << g.first;
    }
    cout << "\n";

    // Print Table
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
