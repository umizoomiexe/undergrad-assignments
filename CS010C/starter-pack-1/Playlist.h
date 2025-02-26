//PLAYLIST.H FILE 
#pragma once //notetoself: use in .h files rather than ifndef

#include <iostream>

using namespace std;

class PlaylistNode {
  string uniqueID;
  string songName;
  string artistName;
  int songLength;
  PlaylistNode* nextNodePtr;
public:
  PlaylistNode();
  PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
  ~PlaylistNode(); 
  PlaylistNode* GetNextNodePtr() const { return nextNodePtr; }
  void SetNextNodePtr(PlaylistNode* newNode) { nextNodePtr = newNode; }
  void InsertAfter(PlaylistNode*  );
  void SetNext(PlaylistNode* newNode); 
  const string& GetID() const { return uniqueID; }
  const string& GetArtistName() const { return artistName; }
  const string& GetSongName() const { return songName; }
  int GetSongLength() const { return songLength; }
  PlaylistNode* GetNext() { return nextNodePtr; }
  const PlaylistNode* GetNext() const { return nextNodePtr; }
  const void PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << '\n';
    cout << "Song Name: " << songName << '\n';
    cout << "Artist Name: " << artistName << '\n';
    cout << "Song Length (in seconds): " << songLength;
  }
};

class Playlist {
  PlaylistNode* head;
  PlaylistNode* tail;
public:
  Playlist()
    : head(nullptr),tail(nullptr)
  {}
  void PrintMenu(const string& title) const; // dont change dec.
  void AddSong(const string& id, const std::string& song, const std::string& artist, int length); // dont change dec. PROGA EXITING NOT CLEAN 
  void RemoveSong();
  void ChangePositionSong();
  void OutputSongsByArtist() const;
  void OutputTotalTime() const;
  void OutputFullPlaylist(const string& playlistTitle) const;
};

