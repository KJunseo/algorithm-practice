package 기초.bruteforce;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class SevenDwarf {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> dwarf = new ArrayList<>(10);
        int total = 0;
        for (int i = 0; i < 9; i++) {
            int tall = Integer.parseInt(br.readLine());
            dwarf.add(tall);
            total += tall;
        }

        Collections.sort(dwarf);

        int remain = total - 100;

        boolean flag = true;
        int i = 0;
        int j = 0;
        for (i = 0; i < 9; i++) {
            for (j = i + 1; j < 9; j++) {
                if ((dwarf.get(i) + dwarf.get(j)) == remain) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }

        for (int k = 0; k < 9; k++) {
            if (k == i) {
                continue;
            }
            if (k == j) {
                continue;
            }
            bw.write(dwarf.get(k) + "\n");
        }
        bw.flush();
    }
}
