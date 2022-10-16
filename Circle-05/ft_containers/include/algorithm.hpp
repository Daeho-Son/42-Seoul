#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include <cstdint>
# include <stdexcept>

namespace ft {
	/* equal
	정리:
		- [first1,last1)] 범위의 요소를 첫 번째 2에서 시작하는 범위의 요소와 비교하고 두 범위의 요소가 모두 일치하면 true를 반환합니다.
	*/
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1,
			   InputIterator1 last1,
			   InputIterator2 first2) {
		while (first1 != last1) {
			if (!(*first1++ == *first2++)) {
				return false;
			}
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1,
			   InputIterator1 last1,
			   InputIterator2 first2,
			   BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1++, *first2++)) {
				return false;
			}
		}
		return true;
	}

	/* lexicographical_compare
	정리:
		- 범위 [first1,last1)]가 사전순으로 범위 [first2,last2]보다 작은 값을 비교할 경우 true를 반환합니다.
	*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1,
								 InputIterator1 last1,
								 InputIterator2 first2,
								 InputIterator2 last2) {
		while (first2 != last2)	{
			if (first1 == last1 || *first1 < *first2) {
				return true;
			}
			if (*first1++ > *first2++) {
				return false;
			}
		}
		return false;
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1,
								 InputIterator1 last1,
								 InputIterator2 first2,
								 InputIterator2 last2,
								 Compare comp) {
		while (first2 != last2) {
			if (first1 == last1 || comp(*first1, *first2)) {
				return true;
			}
			if (comp(*first2++, *first1++)) {
				return false;
			}
		}
		return false;
	}
}

#endif
