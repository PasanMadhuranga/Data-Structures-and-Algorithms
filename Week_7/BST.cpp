#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root != NULL){
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == NULL){
        // If the tree is empty, create a new node and return it
        node = (struct node*) malloc(sizeof(struct node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
    }else{
        if(key <= node->key){
            // If the key is less than the root's key, go to the left subtree
            node->left = insertNode(node->left, key);
        }else{
            // If the key is greater than the root's key, go to the right subtree
            node->right = insertNode(node->right, key);
        }
    }
    // return the root of the updated tree
    return node;
}


// Finding maximum in a tree.
node* FindMax(node* root)
{
	while(root->right != NULL)
        root = root->right;
	return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    // If the tree is empty, return NULL
	if(root == NULL){
        return root;
	}
	// If the key is less than the root's key, go to the left subtree
	else if(key < root->key){
        root->left = deleteNode(root->left, key);
	}
	// If the key is greater than the root's key, go to the right subtree
	else if (key > root->key) {
        root->right = deleteNode(root->right, key);
	}
	else {
		// Case 1:  When there are no children to the node
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// Case 2: When there is only one child to the node
		else if(root->left == NULL) {
			struct node* temp_node = root;
			root = root->right;
			delete temp_node;
		}
		else if(root->right == NULL) {
			struct node* temp_node = root;
			root = root->left;
			delete temp_node;
		}
		// Case 2: When there are two children to the node
		else {
			struct node *max_in_eft = FindMax(root->left); // Find the maximum node in the left subtree
			root->key = max_in_eft->key; // Replace the root's key with the maximum node's key
			root->left = deleteNode(root->left,max_in_eft->key); // Delete the maximum node
		}
	}
    // return the root of the updated tree
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
}
