int digital_root(int n)
{
   if(n < 0) return -1;

  int summ;
  do
  {
    summ = 0;
    do
    {
      
      summ += n % 10;
      
    } while(n /= 10);

    n = summ;
    
   } while(summ/10);

  return summ;
}