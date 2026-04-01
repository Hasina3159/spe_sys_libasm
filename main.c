#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Déclare tes fonctions externes pour que le C les connaisse
extern size_t ft_strlen(const char *s);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main() {
    char *str = "Hello 42!";
    
    // Test ft_strlen
    printf("Vrai strlen : %lu\n", strlen(str));
    printf("Ma ft_strlen : %lu\n", ft_strlen(str));

    // Test ft_write
    printf("Test ft_write :\n");
    ft_write(1, str, 9);
    ft_write(1, "\n", 1);

    return 0;
}