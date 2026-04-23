# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include "replace.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    const char* filename = argv[1];
    const std::string str1 = argv[2];
    const std::string str2 = argv[3];
    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::ofstream outFile(( std::string(filename) + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not create output file." << std::endl;
        return 1;
    }
    std::ostringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    std::string new_content = my_replace(content, str1, str2);
    outFile << new_content;
    infile.close();
    outFile.close();

    return 0;
}