package com.kekwy.leetcode;

import com.kekwy.leetcode.util.TreeNode;
import org.junit.jupiter.api.Test;

import java.sql.Struct;
import java.util.*;

class P1261 {
    class FindElements {

        private final TreeNode root;
        private final List<Integer> layerOrder = new ArrayList<>();

        public FindElements(TreeNode root) {
            root.val = 0;
            this.root = root;
            init(root);
            layerTravers();
        }

        private void init(TreeNode node) {
            if (node == null) return;
            if (node.left != null) node.left.val = 2 * node.val + 1;
            if (node.right != null) node.right.val = 2 * node.val + 2;
            init(node.left);
            init(node.right);
        }

        private void layerTravers() {
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            while (!queue.isEmpty()) {
                TreeNode node = queue.poll();
                layerOrder.add(node.val);
                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }
        }

        public boolean find(int target) {
            // 二分查找
            int begin = 0, end = layerOrder.size();
            while (begin < end) {
                int mid = begin + (end - begin) / 2;
                if (layerOrder.get(mid) > target) {
                    end = mid;
                } else if (layerOrder.get(mid) < target) {
                    begin = mid + 1;
                } else {
                    return true;
                }
            }
            return false;
        }
    }

    @Test
    public void test() {
//        FindElements findElements = new FindElements();

    }

}

class P274 {
    class Solution {
        public int hIndex(int[] citations) {
            List<Integer> list = new ArrayList<>(Arrays.stream(citations).boxed().toList());
            list.sort((a, b) -> b - a);
            int h = 0;
            for (Integer i : list) {
                if (i >= h + 1) h++;
                else break;
            }
            return h;
        }
    }
}

class P238 {
    class Solution {
        public int[] productExceptSelf(int[] nums) {
            int[] res = new int[nums.length];
            int tmp = 1;
            for (int i = 0; i < nums.length; i++) {
                res[i] = tmp;
                tmp *= nums[i];
            }
            tmp = 1;
            for (int i = nums.length - 1; i >= 0; i--) {
                res[i] *= tmp;
                tmp *= nums[i];
            }
            return res;
        }
    }
}

class P134 {
    /**
     * 分析无法达到的情况，通过减少回溯或避免回溯来降低时间复杂度
     * <a href="https://leetcode.cn/problems/gas-station/solutions/488357/jia-you-zhan-by-leetcode-solution/">题解</a>
     */
    class Solution {
        public int canCompleteCircuit(int[] gas, int[] cost) {
            int gasSum = 0;
            int from = 0;
            int i = 0;
            while (true) {
                gasSum += gas[i];
                if (gasSum >= cost[i]) {
                    gasSum -= cost[i];
                    i = (i + 1) % gas.length;
                    if (i == from) return from;
                } else {
                    i = (i + 1) % gas.length;
                    if (i <= from) return -1;
                    from = i;
                    gasSum = 0;
                }
            }
        }
    }
}

class P135 {
    class Solution {
        public int candy(int[] ratings) {
            int res = 0;
            int higherNum = 1;
            int curr = 1;
            for (int i = 0; i < ratings.length - 1; i++) {
                if (ratings[i] <= ratings[i + 1]) {
                    if (higherNum != 1) {
                        res += higherNum * (higherNum - 1) / 2;
                        res += Math.max(curr, higherNum);
                        higherNum = 1;
                        if (ratings[i] == ratings[i + 1]) {
                            curr = 1;
                        } else {
                            curr = 2;
                        }
                    } else {
                        res += curr;
                        if (ratings[i] == ratings[i + 1]) {
                            curr = 1;
                        } else {
                            curr++;
                        }
                    }
                } else {
                    higherNum++;
                }
            }
            if (higherNum != 1) {
                res += higherNum * (higherNum - 1) / 2;
                res += Math.max(curr, higherNum);
            } else {
                res += curr;
            }
            return res;
        }

    }

    @Test
    public void test() {
        Solution solution = new Solution();
        solution.candy(new int[]{1, 3, 4, 5, 2});
    }

}

class P42 {
    class Solution {
        public int trap(int[] height) {
            int res = 0;
            Stack<Integer> stack = new Stack<>();
            stack.push(0);
            for (int i = 0; i < height.length; i++) {
                int top = stack.peek();
                if (height[i] < height[top]) {
                    stack.push(i);
                } else if (height[i] > height[top]) {
                    while (height[i] > height[top]) {
                        int b = stack.pop();
                        if (stack.isEmpty()) break;
                        top = stack.peek();
                        int h = Math.min(height[i], height[top]) - height[b];
                        int w = i - top - 1;
                        res += h * w;
                    }
                    if (!stack.isEmpty() && height[i] == height[top]) {
                        stack.pop();
                    }
                    stack.push(i);
                } else {
                    stack.pop();
                    stack.push(i);
                }
            }
            return res;
        }
    }
}

class P13 {

