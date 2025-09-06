#include <vector>
#include <algorithm> // for lower_bound
#include <utility>	 // for std::pair

// Jacobsthal number
int jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int a = 0, b = 1, c;
	for (int i = 2; i <= n; ++i)
	{
		c = b + 2 * a;
		a = b;
		b = c;
	}
	return b;
}

// Ford-Johnson sort in C++98 style
std::vector<int> fordJohnsonSort(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return vector;

	std::vector<std::pair<int, int>> pairs;
	size_t i = 0;
	for (; i + 1 < vector.size(); i += 2)
	{
		if (vector[i] < vector[i + 1])
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
		else
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
	}

	int extraneous = 0;
	if (i < vector.size())
		extraneous = vector[i];

	// sort larger elements recursively
	std::vector<int> larger_elements;
	for (size_t j = 0; j < pairs.size(); j++)
		larger_elements.push_back(pairs[j].second);

	larger_elements = fordJohnsonSort(larger_elements);

	// collect smaller elements
	std::vector<int> smaller_elements;
	for (size_t j = 0; j < pairs.size(); j++)
		smaller_elements.push_back(pairs[j].first);
	if (extraneous != 0)
		smaller_elements.push_back(extraneous);

	// insert smaller elements using Jacobsthal order
	std::vector<bool> inserted(smaller_elements.size(), false);
	int jacIndex = 1;
	while (jacIndex < (int)smaller_elements.size())
	{
		if (!inserted[jacIndex])
		{
			std::vector<int>::iterator pos = std::lower_bound(
				larger_elements.begin(), larger_elements.end(), smaller_elements[jacIndex]);
			larger_elements.insert(pos, smaller_elements[jacIndex]);
			inserted[jacIndex] = true;
		}
		jacIndex = jacobsthal(jacIndex + 1);
	}
	// insert remaining elements sequentially
	for (size_t k = 0; k < smaller_elements.size(); k++)
	{
		if (!inserted[k])
		{
			std::vector<int>::iterator pos = std::lower_bound(
				larger_elements.begin(), larger_elements.end(), smaller_elements[k]);
			larger_elements.insert(pos, smaller_elements[k]);
			inserted[k] = true;
		}
	}

	return larger_elements;
}
