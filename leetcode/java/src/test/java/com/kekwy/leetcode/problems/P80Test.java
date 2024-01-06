package com.kekwy.leetcode.problems;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * description
 *
 * @author Kekwy
 * @version 1.0
 * @since 2024/1/5 21:32
 */
public class P80Test {

    @Test
    public void testSolution() {
        P80 p80 = new P80();
        P80.Solution solution = p80.getSolution();
        solution.removeDuplicates(new int[]{1, 1, 1, 2, 2, 3});
    }

}