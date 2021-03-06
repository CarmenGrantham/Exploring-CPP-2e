//
// Created by carmen on 8/10/2015.
//
// Can be tested with
// jack smith
// john smith
// end


#ifndef DEPGRAPH_H_
#define DEPGRAPH_H_


#include <unordered_map>
#include <unordered_set>

#include "artifact.h"
#include "topological_sort.h"

/// Dependency graph.
/// From Listing 58-5
class dependency_graph
{
public:
    typedef std::unordered_map<artifact, std::unordered_set<artifact>> graph_type;

    void store_dependency(artifact target, artifact dependency)
    {
        graph_[dependency].insert(target);
        graph_[target]; // ensures that target is in the graph
    }

    graph_type const& graph() const { return graph_; }

    template<class OutIter>
    void sort(OutIter sorted)
    const
    {
        topological_sort(graph_, sorted);
    }

    void dump()
    {
        for (auto const& target : graph()) {
            std::cout << target.first.name() << ": ";
            for (auto const& dep : target.second)
                std::cout << dep.name();
            std::cout << '\n';
        }
    }

private:
    graph_type graph_;
};

#endif
