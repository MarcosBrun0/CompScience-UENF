#define LH +1                          // Left High #define EH  0                          // Even High #define RH -1                          // Right High //	Structure Declarations typedef struct node	{	 void*        dataPtr;	 struct node* left;	 int          bal;	 struct node* right;	} NODE;typedef struct	{	 int    count;	 int   (*compare) (void* argu1, void* argu2);	 NODE*   root;	} AVL_TREE;	//	Prototype Declarations 	AVL_TREE* AVL_Create 	         (int (*compare)(void* argu1, void* argu2));	AVL_TREE* AVL_Destroy (AVL_TREE* tree);	bool  AVL_Insert   (AVL_TREE* tree,  	                    void* dataInPtr);	bool  AVL_Delete   (AVL_TREE* tree,  void* dltKey);	void* AVL_Retrieve (AVL_TREE* tree,  void* keyPtr);	void  AVL_Traverse (AVL_TREE* tree,	                    void (*process)(void* dataPtr));	int  AVL_Count     (AVL_TREE* tree);	bool AVL_Empty     (AVL_TREE* tree);	bool AVL_Full      (AVL_TREE* tree);	static NODE* _insert 	               (AVL_TREE* tree, NODE* root, 	                NODE* newPtr,   bool* taller);	static NODE* _delete    	               (AVL_TREE* tree,	                NODE* root,      void* dltKey, 	                bool* shorter,   bool* success);	static void* _retrieve 	               (AVL_TREE* tree, 	                void* keyPtr,    NODE* root); 	static void _traversal 	               (NODE* root,	                void (*process)(void* dataPtr));	static NODE* rotateLeft   (NODE* root);	static NODE* rotateRight  (NODE* root);	static NODE* insLeftBal  (NODE* root, bool* taller);	static NODE* insRightBal (NODE* root, bool* taller);  	static NODE* dltLeftBal   (NODE* root, bool* shorter);	static NODE* dltRightBal  (NODE* root, bool* shorter);	static void _destroy      (NODE* root);