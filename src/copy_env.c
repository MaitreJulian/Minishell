#include <stdlib.h>
#include <string.h>

char **copy_env(char **envp)
{
    int i, count;
    char **env_copy;

    // Compter le nombre de variables d'environnement
    for (count = 0; envp[count] != NULL; count++);

    // Allouer de la mémoire pour le nouveau tableau (compter +1 pour NULL final)
    env_copy = malloc((count + 1) * sizeof(char *));
    if (!env_copy)
        return NULL;

    // Dupliquer chaque variable
    for (i = 0; i < count; i++) {
        env_copy[i] = strdup(envp[i]);
        if (!env_copy[i]) {
            // En cas d'erreur, on libère ce qui a été alloué jusque-là
            while (i-- > 0)
                free(env_copy[i]);
            free(env_copy);
            return NULL;
        }
    }

    env_copy[count] = NULL; // Terminer par NULL
    return env_copy;
}
