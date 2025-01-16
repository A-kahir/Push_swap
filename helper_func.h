/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <aymanekahir036@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:24:17 by akahir            #+#    #+#             */
/*   Updated: 2025/01/11 15:54:47 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Integer Overflow/Underflow: Reject numbers outside the range of a 32-bit signed integer (INT_MIN to INT_MAX).

    Duplicate Numbers: Reject input containing duplicate integers.

    Non-Numeric Input: Reject input containing characters, words, or symbols that cannot be converted to valid integers.

    Empty Input or No Arguments: Reject if no arguments or only whitespace are provided.

    Invalid Format: Reject inputs with invalid formatting, such as multiple spaces, empty strings, or numbers mixed with characters (e.g., 12a).

    Leading/Trailing Spaces: Handle inputs with leading or trailing spaces correctly.

    Edge Cases: Reject negative zeros (-0), as they can be interpreted as duplicates of 0.
*/