/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:19 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:19 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::~Replace()
{

}

bool file_redable(const std::string &path)
{
    std::ifstream file(path.c_str());
    return file.is_open();
}

void Replace::replace_content(void)
{
    // we check the infile and out file int the main function
    std::ifstream infile(_fileName);
    std::ofstream outfile(_fileName+".replace");
    if (!outfile.is_open())
    {
        std::cerr << "Failed to create output file\n";
        return ;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::string new_line;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(_s1, pos)) != std::string::npos)
        {
            new_line += line.substr(pos, found - pos);  // add text before _s1
            new_line += _s2;                            // replace _s1 with _s2
            pos = found + _s1.length();                 // move past _s1 so next find start from next pos
        }

        new_line += line.substr(pos);  // add remaining text
        outfile << new_line << "\n";   // write line to output file cuz getline removes it
    }

    // close the file
    infile.close();
    outfile.close();
}