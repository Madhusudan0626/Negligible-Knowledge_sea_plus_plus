class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows == 0)
            return triangle;
        vector<int> first_row;
        first_row.push_back(1);
        triangle.push_back(first_row);

        for(int i=1;i<numRows;i++){
            vector <int> pre_row=triangle[i-1];
            vector <int> row;

            row.push_back(1);

            for(int j=1;j<i;j++){
                row.push_back(pre_row[j-1]+pre_row[j]);
            }

            row.push_back(1);
            triangle.push_back(row);

        }

        return triangle;
    }
};
