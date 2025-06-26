#ifndef DB_HPP
#define DB_HPP

#include <string>
#include "config.hpp"

class DBHandler
{
    public:
        DBHandler(const Config& cfg);
        void log_event(const std::string& time, const std::string& user,
                    const std::string& result, const std::string& ip);

    private:
        const Config& config;
};

#endif
