class Solution {
public:
    int original;
    void rec(vector<vector<int>> &image, int sr, int sc, int& color, bool (&vis) [51][51]){
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;

        if (image[sr][sc] != this->original) return;
        if(vis[sr][sc]) return; 
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        rec(image,sr+1,sc,color,vis);
        rec(image,sr-1,sc,color,vis);
        rec(image,sr,sc-1,color,vis);
        rec(image,sr,sc+1,color,vis);
        // rec(image,sr+1,sc+1,color,vis);
        // rec(image,sr-1,sc+1,color,vis);
        // rec(image,sr+1,sc-1,color,vis);
        // rec(image,sr-1,sc-1,color,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bool vis[51][51]={0};
        this->original = image[sr][sc];
        rec(image,sr,sc,color,vis);
        return image;
    }
};
