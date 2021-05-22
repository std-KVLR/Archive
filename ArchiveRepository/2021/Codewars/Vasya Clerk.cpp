#include <string>
#include <vector>

std::string tickets(const std::vector<int>& peopleInLine) {
    size_t billCounts[2] = {0,0};
  
    for(auto it = peopleInLine.begin(); it != peopleInLine.end(); it++){
      switch(*it)
        {
        case 25:
              billCounts[0]++;
              break;
        case 50:
              if(billCounts[0]){
                billCounts[0]--, billCounts[1]++;
                break;
              }
              
        case 100:
             if(billCounts[0] >= 3 || (billCounts[1] && billCounts[0])){
              if(billCounts[1]) billCounts[0]--, billCounts[1]--;
              else billCounts[0] -= 3;  
              break;
             }
          
       default:
              return std::string{"NO"};
        }
    }
    return std::string{"YES"};
}
