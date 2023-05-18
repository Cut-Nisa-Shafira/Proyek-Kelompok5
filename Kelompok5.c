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
