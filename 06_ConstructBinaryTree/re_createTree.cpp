/*
 *struct TreeNOde{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x):val(x),left(NULL),right(NULL){}
 };
*/
class Solution{
public:
	struct TreeNode* reConstructBinTree(vector<int> pre,vector<int> in)
	{
		int n = pre.size();
		if(n == 0){
			return NULL;
		}
		TreeNode* root = new TreeNode(pre[0]);
		int k = 0;
		vector<int> left_pre,left_in,right_pre,right_in;
		while(pre[0] != in[k])
			k++;

		for(int i=1;i<k+1;i++){
			left_pre.push_back(pre[i]);
		}
		for(int i=k+1;i<n;i++){
			right_pre.push_back(pre[i]);
		}
		for(int j=0;j<k;j++){
			left_in.pusk_back(in[j]);
		}
		for(int j=k+1;j<n;j++){
			right_in.push_back(in[j]);
		}

		root->left = reConstructBinTree(left_pre,left_in);
		root->right = reConstructBinTree(right_pre,right_in);

		return root;
	}
};
