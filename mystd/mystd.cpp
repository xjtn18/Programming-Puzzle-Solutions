#include <mystd.h>
#include <sstream>


TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}




// recursive function that fills binary tree row by row left to right
void fill(TreeNode*& node, std::vector<std::string> v, int i){
	if (v[i] == "null"){
		node = nullptr;
		return;
	}

	node->val = std::stoi(v[i]); // assign value

	if (2*i+1 < v.size()){
		node->left = new TreeNode();
		fill(node->left, v, 2*i+1);
	}
	if (2*i+2 < v.size()){
		node->right = new TreeNode();
		fill(node->right, v, 2*i+2);
	}
}


// initialize and fill a binary tree (row by row) from a given vector
TreeNode* createBinaryTree(std::string vstr){
	if (vstr == "") return nullptr;
	std::vector<std::string> v;
	std::stringstream ss(vstr);
	std::string numstr;
	while (getline(ss,numstr,',')){
		v.push_back(numstr);
	}

	TreeNode* head = new TreeNode(stoi(v[0]));
	fill(head, v, 0);
	return head;

}




// print a binary tree

#define COUNT 5


void print2DUtil(TreeNode *root, int space){
    // Base case
    if (root == nullptr){
        return;
	 }
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
	 std::cout << "\n";
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
	 std::cout<<root->val<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 


// Wrapper over print2DUtil()
void dlog(TreeNode* root){
	dlog("\n-----------------------------------------------------", false);
    print2DUtil(root, 0);
	dlog("-----------------------------------------------------\n");
}



// Random arrays/matrices

std::vector<int> irandarray(const size_t len, const int x, const int y){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(x,y);
	
	std::vector<int> a(len);
	for (int i = 0; i < len; ++i){
		a[i] = dist(gen);
	}

	return a;
};

vec2D<int> irandmatrix(const size_t m, const size_t n, const int x, const int y){
	vec2D<int> mat;
	mat.reserve(m);
	for (int i = 0; i < m; ++i){
		mat.push_back(move(irandarray(n, x, y)));
	}

	return mat;
};



