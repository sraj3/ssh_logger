#include "../inc/config.hpp"
#include "../conf/logger.hpp"
#include <iostream>

Config load_config()
{
    Config config;
    config.db_host = DB_HOSTNAME;
    config.db_name = DB_NAME;
    config.db_pass = DB_PASSWORD;
    config.db_user = DB_USERNAME;
    config.log_file = LOG_FILE;

    return config;
}
