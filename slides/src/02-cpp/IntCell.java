// File IntCell.java

public class IntCell {
    public IntCell() {
        this(0);
    }

    public IntCell(int initialValue) {
        storedValue = initialValue;
    }

    public int getValue() {
        return storedValue;
    }

    public void setValue(int val) {
        storedValue = val;
    }

    private int storedValue;

    public static void main( String [] args ) {
        IntCell m1 = new IntCell();
        IntCell m2 = new IntCell(37);
        System.out.println(m1.getValue( ) + " " + m2.getValue( ) );
    }

}
