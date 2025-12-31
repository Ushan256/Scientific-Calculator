#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
const double PI = 3.14159265358979323846;

class ScientificCalculator {
private:
    double mem_val;
    vector<string> history_log;
    
    double toRad(double deg) {
        return deg * (PI / 180.0);
    }

    long long getFactorial(int n) {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;
        return n * getFactorial(n - 1);
    }

public:
    ScientificCalculator() {
        mem_val = 0.0;
        loadData();
    }

    void runArithmetic() {
        double n1, n2;
        char op;
        cout << "\n[Basic Arithmetic]\n";
        cout << "Enter expression (e.g. 5 + 3): ";
        cin >> n1 >> op >> n2;

        double res = 0;
        bool err = false;

        switch(op) {
            case '+': res = n1 + n2; break;
            case '-': res = n1 - n2; break;
            case '*': res = n1 * n2; break;
            case '/': 
                if (n2 == 0) { cout << "Error: Division by Zero\n"; err = true; }
                else res = n1 / n2; 
                break;
            case '%': res = (int)n1 % (int)n2; break;
            default: cout << "Invalid Operator\n"; err = true;
        }

        if (!err) {
            cout << "Result: " << res << endl;
            logHistory(to_string(n1) + " " + op + " " + to_string(n2) + " = " + to_string(res));
        }
    }

    void runTrig() {
        int ch;
        double ang;
        cout << "\n[Trigonometry]\n";
        cout << "1. Sin\n2. Cos\n3. Tan\n4. asin\n5. acos\n6. atan\n";
        cout << "Select: "; cin >> ch;
        cout << "Enter Value: "; cin >> ang;

        double res = 0;
        string fname = "";

        if (ch <= 3) {
            double rad = toRad(ang);
            if (ch == 1) { res = sin(rad); fname = "sin"; }
            else if (ch == 2) { res = cos(rad); fname = "cos"; }
            else if (ch == 3) { 
                if ((int)ang % 180 == 90) { cout << "Undefined\n"; return; }
                res = tan(rad); fname = "tan"; 
            }
        } 
        else {
            if (ch == 4) { 
                if (ang < -1 || ang > 1) { cout << "Domain Error\n"; return; }
                res = asin(ang) * (180.0/PI); fname = "asin"; 
            }
            else if (ch == 5) { 
                if (ang < -1 || ang > 1) { cout << "Domain Error\n"; return; }
                res = acos(ang) * (180.0/PI); fname = "acos"; 
            }
            else if (ch == 6) { res = atan(ang) * (180.0/PI); fname = "atan"; }
        }

        cout << "Result: " << res << endl;
        logHistory(fname + "(" + to_string(ang) + ") = " + to_string(res));
    }

    void runPowerLog() {
        int ch;
        double v1, v2;
        cout << "\n[Power & Log]\n";
        cout << "1. Power\n2. Sqrt\n3. Cube Root\n4. ln\n5. Log10\n";
        cout << "Select: "; cin >> ch;

        double res = 0;
        string lstr = "";

        if (ch == 1) {
            cout << "Base and Power: "; cin >> v1 >> v2;
            res = pow(v1, v2);
            lstr = to_string(v1) + "^" + to_string(v2);
        } else {
            cout << "Enter Value: "; cin >> v1;
            if (ch == 2) { 
                if (v1 < 0) { cout << "Error\n"; return; }
                res = sqrt(v1); lstr = "sqrt(" + to_string(v1) + ")"; 
            }
            else if (ch == 3) { res = cbrt(v1); lstr = "cbrt(" + to_string(v1) + ")"; }
            else if (ch == 4) { 
                if (v1 <= 0) { cout << "Error\n"; return; }
                res = log(v1); lstr = "ln(" + to_string(v1) + ")"; 
            }
            else if (ch == 5) { 
                if (v1 <= 0) { cout << "Error\n"; return; }
                res = log10(v1); lstr = "log(" + to_string(v1) + ")"; 
            }
        }
        cout << "Result: " << res << endl;
        logHistory(lstr + " = " + to_string(res));
    }

