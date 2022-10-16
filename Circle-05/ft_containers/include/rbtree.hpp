#ifndef RBTREE_HPP 
# define RBTREE_HPP 

# include <algorithm>
# include <limits>
# include <memory>
# include "./iterator.hpp"
# include "./pair.hpp"
# include "./type_traits.hpp"

namespace ft {
	/* tree_node */
	template <typename T>
	struct _tree_node {
		typedef T value_type;
		typedef bool binary_type;

		_tree_node* _parent;
		_tree_node* _left;
		_tree_node* _right;
		value_type _value;
		binary_type _is_black;

		/* constructor & destructor */
		_tree_node(void)
			: _parent(ft::nil),
			  _left(ft::nil),
			  _right(ft::nil),
			  _value(value_type()),
			  _is_black(binary_type()) {}
		_tree_node(const value_type& value)
			: _parent(ft::nil),
			  _left(ft::nil),
			  _right(ft::nil),
			  _value(value),
			  _is_black(binary_type()) {}
		_tree_node(const _tree_node& n)
			: _parent(n._parent),
			  _left(n._left),
			  _right(n._right),
			  _value(n._value),
			  _is_black(n._is_black) {}
		~_tree_node(void) {}

		/* member function for util */
		_tree_node& operator=(const _tree_node& n) {
			if (this != &n) {
				_parent = n._parent;
				_left = n._left;
				_right = n._right;
				_value = n._value;
				_is_black = n._is_black;
			}
			return *this;
		}
	};

	/* non member function for util */
	template <class NodePtr>
	bool _is_left_child(const NodePtr& ptr) {
		return ptr == ptr->_parent->_left;
	}

	template <class NodePtr>
	bool _is_right_child(const NodePtr& ptr) {
		return ptr == ptr->_parent->_right;
	}

	template <class NodePtr>
	bool _is_black_color(const NodePtr& ptr) {
		return ptr->_is_black;
	}

	template <class NodePtr>
	bool _is_red_color(const NodePtr& ptr) {
		return !ptr->_is_black;
	}

	template <class NodePtr>
	NodePtr _get_min_node(NodePtr ptr, NodePtr nil) {
		while (ptr->_left != nil) {
			ptr = ptr->_left;
		}
		return ptr;
	}

	/*
	정리: 
	NodePtr nil을 넣어줘야하는 이유: 
		- 클래스 외부에 있는 함수이기 때문에 매개변수로 받아야한다.
	 */
	template <class NodePtr>
	NodePtr _get_max_node(NodePtr ptr, NodePtr nil) {
		while (ptr->_right != nil) {
			ptr = ptr->_right;
		}
		return ptr;
	}

	template <class NodePtr>
	NodePtr _get_next_node(NodePtr ptr, NodePtr nil) {
		if (ptr->_right != nil) {
			return _get_min_node(ptr->_right, nil);
		}
		while (_is_right_child(ptr)) {
			ptr = ptr->_parent;
		}
		return ptr->_parent;
	}

	template <class NodePtr>
	NodePtr _get_prev_node(NodePtr ptr, NodePtr nil) {
		if (ptr->_left != nil) {
			return _get_max_node(ptr->_left, nil);
		}
		while (_is_left_child(ptr)) {
			ptr = ptr->_parent;
		}
		return ptr->_parent;
	}

	template <typename U, typename V, class Comp>
	bool _is_equal(const U& u, const V& v, Comp comp) {
		return !comp(u, v) && !comp(v, u);
	}

	/* tree_iterator */
	template <typename U, typename V>
	class _tree_iterator : public std::iterator<std::bidirectional_iterator_tag, U> {
	public:
		typedef U value_type;
		typedef value_type* pointer;
		typedef value_type& reference;
		typedef V* iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference node_reference;
		typedef std::bidirectional_iterator_tag iterator_category;

		/* constructor & destructor */
		_tree_iterator(void)
			: _cur(ft::nil), _nil(ft::nil) {}
		_tree_iterator(node_pointer cur, node_pointer nil)
			: _cur(cur), _nil(nil) {}
		_tree_iterator(const _tree_iterator &i)
			: _cur(i._cur), _nil(i._nil) {}
		~_tree_iterator(void) {}

		/* member function for util */
		_tree_iterator& operator=(const _tree_iterator& i) {
			if (this != &i) {
				_cur = i._cur;
				_nil = i._nil;
			}
			return *this;
		}

		/* element access */
		node_pointer base(void) const { return _cur; }
		pointer operator->(void) const { return &_cur->_value; }
		reference operator*(void) const { return _cur->_value; }

