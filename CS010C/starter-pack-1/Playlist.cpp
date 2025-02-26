//PLAYLIST.CPP FILE 
#include "Playlist.h"

using namespace std;

//constructor 
PlaylistNode::PlaylistNode() 
  :uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0) 
  {}

//copy constructor 
PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength)
  :uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr)
  {}

//destructor
PlaylistNode::~PlaylistNode()
  {}

//NOTE: From now, refer to function's descriptive names to understand what it is doing to a song(node) in playlist. 
void PlaylistNode::InsertAfter(PlaylistNode* node_to_insert) {
    node_to_insert->SetNext(nextNodePtr);
    SetNext(node_to_insert);
}

void PlaylistNode::SetNext(PlaylistNode* setnextnode){
  nextNodePtr = setnextnode; 
}

void Playlist::PrintMenu(const string& title) const {
  cout << "\n" << title  << " PLAYLIST MENU\n"
		<< "a - Add song\n"
		<< "d - Remove song\n"
		<< "c - Change position of song\n"
		<< "s - Output songs by specific artist\n"
		<< "t - Output total time of playlist (in seconds)\n"
		<< "o - Output full playlist\n"
		<< "q - Quit\n"
		<< "\n"
    << "Choose an option:\n";
}

void Playlist::AddSong(const string& id, const std::string& song, const std::string& artist, int length) {
  PlaylistNode* song_to_add = new PlaylistNode(id, song, artist, length);
    //TEST CASE: if list is empty, head and tail will both point to the added song and exit function
    if (head == nullptr) {
      head = song_to_add;
      tail = song_to_add; 
      return;
    }
    //ELSE : insert song at end of playlist (after tail). inserted song will be last. 
    tail-> InsertAfter(song_to_add); 
    tail = song_to_add; 

    delete song_to_add;
}
 
void Playlist::RemoveSong() {
  cout << "REMOVE SONG" << endl; 
  //TEST CASE: if list is empty, we exit function. can't remove from nothing, duh 
  if (head == nullptr) {
    return;
  }

  string uniqueID;
  cout << "Enter song's unique ID:\n" ; 
  cin >> uniqueID; 

  //TEST CASE: if first song needs to be removed (removing head is special case). then exit.
  if (head->GetID() == uniqueID) {
    PlaylistNode* temp = head;
    head = head->GetNext();
    string songname = temp->GetSongName();
    delete temp;
    cout << '"' << songname << '"' <<  " removed.\n" ;
    return;
  } 

  //Iterate through list to find node to remove: 
  PlaylistNode* current = head;
  PlaylistNode* previous = nullptr;
  
  while (current != nullptr && current->GetID() != uniqueID) { 
    previous = current; 
    current = current->GetNext();
  }

  //TEST CASE: if last song needs to be removed (removing tail is special case). then exit.  
  if (current->GetNext() == nullptr) {
    PlaylistNode* temp = tail;
    tail = previous;
    string songname = temp->GetSongName();
    delete temp;
    cout << '"' << songname << '"' <<  " removed.\n" ;
    return;
  }

  //Normal Case 
  previous->SetNext(current->GetNext());
  string songname = current->GetSongName();
  delete current;
  cout << '"' << songname << '"' << " removed.\n";

}

