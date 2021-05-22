#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void doWork(int runtime = 1)
{
    for(size_t i = 0; i < runtime; ++i){
        cout << this_thread::get_id() << "doWork" << '\n';
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

}
void doWork2(int &q)
{
    this_thread::sleep_for(chrono::milliseconds(5000));
    q = q + 5;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "********THREAD DW2 STOPPED*********";
}

int main()
{
    thread my_th(doWork, 10);
    int q = 5;
    thread my_th1(doWork2,ref(q));
    for(size_t i = 0; i < 10; ++i){
        cout << this_thread::get_id() << "main" << '\n';
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    my_th1.join();
    my_th.join();

    return 0;
}
