#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], tat[n]; // burst time, waiting time, turnaround time
    float avgWT = 0, avgTAT = 0;

    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // FCFS Scheduling
    wt[0] = 0; // first process has zero waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // waiting time = sum of previous burst times
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i]; // turnaround = waiting + burst
    }

    // Calculate averages
    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Output
    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << avgWT;
    cout << "\nAverage Turnaround Time = " << avgTAT << endl;

    return 0;
}
