# pragma once

#include <tuple>
#include <vector>

#include "boost/range/join.hpp"

#include "node.hpp"

namespace node
{
    class GraphCollection
    {

    };

    template <class TNode>
    class BaseNodeCollection
    {

    };

    template <class... TNodes>
    class Graph
    {
    public:
        template<class TNode, class... TArgs>
        TNode& CreateNode(TArgs&&... args)
        {
            auto& node_vector = vector<TNode>();
            node_vector.emplace_back(std::forward<TArgs>(args)...);
            return node_vector.back();
        }

        template<class TNode>
        const std::vector<TNode>& NodesOfType() const
        {
            return std::get<std::vector<TNode>>(node_vectors_);
        }

//        template<class TNode>
//        template std::vector<> NodesOfTypes()
//        {
//
//        }
//
//        template<class TFirstNode, class... TRemainingNodes>
//        auto NodesOfTypes() const
//        {
//            return boost::range::join(NodesOfTypes<TFirstNode>(), NodesOfTypes<TRemainingNodes...>());
//        }
//
//        auto AllNodes()

    private:
        std::tuple<std::vector<TNodes>...> node_vectors_;

        template<class TNode>
        std::vector<TNode>& vector()
        {
            return std::get<std::vector<TNode>>(node_vectors_);
        }


//        template<class TNode>
//        std::vector<BaseNode>& base_vector()
//        {
//            return reinterpret_cast<std::vec> vector<TNode>()
//        }
    };
}