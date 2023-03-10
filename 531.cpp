#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recur(TreeNode *r, int &pos, string &ans)
{

    // if (r == NULL)
    // {
    //     return;
    // }

    // // pos++;

    // cout<<ans<<endl;

    // ans.insert(pos, "()");

    // pos++;

    // string t = to_string(r->val);

    //     cout<<pos<<" wwhen "<<r->val<<endl;

    //     // pos++;

    // ans.insert(pos, t);

    // pos++;

    // recur(r->left, pos, ans);

    // pos++;
    // recur(r->right, pos, ans);

    if (r == NULL)
    {
        return;
    }

    // pos++;

    ans.insert(pos, "()");

    pos++;

    string t = to_string(r->val);

    // cout<<pos<<" wwhen "<<r->val<<endl;

    ans.insert(pos, t);

    pos+=t.length();

    if (r->left != NULL&&r->right==NULL)
    {
        recur(r->left, pos, ans);

        pos++;
    }
    else if (r->left == NULL && r->right != NULL)
    {

        ans.insert(pos, "()");

        pos += 2;

        recur(r->right, pos, ans);

        pos++;
    }
    else if (r->left != NULL && r->right != NULL)
    {

        recur(r->left, pos, ans);

        pos++;
        recur(r->right, pos, ans);

        pos++;
    }
}

string tree2str(TreeNode *root)
{

    string ans = "";

    if (root == NULL)
    {
        return ans;
    }

    int pos = 0;

    // pos++;
    string t = to_string(root->val);

    ans += t;
    pos = ans.length();

    // ans.insert(pos, t);

    if (root->left != NULL&&root->right==NULL)
    {
        recur(root->left, pos, ans);

        pos++;
    }
    else if (root->left == NULL && root->right != NULL)
    {

        ans.insert(pos, "()");

        pos += 2;

        recur(root->right, pos, ans);

        pos++;
    }
    else if (root->left != NULL && root->right != NULL)
    {

        recur(root->left, pos, ans);

        pos++;
        recur(root->right, pos, ans);
    }

    return ans;
}

int main()
{

    string s = "aniruddha";

    s.insert(3, "&");

    cout << s << endl;

    return 0;
}