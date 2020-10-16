FROM debian:buster
MAINTAINER gipark <gipark@student.42seoul.kr>

#update package && install utils
RUN apt-get update && apt-get install -y vim unzip curl expect openssl

#install nginx && setting nginx config
RUN apt-get install -y nginx
COPY ./srcs/default /etc/nginx/sites-available/default

#install php7.3-fpm
RUN apt-get install -y php7.3-fpm
COPY ./srcs/index.htm /var/www/html/

#install mysql
RUN apt-get install -y mariadb-server php-mysql

#install php-mbstring && setting php extenstion config
#Mbstring stands for multi-byte string functions. Mbstring is an extension of php used to manage non-ASCII strings.
RUN apt-get install -y php-mbstring
COPY ./srcs/php.ini /etc/php/7.3/fpm/php.ini

#setting ssl protocol
RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes -out /etc/ssl/certs/private.crt -keyout /etc/ssl/private/private.key -subj "/C=KR/ST=Seoul/L=Gang-nam/OU=42seoul/OU=gipark/CN=student.42seoul.kr"

#set workdir for phpmyadmin and wordpress
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

#set permission
RUN chown -R www-data:www-data * &&\
    chmod -R 755 *

#set workdir for mysql_config
WORKDIR /etc/mysql

#setting mysql config
COPY ./srcs/mysql_secure_installation_auto.sh ./
RUN chmod +x ./mysql_secure_installation_auto.sh
COPY ./srcs/debian.cnf ./debian.cnf
COPY ./srcs/mysql_config.sql ./
COPY ./srcs/init_mysql.sh ./
RUN chmod +x ./init_mysql.sh

#set starting services
COPY ./srcs/init_service.sh /
RUN chmod +x /init_service.sh

CMD service mysql start &&\
    bash ./mysql_secure_installation_auto.sh &&\
    bash ./init_mysql.sh &&\
    bash /init_service.sh
