#ifndef PARSER_HPP
#define PARSER_HPP

#include "config.hpp"
#include "db.hpp"

class LogParser
{
    public:
        LogParser(const Config& cfg, DBHandler& db);
        void start();

    private:
        const Config& config;
        DBHandler& db;
        std::string parse_datetime(const std::string& line);
};

#endif
