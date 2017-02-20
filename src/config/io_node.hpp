//
// Created by Matt on 16-Feb-17.
//

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "boost/optional.hpp"

#include "node.hpp"

namespace node
{
    // Prototypes
    class IoNode;
    class OperationNode;

    enum class IoType
    {
        File,
        Const,
        Var
    };

    class IoNode : public Node<OperationNode, OperationNode>
    {
    public:
        typedef NodeId Id;

        friend class OperationNode;

        IoNode(IoType type, TId&& id) : TBase(std::move(id)), type_(type) {}

        template<class T>
        boost::optional<T&> As()
        {
            if (type_ != T::kTypeId)
            {
                return boost::none;
            }

            return static_cast<T &>(*this);
        }

    private:
        IoType type_;
    };


    template<IoType TIoType>
    class IoNodeImpl : public IoNode
    {
    public:
        static constexpr IoType kTypeId = TIoType;
    protected:
        IoNodeImpl(TId id) : IoNode(TIoType, std::move(id))
        {}
    };


    class IoNodeFile : public IoNodeImpl<IoType::File>
    {
    public:
        IoNodeFile(Id id, std::string file)
            : IoNodeImpl<IoType::File>(id), file_(std::move(file))
        {}

        std::string file_;
    };

}