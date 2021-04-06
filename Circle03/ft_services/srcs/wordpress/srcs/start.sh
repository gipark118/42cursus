#!/bin/sh

tar -xvf wordpress.tar.gz > /dev/null
rm -rf wordpress.tar.gz
mv /custom-wp/ /var/www/wp
chmod -R 755 /var/www/*

sleep 10
mysql -hmysql -Dwordpress -uroot -ppasswd < /wordpress.sql

php-fpm7 & nginx -g "daemon off;"
