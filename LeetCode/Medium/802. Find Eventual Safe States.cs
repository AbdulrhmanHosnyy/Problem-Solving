public class Solution {
    public IList<int> EventualSafeNodes(int[][] graph) {
        int n = graph.Length;
        Dictionary<int, bool> dict = new Dictionary<int, bool>();
        List<int> result = new List<int>();
        for(int i = 0; i < n; i++)
            if(dfs(i, dict, graph))  
                result.Add(i);
        return result;
    }
    private bool dfs(int i, Dictionary<int, bool> dict, int[][] graph)
    {
        if(dict.ContainsKey(i)) return dict[i];
        dict.Add(i, false);
        foreach(var neighbour in graph[i]){
            if(!dfs(neighbour, dict, graph))
                return false;
        }
        dict[i] = true;
        return true;
    }
}
