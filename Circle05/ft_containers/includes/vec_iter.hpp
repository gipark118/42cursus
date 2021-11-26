#ifndef VEC_ITER_HPP
# define VEC_ITER_HPP

#include <cstddef>

namespace ft
{
	template <class T>
	class vec_iter
	{
	public:
		typedef std::ptrdiff_t	difference_type;
		typedef T				value_type;
		typedef T*				pointer;
		typedef const T*		const_pointer;
		typedef T&				reference;
		typedef const T&		const_reference;

	protected:
		pointer	_p;

	public:
		// copy-constructible, copy-assignable and destructible
		vec_iter(const vec_iter &src)
		{
			this->_p = src._p;
		}
		vec_iter &operator=(const vec_iter &rhs)
		{
			this->_p = rhs._p;
			return *this;
		}
		virtual ~vec_iter()
		{
		}

		// Can be incremented
		vec_iter operator++(int) // 후위
		{
			vec_iter result(*this);
			++(this->_p);
			return (result);
		}

		vec_iter &operator++() // 전위
		{
			++(this->_p);
			return (*this);
		}

		// Supports equality/inequality comparisons
		bool operator==(const vec_iter &rhs) const
		{
			return (this->_p == rhs._p);
		}
		bool operator!=(const vec_iter &rhs) const
		{
			return (!this->operator==(rhs));
		}

		// Can be dereferenced as an rvalue & lvalue
		virtual reference operator*()
		{
			return *(this->_p);
		}
		virtual const_reference operator*() const
		{
			return *(this->_p);
		}

		virtual pointer operator->()
		{
			return this->_p;
		}

		virtual const_pointer operator->() const
		{
			return this->_p;
		}

		// 	default-constructible
		vec_iter()
		{
			this->_p = NULL;
		}

		// Can be decremented
		vec_iter operator--(int)
		{
			vec_iter result(*this);
			--(this->_p);
			return (result);
		}

		vec_iter &operator--()
		{
			--(this->_p);
			return (*this);
		}

		// Supports arithmetic operators + and -
		vec_iter operator+(int n)
		{
			vec_iter result(*this);
			result._p += n;
			return result;
		}
		vec_iter operator-(int n)
		{
			vec_iter result(*this);
			result._p -= n;
			return result;
		}
		difference_type operator-(const vec_iter &rhs) const
		{
			return (this->_p - rhs._p);
		}

		// Supports inequality comparisons (<, >, <= and >=) between iterators
		bool operator<(const vec_iter &rhs) const
		{
			return (this->_p < rhs._p);
		}
		bool operator>(const vec_iter &rhs) const
		{
			return (rhs < *this);
		}
		bool operator<=(const vec_iter &rhs) const
		{
			return (!(*this > rhs));
		}
		bool operator>=(const vec_iter &rhs) const
		{
			return (!(*this < rhs));
		}

		// Supports compound assignment operations += and -=
		vec_iter &operator+=(int n)
		{
			this->_p += n;
			return (*this);
		}
		vec_iter &operator-=(int n)
		{
			this->_p -= n;
			return (*this);
		}

		// Supports offset dereference operator ([])
		reference operator[](size_t n)
		{
			return *(this->_p + n);
		}
		const_reference operator[](size_t n) const
		{
			return *(this->_p + n);
		}

		// etc
		explicit vec_iter(pointer p)
		{
			this->_p = p;
		}
		pointer getP() const
		{
			return this->_p;
		}

		template<typename cT>
		vec_iter(vec_iter<cT> const &const_src): _p(const_cast<T*>(const_src.getP())) {}
	};

	template<typename T>
	vec_iter<T> operator+(unsigned int lhs, vec_iter<T>& rhs)
	{
		return (rhs + lhs);
	}

	template <class T>
	class vec_rev_iter: public vec_iter<T>
	{
	public:
		using typename vec_iter<T>::difference_type;
		using typename vec_iter<T>::value_type;
		using typename vec_iter<T>::pointer;
		using typename vec_iter<T>::const_pointer;
		using typename vec_iter<T>::reference;
		using typename vec_iter<T>::const_reference;

		vec_rev_iter(): vec_iter<T>() {}
		vec_rev_iter(const vec_iter<T> &src): vec_iter<T>(src) {}
		vec_rev_iter(const vec_rev_iter &src): vec_iter<T>(src._p) {}
		vec_rev_iter(const pointer p): vec_iter<T>(p) {}

		vec_rev_iter &operator=(const vec_rev_iter &rhs)
		{
			this->_p = rhs._p;
			return *this;
		}
		reference operator*()
		{
			vec_iter<T> result(*this);
			return (*(--result));
		}

		vec_rev_iter operator++(int)
		{ // 후위
			vec_rev_iter result(*this);
			--(this->_p);
			return (result);
		}
		vec_rev_iter &operator++()
		{ // 전위
			--(this->_p);
			return (*this);
		}
		vec_rev_iter operator--(int)
		{ // 후위
			vec_rev_iter result(*this);
			++(this->_p);
			return (result);
		}
		vec_rev_iter &operator--()
		{ // 전위
			++(this->_p);
			return (*this);
		}

		vec_rev_iter operator+(difference_type n)
		{
			return vec_rev_iter(this->_p - n);
		}
		vec_rev_iter &operator+=(difference_type n)
		{
			this->_p -= n;
			return (*this);
		}
		difference_type operator-(const vec_rev_iter &rhs) const
		{
			return (rhs._p - this->_p);
		}
		vec_rev_iter operator-(difference_type n)
		{
			return vec_rev_iter(this->_p + n);
		}
		vec_rev_iter &operator-=(difference_type n)
		{
			this->_p += n;
			return (*this);
		}

		// Supports inequality comparisons (<, >, <= and >=) between iterators
		bool operator<(const vec_rev_iter &rhs) const
		{
			return (this->_p > rhs._p);
		}
		bool operator>(const vec_rev_iter &rhs) const
		{
			return (rhs < *this);
		}
		bool operator<=(const vec_rev_iter &rhs) const
		{
			return (!(*this > rhs));
		}
		bool operator>=(const vec_rev_iter &rhs) const
		{
			return (!(*this < rhs));
		}

		pointer operator->() {
			vec_iter<T> result(*this);
			return (&*(--result));
		}
		const_pointer operator->() const {
			vec_iter<T> result(*this);
			return (&*(--result));
		}
		vec_iter<T> base() const
		{
			return vec_iter<T>(this->_p);
		}

		reference operator[](size_t n)
		{
			return *(this->_p - n - 1);
		}
		const_reference operator[](size_t n) const
		{
			return *(this->_p - n - 1);
		}

		template<typename cT>
		vec_rev_iter(vec_rev_iter<cT> const &const_src)
		{
			this->_p = const_cast<T*>(const_src.getP());
		}
	};

	template<typename T>
	vec_rev_iter<T> operator+(unsigned int lhs, vec_rev_iter<T>& rhs)
	{
		return (rhs + lhs);
	}
}

#endif
