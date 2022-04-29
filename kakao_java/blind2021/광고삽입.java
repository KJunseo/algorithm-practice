package blind2021;

public class 광고삽입 {

    public String solution(String play_time, String adv_time, String[] logs) {
        int pt = toSec(play_time);
        int at = toSec(adv_time);

        long[] psum = new long[pt + 1];
        for (String log : logs) {
            String[] split = log.split("-");
            psum[toSec(split[0])]++;
            psum[toSec(split[1])]--;
        }

        for (int i = 1; i <= pt; i++) { // 현재 시간에 영상을 시청하는 사람 수
            psum[i] += psum[i - 1];
        }

        // 방법1: 누적합 + 슬라이딩 윈도우
        int startTime = 0;
        long time = psum[at - 1];
        long max = time;

        for (int i = at; i < pt; i++) {
            time += psum[i];
            time -= psum[i - at];

            if (time > max) {
                max = time;
                startTime = i - at + 1;
            }
        }

        // 방법2: 누적합 + 누적합
        //        for (int i = 1; i <= pt; i++) { // 현재 시간까지 영상을 시청한 사람 누적 수
        //            psum[i] += psum[i - 1];
        //        }
        //
        //        long time = psum[at - 1];
        //        int startTime = 0;
        //        for (int i = 0; i + at <= pt; i++) {
        //            long temp = psum[i + at] - psum[i];
        //
        //            if (temp > time) {
        //                time = temp;
        //                startTime = i + 1;
        //            }
        //        }

        return secToString(startTime);
    }

    private String secToString(int time) {
        int h = time / (60 * 60);
        time %= (60 * 60);
        int m = time / 60;
        time %= 60;

        String temp = "";
        String hStr = String.valueOf(h);
        if (hStr.length() == 1) {
            temp += "0";
        }
        temp += hStr;
        temp += ":";

        String mStr = String.valueOf(m);
        if (mStr.length() == 1) {
            temp += "0";
        }
        temp += mStr;
        temp += ":";

        String sStr = String.valueOf(time);
        if (sStr.length() == 1) {
            temp += "0";
        }
        temp += sStr;

        return temp;
    }

    private int toSec(String time) {
        String[] split = time.split(":");
        int h = Integer.parseInt(split[0]);
        int m = Integer.parseInt(split[1]);
        int s = Integer.parseInt(split[2]);
        return h * 60 * 60 + m * 60 + s;
    }
}
