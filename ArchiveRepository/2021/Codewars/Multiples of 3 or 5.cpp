int solution(int number) 
{
    if(number < 0) return 0;
    int summ = 0;
    
    for(int i5 = 5, i3 = 3; i3 < number; i3 += 3){
      summ += i3;
      if(i5 < number){
        if(i5 % 3) summ += i5;
        i5 += 5;
      }
    }
  return summ;
}