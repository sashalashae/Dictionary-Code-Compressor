//Name: Sasha Morgan
//PID: sasha97
#ifndef _TREAP_BST_H_
#define _TREAP_BST_H_

#include <random>

#include "abstract_bst.h"

template <typename KeyType, typename ValueType>
class TreapBST : public AbstractBST<KeyType, ValueType>
{
public:
	// constructor
	TreapBST();

	// copy constructor
	TreapBST(const TreapBST<KeyType, ValueType>& x);

	// copy-assignment
	TreapBST& operator=( const TreapBST<KeyType, ValueType> &x); // (TreapBST x);


	// destructor
	~TreapBST();

	// determine if the tree is empty
	 bool empty();

	// Search for key.
	// If found is true returns the value associated with that key.
	// If found is false, returns a default constructed ValueType
	 ValueType search(const KeyType& key, bool& found);

	// Insert value into the BST with unique key.
	// thows std::logic_error if key is already in the tree
	 void insert(const KeyType& key, const ValueType& value);

	// Remove value from the BST with key.
	// throws std::logic_error if empty
	 void remove(const KeyType& key);

private:
	std::mt19937 rndgen;
	template <typename K, typename V>
	struct Node {
		K key; //search key
		V value; //data
		Node* parent; //parent node pointer
		Node* left; //child node pointer left
		Node* right; //child node pointer right
		std::mt19937::result_type priority;
		Node(const K& k, const V& v, Node *p = nullptr) :key(k), value(v), parent(p), left(nullptr), right(nullptr)
		{

		}

	};
	
	template <typename K, typename V>
	struct stackvar {
		Node<K, V>* rhs;
		Node<K, V>** lhs;
	};
	
	typedef Node<KeyType, ValueType>* NodePtr;
	NodePtr root;
	ValueType value;
	NodePtr parent;
	//NodePtr parent;
	void leftshift(NodePtr& pos);
	void rightshift(NodePtr& pos);
	void shelper(KeyType key, Node<KeyType, ValueType>*& curr, Node<KeyType, ValueType>*& parent);
	void clone(Node<KeyType, ValueType>*rhs);
	//void deleteNode(Node<KeyType, ValueType>* a, KeyType key);
	void destroy();
	//ValueType ihelper(NodePtr r, const KeyType& key, const ValueType& value);
};

#include "treap_bst.txx"

#endif // _TREAP_BST_H_
