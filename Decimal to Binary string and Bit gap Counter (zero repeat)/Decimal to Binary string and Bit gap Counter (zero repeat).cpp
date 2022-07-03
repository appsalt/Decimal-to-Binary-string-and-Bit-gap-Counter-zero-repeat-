// Decimal to Binary string and Bit gap Counter (zero repeat).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>

int main()
{
	srand(time(NULL));

	// We make som variables to store counts. 'I' is the integer we will convert
		int I{ rand()*rand() };
		int P{ I };
		std::string bin{};
		int lastBitGap{};
		int bitGap{};

	// We make the integer into a string of the binary representation. 
	// The loop It will find largest digit that is left after every cycel of the loop. 
		std::string next{};
		while (P > 0)
		{
			next = std::to_string(P % 2);
			bin = next + bin; // we must add the new and smaller resolution digit on the right side so that the binary number is not backwards.
			P = P / 2;
		}

	// We find the first 1 of the binary string with an iterator for loop. Because bit gapas are between 1's
		for (std::string::iterator it1 = bin.begin(); it1 != bin.end(); ++it1)
		{
			std::cout << *it1;
			if (*it1 == '1')
			{
				std::cout << "->";
				// Here we count the 0's untill we reach another 1, then we save the curren count of repeating zeroes only if it is larger than the last, and then resett the count regardless
				for (std::string::iterator it2 = it1; it2 != bin.end(); ++it2)
				{
					std::cout << *it2;
					if (*it2 == '1' && lastBitGap < bitGap)
					{
						
						lastBitGap = bitGap;
						bitGap = 0;
					}
					else if (*it2 == '1' && lastBitGap >= bitGap) {
						bitGap = 0;
					}
					else
					{
						++ bitGap;
					}
				}
				break;
			}
		}

	// We end by visualizing the result
		std::cout << std::endl;
		std::cout << "integer:\t";
		std::cout << I;
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "binary:\t\t";
		std::cout << bin;
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << "largest bit gap (zero repeat): ";
		std::cout << lastBitGap;
		std::cout << std::endl;

	return 0;
}
