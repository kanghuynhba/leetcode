class Solution {
private:
    static const int MAX=26;
    struct Node {
        struct Node* child[MAX];
        int countChar;
        int countWord;
    };
    class Trie {
    private:
        Node* root;   

        Node* createNode() {
            Node* node=new Node();
            for(int i=0; i<MAX; i++) {
                node->child[i]=NULL;
            }        
            node->countChar=0;
            node->countWord=0;
            return node;
        }
    public:
        Node* getRoot() {
            return root;
        }

        Trie() {
            root=createNode();
        }

        void addWord(string str) {
            Node* curNode=root;
            for(int i=0; i<str.size(); i++) {
                int ch=str[i]-'a';
                if(curNode->child[ch]==NULL) {
                    curNode->child[ch]=createNode();      
                } 
                curNode=curNode->child[ch];
                curNode->countChar++;
            }    
            curNode->countWord++;
        }

        bool removeWord(struct Node* root, string str, int level) {
            if(!root) {
                return false;
            }                
            if(level==str.size()) {
                if(root->countWord>0) {
                    root->countWord--;
                    return true;
                }    
                return false;
            } 
            int ch=str[level]-'a';  
            bool flag=removeWord(root->child[ch], str, level+1);
            if(flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])) {
                delete root->child[ch];
                root->child[ch]=NULL;
            }
            return flag;
        }

        bool isWord(struct Node* node) {
            return (node->countWord!=0);
        }

        bool isEmpty(struct Node *node) {
            for(int i=0; i<MAX; i++) {
                if(root->child[i]!=NULL) {
                    return false;
                }
            }
            return true;
        }

        bool findWord(string str) {
            Node *curNode=root;
            for(int i=0; i<str.size(); i++) {
                int ch=str[i]-'a';
                if(curNode->child[ch]==NULL) {
                    return false;
                }
                curNode=curNode->child[ch];
            } 
            return curNode->countWord>0;
        }

        void printWord(struct Node* root, string s) {
            if(isWord(root)) {
                cout << s << endl;
            }                
            for(int i=0; i<MAX; i++) {
                if(root->child[i]) {
                    printWord(root->child[i], s+char('a'+i));
                }
            }
        }
    };
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        int size=strs.size();
        string ans="";
        for(int i=0; i<size; i++) {
            trie.addWord(strs[i]);
        }
        bool flag=true;
        Node *root=trie.getRoot();
        while(flag) {
            flag=false;
            for(int i=0; i<MAX; i++) {
                if(root->child[i]!=NULL && root->child[i]->countChar==size) {
                    char c=i+'a';
                    ans+=c;
                    flag=true;
                    root=root->child[i];
                } else if(root->child[i]!=NULL && root->child[i]->countChar<size) {
                    return ans;
                }             
            }
        }
        return ans;
    }
};
