/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:51 by pbengoec          #+#    #+#             */
/*   Updated: 2022/09/29 19:15:47 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

// The isalnum() function returns zero if the character tests false and
//      returns non-zero if the character tests true.
int		ft_isalnum(int c);
// The isalpha() function returns zero if the character tests false and
//      returns non-zero if the character tests true.
int		ft_isalpha(int c);
// The isascii() function tests for an ASCII character, which is any charac-
//      ter between 0 and octal 0177 inclusive.
int		ft_isascii(int c);
// The isdigit() function tests for a decimal digit character.  Regardless
//      of locale, this includes the following characters only:
int		ft_isdigit(int c);
// The isprint() function returns zero if the character tests false and
//      returns non-zero if the character tests true.
int		ft_isprint(int c);
// The functions strchr() and strrchr() return a pointer to the located
//      character, or NULL if the character does not appear in the string.
char	*ft_strchr(const char *s, int c);
// The functions strchr() and strrchr() return a pointer to the located
//      character, or NULL if the character does not appear in the string.
char	*ft_strrchr(const char *s, int c);
// return length of string
size_t	ft_strlen(const char *s);
// Changes upper-case letter to lower-case letter
int		ft_tolower(int c);
// Changes lower-case letter to upper-case letter
int		ft_toupper(int c);
// The strcmp() and strncmp() functions return an integer greater than,
//      equal to, or less than 0, according as the string s1 is greater than,
//      equal to, or less than the string s2.  The comparison is done using
//      unsigned characters, so that `\200' is greater than `\0'.
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// The memset() function writes len bytes of value c (converted to an
//      unsigned char) to the string b.
void	*ft_memset(void *b, int c, size_t len);
// The bzero() function writes n zeroed bytes to the string s.  If n is
//      zero, bzero() does nothing.
void	ft_bzero(void *s, size_t n);
// The memcpy() function copies n bytes from memory area src to memory area
//      dst.  If dst and src overlap, behavior is undefined.  Applications in
//      which dst and src might overlap should use memmove(3) instead.
void	*ft_memcpy(void *dst, const void *src, size_t n);
// The memmove() function copies len bytes from string src to string dst.
//      The two strings may overlap; the copy is always done in a 
//      non-destructive manner.
void	*ft_memmove(void *dst, const void *src, size_t len);
// Copy the string src into dst
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// Appends string src to the end of dst
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// function locates the first occurrence of c (converted to an
//      unsigned char) in string s.
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
#endif