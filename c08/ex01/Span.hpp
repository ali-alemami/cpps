#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iterator>

class Span
{
	private:
		std::vector<int>	_v;
		unsigned int		N;
		Span();

	public:
		Span(unsigned int num);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		class exceededBounds : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class tooFewElements : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void	addNumber(int num);

		template <typename InputIterator>
		void	addNumbers(InputIterator begin,
							InputIterator end)
		{
			if (N - _v.size() < static_cast<unsigned int>(std::distance(begin, end)))
				throw (Span::exceededBounds());
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}

		int		shortestSpan();
		int		longestSpan();
};

#endif