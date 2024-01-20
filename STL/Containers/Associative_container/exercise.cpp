#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

// exercises
// 1. Display the word and count
// 2. set of line numbers in which the word appears.

void display_words(const std::map<std::string, int> &words)
{
    cout << std::setw(12) << std::left << "\nWord"
         << std::setw(7) << std::right << "Count" << std::endl;
    cout << "==============================" << std::endl;

    for (auto pair : words)
    {
        cout << std::setw(12) << std::left << pair.first
             << std::setw(7) << std::right << pair.second << std::endl;
    }
}

void display_words(const std::map<std::string, std::set<int>> &words)
{
    cout << std::setw(12) << std::left << "\nWord"
         << std::setw(7) << std::right << "Line Number" << std::endl;
    cout << "==============================" << std::endl;

    for (auto pair : words)
    {
        cout << std::setw(12) << std::left << pair.first << std::left << "[";
        for (auto ele : pair.second)
            cout << ele << ",";
        cout << "]" << endl;
    }
}
// /home/prasad/VS-code/C++/I.O and Streams/FileOperations/test.txt

std::string clean_string(const std::string &string)
{
    std::string result;
    for (char c : string)
    {
        if (c == '.' || c == ',' || c == ';' || c == ':' || c == '?')
            continue;
        else
            result += c;
    }
    return result;
}

void part1()
{
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"../../../I.O and Streams/FileOperations/test.txt"};
    if (in_file)
    {
        while (std::getline(in_file, line))
        {
            std::stringstream ss{line};
            while (ss >> word)
            {
                word = clean_string(word);
                words[word]++;
            }
        }
        in_file.close();
        display_words(words);
    }
    else
        std::cerr << "Error opening file" << std::endl;
}

void part2()
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    int lineCount = 0;
    std::ifstream in_file{"../../../I.O and Streams/FileOperations/test.txt"};
    if (in_file)
    {
        while (std::getline(in_file, line))
        {
            lineCount++;
            std::stringstream ss{line};
            while (ss >> word)
            {
                word = clean_string(word);
                words[word].insert(lineCount);
            }
        }
        in_file.close();
        display_words(words);
    }
    else
        std::cerr << "Error opening file" << std::endl;
}

int main()
{
    part1();
    part2();
    return 0;
}