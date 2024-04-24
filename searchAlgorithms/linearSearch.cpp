#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std::chrono;

std::vector<int> createVec(const size_t size);
int linearSearch(std::vector<int>& randomSortedVector, const int number);

int main() {

	size_t vectorSize;
	size_t numberOfTrials;
	std::random_device rd;
	std::default_random_engine e1(rd());

	std::cout << "Size of vector: ";
	std::cin >> vectorSize;

	std::uniform_int_distribution<int> uniform_dist(0, vectorSize);


	std::cout << "Number of trials: ";
	std::cin >> numberOfTrials;

	size_t duration = 0;
	size_t steps = 0;

	for (size_t i = 0; i < numberOfTrials; i++)
	{
		int number = uniform_dist(e1);

		std::vector<int> randomSortedVector = createVec(vectorSize);
		auto start = high_resolution_clock::now();

		steps += linearSearch(randomSortedVector, number);

		auto stop = high_resolution_clock::now();
		duration += duration_cast<microseconds>(stop - start).count();
	}



	std::cout << "Find after avrage " << duration / numberOfTrials << "μs" << " in " << steps / numberOfTrials << " steps\n";
}

std::vector<int> createVec(const size_t size) {
	std::vector<int> result(size + 1);

	std::generate(result.begin(), result.end(), [i{0}]() mutable { return i++; });
	return result;
}

int linearSearch(std::vector<int>& randomSortedVector, const int number) {

	size_t steps = 0;

	for (const auto& el : randomSortedVector)
	{
		if(el == number)
			break;
		steps++;
	}
	return steps;
}
