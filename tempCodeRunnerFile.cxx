#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process
{
  int id, arrival_time, burst_time, priority, wait_time = 0, turnaround_time = 0;
};

void priority_scheduling(vector<Process> &processes)
{
  sort(processes.begin(), processes.end(), [](const auto &a, const auto &b)
       { return a.priority > b.priority; });

  int current_time = 0;
  for (auto &p : processes)
  {
    p.wait_time = current_time - p.arrival_time;
    p.turnaround_time = p.wait_time + p.burst_time;
    current_time += p.burst_time;
  }
}

void print_results(const vector<Process> &processes)
{
  cout << "Process | Burst Time | Completion Time | Wait Time | Turnaround Time\n";
  for (const auto &p : processes)
  {
    cout << "   " << p.id << "    |     " << p.burst_time
         << "      |        " << p.burst_time + p.wait_time
         << "        |    " << p.wait_time << "     |        " << p.turnaround_time << "\n";
  }

  double avg_wait_time = 0.0, avg_turnaround_time = 0.0;
  for (const auto &p : processes)
  {
    avg_wait_time += p.wait_time;
    avg_turnaround_time += p.turnaround_time;
  }
  avg_wait_time /= processes.size();
  avg_turnaround_time /= processes.size();
  cout << "\nAverage Wait Time: " << avg_wait_time << "\n";
  cout << "Average Turnaround Time: " << avg_turnaround_time << "\n";
}

int main()
{
  vector<Process> processes = {
      {1, 0, 6, 3},
      {2, 0, 8, 2},
      {3, 0, 7, 1},
      {4, 0, 3, 4},
      {5, 0, 4, 5},
  };

  priority_scheduling(processes);
  print_results(processes);

  return 0;
}
