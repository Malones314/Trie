#include<iostream>
#include<vector>
using namespace std;
class Trie {
    public:
    Trie ( ) :isEnd ( false ), children ( 26, nullptr ) { }

    void insert ( string word ) {
        Trie* node = this;
        for ( char ch : word ) {
            ch -= 'a';
            if ( node->children [ch] == nullptr )
                node->children [ch] = new Trie ( );
            node = node->children [ch];
        }
        node->isEnd = true;
    }

    bool search ( string word ) {
        Trie* node = this->searchWord ( word );
        return node != nullptr && node->isEnd;
    }
    
    Trie* searchWord ( string word ) {
        Trie* node = this;
        for ( char ch : word ) {
            ch -= 'a';
            if ( node->children [ch] == nullptr )
                return nullptr;
            node = node->children [ch];
        }
        return node;
    }
    private:
    vector<Trie*> children;
    bool isEnd;
};
int main ( ) {
    Trie myTrie;
    string word[5];
    for ( int j = 0; j < 5; j++ ) {
        for ( int i = 0; i < 10; i++ )
            word[j] += 'a' + rand ( ) % 26;
        myTrie.insert ( word[j] );
    }
    for ( int i = 0; i < 5; i++ ) {
        cout << myTrie.search ( word [i] ) << endl;
    }
	return 0;
}
