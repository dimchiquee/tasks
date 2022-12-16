#include <iostream>
#include <thread>
#include <atomic>

void summarize(int n, int* inputArray, const int size, const int numberOfThreads, std::atomic<int>& sumResult)
{
	for (int i = n; i < size; i += numberOfThreads)
	{
		sumResult += inputArray[i];
	}
}

int main()
{
	const int amount = 10;
	const int numberOfThreads = 9;
	int* inputArray = new int[amount];
	std::atomic<int> sumResult(0);
	for (int i = 0; i < amount; i++) {
		std::cin >> inputArray[i];
	}
	for (int i = 0; i < numberOfThreads; i++) {
		std::thread t(summarize, i, inputArray, amount, numberOfThreads, std::ref(sumResult));
		t.detach();
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << sumResult << std::endl;

}
