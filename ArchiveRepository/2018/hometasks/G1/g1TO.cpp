#include <iostream>
#include <Sales_item.h>
#include <string.h>
void exs1_9(int first, int last)
{
    int i = first, sum = 0;

        while ( i <= last){
            sum += i++;
        }
        std::cout << "Sum of " << first << " to "
                  << last << " inclusive is "
                  << sum << std::endl;
}

void exs1_10(int first, int last)
{
    int i = first;

        std::cout << "Input from " << first
                  << " to " << last << std::endl;
        while(i >= last){
            std::cout << i-- << '\n';
        }
}
void exs1_11()
{

    int v1, v2;

        std::cout << "Enter the numbers that define the range." << '\n'
                  << "First number: ";
        std::cin >> v1;
        std::cout << "Secont number: ";
        std::cin >> v2;
        std::cout << "Out: " << std::endl;
        if(v1 < v2){
            while(v1++ < v2 - 1){
                std::cout << v1 << '\n';
            }
        }
        else if (v1 > v2){
            while(v2++ < v1 - 1){
                std::cout << v2 << '\n';
            }
        }
        else std::cout << "NONE\nThe numbers are equal." << std::endl;
}
void exs1_16()
{
    int sum = 0, x;

        std::cout << "Enter the sequence:" << std::endl;
        while(std::cin >> x){
            sum += x;
        }
        std::cout << "Result: " << sum << std::endl;
}
void exs1_19()
{
    int v1, v2;

        std::cout << "Enter the numbers that define the range." << '\n'
                  << "First number: ";
        std::cin >> v1;
        std::cout << "Secont number: ";
        std::cin >> v2;
        std::cout << "Out: " << std::endl;
        if(v1 < v2){
            while(v1 <= v2 - 1){
                std::cout << v1++ << '\n';
            }
        }
        else if (v1 > v2){
            while(v2 <= v1 - 1){
                std::cout << v2++ << '\n';
            }
        }
        else std::cout << "NONE\nThe numbers are equal." << std::endl;
}
void exs1_21()
{
    Sales_item item1, item2;
    std::cout << "Enter the first record:" << std::endl;
    std::cin >> item1;

    std::cout << "Enter the second record:" << std::endl;
    std::cin >> item2;
    if(item1.isbn() == item2.isbn())
       std::cout << "SUMM = " <<  item1 + item2 << std::endl;
    else std::cout << "Error: number mismatch." << std::endl;

}
void exs1_22()
{
    Sales_item item1, item2;

    std::cout << "Enter the first record:" << std::endl;
    std::cin >> item1;

    std::cout << "Enter the same ISBN transactions:" << std::endl;
        while(std::cin >> item2){
        if(item1.isbn() == item2.isbn()) item1 += item2;
        else std::cout << "ISBN do not match" << std::endl;
    }

    std::cout << "SUMM = " <<  item1 << std::endl;
}
void exs1_23()
{
     Sales_item item1, item2;

    std::cout << "Transactions input started:" << std::endl;
    std::cin >> item1;
    int count1 = 1;
        while(std::cin >> item2){
            if(item1.isbn() == item2.isbn()) count1++;
            else{ std::cout << "The number of transactions for " << item1
                           << " = "  << count1 << std::endl;
                  item1 = item2, count1 = 1;
            }
    }
    std::cout << "The number of transactions for " << item1
              << " = "  << count1 << std::endl;
}
int exs1_25()
{
    Sales_item total;

    if(std::cin >> total){
        Sales_item trans;
        while(std::cin >> trans){
            if(total.isbn() == trans.isbn()){
                total += trans;
            }
            else{
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else{
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
