public class Hanoi {

    public void hanoi(int n, int from, int mid, int to) {
        if (n == 1) {
            System.out.println(from + " -> " + to);
            return;
        }
        hanoi(n - 1, from, to, mid);
        System.out.println(from + " -> " + to);
        hanoi(n - 1, mid, from, to);
    }
}
