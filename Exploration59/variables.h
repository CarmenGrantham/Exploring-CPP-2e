//
// Created by carmen on 8/10/2015.
//

#ifndef EXPLORING_CPP_2E_VARIABLES_H
#define EXPLORING_CPP_2E_VARIABLES_H

#include <map>
#include <string>

typedef std::map<std::string, std::string> variable_map;
extern variable_map global_variables;

/// Expand variables in a string using a local map
/// and the global key
/// @param str The string to expand
/// @param local_variables The optional, local map; can be null
/// @return The expanded string
std::string expand(std::string str, variable_map const* local_variables);

#endif //EXPLORING_CPP_2E_VARIABLES_H
