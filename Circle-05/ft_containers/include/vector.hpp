#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <limits>
# include <memory>
# include <stdexcept>
# include "./algorithm.hpp"
# include "./iterator.hpp"
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"
# include "./type_traits.hpp"

namespace ft{
	/* vector */
	template <typename T, class Allocator = std::allocator<T> >
	class vector {
	public:
		typedef T value_type;
		typedef Allocator allocator_type;

		typedef std::allocator_traits<allocator_type> type_traits;
		typedef typename type_traits::pointer pointer;
		typedef typename type_traits::const_pointer const_pointer;
		typedef value_type& reference;
		typedef const value_type& const_reference;

		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;

		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/* constructor & destructor */
		explicit vector(const allocator_type& alloc = allocator_type())
			: _begin(ft::nil),
			  _end(ft::nil),
			  _cap(ft::nil),
			  _alloc(alloc) {}
		explicit vector(size_type n,
						const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type())
			: _alloc(alloc) {
			_init(n);
			_construct(n, value);
		}
		template <class InputIterator>
		vector(InputIterator first,
			   InputIterator last,
			   const allocator_type& alloc = allocator_type(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
			: _alloc(alloc) {
			size_type n = ft::distance(first, last);
			_init(n);
			_construct(n);
			std::copy(first, last, _begin);
		}
		vector(const vector& v)
			: _alloc(v._alloc) {
			size_type n = v.size();
			_init(v.capacity());
			_construct(n);
			std::copy(v._begin, v._end, _begin);
		}
		~vector(void) {
			if (_begin == ft::nil) {
				return;
			}
			size_type pre_capacity = capacity();
			_destruct(_begin);
			_alloc.deallocate(_begin, pre_capacity);
		}

		/* member function for util */
		vector& operator=(const vector& v) {
			if (this != &v) {
				assign(v._begin, v._end);
			}
			return *this;
		}

		/* iterators */
		iterator begin(void) {
			return iterator(_begin);
		}
		const_iterator begin(void) const {
			return const_iterator(_begin);
		}
		iterator end(void) {
			return iterator(_end);
		}
		const_iterator end(void) const {
			return const_iterator(_end);
		}
	reverse_iterator rbegin(void) {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(end());
		}
		reverse_iterator rend(void) {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(begin());
		}

		/* element access */
		reference operator[](size_type n) {
			return _begin[n];
		}
		const_reference operator[](size_type n) const {
			return _begin[n];
		}
		reference at(size_type n) {
			if (n >= size()) {
			throw std::out_of_range("index out of range");
			}
			return _begin[n];
		}
		const_reference at(size_type n) const {
			if (n >= size()) {
			throw std::out_of_range("index out of range");
			}
			return _begin[n];
		}
		reference front(void) {
			return *_begin;
		}
		const_reference front(void) const {
			return *_begin;
		}
		reference back(void) {
			return *(_end - 1);
		}
		const_reference back(void) const {
			return *(_end - 1);
		}

		/* capacity */
		size_type size(void) const {
			return static_cast<size_type>(_end - _begin);
		}
		size_type max_size(void) const {
			return std::min<size_type>(std::numeric_limits<size_type>::max(),
									   type_traits::max_size(allocator_type()));
		}
		void resize(size_type n, value_type value = value_type()) {
			if (size() > n) {
				size_type diff = size() - n;
				_destruct(diff);
			} else if (size() < n) {
				size_type diff = n - size();
				if (capacity() < n) {
					reserve(n);
				}
				_construct(diff, value);
			}
		}
		size_type capacity(void) const {
			return static_cast<size_type>(_cap - _begin);
		}
		bool empty(void) const { return _begin == _end; }
		void reserve(size_type n) {
			if (n <= capacity()) {
				return;
			}
			if (n < capacity() * 2) {
				n = capacity() * 2;
			}
			size_type pre_size = size();
			size_type pre_capacity = capacity();
			pointer begin = _alloc.allocate(n);
			std::uninitialized_copy(_begin, _end, begin);
			_destruct(_begin);
			_alloc.deallocate(_begin, pre_capacity);
			_begin = begin;
			_end = _begin + pre_size;
			_cap = _begin + n;
		}

		template <class InputIterator>
		void assign(InputIterator first,
					InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) {
			size_type n = ft::distance(first, last);
			if (capacity() < n) {
				reserve(n);
			}
			std::copy(first, last, _begin);
			_end = _begin + n;
		}
		void assign(size_type n, const value_type& value) {
			if (capacity() < n) {
				reserve(n);
			}
			std::fill_n(_begin, n, value);
			_end = _begin + n;
		}
		void push_back(const value_type& value) {
			size_type n = size() + 1;
			if (capacity() < n) {
				reserve(n);
			}
			_construct(1);
			*(_end - 1) = value;
		}
		void pop_back(void) {
			_destruct(1);
		}
		iterator insert(iterator position, const value_type& value) {
			difference_type diff = position - begin();
			if (capacity() < size() + 1) {
				reserve(size() + 1);
			}
			pointer ptr = _begin + diff;
			_construct(1);
			std::copy_backward(ptr, _end - 1, _end);
			*ptr = value;
			return iterator(ptr);
		}
		void insert(iterator position, size_type n, const value_type& value) {
			difference_type diff = position - begin();
			if (capacity() < size() + n) {
				reserve(size() + n);
			}
			pointer ptr = _begin + diff;
			_construct(n);
			std::copy_backward(ptr, _end - n, _end);
			for (size_type i = 0 ; i < n ; i++) {
				ptr[i] = value;
			}
		}

template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft::nil) {
				if (position > this->end() || position < this->begin())
					return;
				
				size_type	num = ft::distance(first, last);
				size_type	next_size = this->size() + num;
				size_type	prev_capa = this->capacity();
				size_type	pos = &*position - _begin;
				size_type	alloced_size = 0;
				pointer		new_begin = ft::nil;
				pointer		prev_capa_ptr = _cap;

				if (this->max_size() < next_size)
					throw std::length_error("ft::vector::insert: max_size() < this->size() + n");
				if (this->capacity() * 2 < next_size) {
					new_begin = _alloc.allocate(next_size);
					_cap = new_begin + next_size;
					alloced_size = next_size;
				} else {
					new_begin = _alloc.allocate(this->capacity() * 2);
					_cap = new_begin + this->capacity() * 2;
					alloced_size = this->capacity() * 2;
				}
				try {
					for (size_type i = 0; i < pos; ++i)
						_alloc.construct(new_begin + i, *(_begin + i));
					for (size_type i = 0; i < num; ++i)
						_alloc.construct(new_begin + pos + i, *(&*first++));
					for (size_type i = 0; i < this->size() - pos; ++i)
						_alloc.construct(new_begin + pos + num + i, *(_begin + pos + i));
				} catch(...) {
					for (size_type i = 0; i < pos; ++i)
						_alloc.destroy(new_begin + i);
					for (size_type i = 0; i < num; ++i)
						_alloc.destroy(new_begin + pos + i);
					for (size_type i = 0; i < this->size() - pos; ++i)
						_alloc.destroy(new_begin + pos + num + i);
					_alloc.deallocate(new_begin, alloced_size);
					_cap = prev_capa_ptr;
					throw;
				}
				for (size_type i = 0; i < this->size(); ++i)
					_alloc.destroy(_begin + i);
				_alloc.deallocate(_begin, prev_capa);
				_end = new_begin + num + this->size();
				_begin = new_begin;
			}

		iterator erase(iterator position) {
			difference_type diff = position - begin();
			pointer ptr = _begin + diff;
			std::copy(ptr + 1, _end, ptr);
			_destruct(1);
			return iterator(ptr);
		}
		iterator erase(iterator first, iterator last) {
			difference_type n = ft::distance(first, last);
			std::copy(last, end(), first);
			_destruct(n);
			return first;
		}
		void swap(vector& v) {
			std::swap(_begin, v._begin);
			std::swap(_end, v._end);
			std::swap(_cap, v._cap);
			std::swap(_alloc, v._alloc);
		}
		void clear(void) {
			_destruct(_begin);
		}

		/* allocator */
		allocator_type get_allocator(void) const {
			return _alloc;
		}

	private:
		pointer _begin;
		pointer _end;
		pointer _cap;
		allocator_type _alloc;

		/* initialize memory & iterating pointer */
		void _init(size_type n) {
			if (n > max_size()) {
				throw std::length_error("allocation size too big");
			}
			_begin = _alloc.allocate(n);
			_end = _begin;
			_cap = _begin + n;
		}

		/* construct with specific value */
		void _construct(size_type n, T value) {
			for ( ; n > 0 ; _end++, n--) {
				_alloc.construct(_end);
				*_end = value;
			}
		}

		/* construct without value */
		void _construct(size_type n) {
			for ( ; n > 0 ; _end++, n--) {
				_alloc.construct(_end);
			}
		}

		/* destruct with size from end */
		void _destruct(size_type n) {
			for ( ; n > 0 && _end-- ; n--) {
				_alloc.destroy(_end);
			}
		}

		/* destruct from end to pointer */
		void _destruct(pointer until) {
			for ( ; _end != until && _end-- ; ) {
				_alloc.destroy(_end);
			}
		}
	};

