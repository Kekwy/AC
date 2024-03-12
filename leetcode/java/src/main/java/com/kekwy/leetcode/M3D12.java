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
            while(p < pattern.length() - 1) {
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
                if (temp - 1> maxWidth) {
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