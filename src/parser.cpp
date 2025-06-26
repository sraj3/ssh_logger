
#include <iostream>
#include <fstream>
#include <regex>
#include <thread>
#include <chrono>
#include <ctime>
#include "../inc/parser.hpp"

using namespace std;

LogParser::LogParser(const Config& cfg, DBHandler& dbh) : config(cfg), db(dbh) {}

string LogParser::parse_datetime(const string& line)
{
    time_t now = time(nullptr);
    tm* local_tm = localtime(&now);
    char year[5];
    strftime(year, sizeof(year), "%Y", local_tm);
    string ts = line.substr(0, 15);
    return string(year) + "-" + ts;
}

void LogParser::start()
{
    ifstream file(config.log_file);
    if (!file)
    {
        cerr << "Cannot open log file. Check permissions." << endl;
        return;
    }

    file.seekg(0, ios::end);
    string line;
    regex ssh_regex(R"(sshd\[\d+\]: (Failed|Accepted) password for (?:invalid user )?(\w+) from ([\d\.]+))");

    while (true) {
        while (getline(file, line))
        {
            smatch match;
            if (regex_search(line, match, ssh_regex))
            {
                string result = (match[1] == "Accepted") ? "SUCCESS" : "FAILURE";
                string user = match[2];
                string ip = match[3];
                string dt = parse_datetime(line);

                db.log_event(dt, user, result, ip);
                cout << "Logged: " << dt << ", " << user << ", " << result << ", " << ip << endl;
            }
        }

        this_thread::sleep_for(chrono::seconds(1));
        file.clear(); // clear EOF
    }
}
