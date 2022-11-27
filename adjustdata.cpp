#include <fstream>
#include <string>
int main()
{
    std::ifstream input("test.txt");
    std::ofstream output("khafan.txt");
    std::string comma = ",";
    std::string line;
    while (getline(input, line))
    {
        std::string to_be_used = line + comma + "\n";
        output << to_be_used;
    }
    output.close();
    input.close();
    return 0;
}