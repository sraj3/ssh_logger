#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

struct Config
{
    std::string db_host;
    std::string db_user;
    std::string db_pass;
    std::string db_name;
    std::string log_file;
};

Config load_config();

#endif
