#ifndef _DB_HPP_
#define _DB_HPP_

#include "lib/rapidjson/filereadstream.h"
#include "lib/rapidjson/filewritestream.h"
#include "lib/rapidjson/writer.h"
#include "lib/rapidjson/prettywriter.h"
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/stringbuffer.h"
#include "lib/rapidjson/pointer.h"

using namespace rapidjson;

class DB {

private:
    FILE* db_file;

    DB();
    ~DB();

    void load();
    void save(bool);
public:

    static DB& getInstance() {
        static DB singleton;
        return singleton;
    };

    Document d;

    void init();
    void test();
};

#endif