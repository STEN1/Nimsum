#include <iostream>
#include <vector>

int main()
{
	std::cout << "NIMSUM!\n";
	std::cout << "Number of stacks: ";

	int numberOfStacks;
	std::cin >> numberOfStacks;
	std::vector<int> stacks(numberOfStacks);

	for (int i = 0; i < stacks.size(); i++)
	{
		std::cout << "Chips in stack " << i << ": ";
		std::cin >> stacks[i];
	}

	int nimsum{};
	for (int stack : stacks)
		nimsum ^= stack;

	std::cout << "Nimsum: " << nimsum << std::endl;
}