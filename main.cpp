#include <iostream>
#include <vector>

std::vector<int> sieveOfEratoshenes(int highBoundary);

auto main() -> int {

	for (auto&& numb : sieveOfEratoshenes(100))
		std::cout << numb << " ";

}

std::vector<int> sieveOfEratoshenes(int highBoundary) 
{
	std::vector<bool> boolean(highBoundary + 1, true);

	for (int i{ 2 }; i < std::sqrt(highBoundary); ++i)
	{
		if (boolean[i]) 
			for (int j{ i * i }; j <= highBoundary; j += i)
				boolean[j] = false;
	}

	std::vector<int> res;
	res.reserve(highBoundary);
	for (int i{ 2 }; i < highBoundary; ++i)
		if (boolean[i])
			res.push_back(i);

	return res;
}