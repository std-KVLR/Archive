#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>


using namespace std;

double median_search(const vector<double> &dv)
{
	size_t i = dv.size() / 2;
	double temp = dv[i];
	if(temp != dv[i - 1]) return temp;
	while(i != dv.size()) {
		if(dv[i] != temp) return dv[i];
		++i;
	}
	cerr << "Median in undefined";
	throw(-1);
		
}
int main()
{
    vector<double> dv;
    double temp;

	while(cin >> temp)dv.push_back(temp);
	sort(dv.begin(), dv.end());
	for(const auto &i : dv) cout << i << ' ';
	cout << "\nMedian is " << median_search(dv);
	return 0;
}
	
	