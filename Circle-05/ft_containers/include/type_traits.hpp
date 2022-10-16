#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <cstdint>

namespace ft {
	/* nullptr_t
	정리:
	operator T*(void) 형태는 *로 변환해줌
		- https://stackoverflow.com/questions/275169/what-is-operator-tvoid-and-when-it-is-invoked

	nil = {};
		- 바로 선언 해서 한 개의 nullptr_t만 사용할 수 있게 해준다.
		- https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ljy9378&logNo=221515469583
	*/
	const class nullptr_t {
	// private:
		// void operator&(void) const;

	public:
		template <typename T>
		operator T*(void) const { return 0; }

		// template <typename T, typename U>
		// operator T U::*(void) const { return 0; }
	} nil = {};

	/* enable_if
	- https://modoocode.com/255
	*/
	template <bool, typename = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	/* integral_constant */
	template <typename T, T v>
	struct integral_constant {
		typedef T value_type;
		typedef integral_constant type; // ft::integral_constant<T, v>

		static const value_type value = v;

		operator value_type(void) const { return value; }
	};
	typedef integral_constant<bool, true> true_type;

	typedef integral_constant<bool, false> false_type;

	/* remove_cv */
	template <typename T>
	struct remove_cv {
		typedef T type;
	};

	template <typename T>
	struct remove_cv<const T> {
		typedef T type;
	};

	template <typename T>
	struct remove_cv<volatile T> {
		typedef T type;
	};

	template <typename T>
	struct remove_cv<const volatile T> {
		typedef T type;
	};

	/* is_integral_base */
	template <typename>
	struct is_integral_base : public false_type {};

	template <>
	struct is_integral_base<bool> : public true_type {};

	template <>
	struct is_integral_base<char> : public true_type {};

	template <>
	struct is_integral_base<char16_t> : public true_type {};

	template <>
	struct is_integral_base<char32_t> : public true_type {};

	template <>
	struct is_integral_base<wchar_t> : public true_type {};

	template <>
	struct is_integral_base<signed char> : public true_type {};

	template <>
	struct is_integral_base<short int> : public true_type {};

	template <>
	struct is_integral_base<int> : public true_type {};

	template <>
	struct is_integral_base<long int> : public true_type {};

	template <>
	struct is_integral_base<long long int> : public true_type {};

	template <>
	struct is_integral_base<unsigned char> : public true_type {};

	template <>
	struct is_integral_base<unsigned short int> : public true_type {};

	template <>
	struct is_integral_base<unsigned int> : public true_type {};

	template <>
	struct is_integral_base<unsigned long int> : public true_type {};

	template <>
	struct is_integral_base<unsigned long long int> : public true_type {};

	/* is_integral */
	template <typename T>
	struct is_integral : public is_integral_base<typename remove_cv<T>::type> {};
}

#endif