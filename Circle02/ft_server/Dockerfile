FROM debian:buster
MAINTAINER gipark <gipark@student.42seoul.kr>

#update package && install utils
RUN apt-get update && apt-get install -y vim unzip curl

#install nginx && setting nginx config
RUN apt-get install -y nginx
COPY ./srcs/default /etc/nginx/sites-available/default

#install php7.3-fpm
RUN apt-get install -y php7.3-fpm
COPY ./srcs/index.php /var/www/html/

#install mysql
RUN apt-get install -y mariadb-server php-mysql

#install php-mbstring && setting php extenstion config
#Mbstring stands for multi-byte string functions. Mbstring is an extension of php used to manage non-ASCII strings.
RUN apt-get install -y php-mbstring
COPY ./srcs/php.ini /etc/php/7.3/fpm/php.ini

#set workdir
WORKDIR /var/www/html

#install phpMyAdmin && setting phpMyAdmin config
RUN curl https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.zip -o phpMyAdmin.zip &&\
    unzip phpMyAdmin.zip &&\
    rm -rf phpMyAdmin.zip &&\
    mv phpMyAdmin-4.9.5-all-languages/ phpmyadmin
COPY ./srcs/config.inc.php ./phpmyadmin

#install wordpress && setting wordpress config
RUN curl https://wordpress.org/latest.zip -o wordpress.zip &&\
    unzip wordpress.zip &&\
    rm -rf wordpress.zip
COPY ./srcs/wp-config.php ./wordpress
