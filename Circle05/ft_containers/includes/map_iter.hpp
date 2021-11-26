#ifndef MAP_ITER_HPP
# define MAP_ITER_HPP

#include "map_util.hpp"
#include "utils.hpp"

namespace ft
{
	template <typename Key, typename T, class Compare>
	class map_const_iter;

	template <typename Key, typename T, class Compare>
	class map_iter
	{
	public:
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef ft::pair<const Key, T>		value_type;
		typedef Compare						key_compare;
		typedef AVLNode<Key, T, Compare>*	node_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;

	protected:
		node_type	_p;
		node_type	_root;

	private:
		class OutOfRangeException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return "map_iter::OutOfRangeException";
			}
		};

	public:
		map_iter(): _p(NULL), _root(NULL) {}
		map_iter(node_type p, node_type root): _p(p), _root(root) {}
		map_iter(const map_iter &src): _p(src._p), _root(src._root) {}
		map_iter(const map_const_iter<Key, T, Compare> &src): _p(src.getP()), _root(src.getRoot()) {}
		virtual ~map_iter() {}

		map_iter &operator=(const map_iter &rhs)
		{
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		bool operator==(const map_iter &rhs)
		{
			return (this->_p == rhs._p);
		}
		bool operator==(const map_const_iter<Key, T, Compare> &rhs)
		{
			return (this->_p == rhs.getP());
		}
		bool operator!=(const map_iter &rhs)
		{
			return (this->_p != rhs._p);
		}
		bool operator!=(const map_const_iter<Key, T, Compare> &rhs)
		{
			return (this->_p != rhs.getP());
		}

		reference operator*()
		{
			return *(this->_p->val);
		}
		const_reference operator*() const
		{
			return *(this->_p->val);
		}
		pointer operator->()
		{
			return this->_p->val;
		}
		const_pointer operator->() const
		{
			return this->_p->val;
		}

		map_iter operator++(int) // 후위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_iter result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}
		map_iter &operator++() // 전위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}
		map_iter operator--(int) // 후위
		{
			map_iter result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}
		map_iter &operator--() // 전위
		{
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const
		{
			return this->_p;
		}
		const node_type getRoot() const
		{
			return this->_root;
		}
	};

	template <typename Key, typename T, class Compare>
	class map_const_iter
	{
	public:
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef ft::pair<const Key, T>		value_type;
		typedef Compare						key_compare;
		typedef AVLNode<Key, T, Compare>*	node_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef value_type*					pointer;
		typedef const value_type*			const_pointer;

	protected:
		node_type	_p;
		node_type	_root;

	private:
		class OutOfRangeException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return "map_const_iter::OutOfRangeException";
			}
		};

	public:
		map_const_iter(): _p(NULL), _root(NULL) {}
		map_const_iter(node_type p, node_type root): _p(p), _root(root) {}
		map_const_iter(const map_const_iter &src): _p(src._p), _root(src._root) {};
		map_const_iter(const map_iter<Key, T, Compare> &src): _p(src.getP()), _root(src.getRoot()) {}
		virtual ~map_const_iter() {}

		map_const_iter &operator=(const map_const_iter &rhs)
		{
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		bool operator==(const map_iter<Key, T, Compare> &rhs)
		{
			return (this->_p == rhs.getP());
		}
		bool operator==(const map_const_iter &rhs)
		{
			return (this->_p == rhs._p);
		}
		bool operator!=(const map_iter<Key, T, Compare> &rhs)
		{
			return (this->_p != rhs.getP());
		}
		bool operator!=(const map_const_iter &rhs)
		{
			return (this->_p != rhs._p);
		}

		const_reference operator*() const
		{
			return *(this->_p->val);
		}
		const_pointer operator->() const
		{
			return this->_p->val;
		}

		map_const_iter operator++(int) // 후위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_const_iter result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}
		map_const_iter &operator++() // 전위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}
		map_const_iter operator--(int) // 후위
		{
			map_const_iter result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}
		map_const_iter &operator--() // 전위
		{
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const
		{
			return this->_p;
		}
		const node_type getRoot() const
		{
			return this->_root;
		}
	};

	template <typename Key, typename T, class Compare>
	class map_rev_iter: public map_iter<Key, T, Compare>
	{
	public:
		using typename map_iter<Key, T, Compare>::key_type;
		using typename map_iter<Key, T, Compare>::mapped_type;
		using typename map_iter<Key, T, Compare>::value_type;
		using typename map_iter<Key, T, Compare>::key_compare;
		using typename map_iter<Key, T, Compare>::node_type;
		using typename map_iter<Key, T, Compare>::reference;
		using typename map_iter<Key, T, Compare>::const_reference;
		using typename map_iter<Key, T, Compare>::pointer;
		using typename map_iter<Key, T, Compare>::const_pointer;

	private:
		class OutOfRangeException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return "map_rev_iter::OutOfRangeException";
			}
		};

	public:
		map_rev_iter(): map_iter<Key, T, Compare>() {}
		map_rev_iter(const map_iter<Key, T, Compare> &src): map_iter<Key, T, Compare>(src) {}
		map_rev_iter(const map_rev_iter &src): map_iter<Key, T, Compare>(src._p, src._root) {}
		virtual ~map_rev_iter() {}

		map_rev_iter &operator=(const map_rev_iter &rhs)
		{
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		reference operator*()
		{
			if (this->_p == this->_root)
				return *(this->_root->last()->val);
			return *(this->_p->prev()->val);
		}
		const_reference operator*() const
		{
			if (this->_p == this->_root)
				return *(this->_root->last()->val);
			return *(this->_p->prev()->val);
		}
		pointer operator->()
		{
			if (this->_p == this->_root)
				return this->_root->last()->val;
			return this->_p->prev()->val;
		}
		const_pointer operator->() const
		{
			if (this->_p == this->_root)
				return this->_root->last()->val;
			return this->_p->prev()->val;
		}

		map_rev_iter operator--(int) // 후위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_rev_iter result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}
		map_rev_iter &operator--() // 전위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}
		map_rev_iter operator++(int) // 후위
		{
			map_rev_iter result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}
		map_rev_iter &operator++() // 전위
		{
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const
		{
			return this->_p;
		}
		const node_type getRoot() const
		{
			return this->_root;
		}

		map_iter<Key, T, Compare> base() const
		{
			return map_iter<Key, T, Compare>(this->_p, this->_root);
		}
	};

	template <typename Key, typename T, class Compare>
	class map_rev_const_iter: public map_const_iter<Key, T, Compare>
	{
	public:
		using typename map_const_iter<Key, T, Compare>::key_type;
		using typename map_const_iter<Key, T, Compare>::mapped_type;
		using typename map_const_iter<Key, T, Compare>::value_type;
		using typename map_const_iter<Key, T, Compare>::key_compare;
		using typename map_const_iter<Key, T, Compare>::node_type;
		using typename map_const_iter<Key, T, Compare>::reference;
		using typename map_const_iter<Key, T, Compare>::const_reference;
		using typename map_const_iter<Key, T, Compare>::pointer;
		using typename map_const_iter<Key, T, Compare>::const_pointer;

	private:
		class OutOfRangeException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return "map_rev_const_iter::OutOfRangeException";
			}
		};

	public:
		map_rev_const_iter(): map_const_iter<Key, T, Compare>() {}
		map_rev_const_iter(const map_const_iter<Key, T, Compare> &src): map_const_iter<Key, T, Compare>(src) {}
		map_rev_const_iter(const map_rev_const_iter &src): map_const_iter<Key, T, Compare>(src._p, src._root) {}
		virtual ~map_rev_const_iter() {}

		map_rev_const_iter &operator=(const map_rev_const_iter &rhs)
		{
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		const_reference operator*() const
		{
			if (this->_p == this->_root)
				return *(this->_root->last()->val);
			return *(this->_p->prev()->val);
		}
		const_pointer operator->() const
		{
			if (this->_p == this->_root)
				return this->_root->last()->val;
			return this->_p->prev()->val;
		}

		map_rev_const_iter operator--(int) // 후위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_rev_const_iter result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}
		map_rev_const_iter &operator--() // 전위
		{
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}
		map_rev_const_iter operator++(int) // 후위
		{
			map_rev_const_iter result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}
		map_rev_const_iter &operator++() // 전위
		{
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const
		{
			return this->_p;
		}
		const node_type getRoot() const
		{
			return this->_root;
		}

		map_const_iter<Key, T, Compare> base() const
		{
			return map_const_iter<Key, T, Compare>(this->_p, this->_root);
		}
	};
}

#endif
