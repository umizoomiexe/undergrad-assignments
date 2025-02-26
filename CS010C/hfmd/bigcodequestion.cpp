/*[Big code] I want to implement a class that mimics a set of strings. I choose
to do it with a binary search tree. I’ve provided the header. You will implement a few 
of these functions. If you cannot make set intersection work, this is just a BST – 
but you will get partial credit. For reference, my full implementation was about 50 
additional lines. You may use recursive helpers if needed (add them to the header and 
implement them in your answer).*/

//alphebetical - size of string, first char. second char if first is same, etc. 


class StringSet {
    struct Node {
        string key;
        Node* left;
        Node* right;
        Node(const string& key)
            : key(key), left(nullptr), right(nullptr) {}
        ~Node() { delete left; delete right; }
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
    };
    Node* root;
    void copy_helper(const Node* tree) { // pre-order traversal!
        if (tree == nullptr) return;
        add(tree->key);
        copy_helper(tree->left); copy_helper(tree->right);
    }
    public:
    // I'll do these for you (full rule-of-three even!)
    StringSet() : root(nullptr) {}
    ~StringSet() { delete root; }
    StringSet(const StringSet& other) : root(nullptr) {
        copy_helper(other.root);
    }
    StringSet& operator=(const StringSet& other) {
        if (this == &other) return *this;
        delete root; root = nullptr; copy_helper(other.root);
        return *this;
    }
} 


//MY IMPLEMENTATION 
bool StringSet::is_empty() const {
    return root == nullptr; 
}

void StringSet::add(const string& key) {
//< node, > node, = node, null leaf, use recursivwe? 
    add_helper(root, key);

}
void add_helper(Node*& current, const string& key) {
    if (current == nullptr) {
        current = new Node(key);
    } 
    else if (key < current->key) {
        add_helper(current->left, key);
    } 
    else if (key > current->key) {
        add_helper(current->right, key);
    }
}

bool StringSet::contains(const string& key) const {
    Node* current = root;
    while (current) {
        if (current->key == key){
            return true;
        }
        else if (key < current->key){
            current = current->left;
        }
        else{
            current = current->right;
        }
    return false;
    }
}

//thought itd be nicer for it to store all common nodes in a vector... 
vector<int> intersection(const StringSet& other) const {
    vector<int> result;
    intersection(other, result);
    return result;
}

StringSet StringSet::intersection_helper(const StringSet& other, vector<int>& result) {
    if(root == nullptr || other.root == nullptr){
        return; 
    }

    //traverse through left most/rughtmost and compare
    //recursively?? 

    if (root->value == other.root->value) {
        result.push_back(root->value);
    }
    intersection_helper(root->right, other.root->right, result);
}

