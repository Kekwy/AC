package com.kekwy.leetcode;

import com.kekwy.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import java.util.*;

class P2864 {

    class Solution {
        public String maximumOddBinaryNumber(String s) {
            int count = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '1') count++;
            }
            return "1".repeat(count - 1) +
                    "0".repeat(s.length() - count) +
                    "1";
        }
    }

}

class P228 {

    class Solution {
        public List<String> summaryRanges(int[] nums) {
            int lp = 0, rp = 0;
            List<String> res = new ArrayList<>();
            if (nums.length == 0) return res;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] != nums[i - 1] + 1) {
                    if (lp == rp) {
                        res.add(String.valueOf(nums[lp]));
                    } else {
                        res.add(nums[lp] + "->" + nums[rp]);
                    }
                    lp = i;
                }
                rp = i;
            }
            if (lp == rp) {
                res.add(String.valueOf(nums[lp]));
            } else {
                res.add(nums[lp] + "->" + nums[rp]);
            }
            return res;
        }
    }

}

class P56 {
    class Solution {
        public int[][] merge(int[][] intervals) {
            Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
            List<int[]> res = new LinkedList<>();
            int begin = intervals[0][0], end = intervals[0][1];
            for (int i = 1; i < intervals.length; i++) {
                if (intervals[i][0] <= end) {
                    end = Math.max(end, intervals[i][1]);
                } else {
                    res.add(new int[]{begin, end});
                    begin = intervals[i][0];
                    end = intervals[i][1];
                }
            }
            res.add(new int[]{begin, end});
            return res.toArray(new int[0][]);
        }
    }
}

class P57 {
    class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            List<int[]> res = new ArrayList<>();
            boolean flag = false;
            int lBound = newInterval[0], rBound = newInterval[1];
            for (int[] interval : intervals) {
                if (flag) {
                    res.add(interval);
                } else {
                    if (rBound < interval[0]) {
                        res.add(new int[]{lBound, rBound});
                        res.add(interval);
                        flag = true;
                    } else if (lBound > interval[1]) {
                        res.add(interval);
                    } else {
                        lBound = Math.min(lBound, interval[0]);
                        rBound = Math.max(rBound, interval[1]);
                    }
                }
            }
            if (!flag) {
                res.add(new int[]{lBound, rBound});
            }
            return res.toArray(new int[0][]);
        }
    }
}

class P452 {
    class Solution {
        public int findMinArrowShots(int[][] points) {
            Arrays.sort(points, Comparator.comparingInt(a -> a[0]));
            int res = 1;
            int rBound = points[0][1];
            for (int i = 1; i < points.length; i++) {
                if (points[i][0] <= rBound) {
                    rBound = Math.min(rBound, points[i][1]);
                } else {
                    res++;
                    rBound = points[i][1];
                }
            }
            return res;
        }
    }
}

class P71 {
    class Solution {
        public String simplifyPath(String path) {
            String[] strings = path.split("/");
            Deque<String> deque = new LinkedList<>();
            for (String string : strings) {
                if (Objects.equals(string, "") || Objects.equals(string, ".")) continue;
                if (Objects.equals(string, "..")) {
                    if (!deque.isEmpty()) {
                        deque.pollLast();
                    }
                } else {
                    deque.offerLast(string);
                }
            }
            StringBuilder builder = new StringBuilder();
            while (!deque.isEmpty()) {
                builder.append("/").append(deque.pollFirst());
            }
            if (builder.isEmpty()) {
                builder.append("/");
            }
            return builder.toString();
        }
    }

    @Test
    public void test() {
        String[] split = "////".split("/");
        System.out.println(Arrays.toString(split));
    }

}

/**
 * 复习中缀转后缀、逆波兰表达式
 */
class P224 {
    class Solution {

        public int calculate(String s) {
            Stack<Character> opStack = new Stack<>();
            Stack<Integer> numStack = new Stack<>();
//            String
            for (int i = 0; i < s.length(); i++) {

            }
            return 0;
        }
    }
}

class P141 {

    public class Solution {
        public boolean hasCycle(ListNode head) {
            if (head == null || head.next == null) return false;
            ListNode node1 = head, node2 = head.next.next;
            while (node2 != null && node2.next != null) {
                if (node1 == node2) return true;
                node1 = node1.next;
                node2 = node2.next.next;
            }
            return false;
        }
    }

}

class P21 {
    class Solution {
        public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
            ListNode p1 = list1;
            ListNode p2 = list2;
            ListNode dummyHead = new ListNode();
            ListNode res = dummyHead;
            while (p1 != null && p2 != null) {
                if (p1.val < p2.val) {
                    res.next = p1;
                    p1 = p1.next;
                } else {
                    res.next = p2;
                    p2 = p2.next;
                }
                res = res.next;
            }
            for (; p1 != null; p1 = p1.next) {
                res.next = p1;
                res = res.next;
            }
            for (; p2 != null; p2 = p2.next) {
                res.next = p2;
                res = res.next;
            }
            return dummyHead.next;
        }
    }
}

class P138 {

    class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }

    class Solution {

        public Node copyRandomList(Node head) {
            Node dummyHead = new Node(0);
            Map<Node, Node> map = new HashMap<>();
            Node p = dummyHead;
            for (Node node = head; node != null; node = node.next) {
                Node curNode, randomNode;
                if (map.containsKey(node)) {
                    curNode = map.get(node);
                } else {
                    curNode = new Node(node.val);
                    map.put(node, curNode);
                }
                p.next = curNode;
                if (node.random != null) {
                    if (map.containsKey(node.random)) {
                        randomNode = map.get(node.random);
                    } else {
                        randomNode = new Node(node.random.val);
                        map.put(node.random, randomNode);
                    }
                    p.next.random = randomNode;
                }
                p = p.next;
            }
            return dummyHead.next;
        }
    }
}

class P92 {

    class Solution {
        public ListNode reverseBetween(ListNode head, int left, int right) {
            ListNode dummyHead = new ListNode(0);
            dummyHead.next = head;
            ListNode leftNode = head;
            ListNode subListHead = dummyHead;
            for (int i = 1; i < left; i++) {
                subListHead = leftNode;
                leftNode = leftNode.next;
            }
            ListNode rightNode = leftNode;
            ListNode nextNode = leftNode.next;
            for (int i = left + 1; i <= right; i++) {
                ListNode next = nextNode.next;
                nextNode.next = rightNode;
                rightNode = nextNode;
                nextNode = next;
            }
            subListHead.next = rightNode;
            leftNode.next = nextNode;
            return dummyHead.next;
        }
    }

}

class P25 {

    class Solution {
        public ListNode reverseKGroup(ListNode head, int k) {
            ListNode dummyHead = new ListNode();
            dummyHead.next = head;
            ListNode p = head;
            ListNode q = null;
            ListNode groupPrev = dummyHead;
            ListNode groupTail = head;
            int i = 0;

            return dummyHead.next;
        }
    }

}