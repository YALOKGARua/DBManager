#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "logger.h"

class Database {
public:
    Database(const std::string& dbName, Logger* logger = nullptr);
    ~Database();

    void executeQuery(const std::string& query);
    std::vector<std::vector<std::string>> fetchQuery(const std::string& query);

private:
    void* db;
    Logger* logger;
    void checkError(int resultCode, const std::string& errorMessage);
};

#endif