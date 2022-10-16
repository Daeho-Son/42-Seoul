#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	/* pair */
	template <typename T1, typename T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair(void) : first(first_type()), second(second_type()) {}

		template <typename U, typename V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

		pair(const first_type& a, const second_type& b) : first(a), second(b) {}

		~pair(void) {}

		/* member function for util */
		pair& operator=(const pair& p) {
			if (this != &p) {
				first = p.first;
				second = p.second;
			}
			return *this;
		}
	};

	/* make_pair */
	template <typename T1, typename T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y) {
		return pair<T1, T2>(x, y);
	}

	/* relational_operators */
	template <typename T1, typename T2>
	bool operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
		return x.first == y.first && x.second == y.second;
	}

	template <typename T1, typename T2>
	bool operator!=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
		return !(x == y);
	}

	template <typename T1, typename T2>
	bool operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <typename T1, typename T2>
	bool operator<=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
		return !(y < x);
	}

	template <typename T1, typename T2>
	bool operator>(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
		return y < x;
	}

	template <typename T1, typename T2>
	bool operator>=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
		return !(x < y);
	}
}

#endif
