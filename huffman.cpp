#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<string>
#include<fstream>
#include<bitset>
using namespace std;
template<class T>
struct BSTNode
{
	T data;
	BSTNode<T>* right;
	BSTNode<T>* left;
public:
	BSTNode()
	{
		right = nullptr;
		left = nullptr;
	}
	BSTNode(T d)
	{
		data = d;
		right = nullptr;
		left = nullptr;
	}
	bool operator<(BSTNode&_rhs)
	{
		return(data < _rhs.data);
	}
	bool operator>(BSTNode&_rhs)
	{
		return(data > _rhs.data);
	}
	void print()
	{
		cout << data;
	}

};
template <typename T>
struct BST
{
	BSTNode<T>* root;
public:
	BST()
	{
		root = nullptr;
	}
	BSTNode<T>* getRoot()
	{
		return root;
	}
	BSTNode<T>*Search(T d)
	{
		return search(root, d);
	}
	BSTNode<T>* search(BSTNode<T>* r, T d)
	{
		if (!r || r->data == d)
		{
			return r;
		}
		else
		{
			if (r->data > d)
				return search(r->left, d);
			else if (r->data < d)
				return search(r->right, d);
		}
	}
	void insert(T d)
	{
		insert(root, d);
	}
	void insert(BSTNode<T>* &r, T d)
	{
		if (!r)
			r = new BSTNode<T>(d);
		else
		{
			if (r->data > d)
				insert(r->left, d);
			else if (r->data < d)
				insert(r->right, d);
			else
				return;
		}
	}
	BST& operator=(BST& rhs)
	{
		if (this != &rhs)
		{
			root = rhs.root;
		}
		return *this;
	}
	bool operator<(BST &rhs)
	{
		return(root->data < rhs.root->data);
	}
	bool operator>(BST &rhs)
	{
		return(root->data > rhs.root->data);
	}
	void PrintSorted()
	{
		PrintSorted(root);
	}
	void PrintSorted(BSTNode<T> * r)
	{
		if (r)
		{
			PrintSorted(r->left);
			cout << r->data << " ";
			PrintSorted(r->right);
		}
	}
	void Delete(BSTNode<T> * r)
	{
		if (r)
		{
			Delete(r->left);
			Delete(r->right);
			delete r;
		}
	}
	void Remove(T d)
	{
		Remove(root, d);
	}
	void Remove(BSTNode<T>*& r, T d)
	{
		if (r)
		{
			if (r->data == d)
			{
				if (!r->left && !r->right)
				{
					delete r;
					r = nullptr;
				}
				else if (r->left == nullptr || r->right == nullptr)
				{
					if (!r->left)
					{
						BSTNode<T>*temp = r;
						r = r->right;
						delete temp;
					}
					else
					{
						BSTNode<T>*temp = r;
						r = r->left;
						delete temp;
					}
				}
				else if (r->left&&r->right)
				{
					BSTNode<T> * temp = r->right;
					BSTNode<T> *temp2 = nullptr;
					while (temp->left)
					{
						temp2 = temp;
						temp = temp->left;
					}
					r->data = temp->data;
					delete temp;
					temp = nullptr;
					temp2->left = nullptr;
				}
			}
			else {
				if (r->data > d)
				{
					Remove(r->left, d);
				}
				else if (r->data < d)
				{
					Remove(r->right, d);
				}
			}
		}
	}
	friend ostream & operator << (ostream &out, const BST &c)
	{
		out << c.root->data << " ";
		return out;
	}
	~BST()
	{
		Delete(root);
	}
	void print2DUtil(BSTNode<T> *root, int space, int COUNT)
	{
		// Base case 
		if (root == NULL)
			return;

		// Increase distance between levels 
		space += COUNT;

		// Process right child first 
		print2DUtil(root->right, space, COUNT);

		// Print current node after space 
		// count 
		printf("\n");
		for (int i = COUNT; i < space; i++)
			printf(" ");
		printf("%d\n", root->data, COUNT);

		// Process left child 
		print2DUtil(root->left, space, COUNT);
	}
	void Print2d()
	{
		print2DUtil(root, 0, 10);
	}
	int height(BSTNode<T> *n)
	{
		if (!n)
		{
			return -1;
		}
		else
		{
			int x = 1 + height(n->right);
			int y = 1 + height(n->left);
			if (x > y)
				return x;
			return y;
		}
	}
};
template<class T>
class heap
{
private:
	vector<T> arr;
	int maxSize;
	int heapSize;
public:
	heap(int s = 10)
	{
		arr.resize(s + 1);
		maxSize = s;
		heapSize = 0;
	}
	void insert(T _data)
	{
		heapSize++;
		arr[heapSize] = _data;
		int i = heapSize;
		while (i != 1 && *arr[i] < *arr[i / 2])
		{
			swap(arr[i], arr[i / 2]);
			i = i / 2;
		}
	}
	void minHeapify(int i)
	{
		int left = 2 * i;
		int right = (2 * i + 1);
		int smallest = i;
		if (left <= heapSize && *arr[left] < *arr[i])
			smallest = left;
		if (right <= heapSize && *arr[right] < *arr[smallest])
			smallest = right;
		if (smallest != i)
		{
			swap(arr[i], arr[smallest]);
			minHeapify(smallest);
		}
	}
	T extractMin()
	{
		T data = arr[1];
		arr[1] = arr[heapSize];
		heapSize--;
		minHeapify(1);
		return data;
	}

