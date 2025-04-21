#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger {
private:
    vector<string> logs;
    static const int MAX_LOGS = 1000;

    void addLog(const string& severity, const string& message) {
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());
        }
        logs.push_back("[" + severity + "] " + message);
    }

public:
    void logInfo(const string& msg) { addLog("INFO", msg); }
    void logWarning(const string& msg) { addLog("WARNING", msg); }
    void logError(const string& msg) { addLog("ERROR", msg); }

    friend class Auditor;
};

class Auditor {
private:
    string password;

public:
    Auditor(const string& pwd) : password(pwd) {}

    void viewLogs(const Logger& logger) {
        if (password == "admin123") {
            for (const string& log : logger.logs) {
                cout << log << endl;
            }
        } else {
            cout << "Access denied. Invalid credentials." << endl;
        }
    }
};

int main() {
    Logger systemLogger;

    systemLogger.logInfo("Network module initialized.");
    systemLogger.logWarning("Database response slow.");
    systemLogger.logError("Connection lost with server.");

    Auditor a("wrongpass");
    a.viewLogs(systemLogger);

    Auditor admin("admin123");
    admin.viewLogs(systemLogger);

    return 0;
}
