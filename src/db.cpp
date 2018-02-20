#include "db.hpp"
#include "utils.hpp"

DB::DB() {

}

DB::~DB() {

}

void DB::init() {
    print("system", "INIT: DATABASE");
    load();
}

void DB::load() {
    FILE* db_file = fopen("db.json", "r");

    if (!db_file) {
        db_file = fopen("db.json", "w");
        fputs("{}", db_file);
        fclose(db_file);
    }

    char readBuffer[65536];

    rapidjson::FileReadStream is(db_file, readBuffer, sizeof(readBuffer));

    d.ParseStream(is);

    fclose(db_file);
}