#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
using namespace std;
struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double price = 0.0;
};

int salesdata_input(Sales_data *data, char *dataname)
{
        if(dataname != NULL){cout << dataname << endl;}
        cout << "Enter ISBN: ";
        if(cin >> data->bookNo);
        else return -1;
        cout << "Enter count: ";
        if(cin >> data->units_sold);
        else return -1;
        cout << "Enter price: ";
        if(cin >> data->price);
        else return -1;
        data->revenue = data->units_sold * data->price;

        return 0;

}

int salesdata_summcycle_withsameISBN()
{
    Sales_data data1, data2;

    std::cout << "Enter the first record:" << std::endl;
    int err = salesdata_input(&data1, NULL);
    cout << endl;

    if(err == 0){
            std::cout << "Enter the same ISBN transactions:" << std::endl;
            while(err == 0){
                err = salesdata_input(&data2, NULL);
                if(data1.bookNo == data2.bookNo){
                    data1.revenue += data2.revenue;
                    data1.units_sold += data2.units_sold;
                }
                else {
                    std::cout << "ISBN do not match" << std::endl;
                    err = 1;
                }
            }
            std::cout << "SUMM = " <<  data1.bookNo
                      << " " << data1.units_sold
                      << " " << data1.revenue
                      << std::endl;
            return 0;
    }
    if(err == -1){
        cerr << "Uncorrect transaksion." << endl;
        return -1;
    }
}

int salesdata_summ()
{
    Sales_data data1, data2;

        salesdata_input(&data1, "Data1");
        salesdata_input(&data2, "Data2");

        if(data1.bookNo == data2.bookNo){
            cout << "ISBN: " << data1.bookNo << '\n'
                 << "Sold: " << data1.units_sold + data2.units_sold
                 << "\nSumm: " << data1.revenue + data2.revenue << endl;
            return 0;
        }
        else {
            cout << "ISBN's do not match." << endl;
            return -1;
}
}

int salesdata_summcycle_withsameISBNv2()
{
     Sales_data data1, data2;

    std::cout << "Transactions input started:" << '\n';
    int err = salesdata_input(&data1,NULL);

    if(err == 0){
        int count1 = 1;
        err = salesdata_input(&data2,NULL);
        for( err = 0; err == 0; err = salesdata_input(&data2,NULL)){
            if(data1.bookNo == data2.bookNo) count1++;
            else {
                std::cout << "The number of transactions for " << data1.bookNo
                          << " = "  << count1 << std::endl;
                data1 = data2, count1 = 1;
            }
        }
        std::cout << "The number of transactions for " << data1.bookNo
                  << " = "  << count1 << std::endl;
        return 0;
    }
    if(err == -1){
        cerr << "Uncorrect transaksion." << endl;
        return -1;
    }
}
#endif
