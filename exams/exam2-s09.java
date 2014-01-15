public class Exam2 {
    public static void main (String[] args) {
        int tableSize = 9;
        System.out.println ("Table size: " + tableSize);
        System.out.println ("Briana: " + "Briana".hashCode() % tableSize);
        System.out.println ("Dan: " + "Dan".hashCode() % tableSize);
        System.out.println ("Jeff: " + "Jeff".hashCode() % tableSize);
        System.out.println ("John: " + "John".hashCode() % tableSize);
        System.out.println ("Josh: " + "Josh".hashCode() % tableSize);
        System.out.println ("Randolph: " + "Randolph".hashCode() % tableSize);
        System.out.println ("Wil: " + "Wil".hashCode() % tableSize);
    }
}
