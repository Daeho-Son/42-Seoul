#ifndef STACK_HPP 
# define STACK_HPP 

# include "./vector.hpp"

namespace ft {
	/* stack */
	template <typename T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef typename Container::value_type value_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;
		typedef Container container_type;

	protected:
		Container c;

	public:
		/* constructor & destructor */
		explicit stack(const Container& container = container_type()) : c(container) {}
		stack(const stack& s) : c(s.c) {}
		~stack(void) {}

		/* member function for util */
		stack& operator=(const stack& s) {
			if (this != &s) {
				c = s.c;
			}
			return *this;
		}

		/* element access */
		reference top(void) {
			return c.back();
		}
		const_reference top(void) const {
			return c.back();
		}

		/* capacity */
		bool empty(void) const {
			return c.empty();
		}

		size_type size(void) const {
			return c.size();
		}

		/* modifiers */
		void push(const value_type& value) {
			c.push_back(value);
		}
		void pop(void) {
			c.pop_back();
		}

		/* friend non member function for relational operators */
		friend bool operator==(const stack& x, const stack& y) {
			return x.c == y.c;
		}
		friend bool operator!=(const stack& x, const stack& y) {
			return x.c != y.c;
		}
		friend bool operator<(const stack& x, const stack& y) {
			return x.c < y.c;
		}
		friend bool operator<=(const stack& x, const stack& y) {
			return x.c <= y.c;
		}
		friend bool operator>(const stack& x, const stack& y) {
			return x.c > y.c;
		}
		friend bool operator>=(const stack& x, const stack& y) {
			return x.c >= y.c;
		}
	};
}

#endif