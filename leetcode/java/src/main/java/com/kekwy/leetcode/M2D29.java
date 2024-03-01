package com.kekwy.leetcode;

import com.kekwy.leetcode.util.TreeNode;

import java.util.*;

public class M2D29 {


}

class P170 {
    class TwoSum {

        private Map<Integer, Integer> map;

        public TwoSum() {
            map = new HashMap<>();
        }

        public void add(int number) {
            Integer count = map.getOrDefault(number, 0);
            map.put(number, count + 1);
        }

        public boolean find(int value) {
            for (Integer number : map.keySet()) {
                int otherNumber = value - number;
                if (map.containsKey(otherNumber)) {
                    if (number != otherNumber || map.get(number) > 1) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
}

class P173 {
    class BSTIterator {

        private Stack<TreeNode> stack;

        public BSTIterator(TreeNode root) {
            stack = new Stack<>();
            stack.push(root);
        }

        public int next() {
            while (!stack.isEmpty()) {
                TreeNode node = stack.peek();
                if (node != null) {
                    stack.push(null);
                    if (node.left != null) {
                        stack.push(node.left);
                    }
                } else {
                    stack.pop();
                    node = stack.pop();
                    if (node.right != null) {
                        stack.push(node.right);
                    }
                    return node.val;
                }
            }
            return -1;
        }

        public boolean hasNext() {
            return !stack.isEmpty();
        }
    }
}

class P208 {

    class Trie {

        class TrieNode {

            private char val;
            private boolean flag = false;
            private final List<TrieNode> children = new LinkedList<>();

            public TrieNode() {
            }

            public TrieNode(char val) {
                this.val = val;
            }

            public TrieNode addChild(char childVal) {
                TrieNode trieNode = new TrieNode(childVal);
                children.add(trieNode);
                return trieNode;
            }

        }

        private TrieNode root = new TrieNode();

        public Trie() {

        }

        private void insert(String word, int i, TrieNode node) {
            if (i >= word.length()) {
                node.flag = true;
                return;
            }
            char c = word.charAt(i);
            TrieNode child = null;
            for (TrieNode trieNode : node.children) {
                if (trieNode.val == c) {
                    child = trieNode;
                    break;
                }
            }
            if (child == null) {
                child = node.addChild(c);
            }
            insert(word, i + 1, child);
        }

        private boolean search(String word, int i, TrieNode node) {
            if (i >= word.length()) return node.flag;
            char c = word.charAt(i);
            TrieNode child = null;
            for (TrieNode trieNode : node.children) {
                if (trieNode.val == c) {
                    child = trieNode;
                    break;
                }
            }
            if (child == null) {
                return false;
            }
            return search(word, i + 1, child);
        }

        private boolean startsWith(String prefix, int i, TrieNode node) {
            if (i >= prefix.length()) return true;
            char c = prefix.charAt(i);
            TrieNode child = null;
            for (TrieNode trieNode : node.children) {
                if (trieNode.val == c) {
                    child = trieNode;
                    break;
                }
            }
            if (child == null) {
                return false;
            }
            return startsWith(prefix, i + 1, child);
        }

        public void insert(String word) {
            insert(word, 0, root);
        }

        public boolean search(String word) {
            return search(word, 0, root);
        }

        public boolean startsWith(String prefix) {
            return startsWith(prefix, 0, root);
        }
    }

}

class P211 {

    class WordDictionary {

        class TrieNode {

            private char val;
            private boolean flag = false;
            private final TrieNode[] children = new TrieNode[26];

            public TrieNode() {
            }

            public TrieNode(char val) {
                this.val = val;
            }

        }

        public WordDictionary() {

        }

        private TrieNode root = new TrieNode();

        private void addWord(String word, int i, TrieNode node) {
            if (i >= word.length()) {
                node.flag = true;
                return;
            }
            char c = word.charAt(i);
            if (node.children[c - 'a'] == null) {
                node.children[c - 'a'] = new TrieNode(c);
            }
            addWord(word, i + 1, node.children[c - 'a']);
        }

        private boolean search(String word, int i, TrieNode node) {
            if (i >= word.length()) return node.flag;
            char c = word.charAt(i);
            if (c == '.') {
                for (TrieNode trieNode : node.children) {
                    if (trieNode != null && search(word, i + 1, trieNode)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node.children[c - 'a'] == null) {
                    return false;
                }
                return search(word, i + 1, node.children[c - 'a']);
            }
        }

        public void addWord(String word) {
            addWord(word, 0, root);
        }

        public boolean search(String word) {
            return search(word, 0, root);
        }
    }

}

class P77 {

    class Solution {

        private List<List<Integer>> res = new LinkedList<>();

        private void helper(int n, int k, int begin, List<Integer> tmp) {
            if (k == 0) {
                res.add(List.copyOf(tmp));
                return;
            }
            for (int i = begin; i + k - 1 <= n; i++) {
                tmp.add(i);
                helper(n, k - 1, i + 1, tmp);
                tmp.remove(tmp.size() - 1);
            }
        }

        public List<List<Integer>> combine(int n, int k) {
            helper(n, k, 1, new LinkedList<>());
            return res;
        }
    }

}

class P216 {

    class Solution {

        List<List<Integer>> res = new LinkedList<>();
        LinkedList<Integer> path = new LinkedList<>();

        private void helper(int k, int n, int begin) {
            if (k == 0 && n == 0) {
                res.add(List.copyOf(path));
                return;
            }
            if (k * 9 < n) {
                return; // 剪枝
            }
            for (int i = begin; i <= 9; i++) {
                path.add(i);
                helper(k - 1, n - i, i + 1);
                path.removeLast();
            }
        }

        public List<List<Integer>> combinationSum3(int k, int n) {
            helper(k, n, 1);
            return res;
        }
    }

}

class P17 {

    class Solution {

        private char[][] charMap = new char[][]{
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
        };

        private StringBuilder builder = new StringBuilder();
        private List<String> res = new LinkedList<>();

        private void helper(String digits, int index) {
            if (index >= digits.length()) {
                res.add(builder.toString());
            } else {
                for (char c : charMap[digits.charAt(index) - '2']) {
                    builder.append(c);
                    helper(digits, index + 1);
                    builder.deleteCharAt(builder.length() - 1);
                }
            }
        }

        public List<String> letterCombinations(String digits) {
            if (digits.length() > 0) {
                helper(digits, 0);
            }
            return res;
        }
    }

}

class P39 {

    class Solution {

        List<List<Integer>> res = new LinkedList<>();
        LinkedList<Integer> nums = new LinkedList<>();

        private void helper(int[] candidates, int target, int index) {
            if (target == 0) {
                res.add(List.copyOf(nums));
                return;
            }
            if (target < 0 || index >= candidates.length) return;
            for (int i = index; i < candidates.length; i++) {
                nums.add(candidates[i]);
                helper(candidates, target - candidates[i], i);
                nums.removeLast();
            }
        }

        // 一般回溯加剪枝能过的题就不需要考虑DP
        public List<List<Integer>> combinationSum(int[] candidates, int target) {
            helper(candidates, target, 0);
            return res;
        }
    }

}

class P70 {

    class Solution {

        private List<List<Integer>> res = new LinkedList<>();
        private LinkedList<Integer> nums = new LinkedList<>();

        private void helper(int[] candidates, int target, int index) {
            if (target == 0) {
                res.add(List.copyOf(nums));
                return;
            }
            if (target < 0 || index >= candidates.length) return;
            Integer lastChoice = null;
            for (int i = index; i < candidates.length; i++) {
                if (lastChoice != null && candidates[i] == lastChoice) continue;
                lastChoice = candidates[i];
                nums.add(candidates[i]);
                helper(candidates, target - candidates[i], i + 1);
                nums.removeLast();
            }
        }

        public List<List<Integer>> combinationSum2(int[] candidates, int target) {
            int[] sortedCandidates = Arrays.stream(candidates).sorted().toArray();
            helper(sortedCandidates, target, 0);
            return res;
        }
    }

}

class P131 {

    class Solution {

        private List<List<String>> res = new LinkedList<>();

        private LinkedList<String> strings = new LinkedList<>();


        private boolean[][] isPartition;

        private void findPartition(String s) {
            isPartition = new boolean[s.length()][s.length()];
            // dp
            for (int i = s.length() - 1; i >= 0; i--) {
                for (int j = i; j < s.length(); j++) {
                    if (i == j) {
                        isPartition[i][j] = true; // a
                    } else if (j - i == 1) {
                        isPartition[i][j] = s.charAt(i) == s.charAt(j); // aa
                    } else {
                        isPartition[i][j] = s.charAt(i) == s.charAt(j) && isPartition[i + 1][j - 1]; // abba
                    }
                }
            }
        }

        private void helper(String s, int index) {
            if (index >= s.length()) {
                res.add(List.copyOf(strings));
            } else {
                for (int i = index; i < s.length(); i++) {
                    if (isPartition[index][i]) {
                        strings.add(s.substring(index, i + 1));
                        helper(s, i + 1);
                        strings.removeLast();
                    }
                }
            }
        }

        public List<List<String>> partition(String s) {
            findPartition(s);
            helper(s, 0);
            return res;
        }


    }

}






