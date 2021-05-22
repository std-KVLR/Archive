#include <string>
#include <vector>


std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> result;
    if(s.empty()) return result;


    result.push_back("");
    for(size_t strI = 0, vecI = 0; strI < s.size() ; ++strI){
      if(result[vecI].size() == 2){
          result.push_back("");
          ++vecI;
        }  
      result[vecI].push_back(s[strI]);
        
    }
    if( (result.end() - 1)->size() & 1 ) (result.end() - 1)->push_back('_');
    return result;
}
