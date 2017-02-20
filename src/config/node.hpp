# pragma once

#include <vector>
#include "boost/iterator/indirect_iterator.hpp"

#include "id.hpp"

namespace node
{
    class BaseNode
    {
    public:
        typedef NodeId TId;

        BaseNode(TId&& id) : id_(id) {}

        virtual ~BaseNode() = default;

        const TId& id() const { return id_; }

    protected:
        std::vector<BaseNode*> inputs_;
        std::vector<BaseNode*> outputs_;
    private:
        TId id_;
    };


    template<class T>
    class NodeCollection
    {
    public:
        typedef boost::iterators::use_default TDefault;
        typedef boost::indirect_iterator<typename std::vector<T*>::const_iterator, TDefault, TDefault, const T> TIter;

        NodeCollection(const std::vector<BaseNode*>& vector)
        :
            vector_((const std::vector<T*>&) vector)
        {}

        TIter begin() const {  return vector_.begin(); }

        TIter end() const { return vector_.end(); }

        auto size() const { return vector_.size(); }

        auto empty() const { return vector_.empty(); }

    private:
        const std::vector<T*>& vector_;
    };


    template<class TInput, class TOutput>
    class Node : protected BaseNode
    {
    public:
        Node(TId&& id) : BaseNode(std::move(id)) {}

        const TId& id() const { return BaseNode::id(); }

    protected:
        typedef Node<TInput, TOutput> TBase;
        typedef NodeCollection<TInput>  TInputCollection;
        typedef NodeCollection<TOutput> TOutputCollection;

        auto inputs() const  { return TInputCollection  { inputs_ }; }
        auto outputs() const { return TOutputCollection { outputs_ }; }

        void AddInput(TInput &input)
        {
            static_assert(std::is_base_of<BaseNode, TInput>::value,  "TInput must be a descendant of BaseNode");
            inputs_.emplace_back(reinterpret_cast<BaseNode*>(&input));
        }

        void AddOutput(TOutput &output)
        {
            static_assert(std::is_base_of<BaseNode, TOutput>::value, "TOutput must be a descendant of BaseNode");
            outputs_.emplace_back(reinterpret_cast<BaseNode*>(&output));
        }
    };
}