		/* relational operators */
		template <typename T, class Allocator>
		bool operator==(const ft::vector<T, Allocator>& x,
						const ft::vector<T, Allocator>& y) {
			return x.size() == y.size() &&
				ft::equal(x.begin(), x.end(), y.begin());
		}

		template <typename T, class Allocator>
		bool operator!=(const ft::vector<T, Allocator>& x,
						const ft::vector<T, Allocator>& y) {
			return !(x == y);
		}

		template <typename T, class Allocator>
		bool operator<(const ft::vector<T, Allocator>& x,
					const ft::vector<T, Allocator>& y) {
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}

		template <typename T, class Allocator>
		bool operator<=(const ft::vector<T, Allocator>& x,
						const ft::vector<T, Allocator>& y) {
			return x == y || x < y;
		}

		template <typename T, class Allocator>
		bool operator>(const ft::vector<T, Allocator>& x,
					const ft::vector<T, Allocator>& y) {
			return !(x <= y);
		}

		template <typename T, class Allocator>
		bool operator>=(const ft::vector<T, Allocator>& x,
						const ft::vector<T, Allocator>& y) {
			return x == y || x > y;
		}

		/* non member function for util */
		template <typename T, class Allocator>
		void swap(ft::vector<T, Allocator>& x,
				ft::vector<T, Allocator>& y) {
			x.swap(y);
		}
}

#endif