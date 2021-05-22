int countSmileys(std::vector<std::string> arr)
{
  if(arr.empty()) return 0;
  int smileyCount = 0;
  
  for(auto str : arr){
      if( *str.begin() == ':' || *str.begin() == ';' ) {
        if( *(str.begin() + 1) == 'D' || *(str.begin() + 1) == ')' ) smileyCount++;
        else if( *(str.begin() + 1) == '-' || *(str.begin() + 1) == '~' ){
          if( *(str.end() - 1) == 'D' || *(str.end() - 1) == ')' ) smileyCount++;
        }
      }
  }
  return smileyCount;
}

