#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

// Déclare tes fonctions externes
extern size_t ft_strlen(const char *s);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strdup(const char *s);
extern int ft_is_whitespace(char s);
extern int ft_has_whitespaces(char *s);
extern int ft_atoi_base(char *nbr, char *base);
int main() {
    char buffer[1024];
    ssize_t ret;
    int fd;
    char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                     "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                     "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";
    
    printf("==== TEST FT_STRLEN ====\n");
    
    // Test ft_strlen avec chaîne vide
    printf("ft_strlen(\"\") = %lu (expected 0)\n", ft_strlen(""));
    printf("strcmp avec stdlib: strlen(\"\") = %lu\n", strlen(""));
    
    // Test ft_strlen avec chaîne courte
    printf("ft_strlen(\"hello\") = %lu (expected 5)\n", ft_strlen("hello"));
    printf("strcmp avec stdlib: strlen(\"hello\") = %lu\n", strlen("hello"));
    
    // Test ft_strlen avec très longue chaîne
    printf("ft_strlen(long_str) = %lu\n", ft_strlen(long_str));
    printf("strcmp avec stdlib: strlen(long_str) = %lu\n", strlen(long_str));
    
    printf("\n==== TEST FT_STRCPY ====\n");
    
    // Test ft_strcpy avec chaîne vide
    memset(buffer, 'X', sizeof(buffer));
    ft_strcpy(buffer, "");
    printf("ft_strcpy(dest, \"\") = '%s'\n", buffer);
    
    // Test ft_strcpy avec chaîne courte
    ft_strcpy(buffer, "hello");
    printf("ft_strcpy(dest, \"hello\") = '%s'\n", buffer);
    
    // Test ft_strcpy avec très longue chaîne
    ft_strcpy(buffer, long_str);
    printf("ft_strcpy(dest, long_str) = '%s...'\n", buffer);
    
    printf("\n==== TEST FT_STRCMP ====\n");
    
    // Test ft_strcmp avec 2 chaînes vides
    printf("ft_strcmp(\"\", \"\") = %d (expected 0)\n", ft_strcmp("", ""));
    
    // Test ft_strcmp avec 1 chaîne vide en premier argument
    printf("ft_strcmp(\"\", \"hello\") = %d (expected < 0)\n", ft_strcmp("", "hello"));
    
    // Test ft_strcmp avec 1 chaîne vide en second argument
    printf("ft_strcmp(\"hello\", \"\") = %d (expected > 0)\n", ft_strcmp("hello", ""));
    
    // Test ft_strcmp avec plusieurs chaînes
    printf("ft_strcmp(\"abc\", \"abc\") = %d (expected 0)\n", ft_strcmp("abc", "abc"));
    printf("ft_strcmp(\"abc\", \"abd\") = %d (expected < 0)\n", ft_strcmp("abc", "abd"));
    printf("ft_strcmp(\"abd\", \"abc\") = %d (expected > 0)\n", ft_strcmp("abd", "abc"));
    printf("ft_strcmp(\"hello\", \"world\") = %d\n", ft_strcmp("hello", "world"));
    
    printf("\n==== TEST FT_WRITE ====\n");
    
    // Test ft_write avec stdout (fd = 1)
    printf("Test ft_write with stdout (fd=1):\n");
    ret = ft_write(1, "Hello from ft_write!\n", 21);
    printf("ft_write returned: %ld (expected 21)\n", ret);
    
    // Test ft_write avec file descriptor ouvert
    printf("Test ft_write with open file descriptor:\n");
    fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd >= 0) {
        ret = ft_write(fd, "Writing to file\n", 16);
        printf("ft_write to file returned: %ld (expected 16)\n", ret);
        close(fd);
    }
    
    // Test ft_write avec mauvais file descriptor
    printf("Test ft_write with invalid file descriptor (-1):\n");
    errno = 0;
    ret = ft_write(-1, "test\n", 5);
    printf("ft_write(-1, ...) returned: %ld\n", ret);
    printf("errno = %d (%s)\n", errno, strerror(errno));
    
    printf("\n==== TEST FT_READ ====\n");
    
    // Test ft_read avec stdin (fd = 0)
    printf("Test ft_read with stdin (fd=0):\n");
    printf("Type some text and press Enter: ");
    fflush(stdout);
    memset(buffer, 0, sizeof(buffer));
    ret = ft_read(0, buffer, 100);
    printf("ft_read returned: %ld\n", ret);
    if (ret > 0) {
        buffer[ret] = '\0';
        printf("Read: [%s]\n", buffer);
    }
    
    // Test ft_read avec file descriptor ouvert
    printf("Test ft_read with open file descriptor:\n");
    if (access("test_output.txt", F_OK) == 0) {
        fd = open("test_output.txt", O_RDONLY);
        if (fd >= 0) {
            memset(buffer, 0, sizeof(buffer));
            ret = ft_read(fd, buffer, 50);
            printf("ft_read from file returned: %ld\n", ret);
            if (ret > 0) {
                buffer[ret] = '\0';
                printf("Read from file: [%s]\n", buffer);
            }
            close(fd);
        }
    }
    
    // Test ft_read avec mauvais file descriptor
    printf("Test ft_read with invalid file descriptor (-1):\n");
    errno = 0;
    ret = ft_read(-1, buffer, 100);
    printf("ft_read(-1, ...) returned: %ld\n", ret);
    printf("errno = %d (%s)\n", errno, strerror(errno));
    
    printf("\n==== TEST FT_STRDUP ====\n");
    
    // Test ft_strdup avec chaîne vide
    char *dup = ft_strdup("");
    if (dup) {
        printf("ft_strdup(\"\") = '%s' (length: %lu)\n", dup, strlen(dup));
        free(dup);
    } else {
        printf("ft_strdup(\"\") returned NULL\n");
    }
    
    // Test ft_strdup avec chaîne courte
    dup = ft_strdup("hello");
    if (dup) {
        printf("ft_strdup(\"hello\") = '%s'\n", dup);
        free(dup);
    }
    
    // Test ft_strdup avec très longue chaîne
    dup = ft_strdup(long_str);
    if (dup) {
        printf("ft_strdup(long_str) = '%s...'\n", dup);
        printf("Length: %lu\n", strlen(dup));
        free(dup);
    }
    
    printf("\n==== ALL TESTS COMPLETED ====\n");

    printf("Is whitespace : [a] : %d\n", ft_is_whitespace ('a'));
    printf("Is whitespace : [\t] : %d\n", ft_is_whitespace ('\t'));
    printf("Is whitespace : [x] : %d\n", ft_is_whitespace ('x'));
    printf("Is whitespace : [-] : %d\n", ft_is_whitespace ('-'));
    printf("Is whitespace : [ ] : %d\n", ft_is_whitespace (' '));
    printf("Is whitespace : [.] : %d\n", ft_is_whitespace ('.'));

    printf("\n==== ALL TESTS COMPLETED ====\n");

    printf("HAS whitespaces : [%s] : %d\n", "sdfdsf.asdsad", ft_atoi_base ("sdfdsf.asdsad", ""));
    printf("HAS whitespaces : [%s] : %d\n", "adasd-asdd", ft_atoi_base ("adasd-asdd", ""));
    printf("HAS whitespaces : [%s] : %d\n", "sadsad asdasd", ft_atoi_base ("sadsad asdasd", ""));
    printf("HAS whitespaces : [%s] : %d\n", "\tsdfsdfsdf\tsdsada", ft_atoi_base ("\tsdfsdfsdf\tsdsada", ""));
    printf("HAS whitespaces : [%s] : %d\n", "\nsdfdfsdf\nsdfsdfdsf", ft_atoi_base ("\nsdfdfsdf\nsdfsdfdsf", ""));
    printf("HAS whitespaces : [%s] : %d\n", "sdfsdfdsfsdf", ft_atoi_base ("sdfsdfdsfsdf", ""));
    printf("HAS whitespaces : [%s] : %d\n", "sadasdsadasd asdsadasd", ft_atoi_base ("sadasdsadasd asdsadasd", ""));
    

    return 0;
}