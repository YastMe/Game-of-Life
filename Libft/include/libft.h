/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:29:30 by fragarci          #+#    #+#             */
/*   Updated: 2024/06/10 22:23:09 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

// LIBFT

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 *
 * @return The converted value or 0 on error.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Erases the data in the n bytes of the memory starting at the location
 * pointed to by s, by writing zeros (bytes containing '\0') to that area.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory.  The memory is set to zero.  If
 * nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
 * value  that can  later  be  successfully passed  to  free().  If the
 * multiplication of nmemb and size would result in integer overflow, then
 * calloc() returns an error.
 *
 * @return A pointer to the allocated memory, which is suitably aligned
 * for any built-in type.  On error, return NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Checks for an alphanumeric character; it is equivalent to
 * (ft_isalpha(c) || ft_isdigit(c)).
 *
 * @return The values returned are nonzero if the character c falls into
 * the tested class, and zero if not.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks  for an alphabetic character; in the standard "C" locale,
 * it is equivalent to (isupper(c) || islower(c)).  In some locales, there
 * may be additional characters for which isalpha() is true—letters which
 * are neither uppercase nor lowercase.
 *
 * @return The values returned are nonzero if the character c falls into
 * the tested class, and zero if not.
 */
int		ft_isalpha(int c);

/**
 * @brief checks whether c is a 7-bit unsigned char value that fits into the
 * ASCII character set.
 *
 * @return The values returned are nonzero if the character c falls into
 * the tested class, and zero if not.
 */
int		ft_isascii(int c);

/**
 * @brief checks for a digit (0 through 9).
 *
 * @return The values returned are nonzero if the character c falls into
 * the tested class, and zero if not.
 */
int		ft_isdigit(int c);

/**
 * @brief checks for any printable character including space.
 *
 * @return The values returned are nonzero if the character c falls into
 * the tested class, and zero if not.
 */
int		ft_isprint(int c);

/**
 * @brief Converts an integer value to a null-terminated string.
 *
 * @return A pointer to the resulting null-terminated string.
 */
char	*ft_itoa(int n);

/**
 * @brief Add the node 'new' at the end of the list 'lst'
 *
 * @param lst The pointer to the first node of a list
 * @param new The pointer to the node to add to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Add the node 'new' at the start of the list 'lst'
 *
 * @param lst The address of a pointer to the first node of a list
 * @param new The pointer to the node to add at the front of the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Removes and frees the given 'lst' node and all consecutive
 * consecutive ones from that node, using the function function 'del' and
 * free(3). At the end, the pointer to the list must be NULL.
 *
 * @param lst The address of a pointer to a node.
 * @param del A function pointer used to delete the contents of a node.
 * the contents of a node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Takes as parameter an 'lst' node and frees the memory of its
 * memory of the content using the function 'del' given as function given
 * as parameter, in addition to freeing the node. The memory of 'next' must
 * not be freed.
 *
 * @param lst The node to be freed.
 * @param del A pointer to the function used to free the contents of the node.
 * the contents of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Iterate the 'lst' list and apply the 'f' function on the content of
 * each node.
 *
 * @param lst A pointer to the first node.
 * @param f A pointer to the function to be used by each node.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Returns the last node in the list.
 *
 * @param lst The beginning of the list.
 * @return Last node in the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Iterate the 'lst' list and apply the 'f' function to the content of
 * each node. Creates a list resulting of the correct and successive application
 * of the function 'f' on each node. The function 'del' is used to remove the
 * contents of a node, if necessary.
 *
 * @param lst A pointer to a node.
 * @param f The address of a pointer to a function used in the iteration of
 * each element of the list.
 * @param del A function pointer used to delete the contents of a node, if
 * necessary.
 * @return The new list. NULL if the memory reservation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Create a new node using malloc(3). The member variable 'content' is
 * initialized with the content of the 'content' parameter. content parameter
 * 'content'. The variable variable 'next' is initialized with NULL.
 *
 * @param content The content with which to create the node.
 * @return The new node
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Counts the number of nodes in a list.
 *
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c.  Both c and the bytes of the memory area pointed to by
 * s are interpreted as unsigned char.
 *
 * @return A pointer to the matching byte or NULL if the character does not occur
 * in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes (each interpreted as unsigned char) of the
 * memory areas s1 and s2
 *
 * @return An integer less than, equal to, or greater than zero if the first n
 * bytes of s1 is found, respectively, to be less than, to match, or be greater
 * than the first n bytes of s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap.

 * @return A pointer to dest.
 */
