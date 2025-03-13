class Underground {
    private String id = "";
    private int line = 1;
    private int nextStation = 0;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getLine() {
        return line;
    }

    public void setLine(int line) {
        this.line = line;
    }

    public int getNextStation() {
        return nextStation;
    }

    public void setNextStation(int nextStation) {
        this.nextStation = nextStation;
    }

    public int updateNextStation() {
        this.setNextStation((this.nextStation + 1) % 10);
        return this.nextStation;
    }

}

public class MyTestUnderground {
    public static void main(String[] args) {
        Underground t1 = new Underground();
        Underground t2 = new Underground();

        t1.setId("aaa");
        t1.setLine(1);
        t1.setNextStation(8);

        t2.setId("bbb");
        t2.setLine(1);
        t2.setNextStation(5);

        for (int ix = 0; ix < 2; ix++) {
            int t1PrxSt = t1.updateNextStation();
            System.out.println("t1: " + t1PrxSt);

            int t2PrxSt = t2.updateNextStation();
            System.out.println("t2: " + t2PrxSt);
        }
    }
}