		/* increment & decrement */
		_tree_iterator& operator++(void) {
			_cur = ft::_get_next_node(_cur, _nil);
			return *this;
		}
		_tree_iterator& operator--(void) {
			_cur = ft::_get_prev_node(_cur, _nil);
			return *this;
		}
		_tree_iterator operator++(int) {
			_tree_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		_tree_iterator operator--(int) {
			_tree_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		/* relational operators */
		template <typename T>
		bool operator==(const _tree_iterator<T, node_type>& i) const {
			return _cur == i.base();
		}
		template <typename T>
		bool operator!=(const _tree_iterator<T, node_type>& i) const {
			return !(*this == i);
		}

		/* const type overloading */
		operator _tree_iterator<const value_type, node_type>(void) const {
			return _tree_iterator<const value_type, node_type>(_cur, _nil);
		}

	private:
		node_pointer _cur;
		node_pointer _nil;
	};

	/* rbtree */
	template <typename T, class Key, class Comp, class Allocator>
	class _rbtree {
	public:
		typedef T value_type;
		typedef Key key_type;
		typedef Comp compare_type;

		typedef _tree_node<value_type> node_type;
		typedef _tree_node<value_type>* node_pointer;
		typedef _tree_iterator<value_type, node_type> iterator;
		typedef _tree_iterator<const value_type, node_type> const_iterator;

		typedef Allocator allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other node_allocator;
		typedef std::allocator_traits<node_allocator> node_traits;

		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;

		/* constructor & destructor */
		_rbtree(const compare_type& comp, const allocator_type& alloc)
			: _comp(comp), _alloc(alloc), _size(size_type()) {
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, value_type());
			_nil->_is_black = true;
			_nil->_parent = _nil;
			_nil->_left = _nil;
			_nil->_right = _nil;
			_end = _construct_node(value_type());
			_end->_is_black = true;
			_begin = _end;
		}
		_rbtree(const _rbtree& t)
			: _comp(t._comp), _alloc(t._alloc), _size(size_type()) {
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, value_type());
			_nil->_is_black = true;
			_nil->_parent = _nil;
			_nil->_left = _nil;
			_nil->_right = _nil;
			_end = _construct_node(value_type());
			_end->_is_black = true;
			_begin = _end;
			insert(t.begin(), t.end());
		}
		~_rbtree(void) {
			_destruct_node_recursive(_end);
			_destruct_node(_nil);
		}

		/* member function for util */
		_rbtree& operator=(const _rbtree& t) {
			if (this != &t) {
				_rbtree tmp(t);
				swap(tmp);
			}
			return *this;
		}

		/* iterators */
		iterator begin(void) {
			return iterator(_begin, _nil);
		}
		const_iterator begin(void) const {
			return const_iterator(_begin, _nil);
		}
		iterator end(void) {
			return iterator(_end, _nil);
		}
		const_iterator end(void) const {
			return const_iterator(_end, _nil);
		}

		/* capacity */
		size_type size(void) const {
			return _size;
		}
		size_type max_size(void) const {
			return std::min<size_type>(std::numeric_limits<size_type>::max(),
									   node_traits::max_size(node_allocator()));
		}
		bool empty(void) const {
			return _size == 0;
		}

		/* modifiers */
		ft::pair<iterator, bool> insert(const value_type& value) {
			node_pointer ptr = _search_parent(value);
			if (ptr != _end && _is_equal(ptr->_value, value, _comp)) {
				return ft::make_pair(iterator(ptr, _nil), false);
			}
			return ft::make_pair(iterator(_insert_internal(value, ptr), _nil), true);
		}
		iterator insert(iterator position, const value_type& value) {
			node_pointer ptr = _search_parent(value, position.base());
			if (ptr != _end && _is_equal(ptr->_value, value, _comp)) {
				return iterator(ptr, _nil);
			}
			return iterator(_insert_internal(value, ptr), _nil);
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			while (first != last) {
				insert(*first++);
			}
		}
		iterator erase(iterator position) {
			if (_size == 0) {
				return iterator(_nil, _nil);
			}
			iterator tmp(position);
			++tmp;
			if (position == begin()) {
				_begin = tmp.base();
			}
			--_size;
			_remove_internal(position.base());
			_destruct_node(position.base());
			return tmp;
		}
		template <typename U>
		size_type erase(const U& value) {
			iterator i(_find_internal(value), _nil);
			if (i == end()) {
				return 0;
			}
			if (i == begin()) {
				iterator tmp(i);
				++tmp;
				_begin = tmp.base();
			}
			--_size;
			_remove_internal(i.base());
			_destruct_node(i.base());
			return 1;
		}
		void erase(iterator first, iterator last) {
			
			for (; first != last;) {
				first = erase(first);
			}
		}
		void swap(_rbtree& t) {
			std::swap(_nil, t._nil);
			std::swap(_begin, t._begin);
			std::swap(_end, t._end);
			std::swap(_comp, t._comp);
			std::swap(_alloc, t._alloc);
			std::swap(_size, t._size);
		}
		void clear(void) {
			_rbtree tmp(_comp, _alloc);
			swap(tmp);
		}