    class Solution {
        Map<Character, Integer> symbolValues = new HashMap<Character, Integer>() {{
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);
        }};

        public int romanToInt(String s) {
            int ans = 0;
            int n = s.length();
            for (int i = 0; i < n; ++i) {
                int value = symbolValues.get(s.charAt(i));
                if (i < n - 1 && value < symbolValues.get(s.charAt(i + 1))) {
                    ans -= value;
                } else {
                    ans += value;
                }
            }
            return ans;
        }
    }


}

class P58 {
    class Solution {
        public int lengthOfLastWord(String s) {
            int curr = 0;
            int res = 0;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == ' ') {
                    if (curr != 0) {
                        res = curr;
                        curr = 0;
                    }
                } else {
                    curr++;
                }
            }
            if (curr != 0) {
                res = curr;
            }
            return res;
        }
    }
}

class P14 {
    class Solution {
        public String longestCommonPrefix(String[] strs) {
            int i = 0;
            StringBuilder builder = new StringBuilder();
            while (true) {
                if (i >= strs[0].length()) return builder.toString();
                char c = strs[0].charAt(i);
                for (int i1 = 1; i1 < strs.length; i1++) {
                    if (i >= strs[i1].length() || strs[i1].charAt(i) != c) {
                        return builder.toString();
                    }
                }
                builder.append(c);
                i++;
            }
        }
    }
}

class P6 {
    /**
     * 大胆使用模拟法
     */
    class Solution {
        public String convert(String s, int numRows) {
            if (numRows < 2) return s;
            List<StringBuilder> rows = new ArrayList<StringBuilder>();
            for (int i = 0; i < numRows; i++) rows.add(new StringBuilder());
            int i = 0, flag = -1;
            for (char c : s.toCharArray()) {
                rows.get(i).append(c);
                if (i == 0 || i == numRows - 1) flag = -flag;
                i += flag;
            }
            StringBuilder res = new StringBuilder();
            for (StringBuilder row : rows) res.append(row);
            return res.toString();
        }
    }

}

@SuppressWarnings("DuplicatedCode")
class P28 {

    class Solution {
        private int[] getNextArray(String pattern) {
            int[] next = new int[pattern.length()];
            int p = 0, q = -1;
            next[p] = q;
            while (p < pattern.length() - 1) {
                if (q == -1 || pattern.charAt(p) == pattern.charAt(q)) {
                    next[++p] = ++q;
                } else {
                    q = next[q];
                }
            }
            return next;
        }

        public int strStr(String haystack, String needle) {
            int[] nextArray = getNextArray(needle);
            int p = 0, q = 0;
            while (p < haystack.length() && q < needle.length()) {
                if (q == -1 || haystack.charAt(p) == needle.charAt(q)) {
                    p++;
                    q++;
                } else {
                    q = nextArray[q];
                }
            }
            if (q == needle.length()) {
                return p - q;
            } else {
                return -1;
            }
        }
    }
}

class P68 {
    class Solution {
        public List<String> fullJustify(String[] words, int maxWidth) {
            int begin = 0;
            int width = 0;
            int number = 0;

            List<String> res = new ArrayList<>();

            int i = 0;
            while (i < words.length) {
                String word = words[i];
                int temp = width + word.length() + 1;
                if (temp - 1 > maxWidth) {
                    if (number == 1) {
                        res.add(words[begin] + " ".repeat(maxWidth - (width - 1)));
                    } else {
                        int space = (maxWidth - (width - 1)) / (number - 1);
                        int addition = (maxWidth - (width - 1)) % (number - 1);
                        StringBuilder line = new StringBuilder();
                        for (int j = 0; j < number - 1; j++) {
                            line.append(words[begin + j]).append(" ".repeat(space + 1));
                            if (addition > 0) {
                                line.append(" ");
                                addition--;
                            }
                        }
                        line.append(words[begin + number - 1]);
                        res.add(line.toString());
                    }
                    begin = i;
                    width = 0;
                    number = 0;
                } else {
                    width = temp;
                    number++;
                    i++;
                }
            }

            StringBuilder line = new StringBuilder();
            for (int j = 0; j < number - 1; j++) {
                line.append(words[begin + j]).append(" ");
            }
            line.append(words[begin + number - 1]);
            width--;
            if (width < maxWidth) {
                line.append(" ".repeat(maxWidth - width));
            }

            res.add(line.toString());

            return res;

        }
    }
}

class P125 {
    class Solution {
        public boolean isPalindrome(String s) {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (Character.isAlphabetic(c) || Character.isDigit(c)) {
                    builder.append(Character.toLowerCase(c));
                }
            }
            String str = builder.toString();
            int lp = 0, rp = str.length() - 1;
            while (lp < rp) {
                if (str.charAt(lp) == str.charAt(rp)) {
                    lp++;
                    rp--;
                } else {
                    return false;
                }
            }
            return true;
        }
    }
}

class P392 {

