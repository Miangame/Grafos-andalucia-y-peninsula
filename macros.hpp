/*!
  \file   macros.hpp
  \brief  Macros usadas para el menu.
  \author Fco. Javier Clavero Alvarez.
  \date   23/03/2015
*/

#ifndef MACROS_HPP
#define MACROS_HPP

#define LUGAR(x,y)   printf("\033[%d;%dH",x,y) //!< LUGAR
#define BORRAR       printf("\33[2J")   //!< BORRAR
#define PARPADEO     printf("%c[5m",27) //!< PARPADEO 
#define APAGA        printf("%c[0m",27) //!< APAGA
#define INVERSO      printf("%c[7m",27) //!< INVERSO
#define SUBRAYADO    printf("%c[4m",27) //!< SUBRAYADO
#define INTENSIDAD   printf("%c[1m",27) //!< INTENSIDAD

#define RESET "\e[m" //!< RESET

#define GREEN "\e[32m"   //!< GREEN
#define RED "\e[31m"     //!< RED
#define YELLOW "\e[33m"  //!< YELLOW
#define BLUE "\e[34m"    //!< BLUE
#define WHITE "\e[37m"   //!< WHITE
#define MAGENTA "\e[35m" //!< MAGENTA
#define BLACK "\e[30m"   //!<BLACK

#define ONGREEN "\e[42m"   //!< ONGREEN
#define ONRED "\e[41m"     //!< ONRED
#define ONYELLOW "\e[43m"  //!< ONYELLOW
#define ONBLUE "\e[44m"    //!< ONBLUE
#define ONWHITE "\e[47m"   //!< ONWHITE
#define ONMAGENTA "\e[45m" //!< ONMAGENTA
#define ONBLACK "\e[40m"   //!< ONBLACK	


#endif
