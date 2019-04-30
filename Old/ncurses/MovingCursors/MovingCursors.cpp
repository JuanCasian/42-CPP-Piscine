# include <ncurses.h>

int main(int argc, char const *argv[]) {

    initscr();
    // Will move cursor to position (y , x)
    move(10, 10);
    printw("Hello World!");

    int c  = getch();
    // Clears the window
    clear();

    // moves cursos to location (y, x, ...) and prints
    mvprintw(15, 20, "%d", c);

    getch();
    endwin();

    return 0;
}
