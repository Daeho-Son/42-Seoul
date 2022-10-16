#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator.hpp"

namespace ft {
	/*
	정리:
	- reverse_iterator에서 template 매개변수에 iterator가 들어오는 경우
	*/
	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	/*
	정리:
	- vector에서 template 매개변수에 int와 같은 자료형처럼 type들이 정의 되있지 정의 되지 않는 경우
	*/
	template <typename T>
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last) {
		typename ft::iterator_traits<InputIt>::difference_type dist = 0;
		while (first != last) {
			++first;
			++dist;
		}
		return dist;
	}
}

#endif