#include <cstring>
#include <cctype>
#include <vector>


int sourceFind(const std::vector<std::pair<char,bool>>& source, char fchar)
{
   for(size_t i = 0; i < source.size();++i){
       if(islower(fchar) && source[i].first == fchar - 32) return i;
       if(isupper(fchar) && source[i].first == fchar + 32) return i;
       if(source[i].first == fchar) return i;
   }
   return -1;
}

size_t duplicateCount(const std::string& in); // helper for tests
size_t duplicateCount(const char* in)
{
   std::vector< std::pair<char, bool> > source;
   int index;
   size_t result = 0;
    for(size_t i = 0; i <= strlen(in);++i){
        if( (index = sourceFind(source, in[i]) ) && index == -1) source.push_back({in[i], 0});
        else if(source[index].second == 0){
            source[index].second = 1;
            result++;
        }
     }
  return result;
}