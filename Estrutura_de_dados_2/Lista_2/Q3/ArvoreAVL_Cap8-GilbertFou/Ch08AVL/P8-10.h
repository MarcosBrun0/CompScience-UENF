/*	==================== AVL_Retrieve ===================  	Retrieve node searches the tree for the node containing 	the requested key and returns pointer to its data.	   Pre     Tree has been created (may be null) 	           data is pointer to data structure 	                containing key to be located 	   Post    Tree searched and data pointer returned 	   Return  Address of matching node returned 	           If not found, NULL returned */void* AVL_Retrieve  (AVL_TREE* tree, void* keyPtr){//	Statements 	if (tree->root)	    return _retrieve (tree, keyPtr, tree->root);	else	    return NULL;}	// AVL_Retrieve 