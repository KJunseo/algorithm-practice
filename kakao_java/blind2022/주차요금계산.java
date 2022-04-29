package blind2022;

import java.util.*;

public class 주차요금계산 {
    private Map<String, Car> parkingLot;
    private Map<String, Car> result;

    private StringTokenizer st;

    public int[] solution(int[] fees, String[] records) {
        this.parkingLot = new HashMap<>();
        this.result = new HashMap<>();

        for (String record : records) {
            st = new StringTokenizer(record);
            int t = toMinute(st.nextToken());
            String num = st.nextToken();
            String option = st.nextToken();

            if ("IN".equals(option)) {
                Car car = new Car(num, t);
                parkingLot.put(num, car);
            } else if ("OUT".equals(option)) {
                Car car = parkingLot.remove(num);
                int time = t - car.time;

                if (result.containsKey(num)) {
                    time += result.get(num).accumulateTime;
                }
                car.addAccumulateTime(time);
                result.put(num, car);
            }
        }

        for (Map.Entry<String, Car> entry : parkingLot.entrySet()) {
            Car car = entry.getValue();
            int time = toMinute("23:59") - car.time;

            if (result.containsKey(entry.getKey())) {
                time += result.get(entry.getKey()).accumulateTime;
            }
            car.addAccumulateTime(time);
            result.put(entry.getKey(), car);
        }

        int baseTime = fees[0];
        int baseFee = fees[1];
        int unitTime = fees[2];
        int unitFee = fees[3];
        for (Map.Entry<String, Car> entry : result.entrySet()) {
            Car car = entry.getValue();
            car.calculateFee(baseTime, baseFee, unitTime, unitFee);
        }

        List<Car> cars = new ArrayList<>(result.values());
        Collections.sort(cars);

        int[] answer = new int[cars.size()];
        for (int i = 0; i < cars.size(); i++) {
            answer[i] = cars.get(i).fee;
        }

        return answer;
    }

    private int toMinute(String t) {
        String[] split = t.split(":");
        int h = Integer.parseInt(split[0]);
        int m = Integer.parseInt(split[1]);
        return h * 60 + m;
    }

    static class Car implements Comparable<Car> {
        String num;
        int time;
        int accumulateTime;
        int fee;

        public Car(String num, int time) {
            this.num = num;
            this.time = time;
        }

        public void addAccumulateTime(int time) {
            this.accumulateTime += time;
        }

        public void calculateFee(int baseTime, int baseFee, int unitTime, int unitFee) {
            if (accumulateTime <= baseTime) {
                this.fee = baseFee;
            } else {
                this.fee = baseFee + calculateExcessFee(this.accumulateTime - baseTime, unitTime, unitFee);
            }
        }

        private int calculateExcessFee(int excessTime, int unitTime, int unitFee) {
            int t = (int) Math.ceil((double) excessTime / unitTime);
            return t * unitFee;
        }

        @Override
        public int compareTo(Car o) {
            return this.num.compareTo(o.num);
        }
    }
}
