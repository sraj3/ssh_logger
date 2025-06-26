#include "../inc/db.hpp"
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <mysql_driver.h>
#include <iostream>

using namespace std;

DBHandler::DBHandler(const Config& cfg) : config(cfg) {}

void DBHandler::log_event(const string& time, const string& user,
                          const string& result, const string& ip) 
{
    try
    {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        
        std::unique_ptr<sql::Connection> con(driver->connect(
            config.db_host, config.db_user, config.db_pass));
        con->setSchema(config.db_name);

        std::unique_ptr<sql::PreparedStatement> stmt(con->prepareStatement(
            "INSERT INTO login_events (login_time, username, result, ip_address) VALUES (?, ?, ?, ?)"));
        stmt->setString(1, time);
        stmt->setString(2, user);
        stmt->setString(3, result);
        stmt->setString(4, ip);
        stmt->execute();
    }
    catch (sql::SQLException& e)
    {
        cerr << "Database error: " << e.what() << endl;
    }
}
