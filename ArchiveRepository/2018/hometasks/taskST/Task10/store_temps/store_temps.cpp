    #include <iostream>
    #include <fstream>
    #include <cmath>
    #include <string>
    #include <cstdlib>
    #include <ctime>
    #include <vector>
    #include "D:\Programming\CFILES\C++\TasksStroustrup\Task10\Reading.cpp"
    using namespace std;



    string form_lString(const string& startStr, size_t nSpace)
    {
        string workStr = startStr;

        while(workStr.size() != nSpace)
        {
            workStr.push_back(' ');
        }
        return workStr;
    }


    string formString_toTask10(void)
    {
       Reading workStruct = randReading();
       string input =
                     "\n|" + form_lString(to_string(workStruct.day), 3) + "|"
                    + form_lString(to_string(workStruct.hour), 4) + "|"
                    + form_lString(to_string(workStruct.temperature) + workStruct.scale, 11) + "|";
       return input;
    }

    int main()
    {

        vector<string> dataVec;

        cout << "Enter number of records: ";
        int i;
        cin >> i;
        while(--i, i >= 0)
        {
            dataVec.push_back(formString_toTask10());
        }
        fstream ofs("D:\\Programming\\CFILES\\C++\\TasksStroustrup\\Task10\\raw_temps.txt", ios_base::out | ios_base::app);

        for(auto &s : dataVec)
        {
            cout << s << '\n';
            ofs << s;
        }
        ofs.close();
        cout << "Success!" << endl;

        return 0;
    }








