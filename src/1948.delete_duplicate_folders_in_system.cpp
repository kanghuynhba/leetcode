class Solution {
public:
    struct Node{
    string key="/";
    string hashVal="";
    struct Node *parent=nullptr;
    map<string, Node> children;
};
class Tree{
private:
public:
    Node root;
    void insert(struct Node *curNode, vector<string>& path, int i) {
        if(i==path.size()) {
            return;
        }
        string node=path[i];
        if(curNode->children.find(node)==curNode->children.end()) {
            struct Node *newNode=new Node;
            newNode->key=node;
            newNode->parent=curNode;
            newNode->hashVal=node;
            curNode->children[node]=*newNode;
            int j=0;
            while(newNode!=nullptr) {
                for(int k=0; k<j; k++) {
                    newNode->hashVal+="-";
                }
                newNode->hashVal+=node;
                newNode=newNode->parent;
                j++;
            }
        }
        insert(&curNode->children[node], path, i+1);;
    }
    void show(struct Node *curNode, int level=0) {
        for(int i=0; i<level; i++) {
            cout << "  ";
        }
        cout << curNode->hashVal << endl;
        for(auto i=curNode->children.begin(); i!=curNode->children.end(); i++) {
            show(&i->second, level+1);
        }
    }
};
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Tree t;
        for(int i=0; i<paths.size(); i++) {
            t.insert(&t.root, paths[i], 0);
        }
        t.show(&t.root);   
        return {{}};
    }
};
