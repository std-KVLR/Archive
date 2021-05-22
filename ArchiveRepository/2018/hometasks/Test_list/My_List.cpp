#include "My_List.h"



My_list::My_list(const My_list &My_list_copy)
{
    name = My_list_copy.name;
    STR_LST = My_list_copy.STR_LST;
}
void My_list::print_all()
{
    for(size_t i = 0; i < STR_LST.size(); ++i)
        std::cout << i << ": " << STR_LST[i] << '\n';

}
void My_list::del_record(size_t i)
{
    STR_LST.erase(STR_LST.begin()+ i);
}
std::istream& operator>>(std::istream &is, My_list &i_data)
{
    std::string temp;
    is >> temp;
    i_data.STR_LST.push_back(temp);
    return is;
}
std::ostream& operator<<(std::ostream &os, const My_list &o_data)
{
    for(auto &str: o_data.STR_LST) std::cout << str << ' ';
    std::cout << '\n';
    return os;
}