	int getHeapSize()
	{
		return heapSize;
	}
	vector<T> getarr()
	{
		return arr;
	}
};
struct charCode
{
	unsigned char ch;
	vector<bool> code;
	charCode(char _ch, vector<bool> _code)
	{
		ch = _ch; code = _code;
	}
	bool operator==(char check)
	{
		return (check == ch);
	}
};
struct valuePair
{
	unsigned char ch;
	int freq; //frequency of each character
	valuePair()
	{
		ch = 0;
		freq = 0;
	}
	valuePair(char _ch, int _freq)
	{
		ch = _ch; freq = _freq;
	}
	bool operator==(char check)
	{
		return (check == ch);
	}
	bool operator<(valuePair& _rhs)
	{
		return(freq < _rhs.freq);
	}
	bool operator>(valuePair& _rhs)
	{
		return(freq > _rhs.freq);
	}
	friend ostream & operator << (ostream &out, const valuePair &c)
	{
		out << c.ch << " " << c.freq << " ";
		return out;
	}
};
template <class T>
class hashTable
{
	vector<list<T>> table;
	int sizeOfTable;
public:
	hashTable() :table(21)
	{
		sizeOfTable = table.size();
	}

	T *search(char _toSearch)
	{
		int hash = hashFunc(_toSearch);
		for (auto it = (table[hash]).begin();it != table[hash].end();++it)
		{
			if (*it == _toSearch)
			{
				return &(*it);
			}
		}
		return nullptr;
	}
	int hashFunc(int _toHash)
	{
		return (_toHash % table.size());
	}
	void insert(int _toInsert)
	{
		int hash = hashFunc(_toInsert);
		table[hash].push_back(*(new T(_toInsert, 1)));
	}
	void insert(int _toInsert, vector<bool> _characterCode)
	{
		int hash = hashFunc(_toInsert);
		table[hash].push_back(*(new T(_toInsert, _characterCode)));
	}
	int size()
	{
		return (table.size());
	}
	list<T>& getdata(int _iOfTable)
	{
		return(table[_iOfTable]);
	}
};
template <class T>
void searchInTable(hashTable<T> &table, char ch)//search function which inserts the character not present in the table
{
	valuePair *ptr = table.search(ch);
	if (ptr == nullptr)
		table.insert(ch);
	else
		ptr->freq++;
}
void insertCodes(BSTNode<valuePair>* root, vector<bool> arr, hashTable<charCode>&t)
{
	if (root->left)
	{
		arr.push_back(0);
		insertCodes(root->left, arr, t);
		arr.pop_back();
	}
	if (root->right)
	{
		arr.push_back(1);
		insertCodes(root->right, arr, t);
		arr.pop_back();
	}
	if (!root->right && !root->left)
	{
		t.insert(root->data.ch, arr);//inserts the code generated in tha hash table according to its coorresponsding character
		return;
	}
}
unsigned char ToByte(bool b[8])
{
	unsigned char c = 0;
	for (int i = 0; i < 8; ++i)
		if (b[i])
			c |= 1 << i;
	return c;
}
void FromByte(unsigned char c, bool b[8])
{
	for (int i = 0; i < 8; ++i)
		b[i] = (c & (1 << i)) != 0;
}
int main()
{
	hashTable<valuePair> table;
	ifstream fin;
	char buffer;
	fin.open("data.txt");
	if (fin.is_open())
	{
		fin.get(buffer);
		while (!fin.eof())
		{
			searchInTable(table, buffer);
			fin.get(buffer);
		}
	}

	vector<BST<valuePair>*>singleElementHeaps;
	int totalRoots = 0;
	for (int i = 0;i < table.size();i++)
	{
		int j = 0;
		for (auto it = table.getdata(i).begin();j < table.getdata(i).size();++it, j++)
		{
			singleElementHeaps.push_back((new BST<valuePair>()));
			singleElementHeaps[totalRoots]->insert(*it);
			++totalRoots;
		}
	}

	heap<BST<valuePair>*> a(singleElementHeaps.size());
	for (int i = 0;i < singleElementHeaps.size();i++)
	{
		a.insert(singleElementHeaps[i]);
	}
	while (a.getHeapSize() > 1)
	{
		BST<valuePair>* X = a.extractMin();
		BST<valuePair>* Y = a.extractMin();
		BST<valuePair>*Z = new BST<valuePair>();
		Z->root = new BSTNode<valuePair>();
		Z->getRoot()->data.freq = X->getRoot()->data.freq + Y->getRoot()->data.freq;
		Z->getRoot()->left = X->getRoot();
		Z->getRoot()->right = Y->getRoot();
		a.insert(Z);
	}
	hashTable<charCode> codes;
	vector<bool> characterCode;
	BST<valuePair> *_tree = a.extractMin();
	BSTNode<valuePair> * _root = _tree->root;
	insertCodes(_root, characterCode, codes);
	ofstream fout;
	fout.open("Compressed.txt",ios::binary);
	bool b[8];
	fin.close();
	fin.open("data.txt",ios::binary);
	charCode*searched = 0;
	vector<bool> boolean;
	int x = 0;
	if (fin.is_open())
	{
		do
		{
			fin.get(buffer);
			searched = codes.search(buffer);
			if (searched != nullptr) {
				boolean = searched->code;
				for (int i = 0;i < boolean.size();i++)
				{
					b[x++] = boolean[i];
					if (x == 8)
					{
						unsigned char chl = ToByte(b);
						if (chl != 0) {
							cout << chl;
							fout << chl;
						}
						x = 0;
					}
				}
			}
		} while (!fin.eof());
	}
	fout.close();
	ifstream _open;
	_open.open("Compressed.txt",ios::binary);
	//int height=_tree->height(_tree->root);
	vector<bool> cd;
	BSTNode<valuePair> *prevRoot = _root;
	int index = 0;
	ofstream decode;
	decode.open("Decompressed.txt",ios::binary);
	int blb = 0;
	bool bro[8];
	unsigned char bp;
	while (_open)
	{

		bp = _open.get();
		FromByte(bp, bro);
		for (int i = 0; i < 8; i++)
		{
			if (bro[i] == 0)
				_root = _root->left;
			else
				_root = _root->right;
			if (_root->left == nullptr) {
				decode << (char)_root->data.ch;
				cout << (char)_root->data.ch;
				_root = _tree->root;
			}
		}
	}

	return 0;
}