# include <ncurses.h>

int main(int argc, char const *argv[]) {
    // clears screen and allotes memory
    initscr();

    //prints string to the window
    printw("Hello World!");

    // refreshes the screen to match the memeory
    refresh();

    // waits for user input and returns the int value of it
    int c = getch();

    printw("%d", c); // printw can be used as printf

    getch();

    // deallocates the memory and finish ncurses loop
    endwin();

    return 0;
}
