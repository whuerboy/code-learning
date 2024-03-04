#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValidOutSequence(int N, vector<char>& inSequence, vector<char>& outSequence) {
    stack<char> st;
    int outPtr = 0;

    for (int i = 0; i < N; i++) {
        st.push(inSequence[i]);

        while (!st.empty() && st.top() == outSequence[outPtr]) {
            st.pop();
            outPtr++;
        }
    }

    return st.empty();
}



int main27() {
    int N;
    cin >> N;

    vector<char> inSequence(N);
    for (int i = 0; i < N; i++) {
        cin >> inSequence[i];
    }

    vector<char> outSequence(N);
    for (int i = 0; i < N; i++) {
        cin >> outSequence[i];
    }

    bool isValid = isValidOutSequence(N, inSequence, outSequence);
    if (isValid == 1) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
