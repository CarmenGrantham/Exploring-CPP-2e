//
// Created by carmen on 8/10/2015.
//
// Can be tested with
// jack smith
// john smith
// end

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "artifact.h"
#include "topological_sort.h"

typedef std::size_t artifact_index;

class dependency_graph {
public:
    typedef std::unordered_map<std::shared_ptr<artifact>, std::unordered_set<std::shared_ptr<artifact>>> graph_type;

    void store_dependency(std::shared_ptr<artifact> target, std::shared_ptr<artifact> dependency) {
        graph_[dependency].insert(target);
        graph_[target];                     // ensures that target is in the graph
    }

    graph_type const& graph() const { return graph_; }

    template<class OutIter>
    void sort(OutIter sorted) const {
        topological_sort(graph_, sorted);
    }

private:
    graph_type graph_;
};

std::map<std::string, std::shared_ptr<artifact>> artifacts{};
std::shared_ptr<artifact> lookup_artifact(std::string const& name) {
    std::shared_ptr<artifact> a( artifacts[name]);
    // If name not found add it to map
    if (a.get() == nullptr) {
        a = std::make_shared<artifact>(name);
        artifacts[name] = a;
    }
    return a;
}


int main() {
    dependency_graph graph{};

    std::string line{};
    while (std::getline(std::cin, line)) {
        std::string target_name{}, dependency_name{};
        std::istringstream stream{line};

        if (stream >> target_name >> dependency_name) {
            std::shared_ptr<artifact> target{lookup_artifact(target_name)};
            std::shared_ptr<artifact> dependency{lookup_artifact(dependency_name)};
            graph.store_dependency(target, dependency);
        } else if (not target_name.empty()) {
            // Input line has a target with no dependency, so report an error
            std::cerr << "malformed input: target, " << target_name << ", must be followed by a dependency name\n";

            // Only way I can exit while loop (bit of a hack) - CG
            break;
        }
        // else ignore blank lines
    }

    try {
        // Get the artifacts. The sort stores them in reverse order.
        std::vector<artifact*> sorted{};
        graph.sort(std::back_inserter(sorted));
        // Then print them in the correct order
        std::cout << "Dependency list\n";
        for (auto it(sorted.rbegin()), end(sorted.rend()); it != end; ++it) {
            std::cout << (*it)->name() << '\n';         // -> has higher precedence than *, so must put *it in brackets
        }
    } catch (std::runtime_error const& ex) {
        std::cerr << ex.what() << '\n';
        return EXIT_FAILURE;
    }
}