		/* lookup operations */
		iterator find(const key_type& key) {
			return iterator(_find_internal(key), _nil);
		}
		const_iterator find(const key_type& key) const {
			return const_iterator(_find_internal(key), _nil);
		}
		iterator lower_bound(const key_type& key) {
			return iterator(_lower_bound_internal(key), _nil);
		}
		const_iterator lower_bound(const key_type& key) const {
			return const_iterator(_lower_bound_internal(key), _nil);
		}
		iterator upper_bound(const key_type& key) {
			return iterator(_upper_bound_internal(key), _nil);
		}
		const_iterator upper_bound(const key_type& key) const {
			return const_iterator(_upper_bound_internal(key), _nil);
		}
		ft::pair<iterator, iterator> equal_range(const key_type& key) {
			return _equal_range_internal(key);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
			return _equal_range_internal(key);
		}

		/* allocator */
		allocator_type get_allocator(void) const {
			return _alloc;
		}

	private:
		node_pointer _nil;
		node_pointer _begin;
		node_pointer _end;
		compare_type _comp;
		node_allocator _alloc;
		size_type _size;

		/* root */
		node_pointer _get_root(void) const {
			return _end->_left;
		}
		void _set_root(const node_pointer ptr) {
			ptr->_parent = _end;
			_end->_left = ptr;
		}

