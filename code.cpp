/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rt;
    int i;
    Solution()
    {
        rt=NULL;
        i=0;
    }
    TreeNode* form(vector<int>& pre, vector<int>& post,TreeNode* root,int &i,int j)
    {
        if(i<pre.size())
        {
           if(root==NULL)
            {
                root=new TreeNode(pre[i]);
                i++;
            }
            m:
        bool flag=false;
            int p;
            for(p=j+1;p<post.size();p++)
            {
                if(i<pre.size() && post[p]==pre[i])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                if(root->left==NULL)
                {
                    root->left=form(pre,post,root->left,i,p);
                }
                else
                {
                    root->right=form(pre,post,root->right,i,p);
                }
              goto m;
            }
            return root;
        }
        return NULL;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        reverse(post.begin(),post.end());
        int i=0;
        rt=form(pre,post,rt,i,0);
        return rt;
    }
};
