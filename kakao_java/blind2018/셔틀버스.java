package blind2018;

import java.util.*;

public class 셔틀버스 {
    private static final int START_TIME = 540;

    public String solution(int n, int t, int m, String[] timetable) {
        List<Integer> timeTables = new ArrayList<>();
        timeTables.add(-1);
        for (int i = 0; i < n; i++) {
            timeTables.add(START_TIME + t * i);
        }

        Station station = new Station(timeTables);

        List<Integer> waiting = new ArrayList<>();
        for (String arrival : timetable) {
            int time = toMinute(arrival);
            waiting.add(time);
        }

        Collections.sort(waiting);
        station.waitAll(waiting, m);

        int answer = station.find(m);

        return minuteToString(answer);
    }

    private int toMinute(String time) {
        StringTokenizer st = new StringTokenizer(time, ":");
        int hour = Integer.parseInt(st.nextToken());
        return hour * 60 + Integer.parseInt(st.nextToken());
    }

    private String minuteToString(int time) {
        int hour = time / 60;
        int minute = time % 60;

        String result = "";
        if (hour == 0) {
            result += "00";
        } else if (hour < 10) {
            result += "0";
            result += String.valueOf(hour);
        } else {
            result += String.valueOf(hour);
        }
        result += ":";

        if (minute == 0) {
            result += "00";
        } else if (minute < 10) {
            result += "0";
            result += String.valueOf(minute);
        } else {
            result += String.valueOf(minute);
        }

        return result;
    }

    static class Station {
        List<Integer> timeTables;
        Map<Integer, List<Integer>> waiting;

        public Station(List<Integer> timeTables) {
            this.timeTables = timeTables;
            this.waiting = new HashMap<>();
        }

        public void waitAll(List<Integer> waiting, int seat) {
            for (int i = 1; i < timeTables.size(); i++) {
                int prevTime = timeTables.get(i - 1);
                int arrivalTime = timeTables.get(i);

                List<Integer> waitingList = new ArrayList<>();
                List<Integer> prevWaitingList = this.waiting.getOrDefault(prevTime, new ArrayList<>());
                if (prevWaitingList.size() > seat) {
                    int remain = prevWaitingList.size() - seat;
                    int lastIndex = prevWaitingList.size() - 1;
                    while (remain-- > 0) {
                        waitingList.add(prevWaitingList.get(lastIndex--));
                    }
                }

                for (int krew : waiting) {
                    if (prevTime < krew && krew <= arrivalTime) {
                        waitingList.add(krew);
                    } else if (krew > arrivalTime) {
                        break;
                    }
                }

                Collections.sort(waitingList);
                this.waiting.put(arrivalTime, waitingList);
            }
        }

        public int find(int seat) {
            int arrivalTime = timeTables.get(timeTables.size() - 1);
            List<Integer> waitingNum = waiting.get(arrivalTime);

            if (waitingNum.size() + 1 <= seat) {
                return arrivalTime;
            }

            int time = waitingNum.get(seat - 1);
            return time - 1;
        }

    }
}
