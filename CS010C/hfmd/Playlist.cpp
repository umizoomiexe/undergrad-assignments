#include "Playlist.h"

PlaylistNode::PlaylistNode() 
  :uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0) 
  {}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength)
  :uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr)
  {}


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
        
        if (head == nullptr) {
            head = song_to_add;
            tail = song_to_add; 
        } else {
            tail-> InsertAfter(song_to_add); // insert song to add after tail, as teh added song wld be last 
            tail = song_to_add; // update tail after old tail points to added song
        }
    }

    
void Playlist::RemoveSong() {
  cout << "REMOVE SONG" << endl; 
  //if list is empty
   if (head == nullptr) {
        return;
    }
    string uniqueID;
    cout << "Enter song's unique ID:\n" ; 
    cin >> uniqueID; 
    //if head needs to be removed 
    if (head->GetID() == uniqueID) {
        PlaylistNode* temp = head;
        head = head->GetNext();
        string songname = temp->GetSongName();
        delete temp;
        cout << '"' << songname << '"' <<  " removed.\n" ;
        return;
    }

    PlaylistNode* current = head;
    PlaylistNode* previous = nullptr;

    while (current != nullptr && current->GetID() != uniqueID) {
        previous = current; 
        current = current->GetNext();
    }
      //if tail 
    if (current->GetNext() == nullptr) {
        PlaylistNode* temp = tail;
        tail = previous;
        string songname = temp->GetSongName();
        delete temp;
        cout << '"' << songname << '"' <<  " removed.\n" ;
        return;
    }

    previous->SetNext(current->GetNext());
    string songname = current->GetSongName();
    delete current;
    cout << '"' << songname << '"' << " removed.\n";
    }

    
void Playlist::ChangePositionSong() {
  cout << "CHANGE POSITION OF SONG\n";

    //test case if playlist empty 
    if (head == nullptr) {
        return;
    }

    int currentPosition;
    cout << "Enter song's current position:\n";
    cin >> currentPosition;

    //test case if input is less than 1 
    if (currentPosition < 1) {
        return;
    }

    int newPosition;
    cout << "Enter new position for song:\n";
    cin >> newPosition;

    
    // test case: is newposition is less than 1 ? 
    if (newPosition < 1) {
        return;
    }

    //find current position node 
    PlaylistNode* currentPosNode= head;
    PlaylistNode* prevPosNode = nullptr; 
     for (int i = 1; i < currentPosition; i++) {
        if(currentPosNode== nullptr){ 
          break;
        }
        prevPosNode = currentPosNode; 
        currentPosNode = currentPosNode->GetNext();
    }
        //until here is good 
    PlaylistNode* temp1 = currentPosNode;

     if (prevPosNode != nullptr) {
        prevPosNode->SetNext(currentPosNode->GetNext());
    } else {
        head = currentPosNode->GetNext();
    }
    PlaylistNode* NewPosNode= head;
    PlaylistNode* previousofNew= nullptr;
     for (int i = 1; i < newPosition; i++) {
        if(NewPosNode== nullptr){ 
          break;
        }
        previousofNew = NewPosNode; 
        NewPosNode = NewPosNode->GetNext();
    }
    if(newPosition>currentPosition){
      temp1->InsertAfter(NewPosNode);
      if(NewPosNode == nullptr){
        tail = temp1;
      }
    }
    else if(newPosition<currentPosition){
      temp1->InsertAfter(previousofNew);
      if(previousofNew == nullptr){
        head=temp1;
      }
    }
    cout << '"' << temp1->GetSongName() << '"' << " moved to position " << newPosition << endl; 
    string toremoveID = currentPosNode->GetID();
    //running til here before exiting 

  if (head == nullptr) {
        return;
    }
  if (head->GetID() == toremoveID) {
        PlaylistNode* temp2 = head;
        head = head->GetNext();
        string songname = temp2->GetSongName();
        delete temp2;
        return;
    }
   PlaylistNode* current = head;
  PlaylistNode* previous = nullptr;

    while (current != nullptr && current->GetID() != toremoveID) {
        previous = current; 
        current = current->GetNext();
    }
      //if tail 
    if (current->GetNext() == nullptr) {
        PlaylistNode* temp2 = tail;
        tail = previous;
        string songname = temp2->GetSongName();
        delete temp2;
        return;
    }

    previous->SetNext(current->GetNext());
    string songname = current->GetSongName();
    delete current;
 
  delete temp1; 
}


void Playlist::OutputSongsByArtist() const {
    string artistName;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST\n";
    cout << "Enter artist's name:\n";
    cin.ignore(); 
    getline(cin, artistName);

    bool found = false; // to track if there are no songs w that artist 
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

    if (!found) {
        cout << "No songs found for artist " << artistName << "\n";
    }
}

    
void Playlist::OutputTotalTime() const {
  int totalTime = 0;
  for(const PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
     totalTime += curr->GetSongLength();
  }
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n";
    cout << "Total time: " << totalTime << " seconds\n";
}

void Playlist::OutputFullPlaylist(const string& playlistTitle) const{
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST\n";
   
    if (head == nullptr) {
        cout << "Playlist is empty\n";
        return;
    }

    int position = 1;
    PlaylistNode* current = head;

    while (current != nullptr) {
      if(current == head){
        cout << position << ".\n";
      }
      else{
        cout << '\n' << position << ".\n";
      }
        current->PrintPlaylistNode();
      if(current == tail){
        cout << "\n";
        return; 
      }
        cout << "\n";

        current = current->GetNext();
        position++;
    }

}


