#include <iostream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int process(const std::string &response, const std::string &answer)
{
    int score = 0;
    for (int i = 0; i < response.length(); i++)
        if (response.at(i) == answer.at(i))
            score++;
    return score;
}

void print_student(const std::string &name, int &score)
{
    cout << std::setw(15) << std::left << name << std::setw(5) << std::right << score << endl;
}

void print_header()
{
    cout << std::setw(15) << std::left << "Student" << std::setw(5) << std::right << "Score" << endl;
    cout << std::setw(20) << std::setfill('-') << "" << endl;
    cout << std::setfill(' ');
}

void print_footer(const double &average)
{
    cout << std::setw(20) << std::setfill('-') << "" << endl;
    cout << std::setfill(' ');
    cout << std::setw(15) << std::left << "Average Score" << std::setw(5) << std::right << average << endl;
}

int main()
{
    std::fstream in_file;

    std::string answer_key{};
    std::string name{};
    std::string response{};

    int total_students{};
    int running_sum{};
    double average{};

    in_file.open("responses.txt");

    if (!in_file)
    {
        std::cerr << "failed" << endl;
        return 1;
    }

    in_file >> answer_key;
    print_header();

    while (in_file >> name >> response)
    {
        total_students++;
        int score = process(response, answer_key);
        running_sum += score;
        print_student(name, score);
    }

    if (total_students != 0)
        average = static_cast<double>(running_sum) / total_students;

    print_footer(average);
    in_file.close();
    return 0;
}