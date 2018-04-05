#pragma once

#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>


template<typename T>
class StatisticMultiset {

private:
	double sum;
	std::multiset<T> myset;
public:

	void AddNum(T num) {
		myset.insert(num);
		sum += num;
	}

	void AddNum(const std::multiset<T>& numbers) {
		for (auto& it : numbers) {
			AddNum(it);
		}
	};

	void AddNum(const std::vector<T>& numbers) {
		for (auto& it : numbers) {
			AddNum(it);
		}
	};

	void AddNum(const std::list<T>& numbers) {
		for (auto& it : numbers) {
			AddNum(it);
		}
	};

	void AddNumsFromFile(const char& filename) {
		std::ifstream fin(filename);
		int x;
		while (!fin.eof()) {
			fin >> x;
			myset.insert(x);
		}
		fin.close();
	};

	void AddNums(const StatisticMultiset& a_stat_set) {
		for (auto& it : a_stat_set.myset) {
			AddNum(it);
		}
	}


	int GetMax() const {
		int x = *(--myset.end());
		return x;
	}

	int GetMin() const {
		return *myset.begin();
	}

	double GetAvg() const {
		static double avg;
		static double call_avg;
		if (call_avg == sum) {
			return avg;
		}
		int x = myset.size();
		avg = sum / x;
		call_avg = sum;
		return  avg;
	}

	int GetCountUnder(float threshold) const {
		std::multiset<T>::const_iterator first, second;
		first = myset.begin();
		second = myset.lower_bound(threshold);
		return distance(first, second);
	}

	int GetCountAbove(float threshold) const {
		std::multiset <T>::const_iterator first, second;
		first = myset.upper_bound(threshold);
		second = myset.end();
		return distance(first, second);
	}
};