#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool byDate(const string& lhs, const string& rhs)
{
	string left{ lhs,2,10 };
	string right{ rhs,2,10 };
	return left < right;
}

int main()
{
	ifstream from("input.txt");

	if (!from.is_open())
		return 0;

	string line;
	vector<string> inputArray;

	while (!from.eof())
	{
		getline(from, line);
		inputArray.push_back(line);
	}

	sort(inputArray.begin(), inputArray.end(), byDate);

	ofstream to("output.txt");

	for (const auto& i : inputArray)
		to << i << endl;

	cin.get();
	return 0;
}