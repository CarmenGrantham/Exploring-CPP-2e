//
// Created by carmen on 8/10/2015.
//

typedef std::map<std::string, std::string> variable_map;
variable_map variables{};

std::string expand(std::string str) {
    std::string::size_type start{0};        // start searching here
    while (true) {
        // find a dollar sign
        std::string::size_type pos{str.find('$', start)};
        if (pos == std::string::npos) {
            // No more dollar sign
            return str;
        }
        if (pos == str.size() - 1 or str[pos + 1] != '(') {
            // Not a variable reference. Skip the dollar sign and keep searching
            start = pos + 1;
        } else {
            std::string::size_type end{str.find(')', pos)};
            if (end == std::string::npos) {
                // No closing paranthesis.
                return str;
            }

            // Get the variable name.
            std::string varname{str.substr(pos + 2, end - pos - 2)};
            // Replace the entire variable reference.
            str.replace(pos, end - pos + 1, variables[varname]);
            // Scan the replacement text for more variables
            start = pos;
        }
    }
}