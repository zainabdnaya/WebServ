/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:39:32 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/08/07 17:05:00 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/Webserv.hpp"

int nbr_lines(std::string source)
{
    int i;
    int lines;

    i = 0;
    lines = 1;
    while (source[i])
    {
        if (source[i] == '\n')
            lines++;
        i++;
    }
    return (lines);
}

std::string Those_lines(std::string txt, int nbr_line, int txt_lines)
{
    int i = 0;
    int j = 0;
    int w = 0;
    if (nbr_line >= txt_lines)
        return (std::string(NULL));
    while (i < nbr_line)
    {
        if (txt[j] == '\n')
            i++;
        j++;
    }
    while (txt[j] != '\n' && std::isspace(txt[j])) // for the space befor  txt start from where the txt begins
        j++;
    w = 0;
    while (txt[w + j] && txt[w + j] != '\n') // when the line ends until \n
        ++w;
    while (w > 0 && std::isspace(txt[w + j - 1])) // escape space after the txt o the line
        --w;
    return (std::string(txt, j, w));
}

bool compare_end(std::string const &s1, std::string const &s2)
{
    int i;
    int j;

    i = s1.size() - 1;
    j = s2.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s1[i] != s2[j])
            return false;
        i--;
        j--;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Add conf file\n";
        exit(0);
    }
    if (compare_end(av[1], ".conf") == true)
    {
        int res = 0;
        std::string result;
        std::string file = av[1];
        char line[2024];
        int fd = open(file.c_str(), O_RDONLY);
        while ((res = read(fd, line, 1024)) > 0)
        {
            if (std::strcmp(line, "\n") != 0)
                result = result + line;
            int i = 0;
            while (i < 1024)
                line[i++] = 0;
        }
        std::map<int, std::string> tst;
        int i = 0;
        while (i < nbr_lines(result))
        {
            tst[i + 1] = Those_lines(result, i,nbr_lines(result));
            i++;
        }
        std::map<int, std::string>::iterator it = tst.begin();
        for (it = tst.begin(); it != tst.end(); ++it)
        {
            std::cout << "key is " << it->first;
            std::cout << "  the value: \t\t\t";
            std::cout << it->second << std::endl;
        }
    }
    else
        std::cerr << "wrong file \n";
    return (0);
}
