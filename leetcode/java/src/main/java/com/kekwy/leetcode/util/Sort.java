package com.kekwy.leetcode.util;

import java.util.Comparator;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/6 12:05
 */
public class Sort {

    private record QuickSort<U>(U[] array, Comparator<U> comparator) {

        public static <T> void sort(T[] array, Comparator<T> comparator) {
            new QuickSort<>(array, comparator).helper(0, array.length);
        }

        private void helper(int begin, int end) {
            if (begin >= end) return;
            U temp = array[begin];
            int lp = begin, rp = end - 1;
            while (lp < rp) {
                for (; lp < rp; rp--) {
                    if (comparator.compare(array[rp], temp) < 0) {
                        array[lp] = array[rp];
                        break;
                    }
                }
                for (; lp < rp; lp++) {
                    if (comparator.compare(array[lp], temp) > 0) {
                        array[rp] = array[lp];
                        break;
                    }
                }
            }
            array[lp] = temp;
            helper(begin, lp);
            helper(lp + 1, end);
        }

    }

    public static <T> void quickSort(T[] array, Comparator<T> comparator) {
        QuickSort.sort(array, comparator);
    }

}