    void runStats() {
        int ch;
        cout << "\n[Stats & Algebra]\n";
        cout << "1. Factorial\n2. nPr\n3. nCr\n4. Quadratic Eq\n";
        cout << "Select: "; cin >> ch;

        if (ch == 1) {
            int n; cout << "Enter n: "; cin >> n;
            long long r = getFactorial(n);
            if (r == -1) cout << "Error\n";
            else {
                cout << "Result: " << r << endl;
                logHistory(to_string(n) + "! = " + to_string(r));
            }
        } else if (ch == 2 || ch == 3) {
            int n, r;
            cout << "Enter n and r: "; cin >> n >> r;
            if (n < r) { cout << "Error: n < r\n"; return; }
            
            long long num = getFactorial(n);
            long long den = getFactorial(n - r);
            long long res = (ch == 2) ? (num / den) : (num / (den * getFactorial(r)));
            
            cout << "Result: " << res << endl;
            logHistory(((ch==2)?"P":"C") + to_string(n) + "," + to_string(r) + " = " + to_string(res));
        } else if (ch == 4) {
            double a, b, c;
            cout << "Enter a, b, c: "; cin >> a >> b >> c;
            double d = b*b - 4*a*c;
            
            if (d > 0) {
                double x1 = (-b + sqrt(d)) / (2*a);
                double x2 = (-b - sqrt(d)) / (2*a);
                cout << "Roots: " << x1 << ", " << x2 << endl;
                logHistory("Quad Roots: " + to_string(x1) + ", " + to_string(x2));
            } else if (d == 0) {
                cout << "Root: " << -b / (2*a) << endl;
            } else {
                cout << "Imaginary Roots\n";
            }
        }
    }

    void runMemory() {
        int ch;
        double v;
        cout << "\n[Memory: " << mem_val << "]\n";
        cout << "1. M+\n2. M-\n3. MC\n4. MR\n";
        cout << "Select: "; cin >> ch;

        if (ch == 1) {
            cout << "Add: "; cin >> v;
            mem_val += v;
        } else if (ch == 2) {
            cout << "Sub: "; cin >> v;
            mem_val -= v;
        } else if (ch == 3) {
            mem_val = 0;
            cout << "Cleared\n";
        } else if (ch == 4) {
            cout << "Recall: " << mem_val << endl;
        }
    }

    void logHistory(string s) {
        history_log.push_back(s);
        saveData();
    }

    void viewHistory() {
        cout << "\n--- History ---\n";
        if (history_log.empty()) cout << "Empty\n";
        for (size_t i = 0; i < history_log.size(); i++) {
            cout << history_log[i] << endl;
        }
    }

    void wipeHistory() {
        history_log.clear();
        ofstream f("calc_log.txt", ios::trunc);
        f.close();
        cout << "History Deleted\n";
    }

    void saveData() {
        ofstream f("calc_log.txt", ios::app);
        if (!history_log.empty()) {
            f << history_log.back() << endl;
        }
        f.close();
    }

    void loadData() {
        ifstream f("calc_log.txt");
        string line;
        while (getline(f, line)) {
            history_log.push_back(line);
        }
        f.close();
    }
};

int main() {
    ScientificCalculator app;
    int opt;
    cout << "<=== Scientific Calculator ===>\n";
    do {
        cout << "\n1. Arithmetic\n2. Trigonometry\n3. Power/Log\n4. Stats/Algebra\n5. Memory\n6. View History\n7. Clear History\n8. Exit\n";
        cout << "Option: ";
        cin >> opt;

        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        switch (opt) {
            case 1: app.runArithmetic(); break;
            case 2: app.runTrig(); break;
            case 3: app.runPowerLog(); break;
            case 4: app.runStats(); break;
            case 5: app.runMemory(); break;
            case 6: app.viewHistory(); break;
            case 7: app.wipeHistory(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid\n";
        }

    } while (opt != 8);
    return 0;
}