		/* modifiers */
		node_pointer _construct_node(const value_type& value) {
			node_pointer ptr = _alloc.allocate(1);
			_alloc.construct(ptr, value);
			ptr->_parent = _nil;
			ptr->_left = _nil;
			ptr->_right = _nil;
			ptr->_is_black = false;
			return ptr;
		}
		void _destruct_node(node_pointer ptr) {
			_alloc.destroy(ptr);
			_alloc.deallocate(ptr, 1);
		}
		void _destruct_node_recursive(node_pointer ptr) {
			if (ptr == _nil) {
				return;
			}
			_destruct_node_recursive(ptr->_left);
			_destruct_node_recursive(ptr->_right);
			_destruct_node(ptr);
		}
		/*
		정리:
		부모가 될 노드 찾기
		노드 삽입 전 parent를 찾아주는 함수
		*/
		node_pointer _search_parent(const value_type& value, node_pointer position = ft::nil) {
			if (position && position != _end) {
				if (_comp(value, position->_value) && position->_left == _nil) {
					iterator prev = iterator(position, _nil);
					if (prev == begin() || _comp(*--prev, value)) {
						return position;
					}
				}
				else if (position->_right == _nil) {
					iterator next = iterator(position, _nil);
					if (next == end() || _comp(value, *++next)) {
						return position;
					}
				}
			}
			node_pointer cur = _get_root();
			node_pointer tmp = _end;
			for (; cur != _nil;) {
				tmp = cur;
				if (_comp(value, cur->_value)) {
					cur = cur->_left;
				}
				else if (_comp(cur->_value, value)) {
					cur = cur->_right;
				}
				else {
					return cur;
				}
			}
			return tmp;
		}
		/*
		정리:
		노드 삽입 후 RB트리 밸런스 맞추는 작업
		*/
		node_pointer _insert_internal(const value_type& value, node_pointer parent) {
			node_pointer ptr = _construct_node(value);
			if (parent == _end) {
				_set_root(ptr);
			}
			else if (_comp(value, parent->_value)) {
				parent->_left = ptr;
			}
			else {
				parent->_right = ptr;
			}
			ptr->_parent = parent;
			_insert_fixup(ptr);
			_insert_update(ptr);
			return ptr;
		}
		void _insert_fixup(node_pointer ptr) {
			while (_is_red_color(ptr->_parent)) {
				if (_is_left_child(ptr->_parent)) {
					_insert_fixup_left(ptr);
				}
				else {
					_insert_fixup_right(ptr);
				}
			}
			_get_root()->_is_black = true;
		}
		void _insert_fixup_left(node_pointer& ptr) {
			node_pointer uncle = ptr->_parent->_parent->_right;
			if (_is_red_color(uncle)) {
				ptr->_parent->_is_black = true;
				uncle->_is_black = true;
				uncle->_parent->_is_black = false;
				ptr = uncle->_parent;
			}
			else {
				if (_is_right_child(ptr)) {
					ptr = ptr->_parent;
					_rotate_left(ptr);
				}
				ptr->_parent->_is_black = true;
				ptr->_parent->_parent->_is_black = false;
				_rotate_right(ptr->_parent->_parent);
			}
		}
		void _insert_fixup_right(node_pointer& ptr) {
			node_pointer uncle = ptr->_parent->_parent->_left;
			if (_is_red_color(uncle)) {
				ptr->_parent->_is_black = true;
				uncle->_is_black = true;
				uncle->_parent->_is_black = false;
				ptr = uncle->_parent;
			}
			else {
				if (_is_left_child(ptr)) {
					ptr = ptr->_parent;
					_rotate_right(ptr);
				}
				ptr->_parent->_is_black = true;
				ptr->_parent->_parent->_is_black = false;
				_rotate_left(ptr->_parent->_parent);
			}
		}
		void _insert_update(const node_pointer ptr) {
			if (_begin == _end || _comp(ptr->_value, _begin->_value)) {
				_begin = ptr;
			}
			_size++;
		}
		void _remove_internal(node_pointer ptr) {
			node_pointer recolor_node;
			node_pointer fixup_node;
			bool original_color = _is_black_color(ptr);
			if (ptr->_left == _nil) {
				recolor_node = ptr->_right;
				_transplant(ptr, ptr->_right);
			}
			else if (ptr->_right == _nil) {
				recolor_node = ptr->_left;
				_transplant(ptr, ptr->_left);
			}
			else {
				fixup_node = _get_min_node(ptr->_right, _nil);
				original_color = _is_black_color(fixup_node);
				recolor_node = fixup_node->_right;
				if (fixup_node->_parent == ptr) {
					recolor_node->_parent = fixup_node;
				}
				else {
					_transplant(fixup_node, fixup_node->_right);
					fixup_node->_right = ptr->_right;
					fixup_node->_right->_parent = fixup_node;
				}
				_transplant(ptr, fixup_node);
				fixup_node->_left = ptr->_left;
				fixup_node->_left->_parent = fixup_node;
				fixup_node->_is_black = original_color;
			}
			if (original_color) {
				_remove_fixup(recolor_node);
			}
		}
		void _remove_fixup(node_pointer ptr) {
			while (ptr != _get_root() && _is_black_color(ptr)) {
				if (_is_left_child(ptr)) {
					_remove_fixup_left(ptr);
				}
				else {
					_remove_fixup_right(ptr);
				}
			}
			ptr->_is_black = true;
		}
		void _remove_fixup_left(node_pointer& ptr) {
			node_pointer sibling = ptr->_parent->_right;
			if (_is_red_color(sibling)) {
				sibling->_is_black = true;
				ptr->_parent->_is_black = false;
				_rotate_left(ptr->_parent);
				sibling = ptr->_parent->_right;
			}
			if (_is_black_color(sibling->_left) && _is_black_color(sibling->_right)) {
				sibling->_is_black = false;
				ptr = ptr->_parent;
			}
			else if (_is_black_color(sibling->_right)) {
				sibling->_left->_is_black = true;
				sibling->_is_black = false;
				_rotate_right(sibling);
				sibling = ptr->_parent->_right;
			}
			if (_is_red_color(sibling->_right)) {
				sibling->_is_black = _is_black_color(ptr->_parent);
				ptr->_parent->_is_black = true;
				sibling->_right->_is_black = true;
				_rotate_left(ptr->_parent);
				ptr = _get_root();
			}
		}
		void _remove_fixup_right(node_pointer& ptr) {
			node_pointer sibling = ptr->_parent->_left;
			if (_is_red_color(sibling)) {
				sibling->_is_black = true;
				ptr->_parent->_is_black = false;
				_rotate_right(ptr->_parent);
				sibling = ptr->_parent->_left;
			}
			if (_is_black_color(sibling->_right) && _is_black_color(sibling->_left)) {
				sibling->_is_black = false;
				ptr = ptr->_parent;
			}
			else if (_is_black_color(sibling->_left)) {
				sibling->_right->_is_black = true;
				sibling->_is_black = false;
				_rotate_left(sibling);
				sibling = ptr->_parent->_left;
			}
			// 속성5 위반 case 4
			if (_is_red_color(sibling->_left)) {
				sibling->_is_black = _is_black_color(ptr->_parent);
				ptr->_parent->_is_black = true;
				sibling->_left->_is_black = true;
				_rotate_right(ptr->_parent);
				ptr = _get_root();
			}
		}
		void _transplant(node_pointer former, node_pointer latter) {
			if (former->_parent == _end) {
				_set_root(latter);
			}
			else if (_is_left_child(former)) {
				former->_parent->_left = latter;
			}
			else {
				former->_parent->_right = latter;
			}
			latter->_parent = former->_parent;
		}
		void _rotate_left(node_pointer ptr) {
			node_pointer child = ptr->_right;
			ptr->_right = child->_left;
			if (ptr->_right != _nil) {
				ptr->_right->_parent = ptr;
			}
			node_pointer parent = ptr->_parent;
			child->_parent = parent;
			if (parent == _end) {
				_set_root(child);
			}
			else if (_is_left_child(ptr)) {
				parent->_left = child;
			}
			else {
				parent->_right = child;
			}
			child->_left = ptr;
			ptr->_parent = child;
		}
		void _rotate_right(node_pointer ptr) {
			node_pointer child = ptr->_left;
			ptr->_left = child->_right;
			if (ptr->_left != _nil) {
				ptr->_left->_parent = ptr;
			}
			node_pointer parent = ptr->_parent;
			child->_parent = parent;
			if (parent == _end) {
				_set_root(child);
			}
			else if (_is_left_child(ptr)) {
				parent->_left = child;
			}
			else {
				parent->_right = child;
			}
			child->_right = ptr;
			ptr->_parent = child;
		}

		/* lookup operations */
		template <typename U>
		node_pointer _find_internal(const U& value) const {
			node_pointer ptr = _get_root();
			while (ptr != _nil) {
				if (_comp(value, ptr->_value)) {
					ptr = ptr->_left;
				}
				else if (_comp(ptr->_value, value)) {
					ptr = ptr->_right;
				}
				else {
					return ptr;
				}
			}
			return _end;
		}
		/*
		정리:
		lower_bound
			- 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지
		*/
		node_pointer _lower_bound_internal(const key_type& key) const {
			node_pointer ptr = _get_root();
			node_pointer tmp = _end;
			while (ptr != _nil) {
				if (!_comp(ptr->_value, key)) {
					tmp = ptr;
					ptr = ptr->_left;
				}
				else {
					ptr = ptr->_right;
				}
			}
			return tmp;
		}
		/*
		정리:
		upper_bound
			- 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지
		*/
		node_pointer _upper_bound_internal(const key_type& key) const {
			node_pointer ptr = _get_root();
			node_pointer tmp = _end;
			while (ptr != _nil) {
				if (_comp(key, ptr->_value)) {
					tmp = ptr;
					ptr = ptr->_left;
				}
				else {
					ptr = ptr->_right;
				}
			}
			return tmp;
		}
		template <typename U>
		ft::pair<iterator, iterator> _equal_range_internal(const U& value) {
			node_pointer ptr = _get_root();
			node_pointer tmp = _end;
			while (ptr != _nil) {
				if (_comp(value, ptr->_value)) {
					tmp = ptr;
					ptr = ptr->_left;
				}
				else if (_comp(ptr->_value, value)) {
					ptr = ptr->_right;
				}
				else {
					if (ptr->_right != _nil) {
						tmp = _get_min_node(ptr->_right, _nil);
					}
					return ft::make_pair(iterator(ptr, _nil), iterator(tmp, _nil));
				}
			}
			return ft::make_pair(iterator(tmp, _nil), iterator(tmp, _nil));
		}
		template <typename U>
		ft::pair<const_iterator, const_iterator> _equal_range_internal(const U& value) const {
			node_pointer ptr = _get_root();
			node_pointer tmp = _end;
			while (ptr != _nil) {
				if (_comp(value, ptr->_value)) {
					tmp = ptr;
					ptr = ptr->_left;
				}
				else if (_comp(ptr->_value, value)) {
					ptr = ptr->_right;
				}
				else {
					if (ptr->_right != _nil) {
						tmp = _get_min_node(ptr->_right, _nil);
					}
					return ft::make_pair(const_iterator(ptr, _nil), const_iterator(tmp, _nil));
				}
			}
			return ft::make_pair(const_iterator(tmp, _nil), const_iterator(tmp, _nil));
		}
	};
}

#endif
