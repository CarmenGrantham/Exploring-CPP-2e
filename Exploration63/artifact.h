//
// Created by carmen on 8/10/2015.
//

#ifndef EXPLORING_CPP_2E_ARTIFACT_H
#define EXPLORING_CPP_2E_ARTIFACT_H

#include <chrono>
#include <memory>
#include <string>

class artifact_impl;

class artifact
{
public:
    typedef std::chrono::system_clock clock;
    artifact();
    artifact(std::string const& name);
    artifact(artifact const&) = default;
    ~artifact() = default;
    artifact& operator=(artifact const&) = default;

    std::string const& name()     const;
    clock::time_point  mod_time() const;
    std::string        expand(std::string str) const;

    void build();
    clock::time_point get_mod_time();

    void store_variable(std::string const& name, std::string const& value);

private:
    std::shared_ptr<artifact_impl> pimpl_;
};

inline bool operator<(artifact const& a, artifact const& b)
{
    return a.name() < b.name();
}


#endif //EXPLORING_CPP_2E_ARTIFACT_H
