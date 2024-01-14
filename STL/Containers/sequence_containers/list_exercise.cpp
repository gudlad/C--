#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include "Song.hpp"

using std::cin;
using std::cout;
using std::endl;

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    cout << "Playing" << endl;
    cout << song << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    for (const Song &song : playlist)
    {
        cout << song << endl;
    }
    cout << "Current song" << endl;
    cout << current_song << endl;
}

int main()
{

    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    char selection{};
    do
    {
        display_menu();
        cin >> selection;
        selection = std::toupper(selection);
        if (selection == 'F')
        {
            cout << "Playing First Song" << endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }
        else if (selection == 'N')
        {
            cout << "Playing Next Song" << endl;
            current_song++;
            if (current_song == playlist.end())
            {
                cout << "Wrapping to start of playlist" << endl;
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
        }
        else if (selection == 'P')
        {
            cout << "Playing Previous Song" << endl;
            if (current_song == playlist.begin())
            {
                cout << "Wrapping to end of playlist" << endl;
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);
        }
        else if (selection == 'A')
        {
            std::string name, artist;
            int rating;

            // standard practice
            // just clear out everything in std::cin, clears out if there are any garbage values extra returns etc
            // just to make sure that cin is clean.
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Adding and playing new songs" << endl;
            cout << "Enter song name: " << endl;
            std::getline(cin, name);
            cout << "Enter song artist: " << endl;
            std::getline(cin, artist);
            cout << "Enter song rating(1-5): " << endl;
            cin >> rating;

            playlist.insert(current_song, Song{name, artist, rating});
            current_song--;
            play_current_song(*current_song);
        }
        else if (selection == 'L')
        {
            cout << endl;
            display_playlist(playlist, *current_song);
        }
        else if (selection == 'Q')
        {
            cout << "Quitting..." << endl;
        }
        else
        {
            cout << "Cancelling...Illegal Choice.. try again" << endl;
        }

    } while (selection != 'Q');

    cout << "Thanks for Listening" << endl;
    return 0;
}