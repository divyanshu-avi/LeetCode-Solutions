class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i, j, n = wordList.size(), m = wordList[0].length(), steps=0;
        string temp;
        char save, x;
        unordered_map<string, bool> visited;
        for(i=0;i<n;i++)
            visited.insert({wordList[i], false});
        if(visited.find(endWord) == visited.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        bool flag=1;
        while(!q.empty() && flag)
        {
            int oldqsize = q.size();
            for(i=0;i<oldqsize;i++)
            {
                temp = q.front();
                q.pop();
                if(visited[temp])
                    continue;
                visited[temp] = true;
                if(temp == endWord)
                {
                    flag = 0;
                    break;
                }
                for(j=0;j<m;j++)
                {
                    save = temp[j];
                    for(x = 'a'; x<='z' ; x++)
                    {
                        temp[j] = x;
                        //Should belong to the map visited but value should be false
                        if(visited.find(temp) != visited.end() && !visited[temp])
                        {
                            //cout<<temp<<' ';
                            q.push(temp);
                        }
                    }
                    temp[j] = save;
                }
            }
            steps++;
        }
        return visited[endWord] ? steps : 0;
    }
};