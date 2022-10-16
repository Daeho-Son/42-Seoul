#ifndef MAP_HPP 
# define MAP_HPP 

# include <functional>
# include <memory>
# include "./algorithm.hpp"
# include "./pair.hpp"
# include "./rbtree.hpp"
# include "./reverse_iterator.hpp"

namespace ft {
	/* map */
	template <typename U,
			  typename V,
			  class Compare = std::less<U>,
			  class Allocator = std::allocator<ft::pair<const U, V> > >
	class map {
	public:
		typedef U key_type;
		typedef V mapped_type;
		typedef ft::pair<const U, V> value_type;
		typedef Compare key_compare;

		typedef Allocator allocator_type;
		typedef typename allocator_type::template rebind<value_type>::other type_allocator;
		typedef std::allocator_traits<type_allocator> type_traits;
		typedef typename type_traits::pointer pointer;
		typedef typename type_traits::const_pointer const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;

		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;

		/* value_compare */
		class value_compare
			: public std::binary_function<value_type, value_type, bool>{
		protected:
			key_compare comp;

		public:
			/* constructor & destructor */
			value_compare(key_compare c) : comp(c) {}
			~value_compare(void) {}

			/* callable operator */
			bool operator()(const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
			bool operator()(const value_type& x, const key_type& y) const {
				return comp(x.first, y);
			}
			bool operator()(const key_type& x, const value_type& y) const {
				return comp(x, y.first);
			}
		};

		typedef typename ft::_rbtree<value_type, key_type, value_compare, allocator_type>::iterator iterator;
		typedef typename ft::_rbtree<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/* constructor & destructor */
		explicit map(const key_compare& comp = key_compare(),
					 const allocator_type& alloc = allocator_type())
			: _key_comp(comp), _value_comp(comp), _tree(_value_comp, alloc) {}
		template <class InputIterator>
		map(InputIterator first,
			InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
			: _key_comp(comp), _value_comp(comp), _tree(_value_comp, alloc) {
			insert(first, last);
		}
		map(const map &m)
			: _key_comp(m._key_comp),
			  _value_comp(m._value_comp),
			  _tree(m._tree) {}
		~map(void) {}

		/* member function for util */
		map& operator=(const map& m) {
			if (this != &m) {
				_key_comp = m._key_comp;
				_value_comp = m._value_comp;
				_tree = m._tree;
			}
			return *this;
		}

		/* iterators */
		iterator begin(void) {
			return _tree.begin();
		}
		const_iterator begin(void) const {
			return _tree.begin();
		}
		iterator end(void) {
			return _tree.end();
		}
		const_iterator end(void) const {
			return _tree.end();
		}
		reverse_iterator rbegin(void) {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin(void) const {
			return reverse_iterator(end());
		}
		reverse_iterator rend(void) {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend(void) const {
			return reverse_iterator(begin());
		}

		/* capacity */
		bool empty(void) const {
			return _tree.empty();
		}
		size_type size(void) const {
			return _tree.size();
		}
		size_type max_size(void) const {
			return _tree.max_size();
		}

		/* element access */
		mapped_type& operator[](const key_type& key) {
			ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
			return p.first->second;
		}
		mapped_type& at(const key_type& key) {
			iterator i = find(key);
			if (i == end()) {
				throw std::out_of_range("index out of range");
			}
			return i->second;
		}
		const mapped_type& at(const key_type& key) const {
			const_iterator i = find(key);
			if (i == end()) {
				throw std::out_of_range("index out of range");
			}
			return i->second;
		}

		/* modifiers */
		ft::pair<iterator, bool> insert(const value_type& value) {
			return _tree.insert(value);
		}
		iterator insert(iterator position, const value_type& value) {
			return _tree.insert(position, value);
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			_tree.insert(first, last);
		}
		void erase(iterator position) {
			_tree.erase(position);
		}
		size_type erase(const key_type& key) {
			return _tree.erase(key);
		}
		void erase(iterator first, iterator last) {
			_tree.erase(first, last);
		}
		void swap(map& m) {
			_tree.swap(m._tree);
		}
		void clear(void) {
			_tree.clear();
		}

		/* observers */
		key_compare key_comp(void) const {
			return _key_comp;
		}
		value_compare value_comp(void) const {
			return _value_comp;
		}

		/* lookup operations */
		iterator find(const key_type& key) {
			return _tree.find(key);
		}
		const_iterator find(const key_type& key) const {
			return _tree.find(key);
		}
		size_type count(const key_type& key) const {
			return !(find(key) == end());
		}
		iterator lower_bound(const key_type& key) {
			return _tree.lower_bound(key);
		}
		const_iterator lower_bound(const key_type& key) const {
			return _tree.lower_bound(key);
		}
		iterator upper_bound(const key_type& key) {
			return _tree.upper_bound(key);
		}
		const_iterator upper_bound(const key_type& key) const {
			return _tree.upper_bound(key);
		}
		ft::pair<iterator, iterator> equal_range(const key_type& key) {
			return _tree.equal_range(key);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
			return _tree.equal_range(key);
		}

		/* allocator */
		allocator_type get_allocator(void) const {
			return _tree.get_allocator();
		}

	private:
		key_compare _key_comp;
		value_compare _value_comp;
		ft::_rbtree<value_type, key_type, value_compare, allocator_type> _tree;
	};

		/* relational operators */
		template <typename U, typename V, class Compare, class Allocator>
		bool operator==(const ft::map<U, V, Compare, Allocator>& x,
						const ft::map<U, V, Compare, Allocator>& y) {
			return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
		}

		template <typename U, typename V, class Compare, class Allocator>
		bool operator!=(const ft::map<U, V, Compare, Allocator>& x,
						const ft::map<U, V, Compare, Allocator>& y) {
			return !(x == y);
		}

		template <typename U, typename V, class Compare, class Allocator>
		bool operator<(const ft::map<U, V, Compare, Allocator>& x,
					   const ft::map<U, V, Compare, Allocator>& y) {
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}

		template <typename U, typename V, class Compare, class Allocator>
		bool operator<=(const ft::map<U, V, Compare, Allocator>& x,
						const ft::map<U, V, Compare, Allocator>& y) {
			return !(y < x);
		}

		template <typename U, typename V, class Compare, class Allocator>
		bool operator>(const ft::map<U, V, Compare, Allocator>& x,
					   const ft::map<U, V, Compare, Allocator>& y) {
			return y < x;
		}

		template <typename U, typename V, class Compare, class Allocator>
		bool operator>=(const ft::map<U, V, Compare, Allocator>& x,
						const ft::map<U, V, Compare, Allocator>& y) {
			return !(x < y);
		}

		/* non member function for util */
		template <typename U, typename V, class Compare, class Allocator>
		void swap(ft::map<U, V, Compare, Allocator>& x,
				  ft::map<U, V, Compare, Allocator>& y) {
			x.swap(y);
		}
}

#endif