    class Solution {
        public boolean isSubsequence(String s, String t) {
            int sp = 0, tp = 0;
            while (sp < s.length() && tp < t.length()) {
                if (s.charAt(sp) == t.charAt(tp)) {
                    sp++;
                }
                tp++;
            }
            return sp == s.length();
        }
    }

}

class P167 {
    class Solution {
        public int[] twoSum(int[] numbers, int target) {
            int lp = 0, rp = numbers.length - 1;
            while (lp < rp) {
                int tmp = numbers[lp] + numbers[rp];
                if (tmp > target) rp--;
                else if (tmp < target) lp++;
                else break;
            }
            return new int[]{lp + 1, rp + 1};
        }
    }
}

class P11 {
    class Solution {
        public int maxArea(int[] height) {
            int lp = 0, rp = height.length - 1;
            int res = 0;
            while (lp < rp) {
                if (height[lp] < height[rp]) {
                    int tmp = height[lp] * (rp - lp);
                    if (tmp > res) res = tmp;
                    lp++;
                } else if (height[lp] > height[rp]) {
                    int tmp = height[rp] * (rp - lp);
                    if (tmp > res) res = tmp;
                    rp--;
                } else {
                    int tmp = height[lp] * (rp - lp);
                    if (tmp > res) res = tmp;
                    if (height[lp + 1] >= height[rp - 1]) {
                        lp++;
                    } else {
                        rp--;
                    }
                }
            }
            return res;
        }
    }
}

class P15 {
    class Solution {
        /**
         * 可转化为两数之和
         */
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> res = new LinkedList<>();
            int[] array = Arrays.stream(nums).sorted().toArray();
            for (int i = 0; i < array.length; i++) {
                if (i > 0 && array[i] == array[i - 1]) continue;
                int target = -array[i];
                int lp = i + 1, rp = array.length - 1;
                while (lp < rp) {
                    int tmp = array[lp] + array[rp];
                    if (tmp > target) {
                        rp--;
                    } else if (tmp < target) {
                        lp++;
                    } else {
                        res.add(List.of(array[i], array[lp], array[rp]));
                        while (lp + 1 < rp && array[lp + 1] == array[lp]) lp++;
                        while (rp - 1 > lp && array[rp - 1] == array[rp]) rp--;
                        lp++;
                        rp--;
                    }
                }
            }
            return res;
        }
    }

}

class P3 {

    class Solution {
        public int lengthOfLongestSubstring(String s) {
            Set<Character> set = new HashSet<>();
            int res = 0;
            int lp = 0, rp = 0;
            while (rp < s.length()) {
                char c = s.charAt(rp);
                while (set.contains(c)) {
                    set.remove(s.charAt(lp++));
                }
                set.add(c);
                rp++;
                int len = rp - lp;
                if (len > res) res = len;
            }
            return res;
        }
    }
}

class P30 {
    class Solution {
        /**
         * 注意每个单词的长度相等，故我们可以先将原始字符串进行分割，将分割之后的每段与单词等长的子字符串
         * 当作一个整体，与单词列表中的单词进行匹配。
         */
        public List<Integer> findSubstring(String s, String[] words) {
            List<Integer> res = new ArrayList<Integer>();
            int m = words.length, n = words[0].length(), ls = s.length();
            for (int i = 0; i < n; i++) {
                if (i + m * n > ls) {
                    break;
                }
                Map<String, Integer> differ = new HashMap<String, Integer>();
                for (int j = 0; j < m; j++) {
                    String word = s.substring(i + j * n, i + (j + 1) * n);
                    differ.put(word, differ.getOrDefault(word, 0) + 1);
                }
                for (String word : words) {
                    differ.put(word, differ.getOrDefault(word, 0) - 1);
                    if (differ.get(word) == 0) {
                        differ.remove(word);
                    }
                }
                for (int start = i; start < ls - m * n + 1; start += n) {
                    if (start != i) {
                        String word = s.substring(start + (m - 1) * n, start + m * n);
                        differ.put(word, differ.getOrDefault(word, 0) + 1);
                        if (differ.get(word) == 0) {
                            differ.remove(word);
                        }
                        word = s.substring(start - n, start);
                        differ.put(word, differ.getOrDefault(word, 0) - 1);
                        if (differ.get(word) == 0) {
                            differ.remove(word);
                        }
                    }
                    if (differ.isEmpty()) {
                        res.add(start);
                    }
                }
            }
            return res;
        }
    }
}

class P76 {
    class Solution {
        public String minWindow(String s, String t) {
            Map<Character, Integer> mapT = new HashMap<>();
            for (int i = 0; i < t.length(); i++) {
                mapT.put(t.charAt(i), mapT.getOrDefault(t.charAt(i), 0) + 1);
            }
            Map<Character, Integer> mapS = new HashMap<>();
            int lp = 0, rp = 0;
            while (rp < s.length()) {

                rp++;
            }
            return s.substring(lp, rp);
        }
    }
}