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

#set workdir
WORKDIR /usr/share/

#install phpMyAdmin && setting phpMyAdmin config
RUN curl https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.zip -o phpMyAdmin.zip \
    unzip phpMyAdmin.zip \
    rm -rf phpMyAdmin.zip \
    mv phpMyAdmin-4.9.5-all-languages/ phpMyAdmin
COPY ./srcs/config.inc.php ./phpMyAdmin

#install wordpress && setting wordpress config
