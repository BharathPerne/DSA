class Spreadsheet {
public:
private:
    vector<vector<int>> spreadsheet;
    int rows;

public:
    Spreadsheet(int numRows) : rows(numRows) {
        spreadsheet.resize(rows, vector<int>(26)); 
        
        // for (int col = 0; col < 26; col++) {
        //         char current_char = 'A' + col;
        //         for (int row = 0; row < rows; row++) {
        //                 spreadsheet[col][row] = make_pair(current_char, 0);
        //         }
        // }
    }
    
    void setCell(string cell, int value) {
        int index=cell[0]-'A';
        int col=stoi(cell.substr(1)) - 1;
        spreadsheet[col][index]=value;
    }
    
    void resetCell(string cell) {
        int index=cell[0]-'A';
        spreadsheet[stoi(cell.substr(1)) - 1][index]=0;
    }
    
    int getValue(string formula) {
    int sum = 0;
    for (int i = 1; i < formula.size();) {
        if (isalpha(formula[i])) {
            // --- parse cell reference ---
            int col = formula[i] - 'A';
            i++;

            string rowStr = "";
            while (i < formula.size() && isdigit(formula[i])) {
                rowStr += formula[i];
                i++;
            }
            int row = stoi(rowStr) - 1;

            if (row >= 0 && row < rows && col >= 0 && col < 26) {
                sum += spreadsheet[row][col];
            }
        } 
        else if (isdigit(formula[i])) {
            // --- parse standalone number ---
            string str = "";
            while (i < formula.size() && isdigit(formula[i])) {
                str += formula[i];
                i++;
            }
            sum += stoi(str);
        } 
        else {

            i++;
        }
    }
    return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */