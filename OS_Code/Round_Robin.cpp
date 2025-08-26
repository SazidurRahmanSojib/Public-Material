// 06. Round Robin

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Process {
    int pid;            // Process ID
    int at;             // Arrival Time
    int bt;             // Burst Time
    int bt_remaining;   // Remaining Burst Time
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

    int tq;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0;
    queue<int> q;               // Queue for Round Robin
    vector<bool> in_queue(n, false);
    vector<int> gantt_pid;      // Gantt Chart
    vector<int> gantt_start;    
    vector<int> gantt_end;

    // Initially add processes that have arrived at time 0
    for (int i = 0; i < n; i++) {
        if (p[i].at <= time) {
            q.push(i);
            in_queue[i] = true;
        }
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        // Record start of execution in Gantt chart
        gantt_start.push_back(time);
        gantt_pid.push_back(p[idx].pid);

        int exec_time = min(tq, p[idx].bt_remaining);
        p[idx].bt_remaining -= exec_time;
        time += exec_time;

        gantt_end.push_back(time);

        // Add newly arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (!in_queue[i] && p[i].at <= time) {
                q.push(i);
                in_queue[i] = true;
            }
        }

        // If process is not finished, add back to queue
        if (p[idx].bt_remaining > 0) {
            q.push(idx);
        } else {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }

        // If queue is empty but there are processes left, move time to next arrival
        if (q.empty()) {
            for (int i = 0; i < n; i++) {
                if (p[i].bt_remaining > 0) {
                    time = p[i].at;
                    q.push(i);
                    in_queue[i] = true;
                    break;
                }
            }
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
