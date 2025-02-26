//MAIN.CPP FILE 
#include <iostream>

#include "Playlist.h"

using namespace std;

int main() {
  //Retrieve user input for name of playlist
  string title;
  cout << "Enter playlist's title:" << endl;
  getline(cin,title);

  Playlist P;
  P.PrintMenu(title);

  while(true) {
    string command;
    if (command == "q") {
      break;
    } 
    if (!(cin >> command)) {
      break;
    }
    if (command == "a") { //add song command
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
    } else if (command == "d") { //remove song commande 
      P.RemoveSong();
    } else if (command == "c") { //change position of song command 
      P.ChangePositionSong();
    } else if (command == "s") { //output all songs by inputted artist command 
      P.OutputSongsByArtist();
    } else if (command == "t") { //output total time of playlist command
      P.OutputTotalTime();
    } else if (command == "o") { //output all nodes with their info for full playlist 
      P.OutputFullPlaylist(title);
    } else if (command == "q") { //quit command 
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

//END OF MAIN.CPP
