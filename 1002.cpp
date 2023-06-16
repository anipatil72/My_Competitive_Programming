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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *replaceValueInTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    unordered_map<TreeNode *, int> m;

    queue<TreeNode *> q;

    int cur = root->val, next = 0;

    q.push(root);

    m[root] = root->val;

    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *tem = q.front();

        q.pop();

        if (tem == NULL)
        {
            if (q.empty())
            {
            }
            else
            {
                q.push(NULL);
            }

            cur = next;

            next = 0;

            continue;
        }

        int desc = 0;

        if (tem->left != NULL)
        {
            desc += tem->left->val;

            q.push(tem->left);
        }

        if (tem->right != NULL)
        {
            desc += tem->right->val;

            q.push(tem->right);
        }

        next += desc;
        if (tem->left != NULL)
        {
            // desc += tem->left->val;

            m[tem->left] = desc;

            // q.push(tem->left);
        }

        if (tem->right != NULL)
        {
            // desc += tem->right->val;

            m[tem->right] = desc;

            // q.push(tem->right);
        }

        int post = m[tem];

        tem->val = cur - post;
    }

    return root;
}

int main()
{

    return 0;
}

// [0,0,0,12210,12210,8160,8160,17419,17419,null,null,18355,18355,17098,17098,null,null,46296,46296,53884,53884,46465,46465,43228,43228,45871,45871,66216,66216,67831,67831,72567,null,63555,63555,60198,60198,74087,null,62211,62211,75304,75304,69007,69007,null,null,157231,157231,159085,159085,153981,153981,163285,null,160742,160742,166432,166432,163008,null,158871,158871,160942,160942,null,168712,160991,160991,156613,156613,154858,154858,159175,159175,null,169243,158296,158296,188028,null,null,null,null,188834,188132,188132,null,null,null,null,null,null,180986,180986,188519,null,190253,190253,188938,188938,186249,186249,null,195396,null,194955,185326,185326,187438,187438,null,null,185566,185566,183746,183746,191602,191602,183453,183453,180975,180975,193855,193855,182549,182549,185325,185325,null,186701,192635,null,null,null,222283,null,null,229031,null,227682,null,null,226384,226384,null,null,null,null,null,null,226893,null,null,null,null,222779,223148,223148,223470,223470,225665,null,null,231084,212068,212068,216605,216605,222707,null,null,224404,null,225312,220945,220945,218891,218891,null,null,221985,221985,220203,220203,225345,225345,null,null,226559,226559,224520,224520,226189,226189,217410,217410,223597,null,216553,216553,227033,227033,220759,220759,null,null,223144,223144,null,null,null,null,null,null,null,null,329488,329488,330939,330939,null,330309,null,null,null,null,null,332106,null,334397,330489,330489,null,null,null,null,331763,331763,333155,333155,332261,null,null,null,null,null,null,332540,335725,null,null,null,328656,328656,325493,325493,null,334055,327485,327485,331958,null,323054,323054,329767,329767,326613,326613,331986,331986,320422,320422,324334,324334,329823,329823,326878,326878,335520,null,332899,332899,323602,323602,331889,331889,null,336892,322604,322604,321624,321624,null,null,330950,330950,338897,null,null,null,334364,null,269451,269451,276135,null,null,null,null,270808,null,null,null,277965,null,272740,null,274705,null,null,269921,269921,null,null,276363,276363,null,277285,279539,null,null,null,null,null,null,null,null,278990,null,278595,276272,null,270560,270560,null,null,null,null,278657,null,null,null,null,276637,null,null,null,null,271785,271785,274750,null,268210,268210,272211,272211,271195,271195,273711,273711,268727,268727,267307,267307,268698,268698,266437,266437,268447,268447,null,null,265179,265179,271744,271744,271056,271056,273006,273006,null,275818,267672,267672,null,null,275673,null,274207,274207,269878,null,274741,null,274112,274112,null,274536,267619,267619,null,null,null,null,null,null,null,null,null,null,null,null,null,null,334747,null,null,null,326514,326514,326118,326118,null,326895,328288,null,327093,327093,null,null,null,null,328906,null,null,null,324514,324514,328668,null,null,null,null,null,null,332450,null,null,null,null,null,null,null,330592,317227,317227,328523,328523,330450,330450,327999,327999,321948,321948,322790,322790,335042,null,335478,null,332954,null,325631,325631,328216,328216,326109,326109,331983,null,324771,324771,328433,null,null,null,326242,null,330032,null,326999,326999,330784,330784,325360,325360,326276,331144,null,333555,null,null,null,330054,334827,null,317880,317880,null,null,null,333684,325350,325350,null,334333,null,328205,327555,327555,321062,321062,null,null,null,null,330071,330071,null,null,null,344615,348991,null,344277,344277,null,345075,null,348110,null,null,null,null,338802,338802,null,null,342350,342350,343751,343751,344662,null,null,null,347031,null,350978,350978,null,349809,342793,342793,341617,341617,344623,344623,344318,344318,342194,342194,341176,341176,345261,345261,341819,341819,null,null,346599,346599,null,null,354163,null,null,349666,null,null,351262,null,348378,null,335566,335566,339056,339056,345371,345371,null,null,351146,null,347348,null,null,null,345892,345892,null,null,345242,345242,351049,null,343381,343381,351797,346144,null,null,null,null,348487,null,347454,347454,351145,null,null,null,null,350437,null,null,null,null,null,null,null,null,345511,null,null,null,null,null,null,null,null,null,null,348580,340469,340469,null,352642,null,null,null,357059,347607,347607,360567,null,null,null,348005,348005,359240,null,null,355475,null,358771,352055,352055,null,null,360799,null,355998,null,null,null,361045,null,null,356090,null,354465,352320,null,null,null,null,351754,356772,357516,351277,351277,347940,347940,353278,353278,347910,347910,null,357875,356090,356090,343128,343128,null,352846,356083,356083,null,null,353959,353959,352377,352377,356900,356900,353578,null,350532,350532,null,null,null,360581,null,null,359229,null,null,353976,350903,350903,null,360079,null,352340,352717,352717,348510,348510,null,null,358081,null,null,354682,null,359119,null,353898,null,null,354434,null,null,357163,348919,348919,null,null,351677,351677,348791,348791,null,null,null,361148,null,null,353912,null,null,352076,null,null,null,358283,null,null,null,null,361097,null,360362,360362,347883,347883,null,null,null,357697,null,358821,351398,351398,null,null,null,null,359009,359009,null,null,364742,null,353815,353815,null,null,null,355597,null,null,null,null,null,359009,null,null,356160,null,358949,358949,360045,360045,362094,null,362083,null,351013,351013,null,null,347130,347130,null,359784,356012,356012,360651,null,363739,null,358203,359436,null,null,null,363506,355743,355743,364964,null,360206,360206,349023,349023,null,null,358969,358969,null,361565,null,357606,null,null,362600,null,351926,351926,null,null,null,null,null,null,null,null,348022,348022,null,358081,355185,355185,null,null,null,364315,360106,null,null,null,358545,358545,353520,353520,null,357987,null,360615,null,null,null,357141,null,359070,null,null,354543,354543,353357,353357,null,null,364204,null,353028,353028,null,null,null,null,356784,null,248263,248263,null,null,null,256484,null,null,255893,null,null,null,243856,243856,null,null,null,256111,null,null,255598,255598,null,null,254595,null,null,null,253043,null,null,null,253362,253362,260023,null,null,null,null,254077,254174,254174,null,null,null,null,null,null,null,null,261987,null,257901,null,null,null,null,null,null,null,null,null,246446,246446,null,260845,null,257333,254718,null,null,258416,249146,249146,null,null,254406,254406,null,null,null,256676,260828,260828,249631,249631,253771,253771,261831,null,255246,255246,null,null,255030,null,null,null,null,null,null,null,null,null,null,null,null,254655,null,261183,253233,null,null,null,null,261140,null,256006,null,257650,null,null,null,null,257176,null,null,null,null,null,253793,null,255476,255476,258712,null,null,null,253784,null,null,null,null,null,null,null,157313,157313,null,null,null,null,167856,null,null,null,null,null,null,null,163402,null,162214,null,null,null,null,null,160543,160543,null,164421,157126,157126,163752,163752,158301,158301,null,null,165177,165177,164056,null,165309,165309,null,null,null,null,167516,null,null,null,null,161629,159094,159094,null,168393,163837,163837,null,null,null,null,156048,156048,null,null,157367,157367,null,163581,null,169047,null,null,null,168922,null,null,null,null,167968,null,null,162014,null,null,null,null,null,null,null,null,161944,null,null,null,168314,null,null,null,null,null,164768,null,null,134539,null,134044,null,null,null,null,null,null,null,null,null,null,null,null,null,null,140616,null,126389,126389,null,null,140237,null,133740,null,null,null,null,null,null,135894,null,135569,132837,132837,null,134487,null,null,130927,130927,125942,125942,132084,null,139100,null,null,null,131673,131673,125418,125418,null,null,null,139727,null,null,null,null,null,null,null,null,null,null,null,134623,null,null,null,null,null,null,77715,null,null,null,71957,71957,82677,null,null,null,77422,null,null,null,76956,null,75439,75439,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,84350,null,null,71739,71739,null,77343,null,null,null,null,null,79815,null,null,null,42279,null,42099,null,null,null,null,null,null,35942,35942,33387,33387,null,null,null,36015,null,null,34493,34493,null,null,null,null,null,null,null,14000,9328,null,null,null,null,15155,null,null,16256,null,10997,null,4969,4969,null,9275,null,null,null,null,null,null,null,0]
// [0,0,0,12210,12210,8160,8160,17419,17419,null,null,18355,18355,17098,17098,null,null,46296,46296,53884,53884,46465,46465,43228,43228,45871,45871,66216,66216,67831,67831,72567,null,63555,63555,60198,60198,74087,null,62211,62211,75304,75304,69007,69007,null,null,157231,157231,159085,159085,153981,153981,163285,null,160742,160742,166432,166432,163008,null,158871,158871,160942,160942,null,168712,160991,160991,156613,156613,154858,154858,159175,159175,null,169243,158296,158296,188028,null,null,null,null,188834,188132,188132,null,null,null,null,null,null,180986,180986,188519,null,190253,190253,188938,188938,186249,186249,null,195396,null,194955,185326,185326,187438,187438,null,null,185566,185566,183746,183746,191602,191602,183453,183453,180975,180975,193855,193855,182549,182549,185325,185325,null,186701,192635,null,null,null,222283,null,null,229031,null,227682,null,null,226384,226384,null,null,null,null,null,null,226893,null,null,null,null,222779,223148,223148,223470,223470,225665,null,null,231084,212068,212068,216605,216605,222707,null,null,224404,null,225312,220945,220945,218891,218891,null,null,221985,221985,220203,220203,225345,225345,null,null,226559,226559,224520,224520,226189,226189,217410,217410,223597,null,216553,216553,227033,227033,220759,220759,null,null,223144,223144,null,null,null,null,null,null,null,null,329488,329488,330939,330939,null,330309,null,null,null,null,null,332106,null,334397,330489,330489,null,null,null,null,331763,331763,333155,333155,332261,null,null,null,null,null,null,332540,335725,null,null,null,328656,328656,325493,325493,null,334055,327485,327485,331958,null,323054,323054,329767,329767,326613,326613,331986,331986,320422,320422,324334,324334,329823,329823,326878,326878,335520,null,332899,332899,323602,323602,331889,331889,null,336892,322604,322604,321624,321624,null,null,330950,330950,338897,null,null,null,334364,null,269451,269451,276135,null,null,null,null,270808,null,null,null,277965,null,272740,null,274705,null,null,269921,269921,null,null,276363,276363,null,277285,279539,null,null,null,null,null,null,null,null,278990,null,278595,276272,null,270560,270560,null,null,null,null,278657,null,null,null,null,276637,null,null,null,null,271785,271785,274750,null,268210,268210,272211,272211,271195,271195,273711,273711,268727,268727,267307,267307,268698,268698,266437,266437,268447,268447,null,null,265179,265179,271744,271744,271056,271056,273006,273006,null,275818,267672,267672,null,null,275673,null,274207,274207,269878,null,274741,null,274112,274112,null,274536,267619,267619,null,null,null,null,null,null,null,null,null,null,null,null,null,null,334747,null,null,null,326514,326514,326118,326118,null,326895,328288,null,327093,327093,null,null,null,null,328906,null,null,null,324514,324514,328668,null,null,null,null,null,null,332450,null,null,null,null,null,null,null,330592,317227,317227,328523,328523,330450,330450,327999,327999,321948,321948,322790,322790,335042,null,335478,null,332954,null,325631,325631,328216,328216,326109,326109,331983,null,324771,324771,328433,null,null,null,326242,null,330032,null,326999,326999,330784,330784,325360,325360,331144,331144,null,333555,null,null,null,330054,334827,null,317880,317880,null,null,null,333684,325350,325350,null,334333,null,328205,327555,327555,321062,321062,null,null,null,null,330071,330071,null,null,null,344615,348991,null,344277,344277,null,345075,null,348110,null,null,null,null,338802,338802,null,null,342350,342350,343751,343751,344662,null,null,null,347031,null,350978,350978,null,349809,342793,342793,341617,341617,344623,344623,344318,344318,342194,342194,341176,341176,345261,345261,341819,341819,null,null,346599,346599,null,null,354163,null,null,349666,null,null,351262,null,348378,null,335566,335566,339056,339056,345371,345371,null,null,351146,null,347348,null,null,null,345892,345892,null,null,345242,345242,351049,null,343381,343381,346144,346144,null,null,null,null,348487,null,347454,347454,351145,null,null,null,null,350437,null,null,null,null,null,null,null,null,345511,null,null,null,null,null,null,null,null,null,null,348580,340469,340469,null,352642,null,null,null,357059,347607,347607,360567,null,null,null,348005,348005,359240,null,null,355475,null,358771,352055,352055,null,null,360799,null,355998,null,null,null,361045,null,null,360877,null,354465,352320,null,null,null,null,351754,356772,356772,351277,351277,347940,347940,353278,353278,347910,347910,null,357875,356090,356090,343128,343128,null,352846,356083,356083,null,null,353959,353959,352377,352377,356900,356900,353578,null,350532,350532,null,null,null,360581,null,null,359229,null,null,353976,350903,350903,null,360079,null,352340,352717,352717,348510,348510,null,null,358081,null,null,354682,null,359119,null,353898,null,null,354434,null,null,357163,348919,348919,null,null,351677,351677,348791,348791,null,null,null,361148,null,null,353912,null,null,352076,null,null,null,358283,null,null,null,null,361097,null,360362,360362,347883,347883,null,null,null,357697,null,358821,351398,351398,null,null,null,null,359009,359009,null,null,364742,null,353815,353815,null,null,null,355597,null,null,null,null,null,359009,null,null,356160,null,358949,358949,360045,360045,362094,null,362083,null,351013,351013,null,null,347130,347130,null,359784,356012,356012,360651,null,363739,null,358203,358203,null,null,null,363506,355743,355743,364964,null,360206,360206,349023,349023,null,null,358969,358969,null,361565,null,357606,null,null,362600,null,351926,351926,null,null,null,null,null,null,null,null,348022,348022,null,358081,355185,355185,null,null,null,364315,360106,null,null,null,358545,358545,353520,353520,null,357987,null,360615,null,null,null,357141,null,359070,null,null,354543,354543,353357,353357,null,null,364204,null,353028,353028,null,null,null,null,356784,null,248263,248263,null,null,null,256484,null,null,255893,null,null,null,243856,243856,null,null,null,256111,null,null,255598,255598,null,null,254595,null,null,null,253043,null,null,null,253362,253362,260023,null,null,null,null,254077,254174,254174,null,null,null,null,null,null,null,null,261987,null,257901,null,null,null,null,null,null,null,null,null,246446,246446,null,260845,null,257333,254718,null,null,258416,249146,249146,null,null,254406,254406,null,null,null,256676,260828,260828,249631,249631,253771,253771,261831,null,255246,255246,null,null,255030,null,null,null,null,null,null,null,null,null,null,null,null,254655,null,261183,253233,null,null,null,null,261140,null,256006,null,257650,null,null,null,null,257176,null,null,null,null,null,253793,null,255476,255476,258712,null,null,null,253784,null,null,null,null,null,null,null,157313,157313,null,null,null,null,167856,null,null,null,null,null,null,null,163402,null,162214,null,null,null,null,null,160543,160543,null,164421,157126,157126,163752,163752,158301,158301,null,null,165177,165177,164056,null,165309,165309,null,null,null,null,167516,null,null,null,null,161629,159094,159094,null,168393,163837,163837,null,null,null,null,156048,156048,null,null,157367,157367,null,163581,null,169047,null,null,null,168922,null,null,null,null,167968,null,null,162014,null,null,null,null,null,null,null,null,161944,null,null,null,168314,null,null,null,null,null,164768,null,null,134539,null,134044,null,null,null,null,null,null,null,null,null,null,null,null,null,null,140616,null,126389,126389,null,null,140237,null,133740,null,null,null,null,null,null,135894,null,135569,132837,132837,null,134487,null,null,130927,130927,125942,125942,132084,null,139100,null,null,null,131673,131673,125418,125418,null,null,null,139727,null,null,null,null,null,null,null,null,null,null,null,134623,null,null,null,null,null,null,77715,null,null,null,71957,71957,82677,null,null,null,77422,null,null,null,76956,null,75439,75439,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,84350,null,null,71739,71739,null,77343,null,null,null,null,null,79815,null,null,null,42279,null,42099,null,null,null,null,null,null,35942,35942,33387,33387,null,null,null,36015,null,null,34493,34493,null,null,null,null,null,null,null,14000,9328,null,null,null,null,15155,null,null,16256,null,10997,null,4969,4969,null,9275,null,null,null,null,null,null,null,0]

// ॥ जय श्री राम जय श्री कृष्ण ॥