class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // Step 1: Find all suspicious methods reachable from k
        vector<bool> suspicious(n, false);
        vector<int> st = {k};
        suspicious[k] = true;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    st.push_back(v);
                }
            }
        }

        // Step 2: Check if any non-suspicious method invokes a suspicious method
        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }

        // Step 3: Collect the result
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!can_remove || !suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};