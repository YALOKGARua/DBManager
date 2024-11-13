#include "database.h"
#include <stdexcept>
#include <sqlite3.h>

Database::Database(const std::string& dbName, Logger* logger) : logger(logger) {
    if (sqlite3_open(dbName.c_str(), reinterpret_cast<sqlite3**>(&db)) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database");
    }
    if (logger) {
        logger->log("Database opened: " + dbName);
    }
}

Database::~Database() {
    if (db) {
        sqlite3_close(reinterpret_cast<sqlite3*>(db));
        if (logger) {
            logger->log("Database closed");
        }
    }
}

void Database::executeQuery(const std::string& query) {
    char* errorMessage = nullptr;
    int result = sqlite3_exec(reinterpret_cast<sqlite3*>(db), query.c_str(), nullptr, nullptr, &errorMessage);
    if (result != SQLITE_OK) {
        std::string error(errorMessage);
        sqlite3_free(errorMessage);
        throw std::runtime_error("Failed to execute query: " + error);
    }
    if (logger) {
        logger->log("Executed query: " + query);
    }
}

std::vector<std::vector<std::string>> Database::fetchQuery(const std::string& query) {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(reinterpret_cast<sqlite3*>(db), query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare query");
    }

    std::vector<std::vector<std::string>> result;
    int cols = sqlite3_column_count(stmt);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < cols; ++i) {
            const char* data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            row.push_back(data ? data : "");
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    if (logger) {
        logger->log("Fetched query: " + query);
    }
    return result;
}