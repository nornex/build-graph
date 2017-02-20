#pragma once

#include <string>
#include <vector>
#include <memory>

#include "boost/optional.hpp"

#include "id.hpp"
#include "node.hpp"

namespace node
{
    // Prototypes
    class IoNode;
    class OperationNode;

    class OperationNode : public Node<IoNode, IoNode>
    {
    public:
        OperationNode(TId id) : TBase(std::move(id)) {}

        auto inputs() const  { return TBase::inputs(); }
        auto outputs() const { return TBase::outputs(); }

        OperationNode& AddInput(IoNode& input);
        OperationNode& AddOutput(IoNode& output);
    };

}