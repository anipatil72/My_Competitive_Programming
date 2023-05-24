// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun>
class y_combinator_result
{
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *recur(int pre[], int preMirror[], int preStart, int preEnd, int preMirrorStart, int preMirrorEnd, int count)
{

    if (count >= 40)
    {
        return NULL;
    }

    dbg(preStart, preEnd, preMirrorStart, preMirrorEnd);

    if ((preStart > preEnd) || (preMirrorStart > preMirrorEnd))
    {
        return NULL;
    }

    unordered_set<int> s;

    unordered_set<int> p;

    int fir = preStart + 1, las = preMirrorEnd;
    cout << "I am here ! " << endl;
    dbg(fir, las);

    // if (fir==las)
    // {

    // }

    s.insert(pre[fir]);
    p.insert(preMirror[las]);

    fir++;

    las--;

    // cout << "Currently I am here : " << pre[preStart] << endl;

    while ((las > fir))
    {

        s.insert(pre[fir]);
        p.insert(preMirror[las]);

        if (s == p)
        {
            break;
        }

        fir++;

        las--;
    }

    cout << "This is after : " << endl;

    dbg(fir, las);

    Node *lef = recur(pre, preMirror, preStart + 1, fir, las, preMirrorEnd, count + 1);
    Node *rig = recur(pre, preMirror, las, preEnd, preMirrorStart + 1, fir, count + 1);

    Node *root = new Node;

    root->data = pre[preStart];

    root->left = lef;

    root->right = rig;

    return root;
}

// preOrder[] = {1,2,4,5,3,6,7}
// preOrderMirror[] = {1,3,7,6,2,5,4}

Node *constructBinaryTree(int pre[], int preMirror[], int size)
{

    int n = size;

    Node *ans = recur(pre, preMirror, 0, n - 1, 0, n - 1, 0);

    return ans;
}

void dorecur(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    dorecur(root->left);

    cout << root->data << endl;

    dorecur(root->right);
}

// vector<int> findInorder(Node *root)
// {
//     vector<int> ans;

//     if (root == NULL)
//     {
//         return {};
//     }
// }

int main()
{

    // cout << (s == p) << endl;

    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int preOrderMirror[] = {1, 3, 7, 6, 2, 5, 4};

    Node *ans = constructBinaryTree(preOrder, preOrderMirror, 7);

    dorecur(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