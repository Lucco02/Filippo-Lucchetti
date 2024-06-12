#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Per tolower()

// Funzione per pulire lo schermo
void clearScreen() {
    printf("\033[H\033[J");
}

// Funzione per mostrare il menu iniziale
void showMenu() {
    printf("Benvenuto a Call of Duty Quiz!\n");
    printf("Scegli un'opzione:\n");
    printf("A) Iniziare una nuova partita\n");
    printf("B) Uscire dal gioco\n");
    printf("Inserisci la tua scelta (A/B): ");
}

// Funzione per presentare una domanda e restituire 1 se la risposta è corretta, 0 altrimenti
int askQuestion(const char *question, const char *options[], char correctOption) {
    printf("%s\n", question);
    for (int i = 0; i < 3; i++) {
        printf("%c) %s\n", 'A' + i, options[i]);
    }
    printf("Inserisci la tua risposta (A/B/C): ");
    char answer;
    scanf(" %c", &answer);

    // Converte la risposta in minuscolo per il confronto
    answer = tolower(answer);
    correctOption = tolower(correctOption);

    if (answer == correctOption) {
        printf("Corretto!\n\n");
        return 1;
    } else {
        printf("Sbagliato. La risposta corretta era %c.\n\n", toupper(correctOption));
        return 0;
    }
}

// Funzione per gestire l'input in modo sicuro
char getValidatedInput() {
    char input;
    while (1) {
        scanf(" %c", &input);
        input = tolower(input);
        if (input == 'a' || input == 'b') {
            return input;
        } else {
            printf("Scelta non valida. Inserisci 'A' o 'B': ");
        }
    }
}

int main() {
    char choice;
    char name[50];
    int score;

    // Domande e risposte
    const char *questions[] = {
        "In quale anno è stato rilasciato il primo Call of Duty?",
        "Qual è il nome del protagonista in Call of Duty: Modern Warfare?",
        "Quale di questi è un gioco spin-off della serie Call of Duty?"
    };
    const char *options[][3] = {
        {"2001", "2003", "2005"},
        {"John Price", "Alex Mason", "Frank Woods"},
        {"Call of Duty: Ghosts", "Call of Duty: Black Ops", "Call of Duty: Warzone"}
    };
    const char correctOptions[] = {'B', 'A', 'C'};

    while (1) {
        clearScreen();
        showMenu();
        choice = getValidatedInput();

        if (choice == 'a') {
            printf("Inserisci il tuo nome: ");
            scanf("%s", name);

            score = 0;
            for (int i = 0; i < 3; i++) {
                clearScreen();
                score += askQuestion(questions[i], options[i], correctOptions[i]);
            }

            printf("Partita terminata! %s, il tuo punteggio è: %d su 3\n", name, score);
            printf("Vuoi giocare di nuovo? (A per una nuova partita, B per uscire): ");
            choice = getValidatedInput();

            if (choice == 'b') {
                break;
            }
        } else if (choice == 'b') {
            break;
        }
    }

    printf("Grazie per aver giocato!\n");
    return 0;
}