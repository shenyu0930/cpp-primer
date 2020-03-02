#include<string>

class TreeNode {
public:
	TreeNode(const std::string& val = std::string()) 
		:value(val), count(new int(1)), left(nullptr), right(nullptr) {};
	TreeNode(const TreeNode& treeNode) :value(treeNode.value), count(treeNode.count), left(treeNode.left), right(treeNode.right) {
		++* count;
	}
	TreeNode& operator=(const TreeNode& treeNode);
	~TreeNode() {
		if (-- * count == 0) {
			if (left) {
				delete left;
				left = nullptr;
			}
			if (right) {
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	std::string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};
TreeNode& TreeNode::operator=(const TreeNode& treeNode) {
	++* treeNode.count;
	if (--* count == 0) {
		if (left) {
			delete left;
			left = nullptr;
		}
		if (right) {
			delete right;
			right = nullptr;
		}
		delete count;
		count = nullptr;
	}
	value = treeNode.value;
	count = treeNode.count;
	left = treeNode.left;
	right = treeNode.right;
	return *this;
}
class BinStrTree {
public:
	BinStrTree(const TreeNode& treeNode = TreeNode()) :root(new TreeNode(treeNode)) {};
	BinStrTree(const BinStrTree& binStrTree) :root(new TreeNode(*binStrTree.root)) {};
	BinStrTree& operator= (const BinStrTree& binStrTree);
	~BinStrTree() {
		delete root;
	}
private:
	TreeNode* root;
};
BinStrTree& BinStrTree::operator= (const BinStrTree& binStrTree) {
	TreeNode *p = new TreeNode(*binStrTree.root);
	delete root;
	root = p;
	return *this;
}
int main()
{
	
	return 0;
}