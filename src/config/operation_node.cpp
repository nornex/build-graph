#include "io_node.hpp"
#include "operation_node.hpp"

namespace node
{
    OperationNode& OperationNode::AddInput(IoNode& input)
    {
        TBase::AddInput(input);
        input.AddOutput(*this);
        return *this;
    }

    OperationNode& OperationNode::AddOutput(IoNode& output)
    {
        TBase::AddOutput(output);
        output.AddInput(*this);
        return *this;
    }
}