void	*ft_memcpy(void	*dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.  The memory
 * areas may overlap: copying takes place as though the bytes in src are first
 * copied into a temporary array that does not overlap src or dest, and the bytes
 * are then copied  from  the  temporary array to dest.
 *
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * constant byte c.
 *
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Sends the character 'c' to the specified file descriptor.
 *
 * @param c The character to send.
 * @param fd The file descriptor to write to.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Send the string 's' to the given file descriptor, followed by a
 * line break.
 *
 * @param s The string to send.
 * @param fd The file descriptor to write to.
 */
void	ft_putendl_fd(char const *s, int fd);

/**
 * @brief Send the number 'n' to the given file descriptor.
 *
 * @param n The number to send.
 * @param fd The file descriptor to write to.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Send the string 's' to the specified file descriptor.
 *
 * @param s The string to send.
 * @param fd The file descriptor to write to.
 */
void	ft_putstr_fd(char const *s, int fd);

/**
 * @brief Reserve (using malloc(3)) an array of strings resulting from separating
 * the string 's' in substrings using the character 'c' as delimiter. The array
 * must end with a NULL pointer.
 *
 * @param s The string to be separated.
 * @param c The delimiting character.
 * @return The array of new strings resulting from the separation. NULL if the
 * memory reservation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Returns a pointer to the first occurrence of the character c in the
 * string s.
 *
 * @return A pointer to the matched character or NULL if the character is not
 * found. The  terminating  null byte is considered part of the string, so
 * that if c is specified as '\0', these functions return a pointer to the
 * terminator.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief returns a pointer to a new string which is a duplicate of the string
 * s. Memory for the new string is obtained with mal‐ loc(3), and can be freed
 * with free(3).
 *
 * @return On success, the ft_strdup() function returns a pointer to the
 * duplicated string. It returns NULL if insufficient memory was available
 */
char	*ft_strdup(const char *s);

/**
 * @brief To each character of the string 's', it applies the function function
 * 'f' giving as parameters the index of each character within 's' and the
 * address of the character itself, which may be modified if necessary.
 *
 * @param s The string to iterate.
 * @param f The function to apply on each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Reserves (with malloc(3)) and returns a new string, formed by
 * concatenating 's1' and 's2'.
 *
 * @param s1 The first string.
 * @param s2 The string to add to 's1'.
 * @return The new string. NULL if the memory reservation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will
 * append at most size - ft_strlen(dst) - 1 bytes, NUL-terminating the result.
 *
 * @return The total length of the string tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src to
 * dst, NUL-terminating the result.
 *
 * @return The total length of the string tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief calculates the length of the string pointed to by s, excluding the
 * terminating null byte ('\0').
 *
 * @return The number of bytes in the string pointed to by s
 */
size_t	ft_strlen(const char *s);

/**
 * @brief To each character of the string 's', apply the function 'f' giving as
 * parameters the index of each character of the string 's'. function 'f' giving
 * as parameters the index of each character within 's' and the
 *
 * @param s The string to iterate.
 * @param f The function to apply on each character.
 * @return The string created after the correct use of 'f' on each character.
 * NULL if the memory reservation fails
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @brief Compares  the  two  strings  s1 and s2.
 *
 * @return An integer less than, equal to, or greater than zero if s1 (or the
 * first n bytes thereof) is found, respectively, to be less than, to match, or
 * be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Finds  the first occurrence of the substring needle in the string
 * haystack. The terminating null bytes ('\0') are not compared.
 *
 * @return A pointer to the beginning of the located substring, or NULL if
 * the substring is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Returns a pointer to the last occurrence of the character c in the
 * string s.
 *
 * @return A pointer to the matched character or NULL if the character is not
 * found. The  terminating  null byte is considered part of the string, so
 * that if c is specified as '\0', these functions return a pointer to the
 * terminator.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Removes all characters from the string 'set' from the beginning and
 * from the end of 's1', until a character not belonging to 'set' is found.
 * The resulting string is returned with a malloc(3) reservation.
 *
 * @param s1 The string to be trimmed.
 * @param set The characters to remove from the string.
 * @return The trimmed string. NULL if the memory reservation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Reserves (with malloc(3)) and returns a substring of the string 's'.
 * The substring starts from the index 'start' and has a maximum length 'len'.
 *
 * @param s The string from which to create the substring.
 * @param start The index of the character in 's' from which to start the
 * substring.
 * @param len The maximum length of the substring.
 * @return The resulting substring. NULL if the memory reservation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief These functions convert lowercase letters to uppercase, and vice versa.
 *
 * @return The value returned is that of the converted letter, or c if the
 * conversion was not possible.
 */
int		ft_tolower(int c);

/**
 * @brief These functions convert lowercase letters to uppercase, and vice versa.
 *
 * @return The value returned is that of the converted letter, or c if the
 * conversion was not possible.
 */
int		ft_toupper(int c);

// READLINE

/**
 * @brief ft_readline will  read a line from the terminal and return it, using
 * prompt as a prompt. If prompt is NULL or the empty string, no prompt is
 * is‐sued.The line returned is allocated with malloc(3); the caller must free
 * it when finished. The line returned has the final newline  removed, so only
 * the text of the line remains.
 *
 * @return The text of the line read.
 */
char	*ft_readline(const char *prompt);

/**
 * @brief ft_readint will  read a int from the terminal and return it, using
 * prompt as a prompt. If prompt is NULL or the empty string, no prompt is
 * is‐sued.
 *
 * @return The integer value read
 */
int		ft_readint(char	*prompt);

// PRINTF

int		ft_printf(char const *str, ...);

// GET_NEXT_LINE

char	*get_next_line(int fd);

#endif
