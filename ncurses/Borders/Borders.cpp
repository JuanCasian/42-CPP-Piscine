# include <ncurses.h>

int main(int argc, char const *argv[]) {

    initscr();

    // Create a new window variable and initialize it (height, width, start_y, start_x)
    WINDOW *win = newwin(30, 30, 10, 10);
    refresh(); // refresh to add window to main window

    // Create the border of the window (windowpointer, 0, 0)
    box(win, 0, 0);

    // move and print on the window (winpointer, y, x, text)
    mvwprintw(win, 3, 4, "Working...");
    // refresh window to make all appear (windowpointer)
    wrefresh(win);

    getch();

    endwin();

    return 0;
}
