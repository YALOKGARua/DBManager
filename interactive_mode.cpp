#include "interactive_mode.h"
#include <iostream>

void interactiveMode(Database& db) {
    std::string input;
    std::cout << "Interactive mode. Enter SQL queries (type 'exit' to quit):" << std::endl;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        try {
            if (input.find("SELECT") == 0) {
                auto rows = db.fetchQuery(input);
                for (const auto& row : rows) {
                    for (const auto& col : row) {
                        std::cout << col << " ";
                    }
                    std::cout << std::endl;
                }
            } else {
                db.executeQuery(input);
                std::cout << "Query executed successfully." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}