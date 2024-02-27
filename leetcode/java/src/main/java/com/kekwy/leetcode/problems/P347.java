package com.kekwy.leetcode.problems;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class P347 {

    class Element {
        public int value;
        public int count;

        public Element(int value, int count) {
            this.value = value;
            this.count = count;
        }
    }

    class Heap implements Iterable<Element> {

        private final Element[] data;

        private int size;

        public Heap(int maxSize) {
            size = 1;
            data = new Element[maxSize + 1];
        }

        public void add(Element element) {
            if (size < data.length) {
                data[size++] = element;
                adjustUp();
            } else if (element.count > data[1].count) {
                data[1] = element;
                adjustDown(); // bugfix
            }
        }

        private void adjustDown() {
            int i = 1;
            Element element = data[i];
            while (i <= (size - 1) / 2) {
                int left = i * 2;
                int right = i * 2 + 1;
                int min;
                if (right < size && data[right].count < data[left].count) {
                    min = right;
                } else {
                    min = left;
                }
                if (element.count > data[min].count) { // bugfix: if (data[i].count > data[min].count) {
                    data[i] = data[min];
                    i = min;
                } else {
                    break; // bugfix
                }
            }
            data[i] = element;
        }

        private void adjustUp() {
            int i = size - 1;
            Element element = data[size - 1];
            while (i > 1) {
                int parent = i / 2;
                if (element.count < data[parent].count) {
                    data[i] = data[parent];
                    i = parent;
                } else {
                    break;
                }
            }
            data[i] = element;
        }

        @Override
        public Iterator<Element> iterator() {
            Iterator<Element> iterator = Arrays.stream(data).iterator(); // bugfix
            iterator.next();
            return iterator;
        }
    }

    class Solution {

        public int[] topKFrequent(int[] nums, int k) {
            Map<Integer, Integer> countMap = new HashMap<>();
            for (int num : nums) {
                Integer count = countMap.getOrDefault(num, 0) + 1;
                countMap.put(num, count);
            }
            Heap heap = new Heap(k);
            for (Integer value : countMap.keySet()) {
                heap.add(new Element(value, countMap.get(value)));
            }
            int[] res = new int[k];
            int i = 0;
            for (Element element : heap) {
                res[i++] = element.value;
            }
            return res;
        }
    }

    @Test
    public void test() {
        Solution solution = new Solution();
        solution.topKFrequent(new int[]{4,1,-1,2,-1,2,3}, 2);
    }

}
