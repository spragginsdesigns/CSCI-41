#include <iostream>
#include <random>
#include <algorithm>
#include "movieData.h"
#include "priorityQueue.h"
#include "testing.h"
using namespace std;

void intHeapTest();
void movieDataHeapTest();

int main() {
  intHeapTest();
  movieDataHeapTest();

  return 0;
}

void intHeapTest() {
  PriorityQueue<int> pq;
  assertTrue(pq.isEmpty() && pq.getLength() == 0, "empty heap");
  for (int i = 10; i >= 1; i--) {
    pq.push(i);
    assertTrue(!pq.isEmpty() && pq.getLength() == 11 - i, "heap size " + to_string(11 - i));
    assertTrue(pq.peek() == i, "heap's top element should be " + to_string(i));
  }

  for (int i = 1; i <= 10; i++) {
    assertTrue(pq.peek() == i && pq.pop() == i && pq.getLength() == 10 - i,
               "delete " + to_string(i));
  }
  assertTrue(pq.isEmpty() && pq.getLength() == 0, "empty heap (after removing everything)");
}

void movieDataHeapTest() {
  vector<MovieData> movies = {
    MovieData("The Shawshank Redemption", 1994, 9.3),
    MovieData("The Godfather", 1972, 9.2),
    MovieData("The Dark Knight", 2008, 9),
    MovieData("The Godfather: Part II", 1974, 9),
    MovieData("The Lord of the Rings: The Return of the King", 2003, 8.9),
    MovieData("Pulp Fiction", 1994, 8.9),
    MovieData("Schindler's List", 1993, 8.9),
    MovieData("12 Angry Men", 1957, 8.9),
    MovieData("Inception", 2010, 8.8),
    MovieData("Fight Club", 1999, 8.8),
    MovieData("The Lord of the Rings: The Fellowship of the Ring", 2001, 8.8),
    MovieData("Forrest Gump", 1994, 8.8),
    MovieData("The Good, the Bad and the Ugly", 1966, 8.8),
    MovieData("The Lord of the Rings: The Two Towers", 2002, 8.7),
    MovieData("The Matrix", 1999, 8.7),
    MovieData("Goodfellas", 1990, 8.7),
    MovieData("Star Wars: Episode V - The Empire Strikes Back", 1980, 8.7),
    MovieData("One Flew Over the Cuckoo's Nest", 1975, 8.7),
    MovieData("Harakiri", 1962, 8.7),
    MovieData("Parasite", 2019, 8.6),
    MovieData("Interstellar", 2014, 8.6),
    MovieData("City of God", 2002, 8.6),
    MovieData("Spirited Away", 2001, 8.6),
    MovieData("Saving Private Ryan", 1998, 8.6),
    MovieData("The Green Mile", 1999, 8.6),
    MovieData("Life Is Beautiful", 1997, 8.6),
    MovieData("Se7en", 1995, 8.6),
    MovieData("The Silence of the Lambs", 1991, 8.6),
    MovieData("Star Wars: Episode IV - A New Hope", 1977, 8.6),
    MovieData("Anand", 1971, 8.6),
    MovieData("Seven Samurai", 1954, 8.6),
    MovieData("It's a Wonderful Life", 1946, 8.6),
    MovieData("Joker", 2019, 8.5),
    MovieData("Whiplash", 2014, 8.5),
    MovieData("The Intouchables", 2011, 8.5),
    MovieData("The Prestige", 2006, 8.5),
    MovieData("The Departed", 2006, 8.5),
    MovieData("The Pianist", 2002, 8.5),
    MovieData("Gladiator", 2000, 8.5),
    MovieData("American History X", 1998, 8.5),
    MovieData("The Usual Suspects", 1995, 8.5),
    MovieData("Léon: The Professional", 1994, 8.5),
    MovieData("The Lion King", 1994, 8.5),
    MovieData("Terminator 2: Judgment Day", 1991, 8.5),
    MovieData("Cinema Paradiso", 1988, 8.5),
    MovieData("Grave of the Fireflies", 1988, 8.5),
    MovieData("Back to the Future", 1985, 8.5),
    MovieData("Once Upon a Time in the West", 1968, 8.5),
    MovieData("High and Low", 1963, 8.5),
    MovieData("Psycho", 1960, 8.5),
    MovieData("Frozen", 2013, 11.0)
  };

  std::random_device rd;
  std::mt19937 g(rd());
  shuffle(movies.begin(), movies.end(), g);

  vector<MovieData> expected = movies;
  stable_sort(expected.begin(),
              expected.end(),
              [](const MovieData& x, const MovieData& y) {
                return x.getName() < y.getName();
              });
  stable_sort(expected.begin(),
              expected.end(),
              [](const MovieData& x, const MovieData& y) {
                return x.getRating() > y.getRating();
              });

  movies = heapSort(movies);

  /* you might want to uncomment this: */
  // cout << "Sorted movies: " << endl;
  // for (const auto& movie : movies) {
  //   cout << "  " << movie << endl;
  // }

  assertTrue(movies == expected, "heap of movies with custom order");
}
