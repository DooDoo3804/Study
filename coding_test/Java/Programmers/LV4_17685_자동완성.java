import java.io.*;
import java.util.*;

// Trie 자료구조

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static class TrieNode {
        Map<Character, TrieNode> children;
        boolean isWord;
        int count;
        public TrieNode() {
            children = new HashMap<>();
            isWord = false;
            count = 0;
        }
    }

    static class Trie {
        TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        public void insert(String word) {
            TrieNode curr = root;
            for (char c : word.toCharArray()) {
                curr.children.putIfAbsent(c, new TrieNode());
                curr = curr.children.get(c);
                curr.count++;
            }
            curr.isWord = true;
        }

        public int search(String query) {
            TrieNode curr = root;
            int count = 0;
            for (char c : query.toCharArray()) {
                if (!curr.children.containsKey(c)) break;
                curr = curr.children.get(c);
                count++;
                if (curr.count == 1) break;
            }
            return count;
        }

    }
    public static void main(String[] args) throws IOException {
        String[] words = {"go", "gone", "guild"};
        int answer = 0;
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        for (String w : words) {
            answer += trie.search(w);
        }
    }



}
