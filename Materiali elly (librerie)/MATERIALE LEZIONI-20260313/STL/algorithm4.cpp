#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::vector <std::string> projects;
	for (int i = 1; i < argc; ++i)
		projects.push_back(std::string(argv[i]));
	std::vector<std::string>::iterator j =
		std::find(projects.begin(), projects.end(), std::string("Lab8"));
	if (j == projects.end()) cout << "Lab8 not found" << endl;
	else cout << "Lab8 found" << endl;
	return 0;
}