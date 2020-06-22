//
// Created by holysheep on 2020/6/22.
//

#ifndef MR_BELIEVE_STL_STL_LIST_H
#define MR_BELIEVE_STL_STL_LIST_H

#include "stl_config.h"
#include "stl_iterator_base.h"
#include "stl_alloc.h"
#include "stl_alloc.h"
#include "stl_iterator.h"
#include "stl_algobase.h"

__STL_BEGIN_NAMESPACE
    struct _List_node_base {
        _List_node_base *_M_next;
        _List_node_base *_M_prev;
    };
    template<class _Tp>
    struct _List_node : public _List_node_base {
        _Tp _M_data;
    };

    struct _List_iterator_base {
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef bidirectional_iterator_tag iterator_category;
        _List_node_base *_M_node;

        _List_iterator_base(_List_node_base *__x) : _M_node(__x) {}

        _List_iterator_base() {}

        void _M_incr() { _M_node = _M_node->_M_next; }

        void _M_decr() { _M_node = _M_node->_M_prev; }

        bool operator==(const _List_iterator_base &__x) const {
            return _M_node == __x._M_node;
        }

        bool operator!=(const _List_iterator_base &__x) const {
            return _M_node != __x._M_node;
        }
    };

    template<class _Tp, class _Ref, class _Ptr>
    struct _List_iterator : public _List_iterator_base {
        typedef _List_iterator<_Tp, _Tp &, _Tp *> iterator;
        typedef _List_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;
        typedef _List_iterator<_Tp, _Ref, _Ptr> _Self;
        typedef _Tp value_type;
        typedef _Ref reference;
        typedef _Ptr pointer;
        typedef _List_node<_Tp> _Node;

        _List_iterator(_Node *__x) : _List_iterator_base(__x) {}

        _List_iterator() {}

        _List_iterator(const iterator &__x) : _List_iterator_base(__x._M_node) {}

        reference operator*() const {
            return ((_Node *) _M_node)->_M_data;
        }

        pointer operator->() const {
            return &(operator*());
        }

        _Self &operator++() {
            this->_M_incr();
            return *this;
        }

        _Self operator++(int) {
            _Self __tmp = *this;
            this->_M_incr();
            return __tmp;
        }

        _Self &operator--() {
            this->_M_decr();
            return *this;
        }

        _Self operator--(int) {
            _Self __tmp = *this;
            this->_M_decr();
            return __tmp;
        }

    };

    template<class _Tp, class _Alloc>
    class _List_base {
    public:
        typedef _Alloc allocator_type;

        allocator_type get_allocator() const { return allocator_type(); }

        _List_base(const allocator_type &) {
            _M_node = _M_get_node();
            _M_node->_M_next = _M_node;
            _M_node->_M_prev = _M_node;
        }

        ~_List_base() {
            clear();
            _M_put_node(_M_node);
        }

        void clear();

    protected:
        typedef simple_alloc<_List_node<_Tp>, _Alloc> _Alloc_type;

        _List_node<_Tp> *_M_get_node() { return _Alloc_type::allocate(1); }

        void _M_put_node(_List_node<_Tp> *__p) { _Alloc_type::deallocte(__p, 1); }

    protected:
        _List_node<_Tp> *_M_node;
    };

    template<class _Tp, class _Alloc>
    void
    _List_base<_Tp, _Alloc>::clear() {
        _List_node<_Tp> *__cur = (_List_node<_Tp> *) _M_node->_M_next;
        while (__cur != _M_node) {
            _List_node<_Tp> *__tmp = __cur;
            __cur = (_List_node<_Tp> *) __cur->_M_next;
            _Destroy(&__tmp->_M_data);
            _M_put_node(__tmp);
        }
        _M_node->_M_next = _M_node;
        _M_node->_M_prev = _M_node;
    }

    template<class _Tp, class _Alloc>
    class list : protected _List_base<_Tp, _Alloc> {
        typedef _List_base<_Tp, _Alloc> _Base;
    protected:
        typedef void *_Void_pointer;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef value_type &reference;
        typedef const value &const_reference;
        typedef _List_node<_Tp> _Node;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef typename _Base::allocator_type allocator_type;

        allocator_type get_allocator const {
            return _Base::get_allocator();
        }

        public:
    };

















__STL_END_NAMESPACE


#endif //MR_BELIEVE_STL_STL_LIST_H