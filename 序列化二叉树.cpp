class Codec {   //层序遍历
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(!q.empty()){  //按层加入字符串，null则加入#，直到最后一个节点
            TreeNode* cur = q.front();
            q.pop();
            if(cur != nullptr){
                res += to_string(cur -> val);
                q.push(cur -> left);
                q.push(cur -> right);
            }
            else
                res += '#';
            res += ' ';
        }
        while(res.back() == '#')
            res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        stringstream str(data);
        vector<string> s;
        string c;
        while(str >> c){    //用vector存方便stoi
            s.push_back(c);
        }
        int i = 0;
        TreeNode* root = new TreeNode(stoi(s[i]));
        ++i;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(i < s.size() && s[i] != "#")
                cur -> left = new TreeNode(stoi(s[i]));
            ++i;
            if(i < s.size() && s[i] != "#")
                cur -> right = new TreeNode(stoi(s[i]));
            ++i;
            if(cur -> left != nullptr)
                q.push(cur -> left);
            if(cur -> right != nullptr)
                q.push(cur -> right);
        }
        return root;
    }
};

class Codec {   //先序遍历
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";
        return to_string(root->val) + " "   //加空格为输入流做准备
            + serialize(root->left) + " " 
            + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return buildTree(s);
    }
private:
    TreeNode* buildTree(istringstream& s){
        string sub;
        s >> sub;
        if(sub == "#")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(sub));
        node -> left = buildTree(s);
        node -> right = buildTree(s);
        return node;
    }
};