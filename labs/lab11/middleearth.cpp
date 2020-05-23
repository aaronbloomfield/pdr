#include "middleearth.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <cmath>

// New shuffle method that uses the Mersenne Twister engine
void shuffle (vector<string>::iterator first, vector<string>::iterator last, mt19937& g) {
    for (auto i=(last-first)-1; i>0; --i) {
        unsigned int n = (g() / (double) g.max())*distance(first,last);
        swap (first[i], first[n]);
    }
}

// The list of all the place names that we'll be using
const array<string, 40> all_city_names{
    // human towns, cities and strongholds
    "Bree",             // a human and hobbit town between the Shire and Rivendell
    "Isengard",         // the tower fortress where Saruman resided; Gandalf was imprisoned there.
    "Minas Tirith",     // capital of Gondor, the "white city"; home to Boromir, Denethor, and later, Aragorn
    "Osgiliath",        // city on the river Anduin; is at the other end of Pelennor Fields from M. Tirith
    "Edoras",           // the capital city of Rohan, where King Theoden resides
    "Helm's Deep",      // fortress of Rohan, it is where the people of Edoras fled to from the orc invasion
    "Dunharrow",        // a refuge of Rohan, it is where Elrond presents the sword to Aragorn in the movie
    // dwarf cities
    "Moria",            // the enormous dwarven underground complex that the Fellowship traveled through
    // elvish cities
    "Lothlorien",       // the elvish tree-city, home of Lady Galadriel and Lord Celeborn
    "Rivendell",        // the elvish city that is home to Lord Elrond
    "The Grey Havens",  // the port city on the western coast from which the elves travel westward
    // hobbit villages
    "Bucklebury",       // a Shire village, it has a ferry across the Brandywine River that the Hobbits use
    "Bywater",          // a Shire village, it is the site of the Battle of Bywater (removed from the movie)
    "Hobbiton",         // a Shire village, it is home to Bilbo and, later, Frodo
    "Michel Delving",   // a Shire village, it is the chief town of the Shire
    // Mordor places
    "Orodruin",         // Mount Doom in Mordor, it is where the Ring was made, and later, unmade
    "Barad-Dur",        // Sauron's fortress that was part castle, part mountain
    "Minas Morgul",     // formerly the Gondorian city of Minas Ithil; renamed when Sauron took it over
    "Cirith Ungol",     // the mountianous pass that Sam & Frodo went through; home of Shelob
    "Gorgoroth",        // the plains in Mordor that Frodo & Sam had to cross to reach Mount Doom
    // places that are not cities
    "Emyn Muil",        // the rocky region that Sam & Frodo climb through after leaving the Fellowship
    "Fangorn Forest",   // the forest where Treebeard (and the other Ents) live
    "Dagorlad",         // great plain/swamp between Emyn Muil & Mordor where a great battle was fought long ago
    "Weathertop",       // the tower between Bree and Rivendell where Aragorn and the Hobbits take refuge
    "Gladden Fields",   // this is where the Ring is lost in the River Anduin, after Isildur is ambushed and killed by Orcs
    "Entwash River",    // a river through Rohan, which flows through Fangorn Forest
    "River Isen",       // river through the Gap of Rohan; Theoden's son was slain in a battle here.
    "The Black Gate",   // huge gate to Mordor that Aragorn and company attack as the ring is destroyed
    "The Old Forest",   // a forest to the west of the Shire (adventures there were removed from the movie)
    "Trollshaws",       // area to the west of Rivendell that was home to the trolls that Bilbo met
    "Pelennor Fields",  // great plain between M. Tirith and Osgiliath; site of the Battle of M. Tirith
    "Hollin",           // the empty plains that the Fellowship crosses between Rivendell and Moria
    "Mirkwood",         // Legolas' forest home; Bilbo travels there in 'The Hobbit'.
    "Misty Mountains",  // the north-south moutain range that runs through Middle-earth
    "Prancing Pony",    // an inn in Bree where the hobbits tried to meet Gandalf, but meet Aragorn instead
    // places from the Hobbit book and movies
    "Laketown",         // also called Esgaorth, it is the town of men on the Long Lake near Erebor
    "Dale",             // the town of men outside Erebor, destroyed by Smaug long before the Hobbit story
    "Erebor",           // the Elvish name for the Lonely Mountain, where the dwarves had their fortress
    "Beorn's House",    // Beorn is the shape-shifter who shelters the dwarf party
    "Dol Guldur",       // fortress in Mirkwood where Sauron, as the Necromancer, hid during most of the Hobbit
};

