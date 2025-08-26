// 01. First Come First Serve (FCFS) CPU Scheduling

#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int ct;    // Completion Time
    int tat;   // Turnaround Time
    int wt;    // Waiting Time
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
    }

    // Sort by Arrival Time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                swap(p[i], p[j]);
            }
        }
    }

    int time = 0;
    vector<pair<int,int>> gantt; // (completion time, process_id)

    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at; // CPU idle if process hasn't arrived
        }
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        gantt.push_back({time, p[i].pid});
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
