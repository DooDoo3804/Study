import java.util.*;

class Solution {
    public class TrieNode {
        Map<Character, TrieNode> children;
        int count;
        
        public TrieNode() {
            children = new HashMap<>();
            count = 0;
        }
    }
    
    class Trie {
        TrieNode root;
        
        public Trie() {
            root = new TrieNode();
        }
        
        public void insertWord(String word) {
            TrieNode curr = root;
            curr.count++;
            
            for (char c : word.toCharArray()) {
                curr.children.putIfAbsent(c, new TrieNode());
                curr = curr.children.get(c);
                curr.count++;
            }
        }
        
        public int searchWord(String query) {
            TrieNode curr = root;
            
            for (char q : query.toCharArray()) {
                if (q == '?') break;
                if (!curr.children.containsKey(q)) {
                    return 0;
                }
                curr = curr.children.get(q);
            }
            return curr.count;
        }
    }
    
    public int[] solution(String[] words, String[] queries) {
        int[] answer = new int[queries.length];
        
        Map<Integer, Trie> wordMap = new HashMap<>();
        Map<Integer, Trie> reverseWordMap = new HashMap<>();
        
        for (String word : words) {
            int length = word.length();
            
            if (!wordMap.containsKey(length)) {
                wordMap.put(length, new Trie());
                reverseWordMap.put(length, new Trie());
            }
            wordMap.get(length).insertWord(word);
            reverseWordMap.get(length).insertWord(new StringBuilder(word).reverse().toString());
        }
        
        for (int i = 0; i < queries.length; i++) {
            String query = queries[i];
            int length = query.length();
            
            if (!wordMap.containsKey(length)) {
                answer[i] = 0;
                continue;
            }
            
            if (query.charAt(0) != '?') {
                Trie candidateWords = wordMap.get(length);
                answer[i] = candidateWords.searchWord(query);
            } else {
                Trie candidateWords = reverseWordMap.get(length);
                query = new StringBuilder(query).reverse().toString();
                answer[i] = candidateWords.searchWord(query);
            }
        }
        
        return answer;
    }
    
}