//
// Created by carmen on 9/10/2015.
//

class artifact {
public:
    typedef std::chrono::system_clock clock;

    artifact() : name_{}, mod_time_{clock::time_point()} {}

    artifact(artifact&& source) noexcept : name_{std::move(source.name_)}, mod_time_{std::move(source.mod_time_)}, variables_{source.variables_} {
        source.variables_ = nullptr;
    }

    artifact& operator=(artifact&& source) noexcept {
        delete variables_;
        variables_ = source.variables_;
        source.variables_ nullptr;
        name_ = std::move(source.name_);
        mod_time_ = std::move(source.mod_time_);
        return *this;
    }


}
