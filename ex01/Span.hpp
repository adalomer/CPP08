#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span
{
	public:
		explicit Span(unsigned int n = 0);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

	void addNumber(int value);

	template <typename It>
	void addRange(It first, It last)
	{
		if (_values.size() + (std::size_t)std::distance(first, last) > _maxSize)
			throw FullException();
		_values.insert(_values.end(), first, last);
	}

	int shortestSpan() const;
	int longestSpan() const;

	struct FullException : public std::exception {
		const char *what() const throw() { return "Span is full"; }
	};

	struct NotEnoughNumbersException : public std::exception {
		const char *what() const throw() { return "Not enough numbers"; }
	};

private:
	unsigned int _maxSize;
	std::vector<int> _values;
};

#endif