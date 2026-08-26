#include "PmergeMe.hpp"
#include <algorithm>

void    PmergeMe::pairUpElementsDeque(size_t firstIndex, size_t secondIndex, size_t pairSize, size_t level)
{
	size_t originalFirstIndex = firstIndex;
	size_t originalSecondIndex = secondIndex;
	size_t offset;

	if (q.size() < (size_t(1) << level))
		return ;
	for (size_t i = 0; i < q.size(); i += pairSize)
	{
		if (firstIndex >= q.size() || secondIndex >= q.size())
			break ;
		if (q[firstIndex] > q[secondIndex])
		{
			offset = pairSize / 2;
			while (offset != 0)
			{
				std::swap(q[firstIndex - (offset - 1)], q[secondIndex - (offset - 1)]);
				offset--;
			}
		}
		firstIndex += pairSize;
		secondIndex += pairSize;
	}
	pairUpElementsDeque(originalFirstIndex * 2 + 1, originalSecondIndex * 2 + 1, pairSize * 2, level + 1);
}

void    PmergeMe::moveBlocksToChainDeque(std::deque<int>::iterator& it,
	size_t pairSize, size_t& totalBlocks, bool toPendChain)
{
	size_t i = 0;

	while (i < pairSize && totalBlocks)
	{
		if (toPendChain)
			pendChainQ.push_back(*it);
		else
			mainChainQ.push_back(*it);
		++it;
		++i;
		if (i == pairSize)
			--totalBlocks;
	}
}

void    PmergeMe::splitIntoPendAndMainDeque(size_t pairSize, size_t totalBlocks)
{
	std::deque<int>::iterator   it = q.begin();

	mainChainQ.clear();
	pendChainQ.clear();
	extraQ.clear();
	moveBlocksToChainDeque(it, pairSize, totalBlocks, false);
	while (it != q.end() && totalBlocks)
	{
		moveBlocksToChainDeque(it, pairSize, totalBlocks, false);
		moveBlocksToChainDeque(it, pairSize, totalBlocks, true);
	}
	while (it != q.end())
	{
		extraQ.push_back(*it);
		++it;
	}
}

void    PmergeMe::unwindAndInsertDeque(size_t pairSize)
{
	while (pairSize >= 1)
	{
		size_t totalBlocks = q.size() / pairSize;
		
		splitIntoPendAndMainDeque(pairSize, totalBlocks);

		size_t pendBlocksCount = pendChainQ.size() / pairSize;
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
				int targetValue = pendChainQ[b_start_idx + pairSize - 1]; 

				size_t left = 0;
				size_t right = mainChainQ.size() / pairSize;

				while (left < right)
				{
					size_t mid = left + (right - left) / 2;
					int midValue = mainChainQ[mid * pairSize + pairSize - 1]; 

					if (midValue > targetValue)
						right = mid;
					else
						left = mid + 1;
				}
				std::deque<int>::iterator insertPos = mainChainQ.begin() + (left * pairSize);
				std::deque<int>::iterator pendStart = pendChainQ.begin() + b_start_idx;
				std::deque<int>::iterator pendEnd = pendStart + pairSize;

				mainChainQ.insert(insertPos, pendStart, pendEnd);
				insertedCount++;
			}
			JIndex++;
		}
		mainChainQ.insert(mainChainQ.end(), extraQ.begin(), extraQ.end());
		q = mainChainQ;
		pairSize /= 2;
	}
}

void    PmergeMe::mergeInsertDeque()
{
	if (q.size() <= 1)
		return ;

	pairUpElementsDeque(0, 1, 2, 1);

	size_t startPairSize = 1;
	while (startPairSize * 2 <= q.size() / 2)
		startPairSize *= 2;

	unwindAndInsertDeque(startPairSize);
}
