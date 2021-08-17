/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:14:11 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/15 23:04:58 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <iostream>

int main()
{
        char str[50] = "hello world every body !";
        char *ptr = std::strtok(str, " ");
        char **res ;
        int i  = 0;
        int w = 0;
        while (ptr != NULL)
        {
            std::cout << ptr << std::endl;
            ptr = strtok(NULL, " ");
            w++;
        }
        *res = new char[w + 1];
        while (ptr != NULL)
        {
            res[i] = ptr;
            i++;
            ptr = strtok(NULL, " ");
        }
        res[i] = NULL;
        // int j = 0;
        // while(res[j])
        //     std::cout << res[++j] << std::endl;
}