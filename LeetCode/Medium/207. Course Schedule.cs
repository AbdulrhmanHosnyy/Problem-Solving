public class Solution {
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        // Create adjacency list to represent the course dependencies
        List<List<int>> adjList = new List<List<int>>();
        for (int i = 0; i < numCourses; i++) {
            adjList.Add(new List<int>());
        }
        
        // Populate adjacency list with prerequisites
        foreach (int[] prerequisite in prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            adjList[course].Add(prerequisiteCourse);
        }
        
        // Create visited and recursion stack arrays
        bool[] visited = new bool[numCourses];
        bool[] recursionStack = new bool[numCourses];
        
        // Check for cycle in each course using DFS
        for (int course = 0; course < numCourses; course++) {
            if (HasCycle(course, adjList, visited, recursionStack)) {
                return false; // Cycle found, cannot finish all courses
            }
        }
        
        return true; // No cycle found, can finish all courses
    }

    private bool HasCycle(int course, List<List<int>> adjList, bool[] visited, bool[] recursionStack) {
        // Mark the current course as visited and add it to the recursion stack
        visited[course] = true;
        recursionStack[course] = true;
        
        // Traverse the prerequisites of the current course
        foreach (int prerequisiteCourse in adjList[course]) {
            // If the prerequisite course is in the recursion stack, cycle is found
            if (recursionStack[prerequisiteCourse]) {
                return true;
            }
            
            // If the prerequisite course is not visited, recursively check for cycle
            if (!visited[prerequisiteCourse] && HasCycle(prerequisiteCourse, adjList, visited, recursionStack)) {
                return true;
            }
        }
        
        // Remove the current course from the recursion stack
        recursionStack[course] = false;
        
        return false;
    }
}
