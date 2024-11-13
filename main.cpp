#include "database.h"
#include "logger.h"
#include "interactive_mode.h"

int main() {
    try {
        Logger logger("database.log");
        Database db("example.db", &logger);

        db.executeQuery("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT);");
        db.executeQuery("INSERT INTO users (name) VALUES ('YALOKGAR'), ('yalo');");

        auto rows = db.fetchQuery("SELECT * FROM users;");
        for (const auto& row : rows) {
            for (const auto& col : row) {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }

        interactiveMode(db);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}