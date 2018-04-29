#ifndef _DB_HPP_
#define _DB_HPP_

#include "lib/rapidjson/filereadstream.h"
#include "lib/rapidjson/filewritestream.h"
#include "lib/rapidjson/writer.h"
#include "lib/rapidjson/prettywriter.h"
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/stringbuffer.h"

class DB {

private:
    FILE* db_file;
    const int BUFFER_SIZE = 65546;

    DB();
    ~DB();

    void load();
    void save(bool);
public:

    static DB& getInstance() {
        static DB singleton;
        return singleton;
    };

    rapidjson::Document d;

    void init();
};

#endif