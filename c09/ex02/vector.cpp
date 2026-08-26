#include "PmergeMe.hpp"
#include <algorithm>

void    PmergeMe::pairUpElements(size_t firstIndex, size_t secondIndex, size_t pairSize, size_t level)
{
	size_t originalFirstIndex = firstIndex;
	size_t originalSecondIndex = secondIndex;
	size_t offset;

	if (v.size() < (size_t(1) << level))
		return ;
	for (size_t i = 0; i < v.size(); i += pairSize)
	{
		if (firstIndex >= v.size() || secondIndex >= v.size())
			break ;
		if (v[firstIndex] > v[secondIndex])
		{
			offset = pairSize / 2;
			while (offset != 0)
			{
				std::swap(v[firstIndex - (offset - 1)], v[secondIndex - (offset - 1)]);
				offset--;
			}
		}
		firstIndex += pairSize;
		secondIndex += pairSize;
	}
	pairUpElements(originalFirstIndex * 2 + 1, originalSecondIndex * 2 + 1, pairSize * 2, level + 1);
}

void    PmergeMe::moveBlocksToChain(std::vector<int>::iterator& it,
	size_t pairSize, size_t& totalBlocks, bool toPendChain)
{
	size_t i = 0;

	while (i < pairSize && totalBlocks)
	{
		if (toPendChain)
			pendChain.push_back(*it);
		else
			mainChain.push_back(*it);
		++it;
		++i;
		if (i == pairSize)
			--totalBlocks;
	}
}

void    PmergeMe::splitIntoPendAndMain(size_t pairSize, size_t totalBlocks)
{
	std::vector<int>::iterator	it = v.begin();

	mainChain.clear();
	pendChain.clear();
	extra.clear();
	moveBlocksToChain(it, pairSize, totalBlocks, false);
	while (it != v.end() && totalBlocks)
	{
		moveBlocksToChain(it, pairSize, totalBlocks, false);
		moveBlocksToChain(it, pairSize, totalBlocks, true);
	}
	while (it != v.end())
	{
		extra.push_back(*it);
		++it;
	}
}

void    PmergeMe::unwindAndInsert(size_t pairSize)
{
	while (pairSize >= 1)
	{
		size_t totalBlocks = v.size() / pairSize;
		
		splitIntoPendAndMain(pairSize, totalBlocks);

		size_t pendBlocksCount = pendChain.size() / pairSize;
		size_t insertedCount = 0;
		size_t JIndex = 3;

		while (insertedCount < pendBlocksCount)
		{
			size_t jacob = jacobsthal(JIndex);
			size_t prevJacob = jacobsthal(JIndex - 1);

			if (jacob > pendBlocksCount + 1)
				jacob = pendBlocksCount + 1;

			for (size_t k = jacob; k > prevJacob; --k)
			{
				if (k <= 1)
					continue ;
				size_t b_start_idx = (k - 2) * pairSize;
				int targetValue = pendChain[b_start_idx + pairSize - 1];

				size_t left = 0;
				size_t right = mainChain.size() / pairSize;

				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					int midValue = mainChain[mid * pairSize + pairSize - 1];

					if (midValue > targetValue)
						right = mid;
					else
						left = mid + 1;
				}
				std::vector<int>::iterator insertPos = mainChain.begin() + (left * pairSize);
				std::vector<int>::iterator pendStart = pendChain.begin() + b_start_idx;
				std::vector<int>::iterator pendEnd = pendStart + pairSize;

				mainChain.insert(insertPos, pendStart, pendEnd);
				insertedCount++;
			}
			JIndex++;
		}
		mainChain.insert(mainChain.end(), extra.begin(), extra.end());
		v = mainChain;
		pairSize /= 2;
	}
}

void    PmergeMe::mergeInsertVector()
{
	if (v.size() <= 1)
		return ;

	pairUpElements(0, 1, 2, 1);

	size_t startPairSize = 1;
	while (startPairSize * 2 <= v.size() / 2)
		startPairSize *= 2;

	unwindAndInsert(startPairSize);
}
