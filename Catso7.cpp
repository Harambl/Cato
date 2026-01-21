#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <cmath>

using std::min;
using std::vector;
using std::max;
using std::pair;
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;

map <string, pair<int, int>> buttons{ {"1", {1, 1}},  {"2", {1, 2}}, {"3", {1, 3}},
									  {"4", {2, 1}},  {"5", {2, 2}}, {"6", {2, 3}},
									  {"7", {3, 1}},  {"8", {3, 2}}, {"9", {3, 3}},
												      {"0", {4, 2}} };

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	in >> n;

	double count = 0;

	string lefthand = "4";
	string righthand = "6";

	vector<string> clicked;
	for (int i = 0; i < n; ++i) {
		string p = "";
		in >> p;
		clicked.push_back(p);
	}

	for (int j = 0; j < n; ++j) {
		if (lefthand == clicked[j] || righthand == clicked[j]) {}
		else {
			int x = buttons[clicked[j]].first;
			int y = buttons[clicked[j]].second;
			int a = buttons[lefthand].first;
			int b = buttons[lefthand].second;
			int t = buttons[righthand].first;
			int h = buttons[righthand].second;

			if (!(h - y < 0) || !(b - y > 0)) {
				double fromleft = sqrt(pow((x - a), 2) + pow((y - b), 2));
				double fromright = sqrt(pow((x - t), 2) + pow((y - h), 2));
				cout << fromleft << '\n' << fromright << '\n';
				if (fromright > fromleft) {
					count += fromleft;
					lefthand = clicked[j];
					cout << count << ' ' << "HUJ\n";
				}
				else if (fromright < fromleft) {
					count += fromright;
					righthand = clicked[j];
					cout << count << ' ' << "DFGFY\n";
				}
				else {
					count += fromright;
					righthand = clicked[j];
					cout << count << ' ' << "DFppppFY\n";
				}
			}
			else {
				cout << "Here" << '\n';
				if (h - y < 0) {
					double fromright = sqrt(pow((x - t), 2) + pow((y - h), 2));
					count += fromright;
					righthand = clicked[j];
					cout << fromright << '\n' << count << ' ' << "ooioioi\n";
				}
				else if (b - y > 0) {
					double fromleft = sqrt(pow((x - a), 2) + pow((y - b), 2));
					count += fromleft;
					lefthand = clicked[j];
					cout << fromleft << '\n' << count << ' ' << "j;;klkl\n";
				}
			}
		}
		
	}

	out << count;

	in.close();
	out.close();

   return 0;
}
