#include "lib/rapidjson/filereadstream.h"
#include "lib/rapidjson/filewritestream.h"
#include "lib/rapidjson/writer.h"
#include "lib/rapidjson/prettywriter.h"
#include "lib/rapidjson/document.h"

class DB {

private:
    DB();
    ~DB();

    void load();

public:

    static DB& getInstance() {
        static DB singleton;
        return singleton;
    };

    rapidjson::Document d;


    void init();
};