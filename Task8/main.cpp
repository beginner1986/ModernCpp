// print all the 3-digit Armstrong numbers (narcissistic numbers)

#include <iostream>
#include <cmath>

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				int num = 100 * i + 10 * j + 1 * k;
				int val = pow(i, 3) + pow(j, 3) + pow(k, 3);

				if (num == val)
					std::cout << num << std::endl;
			}
		}
	}

	return 0;
}