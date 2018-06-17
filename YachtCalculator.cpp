#include "YachtCalculator.h"
#include <algorithm>


YachtCalculator::YachtCalculator()
{
}


YachtCalculator::~YachtCalculator()
{
}

int YachtCalculator::GetHighestScore(int dice[], int size)
{
	int highest = 0;
	for (int cat = 1; cat <= Count; ++cat)
	{
		int result = GetScore(dice, size, cat);
		if (highest < result)
			highest = result;
	}

	return highest;
}
int YachtCalculator::GetScore(int dice[], int size, int category)
{
	int score = 0;
	switch (category)
	{
		case Ones:
		case Twos:
		case Threes:
		case Fours:
		case Fives:
		case Sixs:
		case Sevens:
		case Eights:
			for (int i = 0; i < size; i++)
			{
				if (dice[i] == category)
				{
					score += category;
				}
			}
			break;

		case ThreeOfAKind:
		case FourOfAKind:
		case Chance:
			if (IsCategory(dice, size, category) || category == Chance)
			{
				for (int i = 0; i < size; i++)
				{
					score += dice[i];
				}
			}
			break;

		case FullHouse:
			if (IsCategory(dice, size, category)) score = 25;
			break;

		case SmallStraight:
			if (IsCategory(dice, size, category)) score = 30;
			break;

		case LargeStraight:
		case AllDifferent:
			if (IsCategory(dice, size, category)) score = 40;
			break;

		case AllSame:
			if (IsCategory(dice, size, category)) score = 50;
			break;

	}
	return score;
}


bool YachtCalculator::IsCategory(int dice[], int size, int category)
{
	int valDict[NUMBER_OF_SIDES] = { 0 };

	for (int i = 0; i < size; ++i)
	{
		valDict[dice[i] - 1]++;
	}

	switch (category)
	{
	case ThreeOfAKind:
		for (int i = 0; i < NUMBER_OF_SIDES; ++i)
		{
			if (valDict[i] >= 3) 
				return true;
		}
		break;
	case FourOfAKind:
		for (int i = 0; i < NUMBER_OF_SIDES; ++i)
		{
			if (valDict[i] >= 4) 
				return true;
		}
		break;
	case FullHouse:
	{
		bool check2 = false;
		bool check3 = false;
		for (int i = 0; i < NUMBER_OF_SIDES; ++i)
		{
			if (valDict[i] >= 3)	  check3 = true;
			else if (valDict[i] >= 2) check2 = true;
		}
		return check2 && check3;
		break;
	}
	case SmallStraight:
	{
		std::sort(dice, dice + size);
		if (dice[0] > NUMBER_OF_SIDES - size + 2 || dice[size - 1] < size - 1) return false;
		int consecutives = 0;
		for (int i = 0; i < size - 1; ++i)
		{
			if (dice[i] + 1 == dice[i + 1]) {
				++consecutives;
				if (consecutives >= 3)
					return true;
			}
			else
				consecutives = 0;
		}
		break;
	}
	case LargeStraight:
		std::sort(dice, dice + size);
		if (dice[0] > NUMBER_OF_SIDES - size + 1 || dice[size - 1] < size) return false;

		for (int i = 0; i < size - 1; ++i)
		{
			if (dice[i] + 1 != dice[i + 1])
				return false;
		}
		return true;
		break;
	case AllSame:
		for (int i = 0; i < NUMBER_OF_SIDES; ++i)
		{
			if (valDict[i] != 0 && valDict[i] != size)
				return false;

			if (valDict[i] == size)
				return true;
		}
		break;
	case AllDifferent:
		for (int i = 0; i < NUMBER_OF_SIDES; ++i)
		{
			if (valDict[i] != 0 && valDict[i] != 1)
			{
				return false;
			}
		}
		return true;
		break;

	}

	return false;
}

