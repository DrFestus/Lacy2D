#include "lacy2Dpch.h"

#include "MySQLDatabase.h"

namespace Lacy2D {

    MySQLDatabase::MySQLDatabase(const std::string& server, const std::string& username, const std::string& password, const std::string& database) :
        server(server), username(username), password(password), database(database) {
        driver = sql::mysql::get_mysql_driver_instance();
    }

    MySQLDatabase::~MySQLDatabase() {
        disconnect();
    }

    void MySQLDatabase::connect() {
        try {
            con.reset(driver->connect(server, username, password));
            con->setSchema(database);
            LACY2D_CORE_INFO("Database connected: {}", database);
        }
        catch (sql::SQLException& e) {
            LACY2D_CORE_ERROR("Failed to connect to database: {}, SQLException: {}", database, e.what());
        }
    }

    void MySQLDatabase::disconnect() {
        if (con.get() != nullptr) {
            con->close();
            LACY2D_CORE_INFO("Database disconnected: {}", database);
        }
    }

    bool MySQLDatabase::insertPlayer(const std::string& name, const std::string& email) {
        try {
            std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("INSERT INTO players (name, email) VALUES (?, ?)"));
            pstmt->setString(1, name);
            pstmt->setString(2, email);
            pstmt->executeUpdate();
            LACY2D_CORE_INFO("Inserted player into database: {}, {}", name, email);
            return true;
        }
        catch (sql::SQLException& e) {
            LACY2D_CORE_ERROR("Failed to insert player: {}, SQLException: {}", name, e.what());
            return false;
        }
    }

    std::shared_ptr<sql::ResultSet> MySQLDatabase::getPlayers() {
        try {
            std::unique_ptr<sql::Statement> stmt(con->createStatement());
            auto res = std::shared_ptr<sql::ResultSet>(stmt->executeQuery("SELECT * FROM players"));
            LACY2D_CORE_INFO("Retrieved players from database");
            return res;
        }
        catch (sql::SQLException& e) {
            LACY2D_CORE_ERROR("Failed to retrieve players, SQLException: {}", e.what());
            return nullptr;
        }
    }
}