//NOTE: This function is currently NOT WORKING. 
//NOTE:It runs, but it is a logic issue that needs to be resolved. 
void Playlist::ChangePositionSong() {
  cout << "CHANGE POSITION OF SONG\n";

  //TEST CASE: if playlist is empty, exit function. 
  if (head == nullptr) {
      return;
  }

  int currentPosition;
  cout << "Enter song's current position:\n";
  cin >> currentPosition;

  //TEST CASE: if position to change (input by user) is less than 1. exit function. 
  if (currentPosition < 1) {
      return;
  }

  int newPosition;
  cout << "Enter new position for song:\n";
  cin >> newPosition;

  
  //TEST CASE: is newposition is less than 1 ? if so, exit function. 
  if (newPosition < 1) {
      return;
  }

  //Find+store current position node  & it's previous node
  PlaylistNode* currentPosNode= head;
  PlaylistNode* prevPosNode = nullptr; 
    for (int i = 1; i < currentPosition; i++) {
      if(currentPosNode== nullptr){ 
        break;
      }
      prevPosNode = currentPosNode; 
      currentPosNode = currentPosNode->GetNext();
  } //function runs without issues until this point. 


  PlaylistNode* temp1 = currentPosNode;
  //TEST CASE: if current node isn't head 
  if (prevPosNode != nullptr) {
    prevPosNode->SetNext(currentPosNode->GetNext());
  } 
  else {
    head = currentPosNode->GetNext();
  }

  //Find+store new position node & it's previous node
  PlaylistNode* NewPosNode= head;
  PlaylistNode* previousofNew= nullptr;
  for (int i = 1; i < newPosition; i++) {
    if(NewPosNode== nullptr){ 
      break;
    }
    previousofNew = NewPosNode; 
    NewPosNode = NewPosNode->GetNext();
  }

  //INSERT INTO NEW POSITION 
  //TEST CASE: if new position is after current, insert after temp1
  if(newPosition>currentPosition){
    temp1->InsertAfter(NewPosNode);
    if(NewPosNode == nullptr){
      tail = temp1;
    }
  } else if(newPosition<currentPosition){ //else insert before 
    temp1->InsertAfter(previousofNew);
    if(previousofNew == nullptr){
      head=temp1;
    }
  } //ERROR: use of InsertAfter function here is WRONG. InsertAfter will only insert at end of list. 

  cout << '"' << temp1->GetSongName() << '"' << " moved to position " << newPosition << endl; 
  string toremoveID = currentPosNode->GetID();

  //REMOVE OLD POSITION FROM FUNCTION
  //TEST CASE: if we need to remove from head (special case). exit after. 
  if (head->GetID() == toremoveID) {
        PlaylistNode* temp2 = head;
        head = head->GetNext();
        string songname = temp2->GetSongName();
        delete temp2;
        return;
    }
  
  //Find+store node to remove 
  PlaylistNode* current = head;
  PlaylistNode* previous = nullptr;

  while (current != nullptr && current->GetID() != toremoveID) {
      previous = current; 
      current = current->GetNext();
  }

  //TEST CASE: if we need to remove tail node (special case). exit after removal. 
  if (current->GetNext() == nullptr) {
      PlaylistNode* temp2 = tail;
      tail = previous;
      string songname = temp2->GetSongName();
      delete temp2;
      return;
  }

  //Normal case for removal 
  previous->SetNext(current->GetNext());
  string songname = current->GetSongName();
  delete current;
 
  delete temp1; 
  //ERRORS: function results in output playlist to be infinite loop. Zybooks give -6 &-11 error. 
  //notetoself: look for dangling pointers and memory management in second half. consider helper function. InsertAfter used wrong. 
}

void Playlist::OutputSongsByArtist() const {
  //Retrieve input from User 
  string artistName;
  cout << "OUTPUT SONGS BY SPECIFIC ARTIST\n";
  cout << "Enter artist's name:\n";
  cin.ignore(); 
  getline(cin, artistName);

  //TEST CASE: use bool false to track if there are no songs with artist that user wants.
  bool found = false;

  //Iterate through list and Print nodes that include artist that user inputted 
  int position = 1; 
  for (const PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) { 
    if (curr->GetArtistName() == artistName) {
      cout << "\n" << position << ".\n"; 
      curr->PrintPlaylistNode();
      cout << "\n";
      found = true;
    }
    position++;
  }

  //SAME TEST CASE: if bool remains false, there are no songs of inputted artist in list. 
  if (!found) {
    cout << "No songs found for artist " << artistName << "\n";
  }

}

void Playlist::OutputTotalTime() const {
  //Initialize time of playlist to 0 seconds to avoid random numbers  
  int totalTime = 0;

  //Iterate through list and add up all seconds 
  for(const PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
     totalTime += curr->GetSongLength();
  }

  cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n";
  cout << "Total time: " << totalTime << " seconds\n";
}

void Playlist::OutputFullPlaylist(const string& playlistTitle) const{
  cout << playlistTitle << " - OUTPUT FULL PLAYLIST\n";
  
  //TEST CASE: if list is empty, we tell user they are dumb. exit function. 
  if (head == nullptr) {
    cout << "Playlist is empty\n";
    return;
  }

  int position = 1;
  PlaylistNode* current = head;

  //Iterate through list and print each node 
  //TEST CASE: only iterate until we have reached the tail (and printed it). once reaching nullptr(tail), exit loop.
  while (current != nullptr) {
    //TEST CASE: if we are printing head, address special case 
    if(current == head){
      cout << position << ".\n";
    }
    else{
      cout << '\n' << position << ".\n";
    }
    
    current->PrintPlaylistNode();

    //TEST CASE: if we are printing head, address special case 
    if(current == tail){
      cout << "\n";
      return; 
    }

    //Normal Case 
    cout << "\n";
    current = current->GetNext();
    position++;
  }
}


