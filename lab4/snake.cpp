#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <set>
#include <chrono>
#include <thread>
#include <vector>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "list.h"
#include "point2D.h"
using namespace std;

class Snake {
public:
  Snake();
  void play();
private:
  void pause(double seconds);
  void drawFrame();
  void moveSnake();
  void clearGrid();
  void drawSnake();
  void handleInput();
  void drawGrid();

  char grid[80][24];
  List snakeBody;
  Point2D snakeDirection;
  Point2D snakeFoodLocation;
};

int main() {
  srand(time(0));

  Snake s;
  s.play();

  return 0;
}

void enableRawMode();

Snake::Snake() {
  // give the snake size 3, starting in the middle
  int middleX = 80/2, middleY = 24/2;
  snakeBody.push_back({middleX, middleY});
  snakeBody.push_back({middleX, middleY+1});
  snakeBody.push_back({middleX, middleY+1});

  // initial direction upward
  snakeDirection = {0, -1};

  // random initial food location
  std::random_device rd;
  std::mt19937 g(rd());
  snakeFoodLocation = {static_cast<int>(g() % 80), static_cast<int>(g() % 12)};

  enableRawMode();
}

void Snake::play() {
  while (true) {
    drawFrame();
    handleInput();
    moveSnake();

    pause(0.1);
  }
}

void Snake::pause(double seconds) {
  std::this_thread::sleep_for (std::chrono::microseconds(static_cast<long long>(seconds * 1e6)));
}

void Snake::drawFrame() {
  clearGrid();
  drawSnake();
  // draw food
  grid[snakeFoodLocation.getX()][snakeFoodLocation.getY()] = 'o';
  drawGrid();
}

void Snake::drawGrid() {
  for (int j = 0; j < 24; j++) {
    for (int i = 0; i < 80; i++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void Snake::moveSnake() {
  // move the head of the snakeBody (snakeBody.first()) in the current direction
  Point2D newLocationForHead = snakeBody.getFirst()->data + snakeDirection;
  int locX = newLocationForHead.getX();
  int locY = newLocationForHead.getY();
  if (locX < 0) locX += 80;
  if (locX >= 80) locX -= 80;
  if (locY < 0) locY += 24;
  if (locY >= 24) locY -= 24;
  newLocationForHead = {locX, locY};

  // add this location to the front of the snake
  snakeBody.push_front(newLocationForHead);

  // if we found food at our new location
  if (snakeFoodLocation == newLocationForHead) {
    // find a new location for the food
    vector<Point2D> possibleFoodLocations;

    set<Point2D> snakeBodyLocations;
    for (const Node *n = snakeBody.getFirst(); n != nullptr; n = n->next) {
      snakeBodyLocations.insert(n->data);
    }
    for (int i = 0; i < 80; i++)
      for (int j = 0; j < 24; j++)
        if (snakeBodyLocations.count({i, j}) == 0)
          possibleFoodLocations.push_back({i, j});

    // if there is no location, end the game
    if (possibleFoodLocations.size() == 0) {
      cout << "YOU WIN!!!" << endl;
      exit(0);
    }

    // shuffle the locations
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(possibleFoodLocations.begin(), possibleFoodLocations.end(), g);
    // put the food in the first location
    snakeFoodLocation = possibleFoodLocations.at(0);
  } else {
    // if we did not find food at our new location, remove the last
    // node to keep the snake the same length
    snakeBody.pop_back();
  }
}

void Snake::clearGrid() {
  for (int i = 0; i < 80; i++)
    for (int j = 0; j < 24; j++)
      grid[i][j] = ' ';
}

void Snake::drawSnake() {
  for (const Node *n = snakeBody.getFirst(); n != nullptr; n = n->next) {
    grid[n->data.getX()][n->data.getY()] = '*';
  }
}

///////////////////////////////////////////////////////////////////////////////
//           The following is well beyond the scope of this class.           //
///////////////////////////////////////////////////////////////////////////////

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  // https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
  // setvbuf(stdin, NULL, _IONBF, 0);

  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  raw.c_cc[VMIN] = 0;
  // raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void die(const char *s) {
  perror(s);
  exit(1);
}

char readKey() {
  // the real work is being done by read(STDIN_FILENO, &c, 1)
  int nread;
  char c;
  if ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1 && errno != EAGAIN) die("read");
    else return 0;
  }
  if (c == '\x1b') {
    char seq[3];
    if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
    if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
    if (seq[0] == '[') {
      switch (seq[1]) {
        case 'A': return 'w';
        case 'B': return 's';
        case 'C': return 'd';
        case 'D': return 'a';
      }
    }
    return '\x1b';
  } else {
    return c;
  }
}

void Snake::handleInput() {
  char c = readKey();
  if (c == 'w') {
    snakeDirection = {0, -1};
  } else if (c == 'a') {
    snakeDirection = {-1, 0};
  } else if (c == 's') {
    snakeDirection = {0, 1};
  } else if (c == 'd') {
    snakeDirection = {1, 0};
  } else if (c == 'q') {
    exit(0);
  }
}
