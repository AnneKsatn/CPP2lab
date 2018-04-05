#include<iostream>
#include"StatisticMultiset.h"


using namespace std;
int main(int argc, char *argv[]) {

	cout << "Lab 02" << endl;

	StatisticMultiset<int>  ms1;

	ms1.AddNum(89);
	ms1.AddNum(54);
	ms1.AddNum(54);
	ms1.AddNum(24);

	StatisticMultiset<int> ms2;
	std::vector<int> somedata = { 10, 40, 6, 87 };
	ms2.AddNum(somedata);

	StatisticMultiset<int>  ms3;
	ms3.AddNums(ms1);
	ms3.AddNums(ms2);

	cout << " Min: " << ms3.GetMin() << " Avg: " << ms3.GetAvg()
		<< " Max: " << ms3.GetMax() << endl;
	system("pause");
	return 0;
}
