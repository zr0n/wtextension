#include <map>

using namespace std;

struct MAP_CREATOR{
    static map<string, string> create(){
        map<string,string> m;
        m["txt"] = "A TXT file is a standard text document that contains unformatted text. It is recognized by any text editing or word processing program and can also be processed by most other software programs.";
        return m;
    }
    //static const map<string, string> myMap;
};

const map<string, string> EXTENSIONS_INFO = MAP_CREATOR::create();