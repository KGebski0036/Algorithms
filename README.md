# Algorithms

This GitHub repository contains my implementations of algorithms that I learnt from my books and courses.

I implement algorithms that I learn from one of my books "Grokking Algorithms" and form course "Algorithms" by Mateusz Adamski

<div align="center">
<b>This repository is not finished yet.</b>

![3%](https://progress-bar.dev/3/?title=Progress)
</div>

## Tehnologies

<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="30" alt="cplusplus  logo"  />

## Contents

1. [Search Algorithms](./searchAlgorithms/)
	- [Linear Search](#linear-search)
	- [Binary Search](#binary-search)
2. [Sort Algorithms](./sortAlgorithms/)
	- [Insertion Sort](#insertion-sort)
	- [Quick Sort](#quick-sort)


## Algorithms

>all files was compiled with `-O3` flag

### [Linear Search](./searchAlgorithms/linearSearch.cpp)

|Number of Elemnts|Time of execution|Number of Steps|
|---|---|---|
|10|0μs|4|
|100|0μs|51|
|10'000|1μs|4838|
|10'000'000|2062μs|5'478'384|
|100'000'000|16731μs|52'733'947|

The algorithm has a computational complexity of $O(n)$.

### [Binary Search](./searchAlgorithms/binarySearch.cpp)

|Number of Elemnts|Time of execution|Number of Steps|
|---|---|---|
|10|0μs|2|
|100|0μs|4|
|10'000|0μs|11|
|10'000'000|1μs|21|
|100'000'000|2μs|24|

The algorithm has a computational complexity of $O(\log_2n)$.

### [Insertion Sort](./sortAlgorithms/insertionSort.cpp)

|Number of Elemnts|Time of execution|Number of Steps|
|---|---|---|
|10|0μs|66|
|100|6μs|5151|
|10'000|2ms|50'015'001|
|100'000|24ms|5'000'150'001|

The algorithm has a computational complexity of $O(n^2)$.

### [Quick Sort](./sortAlgorithms/quickSort.cpp)

|Number of Elemnts|Time of execution|Number of Steps|
|---|---|---|
|10|1μs|21|
|100|24μs|624|
|10'000|1ms|154254|
|100'000|18ms|2'007'798|
|1'000'000|209ms|24'470'203|

The algorithm has a computational complexity of $O(n^2)$ in the worst case but $O(n\log_2n)$ in average case.
