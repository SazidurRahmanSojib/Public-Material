#include <iostream>
#include <vector>

using namespace std;

// Function to find a safe sequence
bool isSafe(int n, int m, const vector<int>& available, const vector<vector<int>>& max, const vector<vector<int>>& allocation) {
    // Calculate the need matrix
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    vector<int> work = available;
    vector<bool> finish(n, false);
    vector<int> safe_sequence;
    int count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_run = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_run = false;
                        break;
                    }
                }

                if (can_run) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            cout << "System is in an unsafe state. A safe sequence cannot be found." << endl;
            return false;
        }
    }

    cout << "System is in a safe state." << endl;
    cout << "Safe Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << "P" << safe_sequence[i] << (i == n - 1 ? "" : " -> ");
    }
    cout << endl;

    return true;
}

int main() {
    int n, m;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resource types: ";
    cin >> m;

    vector<int> available(m);
    cout << "Enter the available resources: ";
    for (int i = 0; i < m; i++) {
        cin >> available[i];
    }

    vector<vector<int>> max(n, vector<int>(m));
    cout << "Enter the maximum resources for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    vector<vector<int>> allocation(n, vector<int>(m));
    cout << "Enter the allocated resources for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    isSafe(n, m, available, max, allocation);

    return 0;
}