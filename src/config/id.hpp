#pragma once

#include <string>

namespace node
{
    class NodeId
    {
    public:
        NodeId(std::string name) : name_(std::move(name)) {}
        NodeId(const char* name) : name_(name) {}

        friend std::ostream& operator<< (std::ostream& stream, const NodeId& id)
        {
            stream << id.name_;
            return stream;
        }

    private:
        std::string name_;
    };

}