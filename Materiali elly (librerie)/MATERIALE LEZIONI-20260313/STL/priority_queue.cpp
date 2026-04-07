#include <iostream>
#include <string>
using namespace std;
#include <queue>

class Task
{
 public:
  Task(int _priority, string _task);
  bool operator<(const Task&) const; // per la classe priority_queue di STL e' necessario definire const sia il parametro sia il metodo
  int priority;
  string task;
};

// The constructor
Task::Task(int _priority, string _task) :
  priority(_priority),
  task(_task) {};

// The comparison function
bool Task::operator<(const Task& right) const
{
 return priority < right.priority;
}

int main()
{
 priority_queue<Task> prioQueue;
 prioQueue.push(Task(4, "Go to the cinema"));
 prioQueue.push(Task(9, "Solve the programming assignments"));
 prioQueue.push(Task(3, "Washing up"));
 while (!prioQueue.empty())
 {
  cout << prioQueue.top().task << endl;
  prioQueue.pop();
 }
}
