# ssh_logger
ssh_logger provides an implementation to capture the successful and failed login attempts from ssh service (eg: sshd daemon in CentOS/RHEL) and store in a MySQL database table.

The table contains the following fields
a. Time and Date of Login Request
b. Username
b. Result (Success or Failure)
c. IP Address of the Client

The implementation uses a dependency on MySQL Connector library to connect to the database.
https://github.com/anhstudios/mysql-connector-cpp

**#Future roadmaps:**

 - Provide separate config file for the user to update the Database configuration.
 - use inotify to notify the update of the LOG_FILE to improve performance and CPU load.

**#Unittest procedure**
Below usecases shall be verified:
- Successful SSH login (valid user)
- Failed SSH login (invalid user)
- Failed SSH login (valid user)
- Irrelevant log line (should not match)
- Time, username, IP correctness


