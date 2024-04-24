#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std::chrono;

std::vector<int> createRandomVec(const size_t size);
size_t insertionSort(std::vector<int>& randomVector);

int main() {

	size_t vectorSize;
	size_t numberOfTrials;

	std::cout << "Size of vector: ";
	std::cin >> vectorSize;

	std::cout << "Number of trials: ";
	std::cin >> numberOfTrials;

	size_t duration = 0;
	size_t steps = 0;

	for (size_t i = 0; i < numberOfTrials; i++) {


		std::vector<int> vec = createRandomVec(vectorSize);

		auto start = high_resolution_clock::now();
		steps += insertionSort(vec);
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

	std::vector<int> result(size + 1);

	std::generate(result.begin(), result.end(), [&]() { return uniform_dist(e1); });
	return result;
}

size_t insertionSort(std::vector<int>& randomVector) {

	size_t steps = 0;

	for(size_t i = 0; i<randomVector.size(); i++) {

		int minValue = randomVector[i];
		size_t minIndex = i;

		for(size_t j = i; j<randomVector.size(); j++) {
			if ( randomVector[j] < minValue)
			{
				minValue = randomVector[j];
				minIndex = j;
			}
			steps++;
		}

		int tmp = randomVector[i];
		randomVector[i] = minValue;
		randomVector[minIndex] = tmp;
	}
	return steps;
}
