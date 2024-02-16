package com.kekwy.kama;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class P54 {



    public static void main(String[] args) {
        StringBuilder builder = new StringBuilder();
        Set<Character> numSet = new HashSet<>();
        numSet.add('0');
        numSet.add('1');
        numSet.add('2');
        numSet.add('3');
        numSet.add('4');
        numSet.add('5');
        numSet.add('6');
        numSet.add('7');
        numSet.add('8');
        numSet.add('9');
        String s = new Scanner(System.in).next();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (numSet.contains(c)) {
                builder.append("number");
            } else {
                builder.append(c);
            }
        }
        System.out.println(builder);
    }

}
