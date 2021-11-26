#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <stdio.h>
#include "map_util.hpp"

namespace ft
{
	template <class>
	struct check_type { typedef void type; };
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Iter, bool>
	struct _iterator_traits {};

    template <class Iter>
    struct _iterator_traits<Iter, true>
    {
        typedef	typename Iter::value_type			value_type;
        typedef	typename Iter::difference_type		difference_type;
        typedef	typename Iter::pointer				pointer;
        typedef	typename Iter::reference			reference;
        typedef	typename Iter::iterator_category	iterator_category;
    };

    template <class T>
	struct _has_iterator_typedefs
	{
	private:
		struct	_two { char _lx; char _lxx; };
		template <class U>	static _two _test(...);
		template <class U>	static char _test(typename	ft::check_type<typename U::iterator_category>::type * = 0,
												typename	ft::check_type<typename U::difference_type>::type * = 0,
												typename	ft::check_type<typename U::value_type>::type * = 0,
												typename	ft::check_type<typename U::reference>::type * = 0,
												typename	ft::check_type<typename U::pointer>::type * = 0
		);
	public:
		static const bool value = sizeof(_test<T>(0,0,0,0,0)) == 1;
	};

    template <class Iter>
    struct iterator_traits : public _iterator_traits<Iter, _has_iterator_typedefs<Iter>::value> {};

    template <class T>
	struct iterator_traits<T*>
	{
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

    template <class T>
	struct iterator_traits<const T*>
	{
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	// Refernce: http://www.cplusplus.com/reference/utility/pair/operators/
	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	// Refernce: http://www.cplusplus.com/reference/utility/make_pair/
	template <class T1,class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( ft::pair<T1,T2>(x,y) );
	}

	template <class It1, class It2>
	bool	lexicographical_compare(It1 begin1, It1 end1, It2 begin2, It2 end2)
	{
		while (begin1 != end1 && begin2 != end2 && *begin1 == *begin2)
		{
			++begin1;
			++begin2;
		}
		if (begin1 == end1)
			return (begin2 != end2);
		if (begin2 == end2)
			return (false);
		return (*begin1 < *begin2);
	}

	template <bool B>
	struct enable_if {};

	template <>
	struct enable_if<true>
	{
		typedef int type;
	};

	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long long>
	{
		static const bool value = true;
	};
}

#endif
