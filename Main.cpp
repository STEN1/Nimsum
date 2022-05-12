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

    if (nimsum == 0)
        return 0;

    std::vector<int> subtractStack(numberOfStacks);

    for (int i = 0; i < numberOfStacks; ++i)
    {
        std::vector<int> tempStack = stacks;

        for (int j = 0; j < stacks[i]; ++j)
        {
            tempStack[i]--;
            int newNimsum{};
            for (int stack : tempStack)
                newNimsum ^= stack;

            if (newNimsum == 0)
            {
                subtractStack[i] = stacks[i] - tempStack[i];
                break;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Options for zeroing the nimsum" << std::endl;

    for (int i = 0; i < subtractStack.size(); i++)
        std::cout << "Subtract " << subtractStack[i] << " from stack " << i << std::endl;
}