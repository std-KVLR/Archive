#ifndef DATA_INPUT
#define DATA_INPUT

#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <ctype.h>
namespace argsprocessing
{
    namespace format{


        void string_format_char(std::string &str_buf, const char* source);
        void string_format_double(std::string &str_buf, const char* source);
        void string_format_int(std::string &str_buf, const char* source);
    }

    // keys classses

    class Key
    {
        bool key = 0;
        std::string name;

    public:
        Key() = default;
        Key(std::string &keyname)
            :name(keyname){}
        Key(const char* keyname)
            :name(keyname) {}

        //value operation
        void setTrue() { key = true; }
        void setFalse() { key = false; }
        void changeState() { key = !key; }
        bool curState() { return key; }


        //compare operator block
        friend bool operator==(const Key& curKey, const Key& othKey) { return curKey.name == othKey.name; }
        friend bool operator==(const Key& curKey, const std::string& str) { return curKey.name == str; }
        friend bool operator==(const std::string& str, const Key& curKey) { return curKey.name == str; }
        friend bool operator==(const Key& curKey, const char* str) { return curKey.name == str; }
        friend bool operator==(const char* str, const Key& curKey) { return curKey.name == str; }

    };
}


#endif // DATA_INPUT
