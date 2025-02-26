#include <iostream>

#include "Playlist.h"

using namespace std;

int main() {
  string title;
  cout << "Enter playlist's title:" << endl;
  getline(cin,title);

  Playlist P;

  // P.AddSong("01", "uma", "a", 19);
  // P.AddSong("02", "nic", "k", 20);
  // P.AddSong("03", "divya", "b", 19);
  // P.AddSong("04", "sarina", "l", 19);
  P.PrintMenu(title);
  while(true) {
    string command;
    if (command == "q") {
      break;
    }
    if (!(cin >> command)) {
      break;
      }
    if (command == "a") {
      string songID; 
      string songname; 
      string artistname; 
      int songlength; 
      cout << "ADD SONG\n" << "Enter song's unique ID:\n";
      cin.ignore();
      getline(cin,songID); 
      cout << "Enter song's name:\n";
      getline(cin,songname); 
      cout << "Enter artist's name:\n";
      getline(cin, artistname);
      cout << "Enter song's length (in seconds):\n";
      cin >> songlength;
      P.AddSong(songID, songname, artistname, songlength);
    } else if (command == "d") {
      P.RemoveSong();
    } else if (command == "c") {
      P.ChangePositionSong();
    } else if (command == "s") {
      P.OutputSongsByArtist();
    } else if (command == "t") {
      P.OutputTotalTime();
    } else if (command == "o") {
      P.OutputFullPlaylist(title);
    } else if (command == "q") {
      break;
    }
    P.PrintMenu(title);
  }

  // If cin is in an error state (even end-of-file), then
  // something went wrong
  if (!cin) {
    cout << "Program did not exit cleanly" << endl;
    return 1;
  }
  
  return 0;
}
