// DataStructuresComparison.java
//
// This program will test the relative speeds of the various
// Collection data structres in the Java 1.5 SDK
//
// Copyright (c) 2007 by Aaron Bloomfield.

import java.util.*;
import java.text.*;

public class DataStructuresComparison {

    public static void main (String args[]) {

        // various counters and such
        final int inserts  = 50000;
        final int searches = 25000;
        final int deletes  = 10000;
        Integer x;
        long insertTime, searchTime, deleteTime, startTime, endTime;
        Collection collection = null;

        // allow for nice printing of the times
        NumberFormat style = NumberFormat.getNumberInstance();
        style.setMaximumFractionDigits(3);
        style.setMinimumFractionDigits(3);

        // print out how many of each operation will be performed
        System.out.println ("Operations performed:");
        System.out.println ("\t" + inserts + "\tinsertions");
        System.out.println ("\t" + searches + "\tsearches");
        System.out.println ("\t" + deletes + "\tdeletions");

        // create the data structure to be time tested
        for ( int j = 0; j >= 0; j++ ) {
            collection = null;
            switch (j) {
                case 0:
                    collection = new Vector();
                    System.out.print ("Vector: ");
                    break;
                case 1:
                    collection = new ArrayList();
                    System.out.print ("ArrayList: ");
                    break;
                case 2:
                    collection = new LinkedList();
                    System.out.print ("LinkedList: ");
                    break;
                case 3:
                    collection = new HashSet();
                    System.out.print ("HashSet: ");
                    break;
                case 4:
                    collection = new TreeSet();
                    System.out.print ("TreeSet: ");
                    break;
            }

            // If no more data structures to try, end the for loop
            if ( collection == null )
                break;

            // insert even numbers from 0 to inserts
            startTime = System.currentTimeMillis();
            for ( int i = 0; i < inserts; i++ ) {
                x = new Integer(i*2);
                collection.add(x);
            }
            endTime = System.currentTimeMillis();
            insertTime = endTime-startTime;

            // search for even and odd numbers from 0 to searches
            startTime = System.currentTimeMillis();
            for ( int i = 0; i < searches; i++ ) {
                x = new Integer(i);
                if ( collection.contains(x) ) { }
            }
            endTime = System.currentTimeMillis();
            searchTime = endTime-startTime;

            // delete even and odd numbers from 0 to deletes
            startTime = System.currentTimeMillis();
            for ( int i = 0; i < deletes; i++ ) {
                x = new Integer(i);
                collection.remove(x);
            }
            endTime = System.currentTimeMillis();
            deleteTime = endTime-startTime;

            // record the finish time, compute time taken, print it out
            double timeInSec = (insertTime+searchTime+deleteTime)/1000.0;
            System.out.println ("\ttook " + (searchTime+insertTime+deleteTime) +
                                " ms\t" + style.format(timeInSec) + " sec (insert: " +
                                insertTime + " ms, search: " + searchTime +
                                " ms, delete: " + deleteTime + " ms)");
        }


        // Now try doing the same thing on a Vector, but sort the stuff first
        Vector vector = new Vector();
        System.out.print ("\nVector, sorted:");

        // insert even numbers from 0 to inserts
        startTime = System.currentTimeMillis();
        for ( int i = 0; i < inserts; i++ ) {
            x = new Integer(i*2);
            vector.add(x);
        }
        Collections.sort(vector);
        endTime = System.currentTimeMillis();
        insertTime = endTime-startTime;

        // search for even and odd numbers from 0 to searches
        startTime = System.currentTimeMillis();
        for ( int i = 0; i < searches; i++ ) {
            x = new Integer(i);
            if ( Collections.binarySearch(vector,x) >= 0 ) { }
        }
        endTime = System.currentTimeMillis();
        searchTime = endTime-startTime;

        // delete even and odd numbers from 0 to deletes
        int index;
        startTime = System.currentTimeMillis();
        for ( int i = 0; i < deletes; i++ ) {
            x = new Integer(i);
            index = Collections.binarySearch(vector,x);
            if ( index >= 0 )
                vector.remove(index);
        }
        endTime = System.currentTimeMillis();
        deleteTime = endTime-startTime;

        // record the finish time, compute time taken, print it out
        double timeInSec = (insertTime+searchTime+deleteTime)/1000.0;
        System.out.println ("\ttook " + (searchTime+insertTime+deleteTime) +
                            " ms\t" + style.format(timeInSec) + " sec (insert: " +
                            insertTime + " ms, search: " + searchTime +
                            " ms, delete: " + deleteTime + " ms)");
        System.exit(0);
    }
}

/** Execution run used in the lectures:

Operations performed:
        50000   insertions
        25000   searches
        10000   deletions
Vector:         took 17311 ms   17.311 sec (insert: 30 ms, search: 12620 ms, delete: 4661 ms)
ArrayList:      took 17281 ms   17.281 sec (insert: 28 ms, search: 12609 ms, delete: 4644 ms)
LinkedList:     took 24255 ms   24.255 sec (insert: 54 ms, search: 17934 ms, delete: 6267 ms)
HashSet:        took 122 ms     0.122 sec (insert: 103 ms, search: 9 ms, delete: 10 ms)
TreeSet:        took 119 ms     0.119 sec (insert: 93 ms, search: 14 ms, delete: 12 ms)

Vector, sorted: took 294 ms     0.294 sec (insert: 36 ms, search: 19 ms, delete: 239 ms)
*/