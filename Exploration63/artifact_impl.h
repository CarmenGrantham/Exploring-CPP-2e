//
// Created by carmen on 16/10/2015.
//

#ifndef EXPLORING_CPP_2E_ARTIFACT_IMPL_H
#define EXPLORING_CPP_2E_ARTIFACT_IMPL_H

#include <cstdlib>
#include <chrono>
#include <memory>
#include <string>
#include "variables.h"

class artifact_impl
{
public:
    typedef std::chrono::system_clock clock;
    artifact_impl();
    artifact_impl(std::string const& name);
    artifact_impl(artifact_impl&&) = default;
    artifact_impl(artifact_impl const&) = delete;
    ~artifact_impl() = default;
    artifact_impl& operator=(artifact_impl&&) = default;
    artifact_impl& operator=(artifact_impl&) = delete;

    std::string const& name()     const { return name_; }
    clock::time_point  mod_time() const { return mod_time_; }

    std::string        expand(std::string str) const;
    void               build();
    clock::time_point  get_mod_time();
    void store_variable(std::string const& name, std::string const& value);
private:
    std::string name_;
    clock::time_point mod_time_;
    std::unique_ptr<variable_map> variables_;
};


#endif //EXPLORING_CPP_2E_ARTIFACT_IMPL_H
