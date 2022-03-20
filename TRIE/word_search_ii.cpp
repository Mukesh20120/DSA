//for trie data structure
struct Node{
    Node *list[26];
    string *s; //store the word at the end of insert of one word
};

class Solution {
private:
     int n,m;       // board dimension
    vector<string>ans; //store answer
    int dir[5]={0,1,0,-1,0}; //move in four direction
    struct Node *root;  //trie node global declare 
public:
    //inserting in trie data sturcture
     void Insert(string &word){
        Node *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->list[word[i]-'a']==NULL){
                temp->list[word[i]-'a']=new Node();
            }
            temp=temp->list[word[i]-'a'];
        }
      temp->s=&word; //store the word address
    }
    
    void dfs(vector<vector<char>>&board,int i,int j,struct Node *node){
        //boundary case                 act as visited or not     check if it is null
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='#' || !node->list[board[i][j]-'a'])return;
        //store the character of board 
        char orgch=board[i][j];
         board[i][j]='#'; //marking as visited
        node=node->list[orgch-'a']; //move ahead
        
        if(node->s!=NULL){
            //if not null then it have address of some word store it
            ans.push_back(*node->s);
            node->s=NULL; //marking it null to remove duplicate
        }
       
        //loop run in four direction of current position
        for(int ind=0;ind<4;ind++)
            dfs(board,i+dir[ind],j+dir[ind+1],node);
        board[i][j]=orgch; //reverse the changes we made above
    }
   
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        root=new Node(); //initilize root
        for(string &w: words)
            Insert(w);
        
        //checking each and every character in board
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dfs(board,i,j,root);
    
        
        return ans;
    }
};