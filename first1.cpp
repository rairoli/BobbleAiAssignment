#include <bits/stdc++.h>
using namespace std;

// Structure for Trie

struct Trie {
	bool EndName;
	unordered_map<char, Trie*> map;
	int f;
};


// Function to create a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;
	node->EndName = false;
	return node;
}


// Function to insert a student with its frequency
// in the dictionary built using a Trie


void insert(Trie*& root, const string& str,
			const int& f)
{

	// If root is null
	if (root == NULL)
		root = getNewTrieNode();

	Trie* t = root;

	for (int i = 0; i < str.length(); i++) {
		char x = str[i];

		// Make a new node if there is no path
		if (t->map.find(x) == t->map.end())
			t->map[x] = getNewTrieNode();

		t = t->map[x];
	}

	// Mark end of Name and store the meaning
	t->EndName = true;
	t->f = f;
}


// Function to search a student in the Trie and return its frequency if it exists

 int search(Trie * root, string word){
     if(root == NULL) return -1;
     Trie* t = root;

	// Search a student in the Trie

	for (int i = 0; i < word.length(); i++) {
		t = t->map[word[i]];
		if (t == NULL)
			return -1;
	}

    if (t->EndName)
		return t->f;
    return -1;
 }

// Main function

int main()
{
	Trie* root = NULL;

	// Build the dictionary
	ifstream myFile;
	myFile.open("EnglishDictionary.csv");
	string line, word;
	string fre;
	vector<pair<string, int>> v;
	int f;

	while(getline(myFile, line)){
		stringstream ss(line);
		getline(ss, word, ',');
		getline(ss, fre, ',');
		f = stoi(fre);
		v.push_back({word,f});
	}

	for(auto it : v){
		insert(root, it.first, it.second);
	}


    int ans = search(root, "cross");
	if(ans != -1) cout << "YES " << ans << endl;
	else cout << "NO\n";

	return 0;
}
