//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlMap.h
//    Author:      Streamlet
//    Create Time: 2009-11-07
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLMAP_H_793F2C3D_4121_413E_B70F_E7A686081AC4_INCLUDED__
#define __XLMAP_H_793F2C3D_4121_413E_B70F_E7A686081AC4_INCLUDED__


#include "../xlDef.h"
#include "xlPair.h"
#include "xlRBTree.h"

namespace xl
{
    template <typename K, typename V>
    class Map
    {
    public:
        Map();
        Map(const Map &that);
        ~Map();

    public:
        Map<K, V> &operator = (const Map<K, V> &that);
        bool operator == (const Map<K, V> &that) const;
        bool operator != (const Map<K, V> &that) const;
        V &operator [] (const K &key);
        const V &operator [] (const K &key) const;

    public:
        bool Empty() const;
        size_t Size() const;

    protected:
        RBTree<Pair<K, V>> m_tRBTree;

    public:
        void Delete(const K &key);
        void Clear();

    // Iterator

    public:
        typedef typename RBTree<Pair<K, V>>::Iterator Iterator;
        typedef typename RBTree<Pair<K, V>>::ReverseIterator ReverseIterator;

    public:
        Iterator Begin() const;
        Iterator End() const;
        ReverseIterator ReverseBegin() const;
        ReverseIterator ReverseEnd() const;

    public:
        Iterator Find(const K &key);
        Iterator Insert(const K &key, const V &value);
        Iterator Insert(const Pair<K, V> &pair);
        Iterator Delete(const Iterator &itWhich);
        ReverseIterator Delete(const ReverseIterator &itWhich);
    };

    template <typename K, typename V>
    inline Map<K, V>::Map()
    {

    }

    template <typename K, typename V>
    inline Map<K, V>::Map(const Map &that)
    {
        this->m_tRBTree = that.m_tRBTree;
    }

    template <typename K, typename V>
    inline Map<K, V>::~Map()
    {

    }

    template <typename K, typename V>
    inline Map<K, V> &Map<K, V>::operator = (const Map<K, V> &that)
    {
        if (this == &that)
        {
            return *this;
        }

        this->m_tRBTree = that.m_tRBTree;

        return *this;
    }

    template <typename K, typename V>
    inline bool Map<K, V>::operator == (const Map<K, V> &that) const
    {
        if (this == &that)
        {
            return true;
        }

        if (this->Size() != that.Size())
        {
            return false;
        }

        for (typename RBTree<Pair<K, V>>::Iterator itThis = this->m_tRBTree.Begin(), itThat = that.m_tRBTree.Begin();
            itThis != this->m_tRBTree.End() && itThat != that.m_tRBTree.End();
            ++itThis, ++itThat)
        {
            if (itThis->Key != itThat->Key || itThis->Value != itThat->Value)
            {
                return false;
            }
        }

        return true;
    }

    template <typename K, typename V>
    inline bool Map<K, V>::operator != (const Map<K, V> &that) const
    {
        if (this == &that)
        {
            return false;
        }

        if (this->Size() != that.Size())
        {
            return true;
        }

        for (typename RBTree<Pair<K, V>>::Iterator itThis = this->m_tRBTree.Begin(), itThat = that.m_tRBTree.Begin();
            itThis != this->m_tRBTree.End() && itThat != that.m_tRBTree.End();
            ++itThis, ++itThat)
        {
            if (itThis->Key != itThat->Key || itThis->Value != itThat->Value)
            {
                return true;
            }
        }

        return false;
    }

    template <typename K, typename V>
    inline V &Map<K, V>::operator [] (const K &key)
    {
        typename Map<K, V>::Iterator it = Find(key);

        if (it == End())
        {
            it = m_tRBTree.Insert(Pair<K, V>(key));
        }

        return it->Value;
    }

    template <typename K, typename V>
    inline const V &Map<K, V>::operator [] (const K &key) const
    {
        typename Map<K, V>::Iterator it = Find(key);

        if (it == End())
        {
            return it->Value;
        }
        else
        {
            return V();
        }
    }

    template <typename K, typename V>
    inline bool Map<K, V>::Empty() const
    {
        return m_tRBTree.Empty();
    }

    template <typename K, typename V>
    inline size_t Map<K, V>::Size() const
    {
        return m_tRBTree.Size();
    }

    template <typename K, typename V>
    inline void Map<K, V>::Delete(const K &key)
    {
        Delete(Find(key));
    }

    template <typename K, typename V>
    inline void Map<K, V>::Clear()
    {
        m_tRBTree.Clear();
    }

    // Iterator

    template <typename K, typename V>
    inline typename Map<K, V>::Iterator Map<K, V>::Begin() const
    {
        return m_tRBTree.Begin();
    }

    template <typename K, typename V>
    inline typename Map<K, V>::Iterator Map<K, V>::End() const
    {
        return m_tRBTree.End();
    }

    template <typename K, typename V>
    inline typename Map<K, V>::ReverseIterator Map<K, V>::ReverseBegin() const
    {
        return m_tRBTree.ReverseBegin();
    }

    template <typename K, typename V>
    inline typename Map<K, V>::ReverseIterator Map<K, V>::ReverseEnd() const
    {
        return m_tRBTree.ReverseEnd();
    }

    template <typename K, typename V>
    inline typename Map<K, V>::Iterator Map<K, V>::Find(const K &key)
    {
        return m_tRBTree.Find(Pair<K, V>(key));
    }

    template <typename K, typename V>
    inline typename Map<K, V>::Iterator Map<K, V>::Insert(const K &key, const V &value)
    {
        return m_tRBTree.Insert(Pair<K, V>(key, value));
    }

    template <typename K, typename V>
    inline typename Map<K, V>::Iterator Map<K, V>::Insert(const Pair<K, V> &pair)
    {
        return m_tRBTree.Insert(pair);
    }

    template <typename K, typename V>
    inline typename Map<K, V>::Iterator Map<K, V>::Delete(const typename Map<K, V>::Iterator &itWhich)
    {
        return m_tRBTree.Delete(itWhich);
    }

    template <typename K, typename V>
    inline typename Map<K, V>::ReverseIterator Map<K, V>::Delete(const typename Map<K, V>::ReverseIterator &itWhich)
    {
        return m_tRBTree.Delete(itWhich);
    }

};

//
// For convenience of debugging, put the following code to the [AutoExpand] section of
//     X:\Program Files\Microsoft Visual Studio 10.0\Common7\Packages\Debugger\autoexp.dat
//
// ;------------------------------------------------------------------------------
// ;  xl::Map
// ;------------------------------------------------------------------------------
// xl::Map<*>{
//     preview (
//         #(
//             "[",
//             $e.m_tRBTree.m_nSize,
//             "](",
//             #tree(
//                 head: $e.m_tRBTree.m_tBinTree.m_pRoot,
//                 left: pLeft,
//                 right: pRight,
//                 size: $e.m_tRBTree.m_nSize
//             ) : $e.tValue.tValue,
//             ")"
//         )
//     )
//     children (
//         #(
//             #tree(
//                 head: $e.m_tRBTree.m_tBinTree.m_pRoot,
//                 left: pLeft,
//                 right: pRight,
//                 size: $e.m_tRBTree.m_nSize
//             ) : $e.tValue.tValue
//         )
//     )
// }
//

#endif // #ifndef __XLMAP_H_793F2C3D_4121_413E_B70F_E7A686081AC4_INCLUDED__
