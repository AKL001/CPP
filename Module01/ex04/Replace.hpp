/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 07:22:22 by ablabib           #+#    #+#             */
/*   Updated: 2025/10/04 07:22:24 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <iostream>
#include <fstream> 

class Replace
{
    private:
        std::string _fileName;
        std::string _s1;
        std::string _s2;   
    public:
        Replace(const std::string  &filename, const std::string   &s1,const std::string &s2) : _fileName(filename) , _s1(s1) , _s2(s2)
        {
        }
        ~Replace();
        void replace_content(void);
};

bool file_redable(const std::string &path);

#endif