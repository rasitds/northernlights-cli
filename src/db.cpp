#include "db.hpp"
#include "utils.hpp"

#define BUFFER_SIZE 65546

DB::DB() {

}

DB::~DB() {

}

void DB::init() {
    print("system", "INIT: DATABASE");
    print("system", "RUN: INITIALIZING DATABASE");
    load();
}

void DB::load() {
    print("system", "RUN: READ DATABASE FILE");
    db_file = fopen("db.json", "r");

    print("system", "RUN: CHECK DATABASE FILE");
    if (!db_file) {
        print("system", "RUN: WRITE DATABASE FILE");
        db_file = fopen("db.json", "w");
        fputs("{}", db_file);
        fclose(db_file);
    }

    char readBuffer[BUFFER_SIZE];

    FileReadStream is(db_file, readBuffer, sizeof(readBuffer));

    if (d.ParseStream(is).HasParseError()) {
        print("system", "FAIL: PARSE ERROR");
    }

    fclose(db_file);
}

void DB::save(bool withPrettier = false) {
    print("system", "RUN: WRITE DATABASE FILE");
    db_file = fopen("db.json", "w");

    char writeBuffer[BUFFER_SIZE];

    FileWriteStream os(db_file, writeBuffer, sizeof(writeBuffer));

    if (withPrettier) {
        print("system", "RUN: PRETTIER");
        PrettyWriter<FileWriteStream> writer(os);
        d.Accept(writer);
    } else {
        Writer<FileWriteStream> writer(os);
        d.Accept(writer);
    }

    print("system", "RUN: SAVE DATABASE FILE");
    fclose(db_file);
}

void DB::test() {
    print("system", "RUN: DATABASE TEST");

    assert(d.IsObject());

    Value::MemberIterator checkAbc = d.FindMember("abc");
    if (checkAbc == d.MemberEnd())
        return;

    d["abc"].SetString("rapid", 5);

    const std::string abc = "abc: ";
    print("system", "TEST: " + abc + d["abc"].GetString());

    d["abc"].SetString("json", 4);

    print("system", "TEST: " + abc + d["abc"].GetString());

    save(true);
}