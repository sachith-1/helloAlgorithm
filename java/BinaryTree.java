/* Class containing left and right child of current 
node and key value*/
class BinaryTree 
{ 
	int key; 
	BinaryTree left, right; 

	public BinaryTree(int item) 
	{ 
		key = item; 
		left = right = null; 
	} 
}