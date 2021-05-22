#include <string>
std::string solution(int number){

  std::string romanStr;

  if(number >= 1000){ romanStr += std::string(number/1000, 'M'); number -= 1000 * (number/1000); }

  if(number >= 900) { romanStr += "CM"; number -= 900; }

  if(number >= 500) { romanStr += 'D'; number -= 500; }

  if(number >= 400) { romanStr += "CD"; number -= 400; }

  if(number >= 100) { romanStr += std::string(number/100, 'C'); number -= 100 * (number/100); }

  if(number >= 90) { romanStr += "XC"; number -= 90; }

  if(number >= 50) { romanStr += 'L'; number -= 50; }
  
  if(number >= 40) { romanStr += "XL"; number -= 40; }

  if(number >= 10) { romanStr += std::string(number/10, 'X'), number -= 10 * (number/10); }

  if(number == 9) { romanStr += "IX"; number -= 9; }

  if(number >= 5) { romanStr += 'V'; number -= 5; }
  
  if(number == 4) { romanStr += "IV"; number -= 4; }

  if(number > 0) { romanStr += std::string(number, 'I'); }

  return romanStr;

}