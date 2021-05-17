/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 05:38:36 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 12:27:10 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    int amount;
    AMateria *sources[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const &oteher);
    virtual ~MateriaSource();

    MateriaSource &operator=(MateriaSource const &other);

    void learnMateria(AMateria *m);
    AMateria* createMateria(std::string const &type);
};

#endif
