#include <iostream>
using namespace std;
#include <queue>

int main()
{
 queue<int> myQueue;
 myQueue.push(1);
 myQueue.push(7);
 myQueue.push(4);
 cout << myQueue.size() << endl;
 while (!myQueue.empty())
 {
  cout << myQueue.front() << endl;
  myQueue.pop();
 }
}