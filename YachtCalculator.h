#pragma once
class YachtCalculator
{

	
public:
	YachtCalculator();
	~YachtCalculator();

	enum  Categories
	{
		None,

		Ones,				// 1
		Twos,				// 2
		Threes,				// 3
		Fours,				// 4
		Fives,				// 5
		Sixs,				// 6
		Sevens,				// 7
		Eights,				// 8
		ThreeOfAKind,		// 9
		FourOfAKind,		// 10
		FullHouse,			// 11
		SmallStraight,		// 12
		LargeStraight,		// 13
		AllDifferent,		// 14
		Chance,				// 15
		AllSame,			// 16

		Count
	};

	const static int NUMBER_OF_SIDES = 8;

	int GetScore(int[], int, int);
	int GetHighestScore(int[], int);
	bool IsCategory(int[], int, int);
};