// Iluvatar, the creator of Middle-Earth
MiddleEarth::MiddleEarth(int xsize, int ysize, int num_cities, int seed) {
    this->xsize = xsize;
    this->ysize = ysize;

    // set up the random number generator
    gen.seed(seed == -1 ? random_device{}() : seed);

    // count the number of cities in the array
    this->num_city_names = all_city_names.size();

    if (num_cities > num_city_names) {
        cout << "There are only " << num_city_names << " city names, so "
             << num_cities << " cities cannot be created." << endl;
        cout << "Exiting." << endl;
        exit(0);
    }

    if (num_cities < 5) {
        num_cities = 5;
    }

    // copy all the cities into a mutable vector
    this->cities = vector<string>(all_city_names.begin(), all_city_names.end());

    shuffle(cities.begin(), cities.end(), gen); // shuffle all the cities
    cities.erase(cities.begin() + num_cities, cities.end()); // then remove the ones we won't be using

    // compute random city positions
    for (auto city : cities) {
        xpos.emplace(city, (gen() / (double) gen.max()) * xsize);
        ypos.emplace(city, (gen() / (double) gen.max()) * ysize);
    }

    // compute the 2-d distance array
    // we assume that num_cities < xsize * ysize
    for (auto city1 : cities) {
        for (auto city2 : cities) {
            distances[city1].emplace(city2, sqrt((xpos[city2] - xpos[city1]) * (xpos[city2] - xpos[city1]) +
                                                 (ypos[city2] - ypos[city1]) * (ypos[city2] - ypos[city1])));
        }
    }
}

// The Mouth of Sauron!
// Prints out info on the created 'world'
void MiddleEarth::print() {
    cout << "there are " << num_city_names
         << " locations to choose from; we are using " << cities.size() << endl;
    cout << "they are: " << endl;
    for (auto city : cities) {
        cout << "\t" << city << " @ (" << xpos[city] << ", " << ypos[city]
             << ")" << endl;
    }
}

// Prints a tab-separated table of the distances,
// which can be loaded into Excel or similar
void MiddleEarth::printTable() {
    cout << "Table: " << endl << endl << "Location\txpos\typos\t";
    for (auto city : cities) {
        cout << city << "\t";
    }
    cout << endl;

    for (auto city1 : cities) {
        cout << city1 << "\t" << xpos[city1] << "\t" << ypos[city1] << "\t";
        for (auto city2 : cities) {
            cout << distances[city1][city2] << "\t";
        }
        cout << endl;
    }
}

// This method returns the distance between the two passed cities.
// If we assume that the hash table (i.e. the map) is O(1),
// then this method call is also O(1)
float MiddleEarth::getDistance(const string& city1, const string& city2) {
    return distances[city1][city2];
}

// Returns the list of cities to travel to.
// The first city is the original start point as well as the end point.
// The number of cities passed in does not include this start/end point
// (so there will be length+1 entries in the returned vector).
vector<string> MiddleEarth::getItinerary(unsigned int length) {
    // check parameter
    if (length >= cities.size()) {
        cout << "You have requested an itinerary of " << length
             << " cities; you cannot ask for an itinerary of more than length "
             << cities.size() - 1 << endl;
        exit(0);
    }

    length++; // to account for the start point

    // we need to make a deep copy of the cities vector
    vector<string> itinerary(cities.begin(), cities.end());

    // shuffle, erase unneeded ones, and return the itinerary
    shuffle(itinerary.begin(), itinerary.end(), gen);
    itinerary.erase(itinerary.begin() + length, itinerary.end());
    return itinerary;
}
