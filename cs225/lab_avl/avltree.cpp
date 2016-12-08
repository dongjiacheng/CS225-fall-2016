/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    Node* newsubroot;
    newsubroot = t->right;
    Node* temp;
    temp = newsubroot->left;
    newsubroot->left = t;
    t->right = temp;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = newsubroot;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
     // your code here
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    Node* newsubroot;
    newsubroot = t->left;
    Node* temp;
    temp = newsubroot->right;
    newsubroot->right = t;
    t->left = temp;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = newsubroot;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1; // your code here
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    rotateRight(t->right);
    rotateLeft(t);// your code here
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{       
        int check = heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
        if(abs(check)<=1)
            return;
        if(check < -2)
            rebalance(subtree->left);
        if(check > 2)
            rebalance(subtree->right);
        int balance = heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
        int subBalance;
        if (balance == -2)
        { 
            subBalance = heightOrNeg1(subtree->left->right)-heightOrNeg1(subtree->left->left);
            if(subBalance == -1)
                rotateRight(subtree);
            else
                rotateLeftRight(subtree);
        }
        else if (balance == 2)
        {   

            subBalance = heightOrNeg1(subtree->right->right)-heightOrNeg1(subtree->right->left);
            if(subBalance == 1)
                rotateLeft(subtree);
            else
                rotateRightLeft(subtree);
        }
     // your code here
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if(subtree==NULL)
        subtree = new Node(key, value);
    else if (key < subtree->key)
    {
        insert(subtree->left, key, value);
      
    }
    else if (key > subtree->key)
    {
        insert(subtree->right, key, value);
 
    }
    rebalance(subtree);
    subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;// your code here
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
       remove(subtree->left,key); // your code here
    } else if (key > subtree->key) {
       remove(subtree->right,key); // your code here
    } else {
        if (subtree->left == NULL || subtree->right == NULL) {
            Node* temp = subtree;
            subtree = NULL;
            delete subtree; 
        }
        else {
            Node * temp = subtree->left;
            while (temp->right) { temp = temp->right; }
            swap(temp, subtree);
            remove(subtree->left, key);
        }
    }
    if (subtree) { rebalance(subtree); }
}
      /**
        if (subtree->left == NULL && subtree->right == NULL) {
           Node* temp = subtree;
           subtree = NULL;
           delete subtree;  no-child remove 
            // your code here
        } else if (subtree->left != NULL && subtree->right != NULL) {
          Node* temp;
          rightmostchild(subtree->left,temp);
          subtree->key = temp->key;
          doremoval(temp);   two-child remove 
            // your code here
        } else {
           Node* temp = subtree;
           if(subtree->left == NULL) subtree = subtree->right;
           else subtree = subtree->left;
           delete temp;  one-child remove 
            // your code here
        }
       rebalance(subtree);
    subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1; // your code here
    }
}

template <class K, class V>
void AVLTree<K, V>::rightmostchild( Node*& subtree, Node*& temp)
{
    
    if(subtree == NULL)
        return;
    rightmostchild(subtree->left,temp);
    temp = subtree;
    rightmostchild(subtree->right,temp);
}

template <class K, class V>

void AVLTree<K, V>::doremoval(Node*& subtree){
     if (subtree->left == NULL && subtree->right == NULL) {
           Node* temp = subtree;
           subtree = NULL;
           delete subtree;  no-child remove 
            // your code here
        } else if (subtree->left != NULL && subtree->right != NULL) {
          Node* temp;
          rightmostchild(subtree->left,temp);
          subtree->key = temp->key;
          doremoval(temp);   two-child remove 
            // your code here
        } else {
           Node* temp = subtree;
           if(subtree->left == NULL) subtree = subtree->right;
           else subtree = subtree->left;
           delete temp; one-child remove 
            // your code here
        }
         rebalance(subtree);
        subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1; 

 }
*/
