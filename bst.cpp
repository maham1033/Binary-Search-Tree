#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    Node * left;
    Node * right;
    string  data;
    Node* parent;
    Node(string val){
    	data=val;
    	left=NULL;
    	right=NULL;
	}
};

class BST
{    
public:   
    Node* root;
    BST()
    {
        root=NULL;
    }
    
    // Inorder Traversal
    void Inorder(Node *n )
    {
        if (n!=NULL)
        {
            Inorder(n->left);
            cout<<n->data<<" ";
            Inorder(n->right);
        }
    }
    
    // Postorder Traversal
    void Postorder(Node *n )
    {
        if(n!=NULL){
        	Postorder(n->left);
        	Postorder(n->right);
        	cout<<n->data<<" ";
		}
    }
    
    // Preorder Traversal
    void Preorder(Node *n)
    {
        if(n!=NULL){
        	cout<<n->data<<" ";
        	Preorder(n->left);
        	Preorder(n->right);
		}
    }
    
    // Insert in Tree
    void insert(int data, string m)
    {
        Node *z=new Node(m);  // nptr
        Node *y=NULL;  //pptr
        Node *x=root;  //tptr
        while(x!=NULL)
        {
            y=x;
            if((conversion(z->data))<(conversion(x->data))){
                x=x->left;
			}
            else{
                x=x->right;
			}   
        }
        z->parent=y;
        if(root==NULL)
            root=z;
        else if((conversion(y->data))>(conversion(z->data)))
            y->left=z;
        else if((conversion(y->data))<(conversion(z->data)))
            y->right=z;
        else{
        	cout<<"already exists."<<endl;
        	return ;
		}
    }
    
    // Min Tree
    string TreeMin(Node* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        while(x->left !=NULL){
            x=x->left;}
        return x->data;
    }
    
     // Max Tree
    string TreeMax(Node* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        while(x->right!=NULL){
            x=x->right;}
        return x->data;
    }
    
    // function to convert string into integer
    int conversion(string s) {
        int data = 0;
        int a = s.length();
        for (int i = 0;i<a;i++) {
//          cout<<int(s[i])<<endl;
            data = data + int(s[i]);
			}
        return data;
	}
	
	Node* search(string s){
		int d = conversion(s);
		Node *t= root;
		while(t!=NULL){
			if(t->data==s){
				cout<<endl<<"String "<<s<<" exists."<<endl;
//				if((t->left==NULL)&&(t->right==NULL)){
//					cout<<"yes";
//				}
				return t;
				
			}
			if(conversion(t->data)>d){
				t=t->left;
			}
			else{
				t=t->right;
			}
		}
		cout<<"String "<<s<<" does not exist."<<endl;
		return NULL;
    }
    
    void successor(Node* t){
    	Node* p = t;
		if(t->right!=NULL){
			cout<<"The successor of "<<t->data<<" is "<<TreeMin(t->right)<<endl;
		} 
		else{
			while((conversion(t->data))>(conversion(p->data))){
				p = p->parent;
			}
			cout<<"The successor of "<<t->data<<" is "<<p->data<<endl;
		}
	}
	
	void predecessor(Node* t){
    	Node* p = t;
		if(t->right!=NULL){
			cout<<"The predecessor of "<<t->data<<" is "<<TreeMax(t->left)<<endl;
		} 
		else{
			while((conversion(t->data))<(conversion(p->data))){
				p = p->parent;
			}
			cout<<"The predecessor of "<<t->data<<" is "<<p->data<<endl;
		}
	}
	
	Node* inOrderPredecessor(Node* root){
	    root = root->left;
	    while(root->right!=NULL){
		   root= root->right;
		}
	    return root;
	}
	    
	


Node* deleteNode(Node* root, string k) 
    { 
        // Base case 
        if (root == NULL) 
            return root; 
        //If root->data is greater than k then we delete the root's subtree
        if((conversion(root->data)) > (conversion(k))){ 
            root->left = deleteNode(root->left, k); 
            return root; 
        } 
        else if((conversion(root->data)) < (conversion(k))){ 
            root->right = deleteNode(root->right, k); 
            return root; 
        } 
  

        // If one of the children is empty 
        if (root->left == NULL) { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
else {
            Node* Parent = root;
            // Find successor of the node
            Node *succ = root->right; 
            while (succ->left != NULL) { 
                Parent = succ; 
                succ = succ->left; 
            } 

            if (Parent != root) 
                Parent->left = succ->right; 
            else
                Parent->right = succ->right; 

            // Copy Successor Data  
            root->data = succ->data; 

            // Delete Successor and return root 
            delete succ;          
            return root; 
        } 
    } 
};

int main()
{
    BST bst;
    int d;
	int option; 
  string val; 
    
     do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. In-order Treversal" << endl;
    cout << "5. Tree-Minimum" << endl;
    cout << "6. Tree-Maximum" << endl;
    cout << "7. Successor" << endl;
    cout << "8. Predecessor " << endl;
    
    cin>>option;
    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter Element of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      //bst->data = val;
	 d = bst.conversion(val);
	 cout<<d<<endl;
	 cout<<"Successfully inserted";
     bst.insert(d,val);
	 cout<<endl;
    		break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter element of TREE NODE to SEARCH in BST: ";
      cin >> val;
       bst.search(val);
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter Element of TREE NODE to DELETE in BST: ";
      cin >> val;
    bst.Inorder(bst.root);
    bst.deleteNode(bst.root,val);
    cout<<endl<<"Now root is: "<<bst.root->data<<endl;
      break;
    case 4:
    cout<<endl<<"Inorder Traversael after insertion."<<endl;
	bst.Inorder(bst.root);
    cout<<endl;
      break;
    case 5:
       cout<<"Tree Minimum is: "<<bst.TreeMin(bst.root)<<endl;
      break;
    case 6:
       cout<<"Tree Maximum is: "<<bst.TreeMax(bst.root)<<endl;
      break;
      case 7:
      	bst.successor(bst.root);
        break;
        case 8:
        bst.predecessor(bst.root);
         break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

    return 0;
}
