class BrowserHistory {
public:
    int currPos;
    vector<string> history;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPos = 0;
    }
    
    void visit(string url) {
        history.resize(currPos + 1);
        history.push_back(url);
        currPos++;
    }
    
    string back(int steps) {
        for(int i = 0; i < steps; i++){
            if(currPos > 0){
                currPos--;
            }
            else{
                break;
            }
        }
        return history[currPos];
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps; i++){
            if(currPos < history.size() - 1){
                currPos++;
            }
            else{
                break;
            }
        }
        return history[currPos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */