# include <ncurses.h>
#include <string>

int main(int argc, char const *argv[]) {

    // common ncurses start
    initscr();
    noecho();
    cbreak();

    // create window
    WINDOW *win = newwin(5, 15, 1, 1);
    box(win, 0 ,0);
    refresh();
    wrefresh(win);

    //makes arrow keys available
    keypad(win, true);

    // Menu Logic

    std::string choices[] = {"Option1", "Option2", "Option3"};
    int choice;
    int highlight = 0;

    while (1)
    {
        for(int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(win, A_REVERSE);
            mvwprintw(win, i+1, 1, choices[i].c_str()); // usas c_str porque la funcion no acepta los strings nuevos
            wattroff(win, A_REVERSE);
        }
        choice = wgetch(win);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight < 0)
                    highlight = 0;
                    break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 2)
                    highlight = 2;
                break;
            default:
                break;
        }
        if (choice == 10)
            break;
    }

    printw("Your choice was: %s", choices[highlight].c_str());
    getch();
    endwin();

    return 0;
}
