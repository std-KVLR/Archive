#include "Name_pairs.h"

#include <iostream>
#include <algorithm>

void Name_pairs::read_names()
{
    std::string temp;
    while(std::cin >> temp)name.push_back(temp);
    if(std::cin.eof()){
            std::cin.clear();
            return;
    }
    if(std::cin.fail()) throw (ioFail);
}

void Name_pairs::read_ages()
{
    double temp;
    for(auto it_b = name.begin(); it_b != name.end(); ++it_b){
        std::cout << *it_b << ": ";
        std::cin >> temp;
        if(std::cin.eof()){ std::cin.clear(); break; }
        if(std::cin.fail()) throw (ioFail);
        age.push_back(temp);

    }
}

void Name_pairs::sort()
{
    std::vector<std::string> name_c = name;
    std::vector<double> age_c = age;

    std::sort(name.begin(),name.end());
    for(size_t i = 0; i < name.size(); ++i){
            for(size_t j = 0; j < name_c.size(); ++j){
                if(name[i] == name_c[j]){
                    age[i] = age_c[j];
                    break;
                }
            }
    }
}

std::ostream& operator<<(std::ostream& os, const Name_pairs &obj)
{
     for(size_t i = 0; i < obj.name.size(); ++i){
         os << "Name: " << obj.name[i]
            << " Age: " << obj.age[i] << '\n';
    }
    return os;
}

bool operator==(const Name_pairs &obj1, const Name_pairs &obj2)
{
    return obj1.name == obj2.name && obj1.age == obj2.age;
}

bool operator!=(const Name_pairs &obj1, const Name_pairs &obj2)
{
    return !(obj1 == obj2);
}
