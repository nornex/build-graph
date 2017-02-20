#include <iostream>
#include <memory>

#include "config/operation_node.hpp"
#include "config/io_node.hpp"
#include "config/graph.hpp"

int main()
{
    using namespace node;

    std::cout << "Hello, World!" << std::endl;

    auto graph = node::Graph<OperationNode, IoNodeFile>{};

    auto& src_file  = graph.CreateNode<IoNodeFile>("foo", "./foo.txt");
    auto& dest_file = graph.CreateNode<IoNodeFile>("bar", "./bar.txt" );

    auto& copy_op =
        graph.CreateNode<OperationNode>("copy")
        .AddInput(src_file)
        .AddOutput(dest_file);

    for (const auto& io : graph.NodesOfType<IoNodeFile>())
    {
        std::cout << io.id() << std::endl;
    }

    for (const auto& op : graph.NodesOfType<OperationNode>())
    {
        std::cout << op.id() << std::endl;
    }

//
//    auto src_file  = node::IoNodeFile { "foo", "./foo.txt" };
//    auto dest_file = node::IoNodeFile { "bar", "./bar.txt" };
//
//    auto op = node::OperationNode { "copy" };
//
//    op.AddInput(src_file);
//    op.AddOutput(dest_file);
//
//    for (const auto& i : op.inputs())
//    {
//        std::cout << i.id() << std::endl;
//    }
//
//    for (const auto& i : op.outputs())
//    {
//        std::cout << i.id() << std::endl;
//    }

    return 0;
}

