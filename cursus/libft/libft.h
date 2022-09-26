/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:33:51 by pbengoec          #+#    #+#             */
/*   Updated: 2022/09/26 18:47:05 by pbengoec         ###   ########.fr       */
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
// The strlen() function returns the number of characters that precede the
//      terminating NUL character.  The strnlen() function returns either the
//      same result as strlen() or maxlen, whichever is smaller.
size_t	ft_strlen(const char *s);
// If the argument is an upper-case letter, the tolower() function returns
//      the corresponding lower-case letter if there is one; otherwise,
//      the argument is returned unchanged.
int		ft_tolower(int c);
// If the argument is a lower-case letter, the toupper() function returns
//      the corresponding upper-case letter if there is one; otherwise, 
//      the argument is returned unchanged.
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
#endif