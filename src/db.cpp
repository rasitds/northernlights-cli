#include "db.hpp"
#include "utils.hpp"

DB::DB() {

}

DB::~DB() {

}

void DB::init() {
    print("INIT: DATABASE");
    load();
}

void DB::load() {
    FILE* fp = fopen("db.json", "r");

    char readBuffer[65536];

    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    d.ParseStream(is);

    fclose(fp);
}