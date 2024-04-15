#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH_IMAGE  80
#define HEIGHT_IMAGE 19
#define WIDTH_HAND   38

typedef char* HAND_IMAGE[HEIGHT_IMAGE];

#define OPTION_ROCK    0
#define OPTION_PAPER   1
#define OPTION_SCIZORS 2

char image_buffer[HEIGHT_IMAGE][WIDTH_IMAGE + 2];

const HAND_IMAGE IMAGE_ROCK = {
    "                                      ",
    "                                      ",
    "                                      ",
    "                .75GBBBY.             ",
    "               5#7.   .!#5.           ",
    "            .?#5        Y@@P.         ",
    "        :?J5&@G.      ^G5:.?#P.       ",
    "      J#B?.  ^Y##Y: ^PJ.     5@:      ",
    "    ?&P:        :Y#&@!        @B      ",
    "   PP.       :     :?PB7    ^#&@5     ",
    "  !P        :@&5^    .&B .?GG^  BG    ",
    "  G5         .!G&&BG#@G?PY^     ^@    ",
    "  B@G.           .P@@#Y~.      .#@    ",
    "  #PY&P:          !@&       .!G&&&    ",
    "  G#  ?#B7        :P7.?JJ5PGGY^ J#    ",
    "   #B   .7JJ:        ^@5..    .J&:    ",
    "    5&!    ^#B!       :#BYJJ5GBJ      ",
    "     .PBJ:   :P&G?^:^!5#Y!~~:.        ",
    "       .7PBG5J?#&#GY7~:               "
};

const HAND_IMAGE IMAGE_PAPER = {
    "                                      ",
    "                   ~G55B5             ",
    "                  ?G.  .#B            ",
    "                 ^&     ~@            ",
    " !YYYJ!.        .&^     B#    :^^.    ",
    "PJ    ^P7      .&Y     P&.  :G5~^G#.  ",
    ":B:     G^    :&J     BG  .J?.   :@?  ",
    " ^@^    7G  .Y#^    .#? ^55:     Y&.  ",
    "  &#     7PJJ~      G57PY:     !G5    ",
    "  5@                .:.    .~5GJ:^?J! ",
    "  7@.         .         .?PBG5JYJ^. BG",
    "  ~@!        !@.        ^GGY?~:     &P",
    "  :@&.       B@                  .?B7 ",
    "  .@&&7     P@:           !JYYYYYY~   ",
    "   &!.YBJ:  ~          .   :Y&#G5     ",
    "   ^@?  ?&Y          :PGP?.    ~@:    ",
    "    .PB?..J&Y:    :7GG:  ^YP5YPG^     ",
    "      .!YPP&@&G55PP?.       ...       ",
    "                                      "
};

const HAND_IMAGE IMAGE_SCIZORS = {
    "          !BGPGG!                     ",
    "         5@^   ^#&^    5#GGP:         ",
    "         !@.     #@.  B@:  ?@!        ",
    "          @Y     :@^ :@Y    #&        ",
    "          G&      @7 Y@.    B&        ",
    "          ?@:     @Y @B     @!        ",
    "          ~@^    .@B5@.    PG         ",
    "          ^@:    .@@@~    YG          ",
    "          #B      ^^    .#@P.         ",
    "        .&@G?7!~^:...   .^~P&#        ",
    "       ?@! .:^~!!77?B@^     ~@B       ",
    "      P@^    .     .#&.    7@G5@^     ",
    "     ~@^    .B#GPG#@@^  .!B#~  @J     ",
    "     5&       ......?B#&Y!.  .5G      ",
    "     ^@?              .J?~!YGG~       ",
    "      ~@&YJ!^:..         7@#          ",
    "       J@7::~7YPGPY?~^~?P&#:          ",
    "        ~#B?^.    :!Y#@&Y:            ",
    "          .!5GGGPP5YJ!:               "
};

const char* NAMES[3] = {
    "ROCK",
    "PAPER",
    "SCIZORS"
};

const HAND_IMAGE* IMAGES[3] = {
    &IMAGE_ROCK,
    &IMAGE_PAPER,
    &IMAGE_SCIZORS
};

void jankenpon();
void showHands(int playerOption, int computerOption);

void main() {
    jankenpon();
}

void jankenpon() {
    srand(time(NULL));

    int points1 = 0;
    int points2 = 0;

    for (;;) {
        printf("Rock-Paper-Scizors (Jan-Ken-Pon)\n\n");
        printf("The current score is:\n");
        printf("  Player: %d\n", points1);
        printf("  Computer: %d\n", points2);
        printf("\nChoose your option:\n");
        printf("  1 - Rock\n");
        printf("  2 - Paper\n");
        printf("  3 - Scizors\n");
        printf("  X - End game\n");

        int playerOption;
        for (;;) {
            char option = getchar();
            if (option == 'X' || option == 'x') {
                printf("Thanks for playing!\n");
                return;
            }

            switch (option) {
                case '1':
                    playerOption = OPTION_ROCK;
                    break;
                case '2':
                    playerOption = OPTION_PAPER;
                    break;
                case '3':
                    playerOption = OPTION_SCIZORS;
                    break;
                default:
                    continue;
            }
            break;
        }

        printf("Jan...");
        fflush(stdout);
        sleep(1);
        printf(" ken...");
        fflush(stdout);
        sleep(1);
        printf(" pon!\n");
        fflush(stdout);
        sleep(1);

        int computerOption = rand() % 3;

        showHands(playerOption, computerOption);

        printf("\n");
        printf("You played: %s\n", NAMES[playerOption]);
        printf("The computer played: %s\n", NAMES[computerOption]);
        sleep(1);

        int diff = (3 + playerOption - computerOption) % 3;
        int whoWon = 0;
        if (diff == 1) {
            whoWon = 1;
        } else if (diff == 2) {
            whoWon = 2;
        }

        if (whoWon == 1) {
            printf("You won this round!\n\n");
            points1 ++;
            continue;
        }

        if (whoWon == 2) {
            printf("The computer won this round!\n\n");
            points2 ++;
            continue;
        }

        printf("No one won this round!\n\n");
        continue;
    }
}

void showHands(int playerOption, int computerOption) {
    for (int y = 0; y < HEIGHT_IMAGE; y ++) {
        for (int x = 0; x < WIDTH_IMAGE; x ++) {
            image_buffer[y][x] = ' ';
        }
        image_buffer[y][WIDTH_IMAGE] = '\n';
        image_buffer[y][WIDTH_IMAGE + 1] = '\0';
    }

    const HAND_IMAGE* player_image = IMAGES[playerOption];
    const HAND_IMAGE* computer_image = IMAGES[computerOption];
    for (int y = 0; y < HEIGHT_IMAGE; y ++) {
        for (int x = 0; x < WIDTH_HAND; x ++) {
            image_buffer[y][x] = (*player_image)[y][x];
            image_buffer[y][WIDTH_IMAGE - 1 - x] = (*computer_image)[y][x];
        }
        printf("%s", image_buffer[y]);
    }
}
