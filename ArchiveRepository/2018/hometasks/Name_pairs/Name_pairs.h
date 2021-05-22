#ifndef NAME_P_H
#define NAME_P_H

#include <string>
#include <vector>

class Name_pairs
{
public:
    const short ioFail = -1;
    void read_names();
    void read_ages();
    void sort();

    friend std::ostream& operator<<(std::ostream&, const Name_pairs&);
    friend bool operator==(const Name_pairs&, const Name_pairs&);
    friend bool operator!=(const Name_pairs&, const Name_pairs&);
private:
    std::vector<std::string> name;
    std::vector<double> age;
};

#endif // NAME_P_H
