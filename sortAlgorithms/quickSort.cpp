#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std::chrono;

#include <thread>

std::vector<int> createRandomVec(const size_t size);
std::vector<int> quickSort(std::vector<int>& randomVector);

size_t steps = 0;

int main() {

	size_t vectorSize;
	size_t numberOfTrials;

	std::cout << "Size of vector: ";
	std::cin >> vectorSize;

	std::cout << "Number of trials: ";
	std::cin >> numberOfTrials;

	size_t duration = 0;

	for (size_t i = 0; i < numberOfTrials; i++) {


		std::vector<int> vec = createRandomVec(vectorSize);

		auto start = high_resolution_clock::now();
		vec = quickSort(vec);
		auto stop = high_resolution_clock::now();

		if (!std::is_sorted(vec.begin(), vec.end()))
			return -1;

		duration += duration_cast<microseconds>(stop - start).count();
	}

	std::cout << "Sort after avrage " << duration / numberOfTrials << "μs" << " in " << steps / numberOfTrials << " steps\n";
}

std::vector<int> createRandomVec(const size_t size) {

	static std::random_device rd;
	static std::default_random_engine e1(rd());
	static std::uniform_int_distribution<int> uniform_dist(-size, size);

	std::vector<int> result(size);

	std::generate(result.begin(), result.end(), [&]() { return uniform_dist(e1); });
	return result;
}

std::vector<int> quickSort(std::vector<int>& vec) {

	if (vec.size() < 2 || std::is_sorted(vec.begin(), vec.end()))
		return vec;

	if (vec.size() == 2) {
		if(vec[0] > vec[1]) {
			std::swap(vec.front(), vec.back());
			steps++;
		}
		return vec;
	}

	int pivot = vec.front();
	std::vector<int> smallerThenPivot;
	std::vector<int> greaterThenPivot;

	std::for_each(vec.begin() + 1, vec.end(),
			[&](auto &el) mutable {
				el > pivot ? greaterThenPivot.push_back(el) : smallerThenPivot.push_back(el);
				steps++;
			});

	std::vector<int> result;

	smallerThenPivot = quickSort(smallerThenPivot);
	greaterThenPivot = quickSort(greaterThenPivot);

	result.insert(result.begin(), smallerThenPivot.begin(), smallerThenPivot.end());
	result.push_back(pivot);
	result.insert(result.end(), greaterThenPivot.begin(), greaterThenPivot.end());

	result.shrink_to_fit();

	return result;
}
