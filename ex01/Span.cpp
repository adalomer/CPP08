#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : _maxSize(n) {}
Span::Span(const Span &o) : _maxSize(o._maxSize), _values(o._values) {}
Span &Span::operator=(const Span &o) 
{
	if (this != &o) { _maxSize = o._maxSize; _values = o._values;}
	return *this; 
}
Span::~Span() {}

void Span::addNumber(int value)
{
	if (_values.size() >= _maxSize) throw FullException();
	_values.push_back(value);
}

int Span::shortestSpan() const 
{
	if (_values.size() < 2) throw NotEnoughNumbersException(); 
	std::vector<int> s(_values);  
	std::sort(s.begin(), s.end()); 
	long min = std::numeric_limits<long>::max();
	for ( std::size_t i = 1; i < s.size(); ++i )
		min = std::min(min, (long)s[i] - s[i-1]);
	return (int)min;
}

int Span::longestSpan() const {
	if (_values.size() < 2 ) throw  NotEnoughNumbersException();
	return *std::max_element(_values.begin(), _values.end() ) - *std::min_element(_values.begin(), _values.end());
}