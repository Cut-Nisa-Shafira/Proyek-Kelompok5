#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 5

typedef struct
{
    char pertanyaan[100];
    char pilihan[4][50];
    char Jawaban;
    int points;
} Pertanyaan;

typedef struct
{
    char username[50];
    char password[50];
} Pengguna_a;

Pertanyaan soal[MAX_QUESTIONS];
Pengguna_a currentUser;

void registerUser()
{
    printf("Registration\n");
    printf("Username: ");
    scanf(" %[^\n]s", currentUser.username);
    printf("Password: ");
    scanf(" %[^\n]s", currentUser.password);

    FILE *file = fopen("login.txt", "w");
    if (file != NULL)
    {
        fprintf(file, "%s\n%s", currentUser.username, currentUser.password);
        fclose(file);
    }
    else
    {
        printf("Registrasi gagal. Harap coba kembali.\n");
        exit(1);
    }
}

void loginpengguna(char *username, char *password)
{
    FILE *file = fopen("login.txt", "r");
    if (file != NULL)
    {
        fscanf(file, "%[^\n]s", currentUser.username);
        fscanf(file, "\n%[^\n]s", currentUser.password);
        fclose(file);

        if (strcmp(currentUser.username, username) == 0 && strcmp(currentUser.password, password) == 0)
        {
            printf("Login Sukses. Selamat Datang, %s!\n", currentUser.username);
        }
        else
        {
            printf("Login gagal. Silahkan cek username dan password.\n");
            printf("Usage: ./namafile \"username dengan spasi\" <password> (jika sandi tidak mengandung spasi)\n");
            printf("Usage: ./namafile \"username dengan spasi\" \"username dengan spasi\" (jika sandi mengandung spasi)\n");
            exit(1);
        }
    }
    else
    {
        printf("Login gagal. Silahkan registrasi terlebih dahulu.\n");
        printf("Usage: ./namafile register\n");
        exit(1);
    }
}
void loadQuestions()
{
    // Pertanyaan 1
    strcpy(soal[0].pertanyaan, "Siapa nama ayah Boboiboy?");
    strcpy(soal[0].pilihan[0], "A. Amato");
    strcpy(soal[0].pilihan[1], "B. Azroy");
    strcpy(soal[0].pilihan[2], "C. Uno");
    strcpy(soal[0].pilihan[3], "D. Upin");
    soal[0].Jawaban = 'A';
    soal[0].points = 20;

    // Pertanyaan 2
    strcpy(soal[1].pertanyaan, "Siapa nama kakek Boboiboy?");
    strcpy(soal[1].pilihan[0], "A. Haji Senin Jum'at");
    strcpy(soal[1].pilihan[1], "B. Tok Aba");
    strcpy(soal[1].pilihan[2], "C. Opah");
    strcpy(soal[1].pilihan[3], "D. Mas Dibo");
    soal[1].Jawaban = 'B';
    soal[1].points = 20;

    // Pertanyaan 3
    strcpy(soal[2].pertanyaan, "Dari mana kekuatan Boboiboy berasal?");
    strcpy(soal[2].pilihan[0], "A Dibo");
    strcpy(soal[2].pilihan[1], "B. Ansell");
    strcpy(soal[2].pilihan[2], "C. Ochobot");
    strcpy(soal[2].pilihan[3], "D. Freya");
    soal[2].Jawaban = 'C';
    soal[2].points = 20;

    // Pertanyaan 4
    strcpy(soal[3].pertanyaan, "Siapa nama alien kepale kotak? ");
    strcpy(soal[3].pilihan[0], "A. Proub");
    strcpy(soal[3].pilihan[1], "B. Fang");
    strcpy(soal[3].pilihan[2], "C. Tigreal");
    strcpy(soal[3].pilihan[3], "D. Adudu");
    soal[3].Jawaban = 'D';
    soal[3].points = 20;

    // Pertanyaan 5
    strcpy(soal[4].pertanyaan, "Kapan tanggal lahir Boboiboy?");
    strcpy(soal[4].pilihan[0], "A. 13 Maret");
    strcpy(soal[4].pilihan[1], "B. 22 Juli");
    strcpy(soal[4].pilihan[2], "C. 1 Februai");
    strcpy(soal[4].pilihan[3], "D. 31 Februar");
    soal[4].Jawaban = 'A';
    soal[4].points = 20;
}
int convertAnswer(char answer)
{
    answer = toupper(answer);
    switch (answer)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    default:
        return -1;
    }
}

int playGame()
{
    int totalPoints = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Pertanyaan %d:\n", i + 1);
        printf("%s\n", soal[i].pertanyaan);
        printf("%s\n", soal[i].pilihan[0]);
        printf("%s\n", soal[i].pilihan[1]);
        printf("%s\n", soal[i].pilihan[2]);
        printf("%s\n", soal[i].pilihan[3]);

        char answer;
        printf("Masukkan Jawaban (A/B/C/D): ");
        scanf(" %c", &answer);

        int choice = convertAnswer(answer);
        if (choice == -1)
        {
            printf("Jawaban tidak valid.\n");
        }
        else if (choice == soal[i].Jawaban - 'A')
        {
            totalPoints += soal[i].points;
            printf("Selamat, Jawaban Anda Benar!\n");
        }
        else
        {
            printf("Yahhh, jawabannya salah, yuk belajar lagi!\n");
        }

        printf("\n");
    }

    return totalPoints;
}
int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "register") == 0)
    {
        registerUser();
    }
    else if (argc == 3)
    {
        char *username = argv[1];
        char *password = argv[2];
        loginpengguna(username, password);

        loadQuestions();
        int finalScore = playGame();

        printf("Final Score: %d\n", finalScore);
    }
    else
    {
        printf("Invalid arguments.\n");
        printf("Usage: ./namafile register\n");
        printf("Usage: ./namafile \"username dengan spasi\" <password> (jika sandi tidak mengandung spasi)\n");
        printf("Usage: ./namafile \"username dengan spasi\" \"username dengan spasi\" (jika sandi mengandung spasi)\n");
    }

    return 0;
}
