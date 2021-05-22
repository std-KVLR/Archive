#include "ProgramBlocks.h"


prblocks::DataInputController::DataInputController(const size_t argc, const char** argv)
{
    init(argc, argv);
}


void prblocks::DataInputController::init(const size_t argc, const char** argv)
{
    for(size_t i = 1, strWatch = 1; i < argc; ++i)
    {
       if(!strcmp(argv[i], "-o") && strWatch)
        {
            //Create Function read from file
            readFileKey.setTrue();
            std::ifstream fileToRead(argv[++i]);

            try
            {
                if(!fileToRead.is_open())throw std::runtime_error(argv[i]);;
                if(read_data_from_file(fileToRead) == -1)
                {
                    std::cerr << "Some happens with input stream. Please restart the program and try again.\n";
                    break;
                }
                std::cout << "Data has been read from file \" " << argv[i];
                strWatch = 0;
            }
            catch(std::invalid_argument &e)
            {
                std::cerr << "Specified file not found " << e.what() << "\n";
                std::cerr << "File must be closed and data will be reading from arguments\n";
            }
            readFileKey.setFalse();
            fileToRead.close();
        }
        else if(!strcmp (argv[i],"-w"))
        {
            saveDataKey.setTrue();
            nameFileToWrite = argv[++i];
        }

        if(strWatch)
        {
            if(!strcmp(argv[i], "-i"))
            {
                ++i;
                typeDataKey = INT;
                argsprocessing::format::string_format_int(args, argv[i]);
            }
            else if(!strcmp(argv[i], "-s"))
            {
                ++i;
                typeDataKey = STRING;
                args.assign(argv[i]);
            }
            else if(!strcmp(argv[i], "-c"))
            {
                ++i;
                typeDataKey = CHAR;
                argsprocessing::format::string_format_char(args, argv[i]);
            }
            else if(!strcmp(argv[i], "-d"))
            {
                ++i;
                typeDataKey = DOUBLE;
                argsprocessing::format::string_format_double(args, argv[i]);
            }
            else{
                typeDataKey = STRING;
                args.assign(argv[i]);
            }
            if(!args.empty()){
                std::cout << "Data has been readed from argument string\n";//
            }
            strWatch = 0;
        }
    }
    if(args.empty()) throw std::runtime_error("Error: necessary data line not found.");
}

int prblocks::DataInputController::read_data_from_file(std::ifstream &file)
{
            std::string tmp;
            char c;
            while((file.get(c)) && c != EOF ){
                tmp.push_back(c);
            }

            if(!file.good() && !file.eof()) return -1;
            if(tmp[0] == '-'){
                if(tmp[1] == 'i') argsprocessing::format::string_format_int(args, &tmp[3]);
                if(tmp[1] == 'c') argsprocessing::format::string_format_char(args, &tmp[3]);
                if(tmp[1] == 'd') argsprocessing::format::string_format_double(args, &tmp[3]);
                if(tmp[1] == 's') args = &tmp[3];
            }
            return 0;
}










