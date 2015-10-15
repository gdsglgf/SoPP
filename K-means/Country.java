public class Country {
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setData(String[] dataString) {
        this.data = new int[dataString.length];
        for (int i = 0; i < dataString.length; i++) {
            data[i] = Integer.parseInt(dataString[i]);
        }
    }

    public int getData(int i) {
        return data[i];
    }

    public int getDataLength() {
        return data.length;
    }

    public String toString() {
        return String.format("%s,%s", name, Arrays.toString(data));
    }

    private String name;
    private int[] data;
}