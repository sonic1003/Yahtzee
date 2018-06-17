#include "YachtCalculator.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <list>



int main()
{
	std::list<std::vector<int>> tests{
		std::vector<int>{ 1,1,1,1,1 },
		std::vector<int>{ 5,2,3,3,1 },
		std::vector<int>{ 5,5,5,5,5 },
		std::vector<int>{ 7,7,3,7,3 },
		std::vector<int>{ 8,2,1,4,3 },
		std::vector<int>{ 6,2,1,4,5 },
		std::vector<int>{ 1,2,3,4,5 },
		std::vector<int>{ 8,2,2,2,2 },
		std::vector<int>{ 6,6,6,6,6 }
	};


	//TODO: error check against input
	// e.g. { 0,0,0,0,0 }


	YachtCalculator calc;

	for (std::vector<int> test : tests) {
		int* input = &test[0];

		
		std::cout << "Current case : ";
		for (int i = 0; i <test.size(); ++i)
		{
			std::cout << input[i] << " ";
		}
		std::cout << std::endl;


		for (int cat = 1; cat <= calc.Count; ++cat)
		{
			int result = calc.GetScore(input, 5, cat);
			std::cout << cat << " \t" << result << std::endl;
		}

		std::cout << "Highest score ===>> \t" << calc.GetHighestScore(input, 5) << std::endl << std::endl;
	}
	


	std::cin.get();

	return 0;
}