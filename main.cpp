#include "inc/config.hpp"
#include "inc/db.hpp"
#include "inc/parser.hpp"

int main() 
{
    Config config = load_config();
    DBHandler db(config);
    LogParser parser(config, db);

    parser.start();

    return 0;
}
