#pragma once

#include "Log.h"
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <memory>
#include <string>

namespace Lacy2D {
    class MySQLDatabase {
    public:
        MySQLDatabase(const std::string& server, const std::string& username, const std::string& password, const std::string& database);
        ~MySQLDatabase();

        void connect();
        void disconnect();

        // Example database operations
        bool insertPlayer(const std::string& name, const std::string& email);
        std::shared_ptr<sql::ResultSet> getPlayers();

    private:
        std::string server, username, password, database;
        sql::mysql::MySQL_Driver* driver;
        std::unique_ptr<sql::Connection> con;
    };
}