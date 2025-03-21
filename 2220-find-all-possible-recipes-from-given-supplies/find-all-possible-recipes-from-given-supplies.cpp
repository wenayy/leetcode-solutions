class Solution {
public:
   vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> available(supplies.begin(), supplies.end()); // Store available ingredients
    unordered_map<string, vector<string>> graph;  // ingredient -> recipes that depend on it
    unordered_map<string, int> indegree; // recipe -> number of required ingredients

    // Initialize indegrees
    for (int i = 0; i < recipes.size(); i++) {
        string recipe = recipes[i];
        indegree[recipe] = ingredients[i].size(); // Number of required ingredients
        for (string ing : ingredients[i]) {
            graph[ing].push_back(recipe); // Ingredient -> list of recipes that need it
        }
    }

    // Queue to process available recipes
    queue<string> q;
    for (string& supply : supplies) {
        q.push(supply);
    }

    vector<string> result;

    // Process ingredients level by level
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (indegree.find(current) != indegree.end()) { // It's a recipe, add to result
            result.push_back(current);
        }

        // Unlock dependent recipes
        for (string& nextRecipe : graph[current]) {
            indegree[nextRecipe]--; // Reduce required ingredient count
            if (indegree[nextRecipe] == 0) { // If all required ingredients are available
                q.push(nextRecipe);
            }
        }
    }
    return result;
}

};