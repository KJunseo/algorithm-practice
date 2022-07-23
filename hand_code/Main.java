import java.util.Arrays;
import java.util.List;

import sorting.*;
import stackqueue.Palindrome;
import stackqueue.QueueUsingTwoStack;
import stackqueue.StackUsingTwoQueue;
import string.*;
import sum.SumThreeFive;
import sum.TwoSum;

public class Main {

    public static void main(String[] args) {
        twoSum();
    }

    private static void twoSum() {
        TwoSum sum = new TwoSum();
        int[] nums = {3, 3};
        int target = 6;
        System.out.println(Arrays.toString(sum.twoSum(nums, target)));
    }

    private static void phone() {
        Phone phone = new Phone();
        List<String> result = phone.solution(15231);
        result.forEach(System.out::println);
    }

    private static void longestStringRemoveChar() {
        String base = "adppsled";
        String[] candidates = {"pled", "apple", "monkey", "ap"};
        LongestStringRemoveChar longestString = new LongestStringRemoveChar();
        System.out.println(longestString.solutionVer1(base, candidates));
        System.out.println(longestString.solutionVer2(base, candidates));
    }

    private static void compression() {
        Compression compression = new Compression();
        System.out.println(compression.compress(new char[]{'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'})); // a3b3c3
        System.out.println(compression.compress(new char[]{'a', 'a', 'b', 'b', 'a', 'c', 'b', 'c', 'c', 'c'})); // a3b3c4
        System.out.println(compression.compressConsecutiveRepeatChar(new char[]{'a', 'a', 'a', 'b', 'b', 'a', 'a', 'a'})); // a3b2a3
    }

    private static void anagram() {
        Anagram anagram = new Anagram();
        System.out.println(anagram.isAnagram("arc", "car")); // true
        System.out.println(anagram.isAnagram("caaabbb", "abababc")); // true
        System.out.println(anagram.isAnagram("caabbbb", "abababc")); // false
        System.out.println(anagram.isAnagram("arc", "carr")); // false
        System.out.println(anagram.isAnagram("arc", "caz")); // false
    }

    private static void stringToInt() {
        String num = "133345";
        System.out.println(new StringToInt().stringToInt(num));
    }

    private static void findKthLargest() {
        int[] nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        FindKthLargest findKthLargest = new FindKthLargest();
        System.out.println(findKthLargest.findKthLargest(nums, k));
        System.out.println(findKthLargest.findKthLargestQuickSelect(nums, k));
    }

    private static void reverseString() {
        String string = "Hello World";
        ReverseString reverseString = new ReverseString();
        System.out.println(reverseString.reverse(string));
        System.out.println(reverseString.reverseUsingStack(string));
        System.out.println(reverseString.reverseUsingArray(string));
    }

    private static void duplicateArray() {
        int[] array = {1, 1, 2, 3, 4, 5, 6, 7};
        System.out.println(new DuplicateArray().isDuplicated(array));
    }

    private static void sumThreeFive() {
        System.out.println(new SumThreeFive().sum());
    }

    private static void kFirstSort() {
        int[] array = {3, 4, 1, 9, 6, 2};
        int k = 3;
        System.out.println(Arrays.toString(new KFirstSort().KFirstSort(array, k))); // 9 1 2 3 4 6
    }

    private static void gcdLcm() {
        System.out.println(Arrays.toString(new GcdLcm().solution(3, 12)));
    }

    private static void hanoi() {
        new Hanoi().hanoi(2, 1, 2, 3);
    }

    private static void factorial() {
        Factorial factorial = new Factorial();
        int n = 12;
        System.out.println(factorial.factorialLoop(n));
        System.out.println(factorial.factorialRecursive(n));
        System.out.println(factorial.factorial(100));
    }

    private static void fibonacci() {
        Fibonacci fibonacci = new Fibonacci();
        int n = 10;
        System.out.println(fibonacci.fiboLoop(n));
        System.out.println(fibonacci.fiboRecursive(n));
        System.out.println(fibonacci.fiboDp(n));
    }

    private static void stackUsingTwoQueue() {
        StackUsingTwoQueue<Integer> stack = new StackUsingTwoQueue<>();
        stack.add(1);
        stack.add(2);
        stack.add(3);
        System.out.println(stack.pop()); // 3
        System.out.println(stack.pop()); // 2
        System.out.println(stack.pop()); // 1
    }

    private static void queueUsingTwoStack() {
        QueueUsingTwoStack<Integer> queue = new QueueUsingTwoStack<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        System.out.println(queue.poll()); // 1
        System.out.println(queue.poll()); // 2
        System.out.println(queue.poll()); // 3
    }

    private static void stackSort() {
        int[] array = {3, 7, 1, 5, 3};
        System.out.println(Arrays.toString(new StackSort().sort2(array)));
    }

    private static void palindrome() {
        int n = 1123543211;
        System.out.println(new Palindrome().palindrome(n));
    }

    private static void bubbleSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new BubbleSort().bubbleSort(array)));
    }

    private static void insertionSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new InsertionSort().insertionSort(array)));
    }

    private static void selectionSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        System.out.println(Arrays.toString(new SelectionSort().selectionSort(array)));
    }

    private static void quickSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        new QuickSort().quickSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }

    private static void mergeSort() {
        int[] array = {1, 4, 2, 9, 9, 17, 30, 5, 6, 19};
        new MergeSort().mergeSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
    }
}
