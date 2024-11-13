# **DBManager**

**DBManager** is a simple yet powerful C++ program designed to interact with SQLite databases. It allows users to create, manage, and query databases through both automated and interactive modes. The project is modular, with clear separation of functionality for logging, database interaction, and user interaction.

---

## **Features**

- Create and interact with SQLite databases.
- Execute SQL queries such as `CREATE`, `INSERT`, `UPDATE`, `DELETE`, and `SELECT`.
- Interactive mode for manual SQL query execution.
- Logs all database actions to a log file for auditing.
- Modular design for extensibility.

---

## **Getting Started**

### Prerequisites

To build and run this project, ensure you have the following installed:

- **C++ Compiler** (e.g., `g++`)
- **SQLite3 Library**  
  Install SQLite3 library if not already installed:
  ```bash
  sudo apt-get install libsqlite3-dev    # For Debian/Ubuntu
  brew install sqlite                    # For macOS
  ```

---

### Installation

1. Clone this repository:  
   ```bash
   git clone https://github.com/your-username/DBManager.git
   cd DBManager
   ```

2. Compile the project:  
   ```bash
   g++ main.cpp database.cpp logger.cpp interactive_mode.cpp -o dbmanager -lsqlite3
   ```

3. Run the program:  
   ```bash
   ./dbmanager
   ```

---

### Usage

1. **Automated Execution**  
   The program will:
   - Create a database file named `example.db` (if not already present).
   - Create a table called `users`.
   - Insert some sample data (`Alice` and `Bob`).
   - Fetch and display the data from the `users` table.

2. **Interactive Mode**  
   Enter interactive mode to manually execute SQL queries:
   ```bash
   ./dbmanager
   ```
   Type SQL commands directly into the terminal. For example:
   ```sql
   SELECT * FROM users;
   INSERT INTO users (name) VALUES ('Charlie');
   ```

   Type `exit` to quit interactive mode.

3. **Logs**  
   All executed queries and actions are logged to a file named `database.log`.

---

## **Project Structure**

```
DBManager/
├── main.cpp              # Program entry point
├── database.h            # Database class header
├── database.cpp          # Database class implementation
├── logger.h              # Logger class header
├── logger.cpp            # Logger class implementation
├── interactive_mode.h    # Interactive mode header
├── interactive_mode.cpp  # Interactive mode implementation
└── README.md             # Project documentation
```

---

## **Contributing**

Contributions are welcome! If you’d like to improve this project:

1. Fork the repository.
2. Create a feature branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature-name`.
5. Open a pull request.

---

## **Contact**

If you have any questions or suggestions, feel free to open an issue or reach out at discord `yalokgar`.
