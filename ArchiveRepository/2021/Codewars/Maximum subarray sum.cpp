#include <vector>


int maxSequence(const std::vector<int>& arr){

  if(arr.empty()) return 0;

  int stepSumm = 0;
  int result = arr[0];

  for(size_t i = 0, j = 0; i < arr.size(); ++j){

    
    if( !(j <= arr.size()) ){
          ++i;
          j = i;
          stepSumm = 0;
      }
    
    stepSumm += arr[j];
    if(stepSumm > result) result = stepSumm;
  }


  return result;
}